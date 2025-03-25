class Solution {
public:
    vector<int>generateRows(int ind){
        int sum=1;
        vector<int>row;
        row.push_back(sum);
        for(int i = 1 ; i<ind ; i++){
            sum=sum*(ind-i);
            sum = sum/i;
            row.push_back(sum);

        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        for(int i = 1 ; i<=numRows ; i++){
            ans.push_back(generateRows(i));
        }
return ans;
    }
};