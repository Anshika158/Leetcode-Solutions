class Solution {
public:
    void dfs(int sr , int sc , vector<vector<int>>&ans,vector<vector<int>>& image, int initialCol , int nRow[] , int nCol[] , int color){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0 ; i<4 ; i++){
            int row = sr+nRow[i];
            int col = sc+nCol[i];
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==initialCol && ans[row][col]!=color){
                dfs(row , col , ans , image , initialCol , nRow , nCol , color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initialCol=image[sr][sc];
        int nRow[]={0,-1,0,1};
        int nCol[]={-1,0,1,0};

        dfs(sr , sc , ans , image , initialCol , nRow, nCol , color);
        return ans;
    }
};