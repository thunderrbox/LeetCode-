class Solution {
public:
    /*
        \U0001f9e0 Intuition:
        ----------------
        The problem asks to remove all '0' digits from a given number.
        For example:
            n = 1020304 → after removing zeros → 1234

        Approach:
        1. Convert the number 'n' into a string for easy digit traversal.
        2. Iterate through each character of the string.
        3. Append every non-zero character to a new string 'ans'.
        4. Finally, convert 'ans' back to a number using stoll().
        5. If 'ans' is empty (meaning all digits were zero), return 0.

        Example Trace:
        ----------------
        Input: n = 105020
        Step 1: num = "105020"
        Step 2: Traverse → {'1','0','5','0','2','0'}
        Step 3: ans = "152"
        Step 4: Convert back → 152
        Output: 152
    */
    long long removeZeros(long long n) {
        string num = to_string(n);  // Step 1: Convert number to string
        string ans = "";            // Step 2: Initialize empty string for non-zero digits

        for (char c : num) {        // Step 3: Traverse each digit
            if (c != '0')           // Step 4: Skip zeros
                ans += c;            // Step 5: Keep non-zero digits
        }

        // Step 6: If all digits were zero, return 0; else convert back to long long
        return ans.empty() ? 0 : stoll(ans);
    }
};

/*
\U0001f4ca Complexity Analysis:
------------------------
Let 'd' be the number of digits in n.

- Time Complexity:  O(d)
    → We traverse each digit once.

- Space Complexity: O(d)
    → We store the string representation and a filtered result string.
*/
