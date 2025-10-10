class Solution {
public:
    int n;

    int getNext(vector<vector<int>>&array , int left , int currentJobEnd){
        int result = n+1;
        int right=n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(array[mid][0]>=currentJobEnd){
                result=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&array , int i , vector<int>&dp ){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int next = getNext(array , i+1 , array[i][1]);
        int taken = array[i][2]+solve(array , next  , dp);
        int notTaken = solve(array, i+1 , dp);

        return dp[i]=max(taken , notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<int>dp(50001 , -1);
        vector<vector<int>>array(n , vector<int>(3,0));
        for(int i=0 ; i<n ; i++){
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }
        // auto comp = [&](auto &vec1 , auto &vec2){
        //     return vec1[0]<=vec2[0];
        // };
        //sort on the basis of startTime
        sort(array.begin(),array.end() , [&](auto &vec1 , auto &vec2){
            return vec1[0]<vec2[0];
        });
        return solve(array,0,dp);
    }
};