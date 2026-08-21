class Solution {
    public int[] shuffle(int[] nums, int n) {

        // nums contains:
        // [x1, x2, x3, ..., xn, y1, y2, y3, ..., yn]
        //
        // We need to rearrange it as:
        // [x1, y1, x2, y2, x3, y3, ..., xn, yn]

        // Create a temporary array to store the first half.
        // temp1 = [x1, x2, ..., xn]
        int[] temp1 = new int[n];

        // Create a temporary array to store the second half.
        // temp2 = [y1, y2, ..., yn]
        int[] temp2 = new int[n];


        // Copy the first n elements of nums into temp1.
        //
        // Parameters:
        // nums  -> source array
        // 0     -> starting index in nums
        // temp1 -> destination array
        // 0     -> starting index in temp1
        // n     -> number of elements to copy
        System.arraycopy(nums, 0, temp1, 0, n);


        // Copy the second half of nums into temp2.
        //
        // nums[n] is the first element of the second half.
        // Example:
        // nums = [1,2,3,4,5,6]
        // n = 3
        //
        // temp1 = [1,2,3]
        // temp2 = [4,5,6]
        System.arraycopy(nums, n, temp2, 0, n);


        // j is used to track the current element
        // from temp1 and temp2.
        //
        // Initially:
        // j = 0
        //
        // So we start with:
        // temp1[0] and temp2[0]
        int j = 0;


        // The final array contains 2*n elements.
        // Therefore, loop from 0 to 2*n - 1.
        for (int i = 0; i < 2 * n; i++) {

            // Even index -> take element from temp1.
            //
            // i = 0 -> temp1[0]
            // i = 2 -> temp1[1]
            // i = 4 -> temp1[2]
            //
            // This places x1, x2, x3, ... at even positions.
            if (i % 2 == 0) {

                nums[i] = temp1[j];

            } 
            else {

                // Odd index -> take element from temp2.
                //
                // i = 1 -> temp2[0]
                // i = 3 -> temp2[1]
                // i = 5 -> temp2[2]
                //
                // This places y1, y2, y3, ... at odd positions.
                nums[i] = temp2[j];

                // Increase j only after placing the element
                // from temp2.
                //
                // This is important because one complete pair
                // has now been created:
                //
                // temp1[j], temp2[j]
                //
                // Then move to the next pair.
                j++;
            }
        }

        // Return the shuffled array.
        return nums;
    }
}