class Solution {
public:
    string firstPalindrome(vector<string>& words) {
          int n = words.size();

        for (int i = 0; i < n; i++) {
            string word = words[i];
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                return word;
            }
        }

        return "";
    }
};