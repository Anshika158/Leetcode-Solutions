class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int zeroCount=0 , oneCount=0 , twoCount=0;
        // int n=nums.size();
        // for(int i=0 ; i<n ; i++){
        //     if(nums[i]==0){
        //         zeroCount++;
        //     }else if(nums[i]==1){
        //         oneCount++;
        //     }else{
        //         twoCount++;
        //     }
        // }
        // for(int i=0 ; i<zeroCount ; i++)nums[i]=0;
        // for(int i=zeroCount ; i<zeroCount+oneCount ; i++)nums[i]=1;
        //  for(int i=oneCount+zeroCount ; i<n ; i++)nums[i]=2;

        //OPTIMAL APPROACH USING LOW HIGH AND MID
        int low=0 , mid =0 , high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid] , nums[high]);
                high--;
            }else{
                mid++;
            }
        }
    }
};