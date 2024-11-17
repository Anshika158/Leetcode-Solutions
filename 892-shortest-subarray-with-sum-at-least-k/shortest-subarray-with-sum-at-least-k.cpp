class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // int sum = accumulate(nums.begin() , nums.end(),0);
        // if(sum==k) return sum;
        deque<pair<long long,int>> dq;
        int  size=nums.size() , minlen=INT_MAX ;
        long long sum=0;
        for(int r =0 ; r<size ; ++r){
            sum+=nums[r];
            if(sum>=k){
               minlen=min(minlen , r+1);
               }
            while(!dq.empty() && sum-dq.front().first>=k){
                minlen=min(minlen , r-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() && dq.back().first>=sum){
                dq.pop_back();
            }
            dq.push_back({sum,r});
            }
        return minlen==INT_MAX ? -1 : minlen;
    }
};