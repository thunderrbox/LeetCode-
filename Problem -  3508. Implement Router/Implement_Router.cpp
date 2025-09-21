class Router {
public:
    int n; // memory limit (max number of packets that can be stored)

    // Stores packet info: key = "source_dest_timestamp", value = {S, D, T}
    unordered_map<string, array<int,3>> packet;

    // For each destination, store a sorted list of timestamps
    // Example: destTime[5] = {90, 105, 110}
    map<int, vector<int>> destTime;

    // Queue of packet keys to track insertion order (for FIFO eviction)
    queue<string> q;

    Router(int memoryLimit) {
        n = memoryLimit;
    }

    // Utility: build a unique string key for packet (source, dest, time)
    string make(int S, int D, int T) {
        return to_string(S) + '_' + to_string(D) + '_' + to_string(T);
    }

    // Add a new packet to the router
    bool addPacket(int source, int destination, int timestamp) {
        string key = make(source, destination, timestamp);

        // Reject if packet already exists
        if (packet.find(key) != packet.end()) {
            return false;
        }

        // If memory full, forward (remove) the oldest packet
        if (q.size() >= n) {
            forwardPacket();
        }

        // Store packet
        packet[key] = {source, destination, timestamp};
        q.push(key);

        // Insert timestamp into the destination's sorted list
        auto &vec = destTime[destination];
        auto pos = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(pos, timestamp);

        return true;
    }

    // Forward (remove) the oldest packet
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        // Get oldest packet's key
        string key = q.front();
        q.pop();

        // Retrieve and remove from packet map
        auto packets = packet[key];
        packet.erase(key);

        int D = packets[1];
        int T = packets[2];

        // Remove timestamp from destination's list
        auto &vec = destTime[D];
        auto it = lower_bound(vec.begin(), vec.end(), T);
        if (it != vec.end() && *it == T) {
            vec.erase(it);
        }

        // Return the removed packet
        return {packets[0], packets[1], packets[2]};
    }

    // Count packets for a destination within a given time range
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTime.find(destination);

        // No packets for this destination
        if (it == destTime.end() || it->second.empty()) {
            return 0;
        }

        auto &vec = it->second;

        // Find first timestamp >= startTime
        int i = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        // Find first timestamp > endTime
        int j = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();

        // Number of packets in range
        return max(0, j - i);
    }
};
