// class Solution {
// public:
//     int function(int idx , vector<int>&nums , vector<int>&dp){
//         if(idx>=nums.size()) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int pick=nums[idx]+function(idx+2 , nums , dp);
//         int notPick=0+function(idx+1,nums,dp);
//          return dp[idx]=max(pick,notPick);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n , -1);
//         return function(0 , nums , dp);
//     }
// };
//Tabulation
class Solution{
public:
    int n;
    int function(vector<int>&nums , vector<int>&dp){
        dp[0]=nums[0];
        for(int i=1 ; i<n ; i++){
            int take=nums[i];
            if(i>1){
                take = take+dp[i-2];
            }
            int notTake = 0  + dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
    int rob(vector<int>&nums){
        n=nums.size();
        vector<int>dp(n,-1);
        return function(nums , dp);

    }
};



















// // SPACE OPTIMIZATION

// // class Solution {
// // public:
// // int function(int ind , vector<int> &nums , vector<int> &dp){
// //     int n = nums.size();
// //     int prev = nums[0];
// //     int prev2 = 0;

// //     for(int i = 1; i<n ; i++){
// //         int take = nums[i];
// //         if(i>1) take+=prev2;

// //         int notTake = 0 + prev;

// //         int curi = max(take , notTake);
// //         prev2 = prev;
// //         prev=curi;
// //     }
// //     return prev;
// // }
// //     int rob(vector<int>& nums) {
// //         int n = nums.size();
// //         vector<int> dp(n , -1);
// //         return function(n -1, nums , dp);
        
// //     }
// // };

// // TABULATION

// class Solution {
// public:
// int function(int ind , vector<int> &nums , vector<int> &dp){
//     int n = nums.size();
//      dp[0] = nums[0];

//     for(int i = 1; i<n ; i++){
//         int take = nums[i];
//         if(i>1){
//              take = take + dp[i-2];
//         }
//         int notTake = 0 + dp[i-1];

//         dp[i] = max(take , notTake);
         
//     }
//     return dp[n-1];
// }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n , -1);
//         return function(n -1, nums , dp);
        
//     }
// };