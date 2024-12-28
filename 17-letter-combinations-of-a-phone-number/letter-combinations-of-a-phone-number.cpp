class Solution {
public:
    void findString(int ind , string digits , vector<string>&result , string current, unordered_map<char,string> &digitMap){
        if(ind==digits.size()){
            result.push_back(current);
            return;
        }
        string letters = digitMap[digits[ind]];
        for(char letter:letters){
            current.push_back(letter);
             findString(ind+1,digits,result,current,digitMap);
             current.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int s=digits.size();
        if(digits.empty()){
            return {};
        }
        unordered_map<char,string> digitMap={{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
 {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string>result;
        string current;
        findString(0,digits,result,current,digitMap);
        return result;
    }
};