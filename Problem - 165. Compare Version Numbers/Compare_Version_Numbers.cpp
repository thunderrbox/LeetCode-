class Solution {
public:
    int compareVersion(string version1, string version2) {
        // ------------------ Intuition ------------------
        // A version number is made up of integers separated by dots (e.g., "1.0.1").
        // To compare two versions:
        //   1. Split them part by part (using '.' as a separator).
        //   2. Convert each part into an integer (leading zeros don't matter).
        //   3. Compare corresponding integers.
        //   4. If a difference is found, return immediately.
        //   5. If one version has more parts, treat missing parts as 0.
        //   6. If all parts are equal, return 0.

        // ------------------ Variables ------------------
        int i = 0;  // pointer for version1
        int j = 0;  // pointer for version2
        int n = version1.size();
        int m = version2.size();

        // ------------------ Main Comparison Loop ------------------
        // Continue until both version strings are fully processed
        while (i < n || j < m) {
            int num1 = 0; // store current integer from version1
            int num2 = 0; // store current integer from version2

            // Extract number from version1 until '.' or end
            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0'); // convert substring to integer
                i++;
            }

            // Extract number from version2 until '.' or end
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0'); // convert substring to integer
                j++;
            }

            // Skip the '.' character in both versions
            i++;
            j++;

            // Compare the extracted numbers
            if (num1 < num2)
                return -1; // version1 < version2
            else if (num1 > num2)
                return 1;  // version1 > version2
        }

        // If all parts are equal, then versions are the same
        return 0;
    }
};

/*
------------------ Understanding ------------------
Example: version1 = "1.0.1", version2 = "1"
Step 1: Compare 1 and 1 → equal → continue
Step 2: Compare 0 and (missing → 0) → equal → continue
Step 3: Compare 1 and (missing → 0) → 1 > 0 → return 1

------------------ Complexity ------------------
Time Complexity: O(n + m)
    - Each character of version1 and version2 is processed once.
Space Complexity: O(1)
    - Only integer variables and pointers used, no extra data structures.
*/
