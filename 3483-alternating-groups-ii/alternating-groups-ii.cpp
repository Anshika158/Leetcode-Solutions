class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int isAlternating = 1;  // 1 means alternating, 0 means not

        // Check first window [0, k-1]
        for (int i = 1; i < k; i++) {
            if (colors[i] == colors[i - 1]) {
                isAlternating = 0;
                break;
            }
        }
        count += isAlternating;

        // Sliding window over the rest of the array
        for (int i = 1; i < n; i++) {
            // Remove previous first element and add new element
            int prevFirst = colors[i - 1];
            int newLast = colors[(i + k - 1) % n];

            // Update isAlternating efficiently
            if (isAlternating) {
                if (prevFirst == colors[i] || colors[(i + k - 2) % n] == newLast) {
                    isAlternating = 0;
                }
            } else {
                isAlternating = 1;
                for (int j = 1; j < k; j++) {
                    if (colors[(i + j) % n] == colors[(i + j - 1) % n]) {
                        isAlternating = 0;
                        break;
                    }
                }
            }

            count += isAlternating;
        }

        return count;
    }
};
