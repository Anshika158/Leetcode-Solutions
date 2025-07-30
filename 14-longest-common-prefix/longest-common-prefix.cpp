class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        for(int i=1 ; i<strs.size() ; i++){
            string s1 = strs[i];
            int pointer=0;
            while(pointer<s1.size() && pointer<answer.size()){
                if(s1[pointer]==answer[pointer]){
                    pointer++;
                }else{
                    break;
                }
            }
            answer = answer.substr(0 , pointer);

        }
        return answer;
    }
};