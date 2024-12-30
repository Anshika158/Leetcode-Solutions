class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        if(size==1 && nums[0]==target){
            return 0;
        }
        for(int i=0 ; i<size ; i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};