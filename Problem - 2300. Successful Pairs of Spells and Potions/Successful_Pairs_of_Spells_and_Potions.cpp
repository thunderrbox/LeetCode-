#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // ======================= OPTIMIZED APPROACH =======================
        // Step 1: Sort potions to enable binary search
        // Sorting is required because we want to quickly find the first potion
        // that satisfies spell * potion >= success for each spell
        sort(potions.begin(), potions.end()); 

        int n = spells.size(); // number of spells
        int m = potions.size(); // number of potions
        vector<int> result(n); // To store the number of successful pairs for each spell

        // Step 2: Iterate through each spell
        for (int i = 0; i < n; i++) {
            long long spell = spells[i]; // Current spell power

            // Step 3: Compute the minimum potion strength required
            // To satisfy spell * potion >= success:
            //   potion >= success / spell
            // We use ceiling division to ensure rounding up because integer division
            // truncates the decimal part
            long long required = (success + spell - 1) / spell; 

            // Step 4: Binary search to find the first potion >= required
            // Initialize binary search boundaries
            int low = 0, high = m - 1, first = m; // 'first' = index of first valid potion
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (potions[mid] >= required) {
                    // Found a valid potion, but maybe there is an earlier valid one
                    first = mid;
                    high = mid - 1; // move left to find earlier valid potion
                } else {
                    // Potion too weak, move right
                    low = mid + 1;
                }
            }

            // Step 5: Calculate number of successful pairs
            // All potions from index 'first' to end are valid
            result[i] = m - first;
        }

        return result;
    }
};

/*
======================== DETAILED INTUITION & UNDERSTANDING ========================

1. Problem:
   - Given spells[i] and potions[j], count for each spell how many potions
     satisfy: spell[i] * potion[j] >= success

2. Brute Force Approach (TLE):
   ------------------------------------------------------
   vector<int> pairs;
   for (auto &i : spells) {
       int count = 0;
       for (auto j : potions) {
           if ((long long)i * j >= success) count++;
       }
       pairs.push_back(count);
   }
   - Compares every spell with every potion
   - Time Complexity: O(n * m)
   - If n, m <= 1e5 → 1e10 operations → TLE
   - Works only for small inputs
   - ❌ Reason for TLE: Nested loop over large input size

3. Optimized Approach (Accepted):
   ------------------------------------------------------
   - Step 1: Sort potions → O(m log m)
     * Sorting allows us to use binary search efficiently
   - Step 2: For each spell:
       a) Compute minimum required potion strength: ceil(success / spell)
       b) Use binary search to find the first potion >= required
       c) All potions after this index are valid → count = m - index
   - Step 3: Total Complexity:
       * Sorting potions: O(m log m)
       * Iterating spells + binary search for each: O(n log m)
       * Total = O(m log m + n log m) → efficient for large inputs

4. Ceiling Division Explanation:
   - success = 10, spell = 3 → success/spell = 3.333...
   - We need potion >= 4 (3*3 < 10)
   - Formula: (success + spell - 1) / spell automatically rounds up

5. Binary Search Explanation:
   - We want first potion >= required
   - Binary search finds index efficiently: O(log m)
   - All potions to the right are guaranteed to form successful pairs

6. Space Complexity:
   - O(n) for result vector
   - Sorting in-place, so extra space negligible

7. Summary:
   - Brute force: correct but too slow (TLE)
   - Optimized: binary search + sorting → fast and accepted
   - Intuition: sort potions → compute minimum required → binary search → count

==================================================================================
*/
