class Solution {
public:
    int jump(vector<int>& nums) {
       int jump=0 , l=0 , r=0  , n=nums.size();
       while(r<n-1){
        int far=0;
        for(int i =l ; i<=r ; i++){
            far=max(far,i+nums[i]);
        }
        l=r+1;
        r=far;
        jump++;
       }
       return jump;
    }
};