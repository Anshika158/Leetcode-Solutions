class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int size=nums.size();
        int l=0 ,r=0 ;
        while(r<size){
            if(r-l+1==k){
                bool isSortedAndConsecutive = true ;
                for(int i=l+1 ; i<=r ; i++){
                    if(nums[i]<=nums[i-1] || nums[i]-nums[i-1] != 1){
                        isSortedAndConsecutive = false;
                        break;
                    }
                }
                if(isSortedAndConsecutive){
                    ans.push_back(nums[r]);
                }else{
                    ans.push_back(-1);
                }
                l++;
            }
            r++;
            }
        return ans;    
    }
};