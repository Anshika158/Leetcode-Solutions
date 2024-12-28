// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n=nums.size();
//         int totalSubset=1<<n;
//         vector<vector<int>> result;
//         for(int i = 0 ; i<totalSubset ; i++){
//             vector<int>subset;
//             for(int j=0 ; j<n ; j++){
//                 //check if the j-th bit in the binary representation
//                 if(i&(1<<j)){
//                     subset.push_back(nums[j]);
//                 }
//             }
//             result.push_back(subset);
//         }
//         return result;
//     }
// };
// using backtracking 
class Solution {
public:
void backtrack(int start , vector<int>&nums , vector<int> &current , vector<vector<int>>&result){
    result.push_back(current);
    for(int i=start ; i<nums.size() ; i++){
        current.push_back(nums[i]);
        backtrack(i+1 , nums , current , result);
        current.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> current;
        backtrack(0,nums,current,result);
        return result;
    }
};