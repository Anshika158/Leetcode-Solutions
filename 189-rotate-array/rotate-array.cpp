class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int len = nums.size();
        if (len == 0 || k == 0 || k % len == 0)
            return; 
        
        k = k % len;  
        vector<int>temp(nums.begin() + len - k , nums.end());
        for(int i=len-1 ; i>=k ; i--){
            nums[i]=nums[i-k];
        }
        for(int i=0 ; i<k; i++){
            nums[i]=temp[i];
        }
        
      
    }
};