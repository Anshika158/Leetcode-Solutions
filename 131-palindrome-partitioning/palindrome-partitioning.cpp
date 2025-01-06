class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // To store all the partitions
        vector<string> currentPartition; // To store the current partition
        backtrack(0, s, currentPartition, result); // Start backtracking
        return result;
    }

private:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false; // Not a palindrome
            start++;
            end--;
        }
        return true; // Is a palindrome
    }

    // Backtracking function
    void backtrack(int start, const string& s, vector<string>& currentPartition, vector<vector<string>>& result) {
        // Base case: If start index reaches the end of the string
        if (start == s.size()) {
            result.push_back(currentPartition); // Add the current partition to the result
            return;
        }

        // Explore all possible substrings starting from 'start'
        for (int end = start; end < s.size(); end++) {
            // Check if the substring s[start:end+1] is a palindrome
            if (isPalindrome(s, start, end)) {
                // Add the palindrome substring to the current partition
                currentPartition.push_back(s.substr(start, end - start + 1));

                // Recur for the remaining substring
                backtrack(end + 1, s, currentPartition, result);

                // Backtrack: Remove the last added substring
                currentPartition.pop_back();
            }
        }
    }
};
