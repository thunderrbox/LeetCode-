class Solution {
public:
    int count; // Stores the number of components whose sum % k == 0

    /*
        dfs() → returns the sum of the subtree rooted at 'curr' modulo k.

        Intuition:
        - Each subtree computes its total sum.
        - If a subtree sum % k == 0, it means this subtree can form its own
          k-divisible connected component.
        - We increment the 'count' and return 0 upward (because once cut, the parent
          should not get its sum added).

        Parameters:
        curr  = current node
        parent = parent node to avoid going back (since the graph is a tree)
        adj   = adjacency list
        values = values assigned to each node
        k     = divisor

        Returns:
        - sum of subtree rooted at curr (mod k)
    */
    int dfs(int curr, int parent, unordered_map<int, vector<int>>& adj,
            vector<int>& values, int k) {

        // Start with the current node's value
        int sum = values[curr];

        // Explore all neighbors (children)
        for (auto& negh : adj[curr]) {
            if (negh != parent) { // Avoid revisiting the parent
                // Add child's subtree sum
                sum += dfs(negh, curr, adj, values, k);
                sum %= k; // Keep numbers small using modulo
            }
        }

        sum %= k; // Normalize sum again after loop

        /*
            If the total subtree sum is divisible by k,
            then this subtree is a valid component.
        */
        if (sum == 0) {
            count++;
        }

        return sum; // Pass the remainder up the DFS tree
    }

    /*
        Builds adjacency list, runs DFS, and returns the count.

        Complexity Analysis:
        - Building adjacency list: O(n)
        - DFS traversal: O(n)
        - Total time: O(n)
        - Space complexity: O(n) for adjacency list + O(n) recursion stack (worst case)
    */
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        unordered_map<int, vector<int>> adj;

        // Build adjacency list for the tree
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        count = 0; // initialize count

        // Start DFS from root node (0), parent = -1 means no parent
        dfs(0, -1, adj, values, k);

        return count;
    }
};
