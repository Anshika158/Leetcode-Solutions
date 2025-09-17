class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>visited(n+1,0);
        // for(int i=0 ;i< n ; i++){
        //     int temp=nums[i];
        //     visited[temp]=1;
        // }
        // for(int i=0 ; i<visited.size() ; i++){
        //     if(visited[i]==0){
        //         return i;
        //     }
        // }
        // return 0;

        //OPTIMAL APPROACH 1

        // int n=nums.size();
        // int sum= (n*(n+1))/2;
        // int s=0;
        // for(int i=0 ; i<n ; i++){
        //     s+=nums[i];
        // } 
        // return sum-s;

        // OPTIMAL APPROACH 2 USING XOR 
        int n=nums.size();
        int xorVal = 0;
        for(auto num: nums){
            xorVal ^= num;
        }
        for(int i=0 ; i<=n ; i++){
            xorVal^=i;
        }
    return xorVal;
    }
};