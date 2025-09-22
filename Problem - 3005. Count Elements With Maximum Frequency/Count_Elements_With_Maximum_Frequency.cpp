class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Step 1: Count frequency of each element
        // Using map<int,int> where key = element, value = frequency of that element
        map<int,int> frequency;
        for (auto &i : nums) {
            frequency[i]++;  // Increment frequency count for element i
        }

        int maxFreq = 0;     // To store the maximum frequency among all elements
        int totalFreq = 0;   // To store the sum of frequencies of elements having max frequency

        // Step 2: Find the maximum frequency value
        for (auto &it : frequency) {
            maxFreq = max(maxFreq, it.second);
        }

        // Step 3: Add the frequency of all elements that have the maximum frequency
        for (auto &it : frequency) {
            if (it.second == maxFreq) {
                totalFreq += maxFreq;
            }
        }

        // Return the total count of elements that appear with maximum frequency
        return totalFreq;
    }
};
