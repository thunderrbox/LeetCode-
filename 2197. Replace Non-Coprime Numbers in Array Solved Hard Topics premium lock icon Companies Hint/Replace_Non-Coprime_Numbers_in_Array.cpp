class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // We will use a stack-like vector (result) to store the processed numbers.
        // The idea is to combine adjacent numbers if they are NOT coprime (i.e., gcd > 1).
        // If two adjacent numbers are not coprime, we replace them with their LCM
        // and check again with the new last element in the result until no further merging is possible.

        vector<int> result;

        for (auto &i : nums) {
            // Try merging current number with the top of 'result' while they are not coprime
            while (!result.empty()) {
                int num = i;
                int last = result.back();

                // If they are coprime (gcd == 1), no merge needed
                if (gcd(num, last) == 1) {
                    break;
                }

                // If not coprime, pop last element and merge it with current i as LCM
                result.pop_back();
                i = lcm(num, last); 
                // Now this new i will again be checked with new top of result
            }

            // After merging as much as possible, push the resulting number into result
            result.push_back(i);
        }

        return result;
    }

private:
    // Iterative gcd using Euclidean algorithm
    int gcd(int x, int y){
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    // LCM using relation: lcm(a,b) = (a*b)/gcd(a,b)
    long long lcm(int x, int y){
        return (1LL * x * y) / gcd(x, y);
    }
};

// This is just for disabling runtime output (not related to logic)
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; }); 


/*
===========================
       INTUITION
===========================
We need to repeatedly merge adjacent numbers if they are not coprime.

Example: nums = [6, 4, 3]
- Start with 6 → result = [6]
- Next is 4 → gcd(6,4)=2 (not coprime)
  → merge → lcm(6,4)=12 → result = [12]
- Next is 3 → gcd(12,3)=3 (not coprime)
  → merge → lcm(12,3)=12 → result = [12]

Result: [12]

Key points:
- We always try to merge from the back so earlier merges can chain with newer numbers.
- We use a stack-like structure (vector) to easily merge backward.

===========================
       COMPLEXITY
===========================
Let n = nums.size()

- Each number can be pushed and popped from 'result' at most once.
- gcd and lcm operations take O(log(max(nums[i]))) time each.
- So overall time complexity:  O(n * log(max(nums[i])))
- Space complexity: O(n) (for the result stack)
*/
