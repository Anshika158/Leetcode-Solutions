class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>st;
        int s=sentence.size();
        for(int i=0 ; i<s ; i++){
            st.insert(sentence[i]);
        }
        if(st.size()==26){
            return true;
        }
        return false;
    }
};