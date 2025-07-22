class Solution {
public:
    int subarrays(vector<int>& nums, int k){
        int left=0 , right=0  , n=nums.size() , count =0 ,sum=0;
        if(k<0){
        return 0;
       }
        while(right<n){
            sum+=nums[right]%2;
            while(sum>k){
                sum-=nums[left]%2;
                left++;
            }
            count+=right-left+1;
            right++;
        }
    return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrays(nums,k)-subarrays(nums,k-1);

    }
};