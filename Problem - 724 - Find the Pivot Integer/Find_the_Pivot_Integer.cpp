class Solution {
public:
    int pivotInteger(int n) {

        /*
        INTUITION:
        A pivot integer x satisfies:
            sum(1 to x) == sum(x to n)

        Using sum formula:
            sum(1 to x) = x * (x + 1) / 2
            sum(x to n) = totalSum - sum(1 to x-1)

        After simplifying the equation, we get:
            x^2 = n * (n + 1) / 2

        So:
        1) Compute total sum from 1 to n
        2) Check if total sum is a perfect square
        3) If yes, its square root is the pivot integer
        */

        // Total sum of numbers from 1 to n
        int total = n * (n + 1) / 2;

        // Candidate pivot integer (square root of total sum)
        int x = sqrt(total);

        /*
        If total sum is a perfect square,
        then x * x will be equal to total
        */
        if (x * x == total) {
            return x;   // Pivot integer exists
        }

        // If total sum is not a perfect square,
        // no pivot integer exists
        return -1;
    }
};
