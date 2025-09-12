class Solution {
public:
    bool doesAliceWin(string s) {
        int vc = 0;
        for(auto &c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vc++;
                break;
            }
        }
        if(vc == 0){
            return false;
        }
        return true;
    }
};