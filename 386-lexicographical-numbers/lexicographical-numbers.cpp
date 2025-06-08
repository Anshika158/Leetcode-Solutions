class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        
        for (int i = 0; i < n; ++i) {
            result.push_back(curr);
            
            if (curr * 10 <= n) {
                // Go deeper (like 1 → 10)
                curr *= 10;
            } else {
                // Go to next sibling or climb up to a valid parent
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr += 1;
            }
        }
        
        return result;
    }
};
