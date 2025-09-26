class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;  
        int n = nums.size();

        /*
        Intuition:
        -----------
        A valid triangle can be formed if the sum of the two smaller sides 
        is greater than the largest side (a + b > c).
        
        Understanding:
        --------------
        - First, sort the array so the largest side is always at the end of a chosen triplet.
        - Fix the largest side as nums[i].
        - Then use two pointers (low and high) to find valid pairs:
            * If nums[low] + nums[high] > nums[i], then all elements between 
              low and high with nums[high] also form valid triangles 
              (because array is sorted).
            * Otherwise, move low forward to increase the sum.
        
        This avoids O(n^3) brute force and solves in O(n^2).
        */

        // Step 1: Sort the numbers so that we can apply the triangle property easily
        sort(nums.begin(), nums.end());

        // Step 2: Iterate over the array, considering nums[i] as the largest side
        for (int i = n - 1; i >= 2; i--) {
            int low = 0;          // pointer to smallest element
            int high = i - 1;     // pointer just before the largest element

            // Step 3: Use two pointers to find valid pairs for nums[i]
            while (low < high) {
                if (nums[low] + nums[high] > nums[i]) {
                    // If nums[low] + nums[high] > nums[i],
                    // then ALL elements from nums[low] to nums[high-1]
                    // with nums[high] are valid pairs
                    count += (high - low);

                    // Move high leftwards to check other possible pairs
                    high--;
                } else {
                    // If sum is too small, move low forward to increase it
                    low++;
                }
            }
        }

        /*
        Complexity:
        -----------
        - Sorting takes O(n log n).
        - Outer loop runs O(n) times.
        - Inner while loop runs O(n) in worst case.
        - Total Time Complexity: O(n^2)
        - Space Complexity: O(1) (only pointers and counters are used).
        */

        return count; // total number of valid triangles
    }
};
