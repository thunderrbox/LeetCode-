class Solution {
    public int[] findErrorNums(int[] nums) {

        // ---------------------------------------------------------
        // APPROACH:
        // We use a frequency array to count how many times
        // each number from 1 to n appears in nums.
        //
        // In the original array:
        // - Every number from 1 to n should appear exactly once.
        // - One number appears twice -> DUPLICATE
        // - One number does not appear -> MISSING
        // ---------------------------------------------------------

        int n = nums.length;

        // Create a frequency array of size n + 1.
        // Index represents the number.
        //
        // Example:
        // nums = [1, 2, 2, 4]
        //
        // freq[1] = 1
        // freq[2] = 2  -> duplicate
        // freq[3] = 0  -> missing
        // freq[4] = 1
        int[] freq = new int[n + 1];

        // Count how many times every number appears.
        for (int num : nums) {
            freq[num]++;
        }

        // Initially, we don't know the duplicate
        // and missing numbers.
        int duplicate = -1;
        int missing = -1;

        // Check every number from 1 to n.
        for (int i = 1; i <= n; i++) {

            // If frequency is 2, the number appeared twice.
            // Therefore, it is the duplicate number.
            if (freq[i] == 2) {
                duplicate = i;
            }

            // If frequency is 0, the number never appeared.
            // Therefore, it is the missing number.
            if (freq[i] == 0) {
                missing = i;
            }
        }

        // Return the answer in the required format:
        // [duplicate, missing]
        return new int[]{duplicate, missing};
    }
}

/*
---------------------------------------------------------
UNDERSTANDING:

Example:
nums = [1, 2, 2, 4]

Step 1: Count frequencies

Number     Frequency
  1           1
  2           2  -> duplicate
  3           0  -> missing
  4           1

Therefore:

duplicate = 2
missing   = 3

Answer = [2, 3]

---------------------------------------------------------
WHY THIS WORKS:

Normally, numbers from 1 to n should occur exactly once.

If:
    freq[i] == 2
then i occurs twice -> DUPLICATE.

If:
    freq[i] == 0
then i does not occur -> MISSING.

---------------------------------------------------------
TIME COMPLEXITY:

O(n)

First loop:
    O(n)

Second loop:
    O(n)

Total:
    O(n) + O(n)
    = O(n)

---------------------------------------------------------
SPACE COMPLEXITY:

O(n)

We create:
    int[] freq = new int[n + 1];

So the extra space required is O(n).
---------------------------------------------------------
*/








// ---------------------------------------------------------
// APPROACH:
//
// This approach tries to find the duplicate by checking
// whether two consecutive elements are equal.
//
// If:
//     nums[i] == nums[i + 1]
//
// then it assumes nums[i] is the duplicate.
//
// It then assumes that the missing number is:
//     duplicate + 1
//
// ---------------------------------------------------------

// class Solution {
//     public int[] findErrorNums(int[] nums) {
//
//         // Create an answer array.
//         // ans[0] -> duplicate
//         // ans[1] -> missing
//         int[] ans = new int[2];
//
//         // Check every pair of adjacent elements.
//         //
//         // We stop at nums.length - 2 because we access
//         // nums[i + 1] inside the loop.
//         for(int i = 0; i < nums.length - 1; i++){
//
//             // If two adjacent elements are equal,
//             // we assume that element is the duplicate.
//             if(nums[i] == nums[i+1]){
//
//                 // Store duplicate number.
//                 ans[0] = nums[i];
//
//                 // Assume the next number is missing.
//                 ans[1] = nums[i] + 1;
//
//                 // Once duplicate is found, stop the loop.
//                 break;
//             }
//         }
//
//         // Return [duplicate, missing].
//         return ans; 
//     }
// }

/*
---------------------------------------------------------
UNDERSTANDING:

The idea is:

If the array looks like:

[1, 2, 2, 4]

Then:

nums[1] == nums[2]

because:

2 == 2

So we identify:

duplicate = 2

Then we assume:

missing = duplicate + 1
missing = 3

Therefore:

answer = [2, 3]

---------------------------------------------------------
IMPORTANT:

This approach DOES NOT work for the general problem.

Example:

nums = [1, 2, 4, 2]

The duplicate is 2, but the two 2s are not adjacent.

Therefore:

nums[i] == nums[i + 1]

will never become true.

It also incorrectly assumes:

missing = duplicate + 1

But the missing number can be before or after the duplicate.

Example:

nums = [1, 3, 3, 4]

duplicate = 3
missing = 2

But:

duplicate + 1 = 4

So the assumption is incorrect.

---------------------------------------------------------
TIME COMPLEXITY:

O(n)

We traverse the array once.

---------------------------------------------------------
SPACE COMPLEXITY:

O(1)

Only a fixed-size array:

int[] ans = new int[2];

is used.

---------------------------------------------------------
FINAL VERDICT:

First approach:
    Correct
    O(n) time
    O(n) space

Second approach:
    Not correct for the general problem
    O(n) time
    O(1) extra space

The second approach would only work under additional
conditions such as the array being sorted and the missing
number following the duplicate.
---------------------------------------------------------
*/