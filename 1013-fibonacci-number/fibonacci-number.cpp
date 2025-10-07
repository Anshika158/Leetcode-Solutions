class Solution {
public:
    // int solve(int n , vector<int>&dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];

    //     return dp[n]=solve(n-1 , dp) + solve(n-2 , dp);
    // }
    // int fib(int n) {
    //     vector<int>dp(n+1,-1);
    //     return solve(n,dp);
    //}
    // // BOTTOM UP APPROACH
    //     int fib(int n){
    //         if(n<=1) return n;
    //         vector<int>store(n+1,-1);
    //         store[0]=0;
    //         store[1]=1;
    //         for(int i=2 ; i<=n ; i++){
    //             store[i]=store[i-1]+store[i-2];
    //         }
    //         return store[n];
    //     }
        //CONSTANT TIME APPROACH
            int fib(int n){
                if(n<=1) return n;
                int c;
                int a = 0 ;
                int b = 1 ;
                for(int i=1 ; i<n  ; i++){
                    c=a+b;
                    a=b;
                    b=c;
                }
                return c;
            }
};






