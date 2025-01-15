class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(c=='(' || c=='{' || c=='['){
                stk.push(c);
            }else if(c==')'|| c=='}' || c==']'){
                if(stk.empty()){
                    return false;
                }
                char poppedChar = stk.top();
                  stk.pop();
                if( (c==')' && poppedChar != '(') || (c==']' && poppedChar != '[') ||(c=='}' && poppedChar != '{') ){
                    return false;
                }
              
            }
        }
        return stk.empty();
    }
};