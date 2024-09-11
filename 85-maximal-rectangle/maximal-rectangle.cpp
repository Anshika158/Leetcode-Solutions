class Solution {
public:

    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int maxA=0;
        for(int i = 0 ; i<=n ; i++){
            int currentHeight = (i==n)? 0 : heights[i];
            while(!st.empty() && currentHeight < heights[st.top()]){
                int length = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i- st.top()-1);
                maxA = max(maxA , width*length);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int n = matrix.size();    // no. of rows
        int m = matrix[0].size(); // no. of columns

        vector<vector<int>> prefix(n , vector<int>(m,0));   //2D prefix sum
        int maxRectangle = 0 ;

        //build the prefkx sum for the first row 
        for(int j = 0 ; j<m ; j++){
            prefix[0][j]=(matrix[0][j]=='1')?1:0;
        }

        //build the prefix sum for remaining rows
        for(int i = 1 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]=='1'){
                    prefix[i][j]=prefix[i-1][j]+1;
                }else{
                   prefix[i][j]=0; 
                }
            }
        }
        for(int i =0 ; i<n ; i++){
            maxRectangle = max(maxRectangle ,largestRectangleArea(prefix[i]));
        }
        return maxRectangle;
    }
};