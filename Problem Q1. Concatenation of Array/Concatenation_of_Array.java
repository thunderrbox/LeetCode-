class Solution {
    public int[] getConcatenation(int[] nums) {

        /*
         * UNDERSTANDING:
         * We need to concatenate the given array with itself.
         *
         * Example:
         * nums = [1, 2, 3]
         *
         * Output:
         * [1, 2, 3, 1, 2, 3]
         *
         *
         * APPROACH:
         * 1. Find the length of nums.
         * 2. Create an answer array of size 2*n.
         * 3. Copy nums into the first half of ans.
         * 4. Copy nums again into the second half of ans.
         * 5. Return ans.
         */

        int n = nums.length;

        // Create an array of size 2*n
        int[] ans = new int[2 * n];

        // Copy nums into the first half of ans
        // nums: [1, 2, 3]
        // ans:  [1, 2, 3, _, _, _]
        System.arraycopy(nums, 0, ans, 0, n);

        // Copy nums into the second half of ans
        // nums: [1, 2, 3]
        // ans:  [1, 2, 3, 1, 2, 3]
        System.arraycopy(nums, 0, ans, n, n);

        return ans;
    }
}

/*
 * COMPLEXITY:
 *
 * Time Complexity: O(n)
 * - We copy n elements two times.
 * - O(2n) = O(n)
 *
 * Space Complexity: O(n)
 * - We create an array of size 2*n.
 */

//  class Solution {
//     public int[] getConcatenation(int[] nums) {

//         /*
//          * UNDERSTANDING:
//          * We need to concatenate nums with itself.
//          *
//          * Example:
//          * nums = [1, 2, 3]
//          *
//          * Output:
//          * [1, 2, 3, 1, 2, 3]
//          *
//          *
//          * APPROACH:
//          * 1. Create an array of size 2*n.
//          * 2. Use an outer loop to copy nums two times.
//          * 3. Use an inner loop to traverse every element of nums.
//          * 4. Store each element in ans.
//          * 5. Return ans.
//          */

//         // Create an array of size 2*n
//         int[] ans = new int[2 * nums.length];

//         // j represents how many times we need
//         // to copy nums.
//         int j = 2;

//         // i represents the current position
//         // in the answer array.
//         int i = 0;

//         // Copy nums two times
//         while (j != 0) {

//             // k traverses through nums
//             int k = 0;

//             // Copy every element of nums
//             while (k < nums.length) {

//                 // Put nums[k] into ans[i]
//                 ans[i] = nums[k];

//                 // Move to next position in ans
//                 i++;

//                 // Move to next element in nums
//                 k++;
//             }

//             // If the entire answer array is filled,
//             // stop the loop.
//             if (i == (2 * nums.length)) {
//                 break;
//             }

//             // One complete copy is finished
//             j--;
//         }

//         return ans;
//     }
// }

// /*
//  * COMPLEXITY:
//  *
//  * Time Complexity: O(n)
//  * - Outer loop runs 2 times.
//  * - Inner loop runs n times.
//  * - O(2*n) = O(n)
//  *
//  * Space Complexity: O(n)
//  * - We create ans[] of size 2*n.
//  */