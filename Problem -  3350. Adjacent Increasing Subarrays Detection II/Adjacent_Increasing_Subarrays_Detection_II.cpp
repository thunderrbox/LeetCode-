class Solution {
public:
    /*
     * Intuition:
     * -----------
     * We need to find the maximum length 'k' such that there exist two 
     * consecutive increasing subarrays of length 'k'.
     * 
     * For example:
     * nums = [1, 2, 3, 1, 2, 3, 4]
     * The increasing subarrays are:
     * - [1, 2, 3] (length = 3)
     * - [1, 2, 3, 4] (length = 4)
     * Here, there are two consecutive increasing subarrays of size 3,
     * so the answer is 3.
     * 
     * Approach:
     * ----------
     * - Traverse the array once while maintaining:
     *    → currLen = length of current increasing subarray
     *    → prevLen = length of previous increasing subarray
     * - Whenever the current increasing sequence breaks (nums[i] <= nums[i-1]),
     *   update prevLen = currLen and reset currLen = 1.
     * - For every position, we check:
     *      1. currLen / 2   → handles the case when both halves are within one long increasing subarray.
     *      2. min(currLen, prevLen) → handles consecutive increasing subarrays.
     * - The maximum of these values gives the result.
     * 
     * Example Walkthrough:
     * ---------------------
     * nums = [1, 2, 3, 1, 2, 3, 4]
     * i=3 → currLen=1 (reset), prevLen=3 → k=max(0, min(1,3))=1
     * i=6 → currLen=4, prevLen=3 → k=max(1, min(4,3))=3
     * Final answer: 3
     * 
     * Complexity:
     * ------------
     * Time Complexity:  O(n)  → Single pass through the array
     * Space Complexity: O(1)  → Constant extra space
     */
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prevLen = 0;   // length of previous increasing subarray
        int currLen = 1;   // length of current increasing subarray
        int k = 0;         // maximum size of consecutive increasing subarrays
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currLen++;  // continue the increasing sequence
            } else {
                prevLen = currLen;  // store previous increasing length
                currLen = 1;        // reset for new sequence
            }
            
            // check possible maximum k
            k = max(k, currLen / 2);
            k = max(k, min(currLen, prevLen));
        }
        
        return k;
    }
};
