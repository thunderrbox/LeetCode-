class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel;
        unordered_map<char,int>consonant;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowel[s[i]]++;
            }
            else{
                consonant[s[i]]++;
            }
        }
        int maxvalue1 = 0;
        int maxvalue2 = 0;
        for(auto& pair1 : vowel){
            maxvalue1 = max(maxvalue1 , pair1.second);
        }
        for(auto& pair2 : consonant){
            maxvalue2 = max(maxvalue2 , pair2.second);
        }
        return maxvalue1 + maxvalue2;
    }
};