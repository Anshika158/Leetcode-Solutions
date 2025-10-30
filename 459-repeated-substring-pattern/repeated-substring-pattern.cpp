class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s+s;
        string check = doubled.substr(1,doubled.size()-2);
        if(check.find(s)!=-1)return true;
        return false;
    }
};