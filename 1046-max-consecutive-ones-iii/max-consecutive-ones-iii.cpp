// // BRUTE FORCE APPROACH
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxLength = 0 ;
//        int length = 0 ;
//        for(int i=0 ; i<nums.size() ; i++){
//         int zeroCount=0;
//         for(int j=i ;j<nums.size() ; j++){
//             if(nums[j]==0){
//                 zeroCount++;
//             }
//             if(zeroCount<=k){
//                 length = j-i+1;
//                 maxLength= max(maxLength , length);
//             }
//         }
//        }
//        return maxLength;
//     }
// };

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//       int length = 0 , maxLength = 0 , left = 0 , right =0 , zeroCount=0;

//       while(right<nums.size()){
//         if(nums[right]==0){
//             zeroCount++;
//         }
//         while(zeroCount>k){
//             if(nums[left]==0){
//                 zeroCount--;
//             }
//             left++;
//         }
//         length = right-left+1;
//         maxLength=max(length , maxLength);
//         right++;
//       }
//       return maxLength;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = 0, zeroCount=0 , maxLength=0;
        int size = nums.size();
        int left = 0 , right = 0 ;
        while(right<size){
           if(nums[right]==0){
            zeroCount++;
           }
           if(zeroCount>k){
            if(nums[left]==0){
                zeroCount--;
            }
            left++;
           }
           length=right-left+1;
           maxLength=max(maxLength , length);
           right++;      
          }
        return maxLength;
    }
};