class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int dSum=0;
        int sSum=0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i]>=10){
                dSum+=nums[i];
            }else sSum+=nums[i];
        }
        if(sSum>dSum || sSum<dSum) return true;
        return false;
    }
};