class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // If numerator is 0 → result is "0"
        if (numerator == 0) return "0";

        string result;

        // Handle sign: negative if exactly one of numerator or denominator is negative
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Convert both to long long to prevent overflow (e.g., INT_MIN case)
        long long absN = llabs((long long)numerator);
        long long absD = llabs((long long)denominator);

        // Append integer part
        result += to_string(absN / absD);

        // Remainder after integer division
        long long remainder = absN % absD;
        if (remainder == 0) return result; // No fractional part

        // Fractional part begins
        result += ".";

        // Map stores remainder → index in result string
        // Helps detect repeating cycles in decimal expansion
        unordered_map<long long, int> mp;

        while (remainder != 0) {
            // If remainder is already seen → repeating decimal
            if (mp.count(remainder)) {
                result.insert(mp[remainder], "("); // insert '(' where cycle started
                result += ")";                    // close cycle
                break;
            }

            // Store current remainder position
            mp[remainder] = result.size();

            remainder *= 10;
            result += to_string(remainder / absD); // Next fractional digit
            remainder %= absD;                     // Update remainder
        }

        return result;
    }
};
