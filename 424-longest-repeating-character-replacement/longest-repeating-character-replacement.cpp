class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int maxf = 0, maxlen = 0, right = 0, left = 0;
        int hash[26] = {0};

        while (right < size) {
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);
            int changes = (right - left + 1) - maxf;
            while (changes > k) {
                hash[s[left] - 'A']--;
                left++;
                changes = (right - left + 1) - maxf;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    }
};
