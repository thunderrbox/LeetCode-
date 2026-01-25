class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        /*
        =========================================================
        PROBLEM UNDERSTANDING:
        ---------------------------------------------------------
        An arithmetic progression (AP) is a sequence of numbers
        where the difference between consecutive elements is constant.

        Example:
        [2, 4, 6, 8]  → common difference = 2

        Important:
        - The array can be rearranged.
        - Therefore, order matters → sorting is required.
        =========================================================
        */

        // Step 1: Sort the array to bring elements in order
        sort(arr.begin(), arr.end());

        int n = arr.size();

        /*
        =========================================================
        INTUITION:
        ---------------------------------------------------------
        After sorting:
        - If the array can form an AP,
          then every adjacent pair must have the SAME difference.
        - First compute the expected common difference
          using the first two elements.
        =========================================================
        */

        int diff = arr[1] - arr[0];

        /*
        =========================================================
        LOGIC:
        ---------------------------------------------------------
        Compare the difference of each adjacent pair
        with the expected common difference.
        If any pair violates this, return false immediately.
        =========================================================
        */

        for (int i = 1; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] != diff) {
                return false;   // Not an arithmetic progression
            }
        }

        // If all adjacent differences are equal
        return true;
    }
};


/*
=========================================================
WRONG APPROACH (FOR LEARNING PURPOSE):
---------------------------------------------------------

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if((arr[i] - arr[i+1]) == (arr[i] - arr[i+2])){
                return true;
            }
        }
        return false;
    }
};

=========================================================
WHY THIS APPROACH IS WRONG:
---------------------------------------------------------
1) NO SORTING:
   - Arithmetic progression depends on order.
   - Without sorting, difference checks are meaningless.

2) OUT-OF-BOUND ERROR:
   - arr[i+1] and arr[i+2] will cause runtime error
     when i reaches n-2 or n-1.

3) INCORRECT INTUITION:
   - Checking only one condition is not enough.
   - Arithmetic progression requires ALL consecutive
     differences to be equal.

4) FALSE POSITIVE:
   - One matching difference does NOT guarantee
     the entire array forms an AP.

=========================================================
TIME & SPACE COMPLEXITY:
---------------------------------------------------------
Time Complexity:
- Sorting: O(n log n)
- Traversal: O(n)
- Total: O(n log n)

Space Complexity:
- In-place sorting
- No extra data structures
- O(1) auxiliary space

=========================================================
FINAL TAKEAWAY:
---------------------------------------------------------
✔ Always sort when order matters
✔ Fix a common difference
✔ Validate the entire sequence
✔ Avoid partial or local checks
=========================================================
*/
