class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();                 // number of rows in the triangle
        int m = triangle[n-1].size();            // number of elements in the last row (widest row)

        // DP table to store the minimum path sum from (i, j) to bottom
        vector<vector<int>> dp(n , vector<int>(m, -1));

        // Base case: The last row values are themselves the minimum path sums
        for(int i = 0 ; i < m ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        // Bottom-up DP: process from second-last row upwards
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < triangle[i].size(); j++){

                // Possible moves:
                // 1. Go straight down (row+1, col)
                int a = dp[i+1][j];

                // 2. Go diagonal right (row+1, col+1) — check bounds
                if(j < triangle[i].size()) 
                    a = min(a, dp[i+1][j+1]);

                // Current cell value + best of the two options
                dp[i][j] = triangle[i][j] + a;
            }
        }

        // Final answer is stored at top of the triangle
        return dp[0][0];
    }

private:
    // ❌ Incorrect DFS attempt (commented in your code)
    // A recursive solution could work but is inefficient due to overlapping subproblems.
    // int dfs(vector<vector<int>> nums, int row, int col) {
    //     if(row == nums.size()-1){
    //         return nums[row][col];
    //     }
    //     int same = dfs(nums, row + 1, col);
    //     int diagonal = dfs(nums, row + 1, col + 1);
    //     return nums[row][col] + min(same, diagonal);
    // }
};

/*
\U0001f4cc Intuition:
We are asked to find the minimum path sum from the top of the triangle to the bottom. 
At each cell (i, j), you can move either:
    - straight down to (i+1, j), or
    - diagonally right to (i+1, j+1).
So, the value of dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]).

By starting from the bottom row and moving upward, we avoid recomputation and 
directly build the solution to the top.

\U0001f4cc Understanding:
- Base case: The last row has no further moves, so dp[last_row][j] = triangle[last_row][j].
- Transition: dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]).
- We compute from bottom → top, so by the time we compute dp[i][j], its children are already known.

\U0001f4cc Complexity:
- Time Complexity: O(n^2), since we visit each element of the triangle once (total ~ n(n+1)/2 elements).
- Space Complexity: O(n^2) due to the dp table.
  \U0001f449 Can be optimized to O(n) by reusing a single 1D array (rolling DP).
*/
