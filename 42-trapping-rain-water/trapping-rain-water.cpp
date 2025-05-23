class Solution {
public:
    int trap(vector<int>& height) {

        //OPTIMAL APPROACH
        int n=height.size();
        int left = 0 , right = n-1 ;
        int leftMax=0 , rightMax=0;
        int waterTrapped=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax){
                    leftMax=height[left];
                }else{
                    waterTrapped += leftMax-height[left];
                }
                left++;
            }else{
                if(height[right]>=rightMax){
                    rightMax=height[right];
                }else{
                    waterTrapped+=rightMax-height[right];
                } 
                right--;
            }
        }
        return waterTrapped;


        // //BETTER APPROACH  STORE PREFIX AND SUFFIX 
        // int waterTrapped = 0 ;
        // int n = height.size();
        // vector<int>prefix(n) ; vector<int>suffix(n);
        // prefix[0]=height[0];
        // for(int i=1 ; i<n ; i++){
        //     prefix[i]=max(prefix[i-1] , height[i]);
        // }
        // suffix[n-1]=height[n-1];
        // for(int i=n-2 ; i>=0 ; i--){
        //     suffix[i]=max(suffix[i+1] , height[i]);
        // }
        // for(int i=0 ; i<n ; i++){
        //     waterTrapped+=min(prefix[i] , suffix[i])-height[i];
        // }
        // return waterTrapped;


        // // BRUTE APPROACH

        // int waterTrapped = 0 ;
        // int n=height.size();
        // for(int i=0 ; i<n ; i++){
        //     int leftMax=0 , rightMax=0;
        //     int j=i;
        //     while(j>=0){
        //         leftMax= max(leftMax , height[j]);
        //         j--;
        //     }
        //     j=i;
        //     while(j<n){
        //         rightMax=max(rightMax , height[j]);
        //         j++;
        //     }
        //     waterTrapped += min(leftMax , rightMax)-height[i];
        // }
        // return waterTrapped;
    }
};