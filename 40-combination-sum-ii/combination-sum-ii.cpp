class Solution {
public:
     void findC(int ind  , vector<int>&candidates , int target , vector<int>&ans , vector<vector<int>>&result){
        if(target==0){
            result.push_back(ans);
            return ;
        }
        int n=candidates.size();
        for(int i=ind ; i<n ; i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ans.push_back(candidates[i]);
            findC(i+1 , candidates , target-candidates[i], ans , result);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> ans;
        vector<vector<int>> result;
        findC(0 , candidates , target , ans , result);
        return result;
    }
};