class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        
        vector<int> freq(N + 1, 0);
        int repeated = -1, missing = -1;
        
        // Count frequency of each number in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                freq[val]++;
                if (freq[val] == 2) {
                    repeated = val;
                }
            }
        }
        
        // Find the missing number
        for (int i = 1; i <= N; ++i) {
            if (freq[i] == 0) {
                missing = i;
                break;
            }
        }
        
        return {repeated, missing};
    }
};
