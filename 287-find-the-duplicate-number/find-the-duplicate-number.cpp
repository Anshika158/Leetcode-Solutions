// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int ans=0;
//         int n=nums.size();
//         sort(nums.begin() , nums.end());
//         int i=0 ;
//         while(i<=n){
//             if(nums[i]==nums[i+1]){
//                 ans=nums[i];
//                 break;
//             }else{
//                  i++;
//         }
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
       vector<int> freq(n,0);
       for(int i=0 ; i<n ; i++){
        if(freq[nums[i]]==0){
            freq[nums[i]]+=1;
        }else{
            return nums[i];
        }
       }
       return 0;
    }
};