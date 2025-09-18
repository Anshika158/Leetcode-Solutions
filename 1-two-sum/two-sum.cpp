class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int , int >mpp;
     int n=nums.size();
     for(int i=0 ;i<n ;i++){
        int a = nums[i];
        int req = target-a;
        if(mpp.find(req)!=mpp.end()){
            return {mpp[req] , i};
        }
        mpp[a]=i;
     }
     return {};
    }
};