class Solution {
public:
    int count(vector<int>&nums , int k){
        int l=0 , r=0 , count=0 , size=nums.size() ;
         unordered_map<int , int > mpp;
        while(r<size){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k)-count(nums , k-1);
    }
};