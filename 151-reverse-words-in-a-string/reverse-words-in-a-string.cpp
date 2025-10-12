class Solution {
public:
    string reverseWords(string s) {
        // stack<string>answer;
        // string word = "";
        // for(int i=0 ; i<s.size() ; i++){ 
        //     if(s[i]!=' '){
        //         word +=s[i];
        //     }else{
        //         if(!word.empty()){
        //             answer.push(word);
        //             word="";
        //         }
        //     }
        // }
        // if (!word.empty()) {
        //     answer.push(word);
        // }
        // string result="";
        // while(!answer.empty()){
        //     result+=answer.top();
        //     answer.pop();
        //     if(!answer.empty()){
        //         result+=" ";
        //     }
        // }
        // return result;

        int left , right =  s.size()-1;
        string result="";
        while(right>=0){
            while(right>=0 && s[right] == ' ')right--;
            if(right<0) break ;
            left=right;

            while(right>=0 && s[right]!=' ') right--;
                if (!result.empty()) result += " ";
                result += s.substr(right + 1, left-right);
            
            
        }
        return result;
    }
};