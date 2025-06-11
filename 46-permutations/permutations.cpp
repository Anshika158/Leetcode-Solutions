class Solution {
public:
    void getPermutation(vector<int>number , int index ,vector<vector<int>> &ans){
        if(index==number.size()){
            ans.push_back(number);
            return;
        }
        for(int i=index ; i<number.size() ;i++){
            swap(number[index] , number[i]);
            getPermutation(number , index+1 , ans);
            swap(number[index] , number[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // if(nums.size()==1){
        //     return nums;
        // }
        vector<int>number;
        for(int i=0 ; i<nums.size() ; i++){
            number.push_back(nums[i]);
        }
        vector<vector<int>> ans;
        getPermutation(number , 0 , ans);
        return ans;
        
    }
};