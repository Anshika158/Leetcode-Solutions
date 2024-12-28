class Solution {
public:
    void findCombination(int ind , vector<int>&candidates ,int target, vector<vector<int>> &result , vector<int>&ans){
            if(target==0){
            result.push_back(ans);
            return;
        }
       for(int i = ind ; i<candidates.size() ; i++){
        if(i>ind && candidates[i]==candidates[i-1]){
            continue;
        }
        if(candidates[i]>target){
            break;
        }
        ans.push_back(candidates[i]);
        findCombination(i+1,candidates,target-candidates[i],result,ans);
        ans.pop_back();
       }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        sort(candidates.begin() , candidates.end());
        findCombination(0,candidates,target,result,ans);
        return result;
    }
};