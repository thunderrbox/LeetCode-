
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Intuition:
        // To form a valid triangle, the sum of any two sides must be strictly greater than the third side.
        // We need to check all possible triplets from the array and find the maximum perimeter among valid triangles.
        // Sorting helps in simplifying triangle validity checks because sorted sides allow easy application of triangle inequality.

        int maxperimeter = 0;      // Stores the maximum valid perimeter found
        int n = nums.size();       

        // Step 1: Sort the array
        // Sorting makes it easier to check validity of consecutive triplets.
        sort(nums.begin(), nums.end());

        // Step 2: Traverse through all consecutive triplets
        for (int i = 0; i < n - 2; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Step 3: Compute area to check validity
            // If area > 0, then the triplet forms a valid triangle
            double are = area(a, b, c);

            if (are > 0.0) {  // Valid triangle exists
                int perimeter = a + b + c;                 // Compute perimeter
                maxperimeter = max(maxperimeter, perimeter); // Update maximum perimeter
            }
        }
        return maxperimeter;
    }

private:
    double area(int a, int b, int c) {
        // Step 1: Check for invalid (non-positive) sides
        if (a <= 0.0 || b <= 0.0 || c <= 0.0) {
            return -1;
        }

        // Step 2: Store sides for easier handling
        vector<int> sides = {a, b, c};

        // Step 3: Check triangle inequality:
        // For a valid triangle: sum of smaller two sides > largest side
        // Here sorting is not required since caller already provides sorted triplets,
        // but if needed we can uncomment sorting.
        // sort(sides.begin(), sides.end());
        if (sides[0] + sides[1] <= sides[2]) {
            return -1; // Not a valid triangle
        }

        // Step 4: Compute area using Heron's Formula:
        // s = semi-perimeter = (a+b+c)/2
        // area = sqrt(s * (s-a) * (s-b) * (s-c))
        double s = (sides[0] + sides[1] + sides[2]) / 2.0;
        double areaa = sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
        return areaa;
    }
};

/*
-----------------------------------
Complexity Analysis:
-----------------------------------
1. Sorting: O(n log n), where n = size of nums
2. Looping through n-2 triplets: O(n)
3. Area calculation (constant time): O(1) per triplet
=> Overall Time Complexity = O(n log n) + O(n) ≈ O(n log n)

Space Complexity:
- Sorting done in-place: O(1) extra space (apart from input)
- Constant auxiliary space for sides vector: O(1)
=> Overall Space Complexity = O(1)

-----------------------------------
Understanding:
-----------------------------------
- Sorting ensures we can directly test consecutive triplets instead of random picks.
- Valid triangle is confirmed using Heron's formula (area > 0).
- We maximize the perimeter among all valid triangles.
*/

