#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
                    APPROACH 1: BRUTE FORCE
    ============================================================

    UNDERSTANDING:
    - Check every possible pair.
    - For every element nums[i], check all elements
      after it.
    - If nums[i] + nums[j] == target, return their indices.

    TIME COMPLEXITY:
    O(n^2)

    SPACE COMPLEXITY:
    O(1)

    ------------------------------------------------------------

    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {

            for (int j = i + 1; j < n; j++) {

                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }

    */


    /*
    ============================================================
             APPROACH 2: SORTING + TWO POINTER
    ============================================================

    UNDERSTANDING:
    - Store each number with its original index.
    - Sort according to the values.
    - Use two pointers:
          left  -> smallest value
          right -> largest value

    - If sum < target:
          left++

    - If sum > target:
          right--

    - If sum == target:
          return original indices.

    IMPORTANT:
    We store the original indices because sorting changes
    the positions of elements.

    TIME COMPLEXITY:
    O(n log n)

    SPACE COMPLEXITY:
    O(n)

    ------------------------------------------------------------

    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        // {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort according to value
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int sum = arr[left].first + arr[right].first;

            if (sum == target) {

                return {
                    arr[left].second,
                    arr[right].second
                };
            }

            else if (sum < target) {

                // Need a larger value
                left++;
            }

            else {

                // Need a smaller value
                right--;
            }
        }

        return {};
    }

    */


    /*
    ============================================================
                 APPROACH 3: TREE / BST APPROACH
    ============================================================

    UNDERSTANDING:
    - Use a balanced Binary Search Tree.
    - C++ std::set internally uses a balanced BST.
    - Store previously seen numbers in the set.
    - For every nums[i], calculate:

          required = target - nums[i]

    - Search for 'required' in the set.
    - If found, we know that a valid pair exists.

    IMPORTANT:
    std::set only stores values, so we need another map
    to remember the original index of each value.

    Example:

        nums = [2, 7, 11, 15]
        target = 9

        i = 0
        required = 9 - 2 = 7

        7 not in tree.
        Insert 2.

        i = 1
        required = 9 - 7 = 2

        2 exists in tree.

        Answer = [index of 2, 1]
                = [0, 1]

    SEARCH IN BALANCED BST:
    O(log n)

    TIME COMPLEXITY:
    O(n log n)

    SPACE COMPLEXITY:
    O(n)

    ------------------------------------------------------------

    vector<int> twoSum(vector<int>& nums, int target) {

        // Balanced BST
        set<int> tree;

        // Store number -> original index
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {

            int required = target - nums[i];

            // Search required number in BST
            if (tree.find(required) != tree.end()) {

                return {index[required], i};
            }

            // Insert current number
            tree.insert(nums[i]);

            // Store its index
            index[nums[i]] = i;
        }

        return {};
    }

    */


    /*
    ============================================================
              APPROACH 4: OPTIMAL - HASH MAP
    ============================================================

    THIS IS THE OPTIMAL APPROACH.

    UNDERSTANDING:
    - Use an unordered_map.
    - Store:

          number -> index

    For every nums[i]:

          required = target - nums[i]

    Check whether 'required' already exists.

    If it exists:
        We have found the two numbers.

    If it doesn't exist:
        Store the current number and its index.

    ------------------------------------------------------------

    EXAMPLE:

        nums = [2, 7, 11, 15]
        target = 9

        i = 0

        nums[i] = 2

        required = 9 - 2
                 = 7

        7 is not present.

        Store:
        2 -> 0


        i = 1

        nums[i] = 7

        required = 9 - 7
                 = 2

        2 already exists.

        Therefore:

        nums[0] + nums[1] = 9

        Answer = [0, 1]

    ------------------------------------------------------------

    WHY IS THIS OPTIMAL?

    Brute Force:
        Search every pair
        O(n^2)

    Tree:
        Search in balanced BST
        O(log n) per element
        O(n log n)

    Hash Map:
        Average O(1) lookup
        O(n) overall

    ------------------------------------------------------------

    TIME COMPLEXITY:
    O(n) average

    SPACE COMPLEXITY:
    O(n)

    ============================================================
    */

    vector<int> twoSum(vector<int>& nums, int target) {

        // Hash Map:
        // number -> index
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            // Find the complement required
            // to reach the target.
            int required = target - nums[i];

            // Check whether required number
            // has already been seen.
            if (mp.find(required) != mp.end()) {

                // Return:
                // index of required number
                // current index
                return {mp[required], i};
            }

            // Store current number and its index.
            mp[nums[i]] = i;
        }

        // No valid pair found.
        return {};
    }
};