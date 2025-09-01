// class Solution {
// public:
//     void dfs(int row , int col , int delRow[],int delCol[],vector<vector<int>>&visited,vector<vector<int>>& grid){
//         int n=grid.size();
//         int m=grid[0].size();

//         visited[row][col]=1;

//         for(int i=0 ; i<4 ; i++){
//             int newR=row+delRow[i];
//             int newC=col+delCol[i];

//             if(newR>=0 && newR<n && newC>=0 && newC<m && !visited[newR][newC] && grid[newR][newC]==1){
//                 dfs(newR , newC , delRow , delCol , visited , grid);
//             }
//         }
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();

//         vector<vector<int>>visited(n , vector<int>(m,0));

//         int delRow[]={0,-1,0,1};
//         int delCol[]={-1,0,1,0};
        
//         int landC=0;

//         for(int j=0 ; j<m; j++){
//             if(!visited[0][j] && grid[0][j]==1){
//                 dfs(0 , j , delRow , delCol , visited , grid);
//             }
//             if(!visited[n-1][j] && grid[n-1][j]==1){
//                 dfs(n-1 , j , delRow , delCol , visited , grid);
//             }
//         }
//          for(int i=0 ; i<n ; i++){
//             if(!visited[i][0] && grid[i][0]==1){
//                 dfs(i,0, delRow , delCol , visited , grid);
//             }
//             if(!visited[i][m-1] && grid[i][m-1]==1){
//                 dfs(i , m-1 , delRow , delCol , visited , grid);
//             }
//         }
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m ; j++){
//                 if(!visited[i][j] && grid[i][j]==1){
//                     landC++;
//                 }
//             }
//         }
//         return landC;
//     }
// };

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

       queue<pair<int , int>> q;
       vector<vector<int>>visited(n , vector<int>(m,0));

       for(int j=0 ; j<m ; j++){
        //first row
            if(!visited[0][j] && grid[0][j]==1){
                visited[0][j]=1;
                q.push({0 , j });
            }
        //last row
            if(!visited[n-1][j] && grid[n-1][j]==1){
                visited[n-1][j]=1;
                q.push({n-1 , j });
            }
       }
        for(int i=0 ; i<n ; i++){
        //first col
            if(!visited[i][0] && grid[i][0]==1){
                visited[i][0]=1;
                q.push({i , 0 });
            }
        //last col
            if(!visited[i][m-1] && grid[i][m-1]==1){
                visited[i][m-1]=1;
                q.push({i , m-1 });
            }
       }
       while(!q.empty()){
        int row = q.front().first;
        int col= q.front().second;

        q.pop();
        int delRow[]={0,-1,0,1};
        int delCol[]={-1,0,1,0};

        for(int k=0 ; k<4 ; k++){
            int nRow = row+delRow[k];
            int nCol = col+delCol[k];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && grid[nRow][nCol]==1){
                visited[nRow][nCol]=1;
                q.push({nRow , nCol});
            }
        }
       }
       int landC=0;
       for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!visited[i][j] && grid[i][j]==1){
                landC++;
            }
        }
       }
        return landC;
    }
};