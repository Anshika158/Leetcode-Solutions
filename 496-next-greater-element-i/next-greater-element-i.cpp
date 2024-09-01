class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // store the element
        unordered_map<int , int> ngeMap;
        stack<int> st;
        // we will be doing  back-traversing
        int n = nums2.size();
        // nge[n-1]=-1;
        // st.push(num1(n-1));
        for(int i = n-1 ; i>=0 ; i--){
            int num = nums2[i];
            while(!st.empty() && st.top()<=num){
                st.pop();
            }
            if(st.empty()){
                ngeMap[num]=-1;
                //st.push(num[i]);
            }else{
                ngeMap[num]=st.top();
            }
            st.push(num);
        }
        vector<int> result;
        for(int num: nums1){
            result.push_back(ngeMap[num]);
        }
    return result;
    }
};