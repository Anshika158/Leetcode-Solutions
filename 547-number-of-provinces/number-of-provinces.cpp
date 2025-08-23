// class Solution {
// public:
// void dfs(int node ,vector<vector<int>> &adjLS , vector<bool>&visited){
//     visited[node]=true;
//     for(auto it : adjLS[node]){
//         if(!visited[it]){
//             dfs(it , adjLS , visited);
//         }
//     }
// }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V=isConnected.size();
//        vector<vector<int>> adjLS(V);
//         for(int i=0; i<V ; i++){
//             for(int j=0 ; j<V ; j++){
//                 if(isConnected[i][j]==1 && i!=j ){
//                     adjLS[i].push_back(j);
//                     adjLS[j].push_back(i);
//                 }
//             }
//         }
//         vector<bool>visited(V , false);
//         int count=0;
//         for(int i=0 ; i<V ; i++){
//             if(!visited[i]){
//                 count++;
//                 dfs(i , adjLS , visited);
//             }
//         }
//     return count;
//     }
// };

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