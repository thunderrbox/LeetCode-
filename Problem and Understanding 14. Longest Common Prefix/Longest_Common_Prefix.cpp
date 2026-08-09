#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    PROBLEM: Longest Common Prefix
    ============================================================

    Given an array of strings, find the longest common prefix
    among all the strings.

    Example:
    strs = ["flower", "flow", "flight"]

    Answer = "fl"


    ============================================================
    UNDERSTANDING
    ============================================================

    A prefix means characters starting from index 0.

    For example:

    "flower" -> f l o w e r
    "flow"   -> f l o w
    "flight" -> f l i g h t

    We need to find characters that are present at the same
    position in EVERY string.

    Position 0:
        flower -> f
        flow   -> f
        flight -> f
        => Common

    Position 1:
        flower -> l
        flow   -> l
        flight -> l
        => Common

    Position 2:
        flower -> o
        flow   -> o
        flight -> i
        => Not common

    So the answer is:

        "fl"


    ============================================================
    APPROACH
    ============================================================

    We will use the FIRST string as the reference string.

    Why?

    The longest common prefix cannot be longer than the first
    string itself.

    Step 1:
        Check if the vector is empty.
        If empty, return "".

    Step 2:
        Traverse every character of strs[0].

    Step 3:
        For each character, compare it with the character at
        the SAME index in every other string.

    Step 4:
        If either:
            a) The current string is shorter, OR
            b) The character does not match

        then the common prefix ends at this position.

    Step 5:
        Return the part of strs[0] before the mismatch.

    Step 6:
        If no mismatch is found, the entire first string is
        the common prefix.


    ============================================================
    ALGORITHM
    ============================================================

    1. If strs is empty, return "".

    2. Run a loop:
           i = 0 to length of strs[0] - 1

    3. Store:
           ch = strs[0][i]

    4. Compare ch with strs[j][i] for every string j.

    5. If:
           i >= strs[j].size()
       OR
           strs[j][i] != ch

       return strs[0].substr(0, i).

    6. If the complete loop finishes, return strs[0].


    ============================================================
    CODE
    ============================================================
    */

    string longestCommonPrefix(vector<string>& strs) {

        // If there are no strings
        if (strs.empty()) {
            return "";
        }

        // Traverse every character of the first string
        for (int i = 0; i < strs[0].size(); i++) {

            // Character from the first/reference string
            char ch = strs[0][i];

            // Compare this character with every other string
            for (int j = 1; j < strs.size(); j++) {

                // If current string is shorter
                // OR character does not match
                if (i >= strs[j].size() || strs[j][i] != ch) {

                    // Common prefix ends before index i
                    return strs[0].substr(0, i);
                }
            }
        }

        // Entire first string is common
        return strs[0];
    }
};


/*
============================================================
COMPLEXITY
============================================================

Let:

N = number of strings
M = length of the shortest string

Time Complexity:
    O(N × M)

Why?
    In the worst case, we compare M characters across N strings.

Space Complexity:
    O(1) auxiliary space

We are not using any extra data structure.
============================================================
*/


/*
============================================================
DRY RUN
============================================================

Input:
    ["flower", "flow", "flight"]

i = 0
    f == f == f
    Common prefix = "f"

i = 1
    l == l == l
    Common prefix = "fl"

i = 2
    o == o
    But:
        flight[2] = 'i'

    Mismatch found.

Return:
    strs[0].substr(0, 2)

Answer:
    "fl"


============================================================
KEY DSA PATTERN
============================================================

This is called:

    "Vertical Scanning"

Instead of comparing complete strings one by one,
we compare the SAME INDEX across all strings.

Think:

    flower
    flow
    flight
      ^
      |
      Compare this column

The moment a mismatch occurs,
we stop because no longer prefix is possible.
============================================================
*/