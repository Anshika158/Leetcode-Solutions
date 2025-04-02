class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;

        // Maintain maxPrefix (max nums[i] before j)
        int maxPrefix = nums[0];

        // Maintain maxSuffix[j+1] (max nums[k] after j)
        vector<int> maxSuffix(n, 0);
        maxSuffix[n - 1] = nums[n - 1];

        // Populate maxSuffix array
        for (int k = n - 2; k >= 0; --k) {
            maxSuffix[k] = max(maxSuffix[k + 1], nums[k]);
        }

        // Iterate for j (middle element)
        for (int j = 1; j < n - 1; ++j) {
            // Ensure we have a valid i before j and k after j
            if (maxPrefix > nums[j] && maxSuffix[j + 1] > 0) {
                maxValue = max(maxValue, (long long)(maxPrefix - nums[j]) * maxSuffix[j + 1]);
            }

            // Update maxPrefix for next iteration
            maxPrefix = max(maxPrefix, nums[j]);
        }

        return maxValue;
    }
};
