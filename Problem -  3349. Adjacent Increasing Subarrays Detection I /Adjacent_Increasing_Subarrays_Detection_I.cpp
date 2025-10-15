class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) return true;
        int n = nums.size();
        int prev = 0;
        int curr = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }else{
                prev = curr;
                curr = 1;
            }

            if(curr >= 2*k){
                return true;
            }
            if(min(prev, curr) >= k){
                return true;
            }
        }
        return false;
    }
};