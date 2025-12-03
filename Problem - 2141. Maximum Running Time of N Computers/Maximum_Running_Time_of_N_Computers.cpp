class Solution {
public:

    /*
        ----------------------------------------------------------
        INTUITION / UNDERSTANDING
        ----------------------------------------------------------
        We have n computers that must all run simultaneously for 
        the same amount of time. We have several batteries, and 
        each battery can contribute up to its capacity. A battery 
        can be split across computers (because swapping is allowed).

        We want to find the maximum time T such that:
            total usable battery time ≥ n * T

        For a given target time T:
           - From each battery, we can use at most min(battery[i], T)
             (because a battery cannot give more than its capacity).

           - If sum(min(b[i], T)) >= n*T, then it is possible to run
             all n computers for T minutes.

        This forms a monotonic condition => we can apply Binary Search.

        Binary Search Range:
           low  = 0
           high = sum(batteries) / n
             (because total energy divided equally among n computers 
              gives the absolute maximum possible running time)

        Then binary search for the largest T that satisfies the check().
    */

    // ----------------------------------------------------------
    // CHECK FUNCTION
    // Checks if we can run n computers for target_time T.
    // ----------------------------------------------------------
    bool check(long long target_time, int n, const vector<int>& batteries) {

        long long total_available_time = 0;

        // Accumulate usable time per battery
        for (int b : batteries) {
            // A battery can contribute at most T or its full capacity
            total_available_time += std::min((long long)b, target_time);
        }

        // Check if total available energy is enough for n computers
        return total_available_time >= (long long)n * target_time;
    }

    // ----------------------------------------------------------
    // MAIN FUNCTION
    // ----------------------------------------------------------
    long long maxRunTime(int n, std::vector<int>& batteries) {

        long long low = 0;
        long long high = 0;

        // Total sum of battery capacities
        for (int b : batteries) {
            high += b;
        }

        // Maximum possible time (if perfectly distributed)
        high /= n;

        long long ans = 0;

        // ----------------------------------------------------------
        // BINARY SEARCH FOR MAXIMUM POSSIBLE RUN TIME
        // ----------------------------------------------------------
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // If mid is possible → try a larger time
            if (check(mid, n, batteries)) {
                ans = mid;
                low = mid + 1;
            } 
            // Otherwise try a smaller time
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

