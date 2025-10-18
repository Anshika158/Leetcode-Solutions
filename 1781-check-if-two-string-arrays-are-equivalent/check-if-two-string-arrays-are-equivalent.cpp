class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size() , n = word2.size();
        string result1="";
        for(int i=0 ; i<m ; i++){
            result1+=word1[i];
        }
        string result2="";
        for(int i=0 ; i<n ; i++){
            result2+=word2[i];
        }
        if(result1.size() != result2.size()) return false;
        for(int i=0 ; i<result1.size() ; i++){
            if(result1[i] != result2[i]) return false;
        }
        return true;
    }
};