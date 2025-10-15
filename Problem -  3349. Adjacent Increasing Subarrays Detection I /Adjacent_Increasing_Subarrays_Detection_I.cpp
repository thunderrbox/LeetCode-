class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // \U0001f539 Intuition:
        // We need to check if there exist two *increasing subarrays* of length k each
        // that are adjacent or overlapping.
        // Instead of explicitly finding all subarrays, we track the length of the
        // current increasing streak and the previous one.
        //
        // Example:
        // nums = [1,2,3,1,2,3], k = 2
        // Increasing streaks are [1,2,3] and [1,2,3].
        // We can detect these by comparing nums[i] > nums[i-1].
        //
        // prev → stores the length of previous increasing segment
        // curr → stores the length of current increasing segment
        // If at any point:
        //   - curr >= 2*k  → one long segment can contain two increasing parts of size k
        //   - min(prev, curr) >= k  → consecutive increasing runs can form two subarrays
        //
        // This gives an O(n) one-pass check without generating subarrays.

        if(k == 1) return true;  // Base case: any single element forms a subarray of size 1

        int n = nums.size();
        int prev = 1;  // length of previous increasing segment
        int curr = 1;  // length of current increasing segment

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                curr++;  // continue increasing sequence
            } else {
                prev = curr;  // store previous streak
                curr = 1;     // reset current streak
            }

            // \U0001f538 Case 1: A single long increasing segment contains both subarrays
            if(curr >= 2 * k){
                return true;
            }

            // \U0001f538 Case 2: Two consecutive increasing segments each can form a subarray of size k
            if(min(prev, curr) >= k){
                return true;
            }
        }
        return false;
    }
};

/*
\U0001f539 Time Complexity: O(n)
   → We traverse the array once and perform O(1) work per element.

\U0001f539 Space Complexity: O(1)
   → We only use constant extra space (prev, curr).

\U0001f539 Summary:
   Efficient sliding comparison approach to detect two increasing subarrays
   of size k either overlapping or back-to-back without storing all subarrays.
*/
