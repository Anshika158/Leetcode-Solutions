class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n=nums.size();
        // unordered_map<int,int>freq;
        // for(auto num : nums){
        //    freq[num]++;
        // }
        // for(auto it: freq){
        //     if(it.second==1){
        //         return it.first;
        //     }
        // }
        // return -1;

        //OPTIMAL APPROACH USING XOR OPERATION

        int xorVal=0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            xorVal^=nums[i];
        }
        return xorVal;
    }
};