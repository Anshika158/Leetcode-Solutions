class Solution {
public:
    int count(vector<int>& nums , int goal){
        int l=0 , r=0 , count=0 , size=nums.size() , sum=0 ;
        if(goal < 0){
            return 0;
        }
       while(r<size){
        sum+=nums[r];
        while(sum>goal){
            sum=sum-nums[l];
            l++;
        }
        count = count + (r-l+1);
        r++;
       } 
       return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int total = count(nums, goal) - count(nums , goal-1);
       return total;
    }
};