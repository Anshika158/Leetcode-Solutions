class Solution {
public:
    string removeOuterParentheses(string s) {
        queue<char> valid ;
        string answer="";
        int count=0 , right=0;
        while(right<s.size()){
            if(s[right]=='(' ){
                if(count>0){
                answer.push_back(s[right]);
                }
                count++;
            }
            
            if(s[right]==')'){
                count--;
                if(count>0){
                    answer.push_back(s[right]);
                }
            }
            right++;
        }
        return answer;
    }
};