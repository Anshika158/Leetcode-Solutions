// // BRUTE FORCE APPROACH
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//        int maxLength = 0 ; 
//        int length = 0 ;
//        int zeroCount=0;
//        int size = nums.size();
//        for(int i = 0 ; i < size ; i++){
//         for(int j = i ; j<size ; j++){
//             if(nums[j]==0){
//                 zeroCount++;
//             }
//             if(zeroCount > k){
//                 break;
//             }
//             length = j-i+1;
//         }
//         maxLength = max(maxLength , length);
//         zeroCount = 0;
//        } 
//        return maxLength;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = 0 , maxlength = 0 ;
        int left = 0 , right = 0;
        int zeroCount =0;
        int size = nums.size();
        while(right<size){
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
                length = right-left+1;
                maxlength = max(maxlength , length);
            }
            right++;
        }
        return maxlength;
    }
};

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int length = 0, zeroCount=0 , maxLength=0;
//         int n = nums.size();
//         int left = 0 , right = 0 ;
//         while(right<n){
//             if(nums[right]==0){
//                 zeroCount++;
//             }
//             if(zeroCount>k){
//                 if(nums[left]==0){
//                     zeroCount--;
                    
//                 }
//                 left++;
//                 if(zeroCount<=k){
//                     length = right-left+1;
//                     maxLength = max(maxLength , length);
//                 }

//             }
//             right++;
//         }
//            return maxLength; 
//     }
// };