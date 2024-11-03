// class Solution {
// public:
// int function(int ind , vector<int> &nums , vector<int> &dp){
//     if(ind==0){
//         return nums[ind];
//     }
//     if(ind<0){
//         return 0;
//     }
//     if (dp[ind]!= -1) return dp[ind];

//     int pick = nums[ind]+function(ind-2 , nums , dp);
//     int notpick = 0 + function(ind-1 , nums , dp);
//     return dp[ind] = max(pick , notpick);

// }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n , -1);
//         return function(n -1, nums , dp);
        
//     }
// };

// class Solution {
// public:
// int function(int ind , vector<int> &nums , vector<int> &dp){
//     int n = nums.size();
//     int prev = nums[0];
//     int prev2 = 0;

//     for(int i = 1; i<n ; i++){
//         int take = nums[i];
//         if(i>1) take+=prev2;

//         int notTake = 0 + prev;

//         int curi = max(take , notTake);
//         prev2 = prev;
//         prev=curi;
//     }
//     return prev;
// }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n , -1);
//         return function(n -1, nums , dp);
        
//     }
// };

class Solution {
public:
int function(int ind , vector<int> &nums , vector<int> &dp){
    int n = nums.size();
     dp[0] = nums[0];

    for(int i = 1; i<n ; i++){
        int take = nums[i];
        if(i>1){
             take = take + dp[i-2];
        }
        int notTake = 0 + dp[i-1];

        dp[i] = max(take , notTake);
         
    }
    return dp[n-1];
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return function(n -1, nums , dp);
        
    }
};