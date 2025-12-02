class Solution {
public:
    const long MOD = 1e9 + 7;

    // ---------------------------------------------------------------
    // INTUITION:
    // A trapezoid is formed when we pick two horizontal segments
    // that lie on different y-levels (parallel lines).
    //
    // For each y-level having c points → number of segments = C(c,2).
    // Let's call this seg[i].
    //
    // Total trapezoids = sum over all pairs of levels (i < j):
    //          seg[i] * seg[j]
    //
    // That equals:
    //     (sum(seg[i])^2 - sum(seg[i]^2)) / 2
    //
    // This is exactly what this solution computes efficiently.
    // ---------------------------------------------------------------


    int countTrapezoids(vector<vector<int>>& points) {

        // freq[y] = number of points having same y-coordinate.
        // Idea: count how many points lie on each horizontal level.
        unordered_map<int,long> freq;

        // Count points per y-level
        for (auto &p : points) 
            freq[p[1]]++;


        long total = 0;        // stores sum of seg[i] values
        long sumSquares = 0;   // stores sum of seg[i]^2


        // For every y-level:
        // If that level has c points → number of horizontal segments = C(c,2)
        for (auto &it : freq) {
            long c = it.second;

            // Segments only exist if >= 2 points on the same y-level
            if (c < 2) continue;

            // seg = number of horizontal lines possible on this y-level
            long seg = (c * (c - 1) / 2) % MOD;

            // Maintain total sum(seg)
            total = (total + seg) % MOD;

            // Maintain total sum(seg^2)
            sumSquares = (sumSquares + (seg * seg) % MOD) % MOD;
        }


        // Now compute: (total^2 - sumSquares) / 2  (modulo form)
        // total^2 counts ordered pairs of levels (i, j)
        // subtracting sumSquares removes pairs where i == j
        long totalSq = (total * total) % MOD;

        long ans = (totalSq - sumSquares + MOD) % MOD;

        // Modular inverse of 2 under MOD = 1e9+7
        long inv2 = 500000004;  // (2^(MOD-2)) % MOD

        // Final answer = divide by 2 using modular inverse
        ans = (ans * inv2) % MOD;

        return ans;
    }
};
