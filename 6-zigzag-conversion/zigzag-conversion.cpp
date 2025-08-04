class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s; // edge case

        int ind = 0, d = 1;
        int n = s.size();
        vector<vector<char>> grid(numRows);

        for(char c : s){
            grid[ind].push_back(c);
            if(ind == 0){
                d = 1;
            } else if(ind == numRows - 1){
                d = -1;
            }
            ind += d;
        }

        string ans;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                ans += grid[i][j];
            }
        }
        return ans;
    }
};
