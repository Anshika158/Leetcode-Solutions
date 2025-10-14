class Solution{
public:
    int longestCommonSubsequence(string text1, string text2){
        int m=text1.size() , n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        // first row and first col will be initialize to 0;
        for(int row=0 ; row<m+1 ; row++ ){
            dp[row][0]=0;
        }
        for(int col=0 ; col<n+1 ; col++ ){
            dp[0][col]=0;
        }
        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

// class Solution {
// public:
//     int n,m;
//     int function(int i , int j , string text1 , string text2,vector<vector<int>>&dp){
//         if(i>=n || j>=m) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(text1[i]==text2[j]){
//             return dp[i][j]= 1+function(i+1 , j+1 , text1 , text2,dp);
//         }
//         return dp[i][j]= max(function(i+1,j,text1,text2,dp) , function(i,j+1,text1 , text2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         n=text1.size();
//         m=text2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return function(0 , 0, text1 , text2 ,dp );
//     }
// };