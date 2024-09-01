class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int siz = nums.size();
        vector<int> nge(siz , -1);
        for(int i = 0 ; i< siz ; i++){
            for(int j=1 ;j<siz ; j++ ){
                int index = (i+j)%siz;
                if(nums[index]>nums[i]){
                    nge[i]=nums[index];
                    break;
                }
            }
        }
        return nge;
    }
};