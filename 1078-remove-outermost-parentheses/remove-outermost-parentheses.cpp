class Solution {
public:
    string removeOuterParentheses(string s) {
        int right=0 , count=0;
        string answer="";
        while(right<s.size()){
            if(s[right]=='('){
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
























//class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string answer='';
//         int count=0 , right=0;
//         while(right<s.size()){
//             if(s[right]=='(' ){
//                 if(count>0){
//                 answer.push_back(s[right]);
//                 }
//                 count++;
//             }
            
//             if(s[right]==')'){
//                 count--;
//                 if(count>0){
//                     answer.push_back(s[right]);
//                 }
//             }
//             right++;
//         }
//         return answer;
//     }
// };