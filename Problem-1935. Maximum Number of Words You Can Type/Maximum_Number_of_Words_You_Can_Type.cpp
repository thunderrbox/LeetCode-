class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        /*
         Intuition and Problem Understanding:

         - We are given a sentence (text) and a set of broken letters (brokenLetters).
         - A word is considered "typable" if it does NOT contain any of the broken letters.
         - We need to count how many words from the sentence are completely typable.

         Approach / Plan:

         1. Add an extra space at the end of the text so the last word also gets processed
            (because normally we detect the end of a word when we hit a space).
         2. Traverse through each character of the text.
         3. Build each word character by character until we find a space.
         4. When a space is found, it means one complete word is formed.
         5. Check this word:
             - Assume it is valid → increase the count.
             - Then check each character of this word against all broken letters.
             - If any character is broken, then:
                 - Decrease the count (as it's not valid)
                 - Stop checking this word.
         6. Reset the temporary word string and continue to process the next word.
         7. Finally return the count of words that can be typed.

         This way, we only use simple loops and no extra data structures.
        */

        // Step 1: Add space at the end so the last word also gets processed
        text = text + ' ';

        int count = 0;   // Will count how many words can be typed
        string s = "";   // To store characters of the current word

        // Step 2: Traverse each character in the text
        for (auto &c : text) {

            if (c != ' ') {
                // Step 3: If it's not space, add it to current word
                s += c;
            } 
            else {
                // Step 4: If we find a space, we got one complete word

                count++;  // Step 5a: Assume this word is valid

                // Step 5b: Check if this word contains any broken letter
                for (auto &c1 : s) {
                    int flag = 0; // Will mark if a broken letter is found

                    for (auto &c2 : brokenLetters) {
                        if (c1 == c2) {
                            // Found a broken letter in this word
                            count--;      // This word is not valid, reduce count
                            flag = 1;     // Mark that this word is broken
                            break;        // No need to check more letters
                        }
                    }

                    if (flag == 1) break; // Stop checking more letters of this word
                }

                // Step 6: Clear the word to start forming the next one
                s = "";
            }
        }

        // Step 7: Return the count of typable words
        return count;
    }
};
