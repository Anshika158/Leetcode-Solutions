class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , max_count=0;
        int len = nums.size();
        for(int i=0 ; i<len ; i++){
            if(nums[i]==1){
                count++;
                max_count= max(max_count , count);
            }
            
            else if(nums[i]!=1){
                count=0;
            }
            
        }
        max_count=max(max_count , count);
        return max_count;
    }
};