class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        // Maximize: replace first non-9 digit with 9
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char &c : a) {
                if (c == toReplaceMax) c = '9';
            }
        }

        // Minimize
        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char &c : b) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 1; i < b.size(); i++) {
                    if (b[i] == toReplaceMin) b[i] = '0';
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
