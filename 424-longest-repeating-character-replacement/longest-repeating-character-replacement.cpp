class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int maxlen = 0;
        int maxf = 0;
        int hash[26] = {0};
        
        int left = 0;
        for (int right = 0; right < size; right++) {
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);
            
            // Calculate the number of changes required
            while ((right - left + 1) - maxf > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};
