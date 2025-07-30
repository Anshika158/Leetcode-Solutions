class Solution {
public:
    string reverseWords(string s) {
        stack<string>answer;
        string word = "";
        for(int i=0 ; i<s.size() ; i++){ 
            if(s[i]!=' '){
                word +=s[i];
            }else{
                if(!word.empty()){
                    answer.push(word);
                    word="";
                }
            }
        }
        if (!word.empty()) {
            answer.push(word);
        }
        string result="";
        while(!answer.empty()){
            result+=answer.top();
            answer.pop();
            if(!answer.empty()){
                result+=" ";
            }
        }
        return result;
    }
};