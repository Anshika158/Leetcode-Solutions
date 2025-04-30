class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin() , nums.end());
        int i=0 ;
        while(i<=n){
            if(nums[i]==nums[i+1]){
                ans=nums[i];
                break;
            }else{
                 i++;
        }
        }
        
        return ans;
    }
};