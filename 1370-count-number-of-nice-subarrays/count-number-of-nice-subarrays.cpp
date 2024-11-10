class Solution {
public:
    int subarrays(vector<int>& nums, int k){
        int l= 0 , r=0 , size=nums.size() , sum = 0 , count = 0 ;
        while(r<size){
            if(k<0){
                return 0;
            }
           sum += nums[r]%2;
           while(sum>k){
                sum = sum - (nums[l]%2);
                l++;
           }
           count = count + r-l+1;
           r++;
        } 
        return count ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrays(nums , k)-subarrays(nums , k-1);

    }
};