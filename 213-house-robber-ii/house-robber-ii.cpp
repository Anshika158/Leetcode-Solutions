class Solution {
public:

    int function(vector<int> &nums ){
        int n = nums.size();
        int prev=nums[0];
        int prev2=0;

        for(int i = 1 ; i< n ; i++){
            int take = nums[i];
            if(i>0){
                take = take + prev2;
            }
            int notTake = 0+prev;

            int curi = max(take , notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;

    }

    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> temp1 , temp2;
       if(n==1){
        return nums[0];
       }
       for(int i = 0 ; i<n ; i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
       }
       return max(function(temp1) , function(temp2));
    }
};