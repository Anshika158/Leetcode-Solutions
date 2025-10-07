class Solution {
public:
    int solve(vector<int>&jobDifficulty , int n  , int idx , int d , vector<vector<int>>&dp){
    //BASE CASE
        if(d==1){
            int maxD=jobDifficulty[idx];
            for(int i=idx+1;i<n;i++){
                maxD=max(maxD,jobDifficulty[i]);
            }
            return maxD;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int maxD=jobDifficulty[idx];
        int finalR=INT_MAX;
        for(int i=idx ; i<=n-d ; i++){
            maxD=max(maxD , jobDifficulty[i]);
            int result=maxD + solve(jobDifficulty , n , i+1 , d-1 , dp);
            finalR=min(finalR , result);
        }
        return dp[idx][d]=finalR;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        int sum;
        //BASE CASE
        if(d>n) return -1;
        vector<vector<int>>dp(n , vector<int>(d+1 , -1));
        return solve(jobDifficulty , n , 0 , d  , dp);
    }
};