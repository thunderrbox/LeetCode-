class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        /*
         \U0001f9e0 Understanding:
         1. The goal here is to find the maximum difference between 
            two halves of the array after squaring and sorting.
         2. First, we square every element (to make all values positive and 
            emphasize larger magnitudes).
         3. Then, we sort the squared values in descending order 
            (so the largest squares come first).
         4. Finally, we split the array into two halves:
            → 'maxi' = sum of the larger half
            → 'mini' = sum of the smaller half
            and return (maxi - mini).
        */

        // Step 1: Square each element of the array
        transform(nums.begin(), nums.end(), nums.begin(),
                  [](int x) { return x * x; });

        // Step 2: Sort in descending order to place larger squares first
        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        long long maxi = 0;  // sum of the first (larger) half
        long long mini = 0;  // sum of the second (smaller) half

        // Step 3: Divide array into two parts and compute difference
        if (n % 2 == 0) {
            // Case 1: Even number of elements
            for (int i = 0; i < nums.size() / 2; i++) {
                maxi += nums[i];
            }
            for (int i = nums.size() / 2; i < nums.size(); i++) {
                mini += nums[i];
            }
        } 
        else {
            // Case 2: Odd number of elements → first half gets one extra element
            for (int i = 0; i <= nums.size() / 2; i++) {
                maxi += nums[i];
            }
            for (int i = (nums.size() / 2) + 1; i < nums.size(); i++) {
                mini += nums[i];
            }
        }

        /*
         \U0001f4a1 Intuition:
         - By squaring, larger numbers become more dominant.
         - Sorting descending ensures the biggest values contribute 
           to maximizing the positive part ('maxi').
         - Subtracting the smaller half ('mini') gives the largest 
           possible alternating difference between two groups.
        */

        /*
         ⏱️ Time Complexity:
         - Squaring using transform → O(n)
         - Sorting → O(n log n)
         - Summing two halves → O(n)
         ✅ Total = O(n log n)

         \U0001f9ee Space Complexity:
         - In-place operations (no extra data structures) → O(1)
        */

        return maxi - mini;
    }
};
