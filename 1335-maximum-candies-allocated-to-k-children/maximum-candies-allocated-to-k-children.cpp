class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1;
        long long right = *max_element(candies.begin(), candies.end());
        long long result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            
            for (int candy : candies) {
                count += candy / mid;
            }
            
            if (count >= k) { // We can satisfy k children
                result = mid; // Update result and try for more candies per child
                left = mid + 1;
            } else {
                right = mid - 1; // Try reducing the candies per child
            }
        }
        
        return result;
    }
};
