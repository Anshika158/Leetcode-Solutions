// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> list;
//         for(int i = 0 ; i<=n-k ; i++){
//             int maxi = nums[i];
//             // find the maximum in current window
//             for(int j=i ; j<i+k ; j++){
//                 maxi = max(maxi , nums[j]);
//             }
//              list.push_back(maxi);
//         } 
//         return list;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq; // to store the indicies of the element of the current widow
       vector<int> ans; // to store the maximum of the sliding window
       int n = nums.size();
       for(int i =0 ; i<n ; i++){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
        
       }
       return ans;
    }
};