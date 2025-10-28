#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        auto canMakeAllZero = [&](int start, int dir) {
            vector<int> arr = nums;
            int curr = start;

            while (curr >= 0 && curr < n) {
                if (arr[curr] == 0) {
                    curr += dir;
                } else {
                    arr[curr] -= 1;
                    dir *= -1;
                    curr += dir;
                }
            }
            // Check if all elements became 0
            for (int x : arr) {
                if (x != 0) return false;
            }
            return true;
        };

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (canMakeAllZero(i, 1)) count++;   // move right
                if (canMakeAllZero(i, -1)) count++;  // move left
            }
        }
        return count;
    }
};
