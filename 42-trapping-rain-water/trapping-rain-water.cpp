class Solution {
public:
   int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1 ;
        int rws = 0;
        int leftMax=0 , rightMax=0 ;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax){
                    leftMax = height[left];
                }else{
                    rws +=  leftMax - height[left];
                }
                left++;
            }else{
                if(height[right]>=rightMax){
                    rightMax = height[right];
                }else{
                    rws += rightMax - height[right];
                }
                right--;
            }
        }
        return rws;
        
    }
};

//optimal approach 1 

// class Solution {
// public:
//    int trap(vector<int>& height) {
//         int n = height.size();
//         int prefix[n] , suffix[n];
//         prefix[0] = height[0];
//         for(int i = 1 ; i<n ; i++){
//             prefix[i]=max(prefix[i-1],height[i]);
//         }
//         suffix[n-1]=height[n-1];
//         for(int i = n-2 ; i>=0 ; i--){
//             suffix[i]=max(suffix[i+1] , height[i]);
//         }
//         int rainWaterTrapped = 0;
//         for(int i = 0 ; i<n ; i++){
//             rainWaterTrapped += min(prefix[i] , suffix[i]) - height[i];
//         }
//         return rainWaterTrapped;
//     }
// };


// Brute Approach

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int size = height.size();
//         int rainWaterTrapped = 0;
//         for(int i = 0 ; i<size ; i++){
//             int j = i;
//             int leftMax = 0 , rightMax = 0 ;
//             while(j>=0 ){
//                 leftMax = max(leftMax , height[j]);
//                 j--;
//             }
//             j=i;
//             while(j<size){
//                 rightMax = max(rightMax , height[j]);
//                 j++;
//             }
//             rainWaterTrapped += min(leftMax , rightMax)- height[i];
//         }
//         return  rainWaterTrapped;

//     }
// };