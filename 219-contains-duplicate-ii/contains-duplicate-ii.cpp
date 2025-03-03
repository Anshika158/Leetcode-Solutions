#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // Stores number and its last index

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && (i - mp[nums[i]] <= k)) {
                return true;
            }
            mp[nums[i]] = i; // Update index of the number
        }
        return false;
    }
};
