class Solution {
public:
    string makeGood(string s) {
        if(s.size()==1) return s;
        string result="";
        for(char c : s){
            if(!result.empty() && abs(result.back()-c)==32){
                result.pop_back();
            }else{
                result.push_back(c);
            }
        }
        return result;
    }
};