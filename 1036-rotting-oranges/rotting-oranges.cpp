class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute=-1;
        int fresh=0;
        int delRow[]={0,-1,0,1};
        int delCol[]={-1,0,1,0};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int , int>>q;
        vector<vector<int>>visited(n , vector<int>(m,0));

        for(int i=0  ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0 ; //no fresh oranges;

        while(!q.empty()){
            minute++;
            int size=q.size();
            for(int k=0 ; k<size; k++){
                auto [ r , c] = q.front();
                q.pop();
                for(int l=0 ; l<4 ; l++){
                    int nRow = r+delRow[l];
                    int nCol=c+delCol[l];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1){
                        grid[nRow][nCol]=2;
                        fresh--;
                        q.push({nRow,nCol});
                    }
                }
            }

        }
        return (fresh==0)?minute:-1;
    }
};