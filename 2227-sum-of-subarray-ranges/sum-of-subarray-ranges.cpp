class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            int minval = nums[i] , maxval = nums[i];
            for(int j=i; j<n ; j++){
                minval = min(minval , nums[j]);
                maxval = max(maxval , nums[j]);

                sum+=( maxval - minval );
            }
        }
        return sum;
    }
};