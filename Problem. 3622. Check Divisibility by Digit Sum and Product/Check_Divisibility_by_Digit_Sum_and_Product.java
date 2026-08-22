class Solution {

    public boolean checkDivisibility(int n) {

        // Stores the product of all digits
        // Start with 1 because we are doing multiplication
        int prod = 1;

        // Stores the sum of all digits
        int sum = 0;

        // Save the original number because 'n' will become 0
        // while extracting its digits
        int temp = n;

        // Extract digits one by one
        while (n != 0) {

            // Get the last digit
            // Example: 123 % 10 = 3
            sum += n % 10;

            // Multiply the last digit with the product
            // Example: 1 * 2 * 3 = 6
            prod *= n % 10;

            // Remove the last digit
            // Example: 123 / 10 = 12
            n = n / 10;
        }

        // Check if the original number is divisible by
        // (sum of digits + product of digits)
        if (temp % (sum + prod) == 0) {
            return true;
        }

        return false;
    }
}