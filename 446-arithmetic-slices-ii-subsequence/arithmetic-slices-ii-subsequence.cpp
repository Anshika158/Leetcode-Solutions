class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result =0;
        unordered_map<long , int>mp[n]; // array of map // first int will store the common difference and the second int will store the key values
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                long diff =(long)nums[i]-nums[j];
                auto it = mp[j].find(diff);
                int count_at_j = it==mp[j].end() ? 0 : it->second;
                
                mp[i][diff]+=count_at_j+1;

                result+=count_at_j;
            }
        }
        return result;
    }
};