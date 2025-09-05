class Solution {
public:
    void merge(vector<int>&nums ,int low , int mid , int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid  && right<=high){
            if(nums[left]>=nums[right]){
                temp.push_back(nums[right]);
                right++;
            }else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low ; i<=high ; i++){
            nums[i]=temp[i-low];
        }
    }
    void mS(vector<int>&nums , int low , int high){
        if(low>=high) return ; // base case
        int mid=(low+high)/2;
        mS(nums , low , mid );
        mS(nums , mid+1 , high);
        merge(nums , low , mid , high);
    }
    vector<int> sortArray(vector<int>& nums) {
        // //using selection sort
        // int n=nums.size();
        // int mini=0;
        // for(int i=0 ; i<n-1 ; i++){
        //     mini=i;
        //     for(int j=i+1 ; j<n ; j++){
        //         if(nums[mini]>nums[j]){
        //             mini=j;
        //         }
        //     }
        //     swap(nums[mini],nums[i]);
        // }
        // return nums;

        // //USING BUBBLE SORT
        // int n=nums.size();
        // for(int i=n-1 ; i>=0 ; i--){
        //     int didSwap=0;
        //     for(int j=0 ; j<i ; j++){
        //         if(nums[j]>nums[j+1]){
        //             swap(nums[j],nums[j+1]);
        //             int didSwap=1;
        //         }
        //     }
        //     if(didSwap=0){
        //         break;
        //     }
        // }
        // return nums;

        // //using INSERTION SORT
        // int n=nums.size();
        // for(int i=0 ; i<n ; i++){
        //     int j=i;
        //     while(j>0 && nums[j-1]>nums[j]){
        //         swap(nums[j] , nums[j-1]);
        //         j--;
        //     }
        // }
        // return nums;

        //USING MERGE SORT
        int n=nums.size();
        mS(nums , 0 , n-1);
        return nums;
    }
};