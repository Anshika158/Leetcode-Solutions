#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;
        for (int r : ranks) {
            totalCars += sqrt(time / r); // max cars that can be repaired by a mechanic in the given time
            if (totalCars >= cars) return true; // No need to check further if already possible
        }
        return totalCars >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long)cars * cars * *min_element(ranks.begin(), ranks.end());
        long long ans = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isPossible(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1; // Try to minimize time
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
