import java.util.AbstractList;
import java.util.ArrayList;
import java.util.List;

class Solution {

    // Stores the final list of disappeared numbers.
    // It is initialized only when size() or get() is called.
    private List<Integer> list;

    /*
     * Approach:
     *
     * We need to find numbers from 1 to n that do not appear in nums.
     *
     * Instead of using an extra frequency array, we use the input array itself
     * to mark which numbers are present.
     *
     * For every number nums[i]:
     *      1. Take its absolute value.
     *      2. Convert that value into an array index: val - 1.
     *      3. Make nums[val - 1] negative.
     *
     * Negative means:
     *      "This number exists in the array."
     *
     * After marking:
     *      nums[i] > 0  -> number i + 1 is missing
     *      nums[i] < 0  -> number i + 1 exists
     *
     * The AbstractList is used to create the result lazily.
     * The actual processing happens only when size() or get() is called.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n) for the returned result list.
     * Extra marking space: O(1), because we modify nums itself.
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {

        // Return a custom List implementation.
        return new AbstractList<Integer>() {

            /*
             * size() is called when someone wants to know
             * how many disappeared numbers are present.
             */
            public int size() {

                // Make sure the result is initialized.
                init();

                return list.size();
            }

            /*
             * get(i) returns the disappeared number
             * at index i in the result list.
             */
            public Integer get(int i) {

                // Make sure the result is initialized.
                init();

                return list.get(i);
            }

            /*
             * Performs the actual algorithm only once.
             *
             * This is called "lazy initialization".
             *
             * If the list has already been created,
             * we don't perform the work again.
             */
            private void init() {

                // Already initialized -> no need to process again.
                if (list != null)
                    return;

                int n = nums.length;

                /*
                 * STEP 1: Mark all numbers that are present.
                 *
                 * Example:
                 * nums = [4,3,2,7,8,2,3,1]
                 *
                 * For value 4:
                 * index = 4 - 1 = 3
                 * nums[3] becomes negative.
                 *
                 * The absolute value is required because
                 * an element may already have been made negative
                 * while processing another number.
                 */
                for (int i = 0; i < n; i++) {

                    // Get the actual value, ignoring any previous marking.
                    int val = Math.abs(nums[i]);

                    // Mark the position corresponding to val as negative.
                    nums[val - 1] = -Math.abs(nums[val - 1]);
                }

                /*
                 * STEP 2: Find the numbers that were never marked.
                 *
                 * If nums[i] is still positive:
                 *      i + 1 never appeared in the original array.
                 *
                 * Therefore, i + 1 is a disappeared number.
                 */
                list = new ArrayList<>();

                for (int i = 0; i < n; i++) {

                    if (nums[i] > 0) {

                        // Convert index back to the number.
                        list.add(i + 1);
                    }
                }
            }
        };
    }
}








// class Solution {

//     /*
//      * Understanding:
//      *
//      * The array contains n numbers where each number is in the range 1 to n.
//      * Some numbers may appear twice, which means some other numbers are missing.
//      *
//      * We need to return all numbers from 1 to n that do not appear in nums.
//      *
//      * Example:
//      * nums = [4,3,2,7,8,2,3,1]
//      *
//      * Numbers from 1 to 8:
//      * 1 -> present
//      * 2 -> present
//      * 3 -> present
//      * 4 -> present
//      * 5 -> missing
//      * 6 -> missing
//      * 7 -> present
//      * 8 -> present
//      *
//      * Answer = [5,6]
//      *
//      *
//      * Approach:
//      *
//      * 1. Create a frequency array of size n + 1.
//      *    We use n + 1 because numbers are from 1 to n,
//      *    and index 0 is not used.
//      *
//      * 2. Traverse nums and increase the frequency of every number.
//      *
//      * 3. Traverse the frequency array from 1 to n.
//      *    If freq[i] == 0, number i never appeared in nums,
//      *    so it is a missing number.
//      *
//      * 4. Add every missing number to the answer list.
//      *
//      *
//      * Time Complexity:
//      * O(n) + O(n) = O(n)
//      *
//      * Space Complexity:
//      * O(n)
//      *
//      * The frequency array requires O(n) extra space.
//      */
//     public List<Integer> findDisappearedNumbers(int[] nums) {

//         // Stores all numbers that are missing from nums.
//         ArrayList<Integer> ans = new ArrayList<>();

//         // Frequency array.
//         // Index represents the number.
//         // freq[i] represents how many times i occurs in nums.
//         //
//         // Size is n + 1 because numbers range from 1 to n.
//         int[] freq = new int[nums.length + 1];

//         // Count the frequency of every number in nums.
//         for (int num : nums) {

//             // Increase the frequency of the current number.
//             freq[num]++;
//         }

//         // Check every number from 1 to n.
//         for (int i = 1; i < freq.length; i++) {

//             // If frequency is 0, this number is missing.
//             if (freq[i] == 0) {

//                 // Add the missing number to the answer.
//                 ans.add(i);
//             }
//         }

//         // Return all missing numbers.
//         return ans;
//     }
// }