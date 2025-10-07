class Solution {
public:
    int helper(int n , vector<int>&dp){
        if(n==0) return 0;
        int minC=INT_MAX;
        if(dp[n]!= -1) return dp[n];
        for(int i=1 ; i*i<=n ; i++){
            int result=  1+helper(n-i*i,dp);
            minC=min(minC , result);
        }
        return dp[n]= minC;
    }
    int numSquares(int n) {
        vector<int>dp(10001,-1);
        return helper(n,dp);
    }
};