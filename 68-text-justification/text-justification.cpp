class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int eachSpace, int extraSpace, vector<string>& words, bool lastLine) {
        string line;
        for (int k = i; k < j; k++) {
            line += words[k];
            if (k == j - 1) continue;  // last word in line

            if (lastLine) {
                line += " "; // only 1 space for last line
            } else {
                for (int z = 0; z < eachSpace; z++) line += " ";
                if (extraSpace > 0) {
                    line += " ";
                    extraSpace--;
                }
            }
        }
        while (line.length() < MAX_WIDTH) line += " ";
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        MAX_WIDTH = maxWidth;
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int letterCount = words[i].length();
            int j = i + 1;

            while (j < n && letterCount + words[j].length() + (j - i) <= maxWidth) {
                letterCount += words[j].length();
                j++;
            }

            int spaceCount = j - i - 1;
            int remaining = maxWidth - letterCount;

            bool lastLine = (j == n || spaceCount == 0);
            int eachSpace = lastLine ? 1 : remaining / spaceCount;
            int extraSpace = lastLine ? 0 : remaining % spaceCount;

            result.push_back(findLine(i, j, eachSpace, extraSpace, words, lastLine));
            i = j;
        }

        return result;
    }
};
