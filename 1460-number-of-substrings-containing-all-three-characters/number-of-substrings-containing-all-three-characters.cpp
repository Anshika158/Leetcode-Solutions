class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int lastSeen[3] = {-1, -1, -1}; // Last seen indices for 'a', 'b', and 'c'

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i; // Update last seen index for current character

            // If all characters have been seen at least once
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int minLastSeen = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                count += (1 + minLastSeen);
            }
        }
        return count;
    }
};
