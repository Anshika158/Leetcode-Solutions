class Solution {
public:
    int binarySearch(vector<int>&nums , int target , int start , int end )
    {
        if(start>end) return -1;
        int mid=(start+end)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target){
           return binarySearch(nums , target , start , mid-1);
        }else{
            return binarySearch(nums , target , mid+1 , end);
        }
    }
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        return binarySearch(nums , target ,0, size-1);
    }
};