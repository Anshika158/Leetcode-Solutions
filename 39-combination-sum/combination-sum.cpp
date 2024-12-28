class Solution {
public:
    void findCombination(int ind , vector<int>&candidates ,int target, vector<vector<int>> &result , vector<int>&ans){
        if(ind==candidates.size()){
            if(target==0){
                result.push_back(ans);
            }
            return;
        }
        if(candidates[ind]<=target){
            ans.push_back(candidates[ind]);
            findCombination(ind , candidates , target-candidates[ind] , result , ans);
            ans.pop_back();
        }
        findCombination(ind+1,candidates , target , result , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>ans;
        findCombination(0 , candidates , target , result , ans);
        return result;

    }
};