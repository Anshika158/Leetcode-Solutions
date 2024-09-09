// Brute Approach

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         long long maxArea = 0;
//         for(int i = 0 ; i < n ; i++){
//             int minHeight = INT_MAX;
//             for(int j=i ; j<n ; j++){
//                 minHeight = min(minHeight , heights[j]);
//                 maxArea = max(maxArea ,(long long)minHeight * (j-i+1));
//             }
//         }
//         return (int)maxArea;
//     }
// };

// Optimal Approach

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // We have to find PSE and NSE 
        stack<int> st;
        vector<int> leftS(n);
        vector<int>rightS(n);
        // NSE
        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            leftS[i] = st.empty()?0 : st.top()+1;
            st.push(i);
        } 
        // clearing stack for next use;
        while(!st.empty()){
            st.pop();
        }   
        //PSE
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rightS[i]=st.empty() ? n-1 : st.top()-1;
            st.push(i);
        }  
        int maxA=0;
        for(int i = 0 ; i< n ; i++){
            maxA= max(maxA , heights[i] * (rightS[i]-leftS[i]+1));
        } 
        return maxA;
    }
};