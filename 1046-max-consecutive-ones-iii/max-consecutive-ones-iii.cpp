// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int length = 0 , maxlength=0;
//         int zeroCount=0;
//         int n = nums.size();
//         for(int i = 0 ; i<n ; i++){
//             for(int j=i ; j<n ; j++){
//                 if(nums[j]==0){
//                     zeroCount++;
//                 }
//                 if(zeroCount>k){
//                     break;
//                 }
//                 length=j-i+1;
//                 maxlength=max(maxlength,length);
                
//             }
//             zeroCount=0;
//         }
//         return maxlength;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = 0, zeroCount=0 , maxLength=0;
        int n = nums.size();
        int left = 0 , right = 0 ;
        while(right<n){
            if(nums[right]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(nums[left]==0){
                    zeroCount--;
                }
                 left++;
            }
            if(zeroCount<=k){
                length=right-left+1;
                maxLength=max(maxLength , length);
            }
            right++;
        }
       return maxLength; 
    }
};