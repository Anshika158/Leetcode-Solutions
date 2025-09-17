class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return ;
        int count=0;
        int j=-1;
        for(int i=0; i<n ; i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return ;  // array doesnt have zero

        for(int i=j+1 ; i<n ; i++){
            if(nums[i]!=0){
                swap(nums[i] , nums[j]);
                j++;
            }
        }
    }
};