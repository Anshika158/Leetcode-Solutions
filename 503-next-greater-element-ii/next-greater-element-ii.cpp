class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       
       stack<int> st;
       int n = nums.size();
       vector<int> nge(n,-1);
       for(int i = 2*n-1 ; i>=0 ; i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    nge[i]=st.top();
                }else{
                   nge[i]=-1; 
                }
            }
            st.push(nums[i%n]);
       }
            return nge;
    }
};
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int size = nums.size();
//         vector<int> nge(size , -1);
//         for(int i = 0 ; i<size ; i++){
//             for(int j = 1 ; j< size ; j++){
//                 int index= (i+j)%size;
//                 if(nums[index]>nums[i]){
//                     nge[i]=nums[index];
//                     break;
//                 }
//             }
//         }
//         return nge;
//     }
// };