class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int totalSubset=1<<n;
        vector<vector<int>> result;
        for(int i = 0 ; i<totalSubset ; i++){
            //check if the bit is set or not
            vector<int>subset;
            for(int j=0 ; j<n ; j++){
                //check if the j-th bit in the binary representation
                if(i&(1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};