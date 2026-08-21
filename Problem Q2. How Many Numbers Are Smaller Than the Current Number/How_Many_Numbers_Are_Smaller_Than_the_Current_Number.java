class Solution {

    /*
     * =========================================================
     * UNDERSTANDING:
     * =========================================================
     * For every element nums[i], we need to find how many
     * elements in the array are strictly smaller than nums[i].
     *
     * Example:
     * nums = [8, 1, 2, 2, 3]
     *
     * For 8 -> smaller elements are [1, 2, 2, 3] -> 4
     * For 1 -> no smaller element -> 0
     * For 2 -> smaller element is [1] -> 1
     * For 2 -> smaller element is [1] -> 1
     * For 3 -> smaller elements are [1, 2, 2] -> 3
     *
     * Answer = [4, 0, 1, 1, 3]
     *
     *
     * =========================================================
     * APPROACH:
     * =========================================================
     * 1. Take each element one by one using the outer loop.
     *
     * 2. For the current element nums[i], compare it with
     *    every element in the array using the inner loop.
     *
     * 3. If nums[i] > nums[j], then nums[j] is smaller than
     *    nums[i], so increase the count.
     *
     * 4. Store the final count in ans[i].
     *
     * 5. Return the ans array.
     *
     *
     * =========================================================
     * TIME COMPLEXITY:
     * =========================================================
     * Outer loop runs n times.
     * Inner loop also runs n times for every outer iteration.
     *
     * Time = O(n * n)
     *      = O(n²)
     *
     *
     * =========================================================
     * SPACE COMPLEXITY:
     * =========================================================
     * We use an ans[] array of size n.
     *
     * Space = O(n)
     *
     * Auxiliary space excluding the output array = O(1)
     */

    public int[] smallerNumbersThanCurrent(int[] nums) {

        // Store the size of the input array.
        int n = nums.length;

        // ans[i] will store the number of elements
        // that are smaller than nums[i].
        int[] ans = new int[n];

        // Select each element one by one.
        for (int i = 0; i < n; i++) {

            // Count of elements smaller than nums[i].
            int count = 0;

            // Compare nums[i] with every element.
            for (int j = 0; j < n; j++) {

                // If nums[j] is strictly smaller than nums[i],
                // increase the count.
                //
                // i != j is not actually necessary because
                // nums[i] > nums[i] is always false.
                if (i != j && nums[i] > nums[j]) {
                    count++;
                }
            }

            // Store the count for the current element.
            ans[i] = count;
        }

        // Return the final result.
        return ans;
    }
}













// class Solution {

//     /*
//      * =========================================================
//      * UNDERSTANDING:
//      * =========================================================
//      * We need to find, for every nums[i], how many numbers
//      * in the array are strictly smaller than nums[i].
//      *
//      * Instead of comparing every element with every other
//      * element, we can use the constraint that:
//      *
//      *      0 <= nums[i] <= 100
//      *
//      * Therefore, we can create a frequency array of size 101.
//      *
//      * freq[x] = number of times x appears in nums.
//      *
//      * After converting freq[] into a prefix sum:
//      *
//      * freq[x] = number of elements <= x
//      *
//      * Therefore:
//      *
//      * freq[x - 1] = number of elements < x
//      *
//      * This allows us to directly find the answer for each
//      * element.
//      *
//      *
//      * Example:
//      * nums = [8, 1, 2, 2, 3]
//      *
//      * Frequency:
//      * 1 -> 1 time
//      * 2 -> 2 times
//      * 3 -> 1 time
//      * 8 -> 1 time
//      *
//      * After prefix sum:
//      *
//      * freq[1] = 1
//      * freq[2] = 3
//      * freq[3] = 4
//      *
//      * For 3:
//      * freq[3 - 1] = freq[2] = 3
//      *
//      * So there are 3 numbers smaller than 3.
//      *
//      *
//      * =========================================================
//      * APPROACH:
//      * =========================================================
//      * 1. Create a frequency array of size 101 because the
//      *    numbers can only range from 0 to 100.
//      *
//      * 2. Count the occurrence of every number.
//      *
//      * 3. Convert the frequency array into a prefix sum array.
//      *
//      * 4. For every nums[i]:
//      *
//      *      If nums[i] == 0:
//      *          Answer = 0
//      *
//      *      Otherwise:
//      *          Answer = freq[nums[i] - 1]
//      *
//      * 5. Return the result array.
//      *
//      *
//      * =========================================================
//      * TIME COMPLEXITY:
//      * =========================================================
//      * Counting frequencies = O(n)
//      *
//      * Prefix sum from 1 to 100 = O(101)
//      *
//      * Creating result = O(n)
//      *
//      * Total:
//      * O(n + 101 + n)
//      *
//      * Since 101 is a constant:
//      *
//      * Time = O(n)
//      *
//      *
//      * =========================================================
//      * SPACE COMPLEXITY:
//      * =========================================================
//      * result[] = O(n)
//      * freq[]   = O(101)
//      *
//      * Total:
//      * O(n + 101)
//      *
//      * Since 101 is constant:
//      *
//      * Space = O(n)
//      */

//     public int[] smallerNumbersThanCurrent(int[] nums) {

//         // Store the size of the input array.
//         int n = nums.length;

//         // Result array.
//         // ans[i] will store the number of elements
//         // smaller than nums[i].
//         int[] ans = new int[n];

//         // Since nums[i] is between 0 and 100,
//         // we need an array of size 101.
//         int[] freq = new int[101];

//         // -----------------------------------------------------
//         // STEP 1: Count the frequency of every number.
//         // -----------------------------------------------------
//         //
//         // Example:
//         // nums = [8, 1, 2, 2, 3]
//         //
//         // freq[1] = 1
//         // freq[2] = 2
//         // freq[3] = 1
//         // freq[8] = 1
//         //
//         for (int num : nums) {
//             freq[num]++;
//         }

//         // -----------------------------------------------------
//         // STEP 2: Create the prefix sum.
//         // -----------------------------------------------------
//         //
//         // After this operation:
//         //
//         // freq[x] = number of elements <= x
//         //
//         // Example:
//         //
//         // Before:
//         // freq[1] = 1
//         // freq[2] = 2
//         // freq[3] = 1
//         //
//         // After prefix sum:
//         //
//         // freq[1] = 1
//         // freq[2] = 3
//         // freq[3] = 4
//         //
//         for (int i = 1; i < 101; i++) {
//             freq[i] += freq[i - 1];
//         }

//         // -----------------------------------------------------
//         // STEP 3: Find the number of smaller elements.
//         // -----------------------------------------------------
//         for (int i = 0; i < n; i++) {

//             // If the current number is 0,
//             // there cannot be any smaller number.
//             if (nums[i] == 0) {
//                 ans[i] = 0;
//             } else {

//                 // freq[nums[i] - 1] gives the number
//                 // of elements strictly smaller than nums[i].
//                 ans[i] = freq[nums[i] - 1];
//             }
//         }

//         // Return the final answer.
//         return ans;
//     }
// }