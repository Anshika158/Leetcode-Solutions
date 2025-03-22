#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<unordered_set<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        vector<bool> visited(n, false);
        
        // Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        int completeComponents = 0;

        // Find all connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // Check if the component is complete
                int size = component.size();
                int expectedEdges = size * (size - 1) / 2;
                int actualEdges = 0;

                for (int node : component) {
                    actualEdges += adj[node].size();
                }

                // Each edge is counted twice in an undirected graph
                if (actualEdges / 2 == expectedEdges) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
