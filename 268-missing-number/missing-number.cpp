class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>visited(n+1,0);
        for(int i=0 ;i< n ; i++){
            int temp=nums[i];
            visited[temp]=1;
        }
        for(int i=0 ; i<visited.size() ; i++){
            if(visited[i]==0){
                return i;
            }
        }
        return 0;
    }
};