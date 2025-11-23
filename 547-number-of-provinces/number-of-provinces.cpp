

class Solution {
public:
    void dfs(int node,vector<int>&visited,vector<vector<int>>& isConnected) {
        visited[node] = 1;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && visited[i]!=1) {
               dfs(i,visited,isConnected);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<int> visited(isConnected.size());
        int node = 0;
        int count=0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] != 1) {
                dfs(i,visited,isConnected);
                count++;
            }
        }
   return count; }
};