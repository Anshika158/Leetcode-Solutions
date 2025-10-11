class Solution {
public:
//RECURSION + MEMOIZATION
    int solve(int n , vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 1;
        int one_step = solve(n-1 , dp);
        int two_step = solve(n-2 , dp);
    return dp[n]=one_step+two_step;
    }
    int climbStairs(int n){\
        vector<int>dp(n+1,-1);
        return solve(n , dp);
    // }
    // int climbStairs(int n) {
    //     if(n<=2)return n;
    //     vector<int>dp(n+1);
    //     dp[1]=1;
    //     dp[2]=2;
    //     for(int i=3 ; i<=n ; i++){
    //         dp[i]=dp[i-2]+dp[i-1];
    //     }
    //     return dp[n];
    }
};




 