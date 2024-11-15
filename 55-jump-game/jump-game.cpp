class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxSize=0;
       for(int i=0 ;i<nums.size() ; i++){
        if(i>maxSize) return false;
        maxSize=max(maxSize , i+nums[i]);
       }
       return true;
      
    }
};