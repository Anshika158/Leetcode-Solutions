class Solution {
public:
    void findSubset(int start , vector<int>&nums , vector<vector<int>>&result , vector<int>&current){
        result.push_back(current);
        for(int i=start ; i<nums.size() ;i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            current.push_back(nums[i]);
            findSubset(i+1,nums,result,current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result ;
        vector<int>current;
        sort(nums.begin() ,nums.end());
        findSubset(0,nums,result,current);
        return result;
        
    }
};