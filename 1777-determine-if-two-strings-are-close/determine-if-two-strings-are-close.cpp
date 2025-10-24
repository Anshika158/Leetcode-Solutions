class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        int n1=word1.size();
        int n2=word2.size();
        vector<int>st1(26,0);
        vector<int>st2(26,0);
        for(int i=0 ; i<n1 ; i++){
            st1[word1[i]-'a']++;
            st2[word2[i]-'a']++;
        }
        
        for(int i=0 ; i<26 ; i++){
            if(st1[i]==0 && st2[i]==0)continue;
            if(st1[i]!=0 && st2[i]!=0)continue;
            return false;
        }
        sort(st1.begin() , st1.end());
        sort(st2.begin() , st2.end());
        return st1==st2;
    }
};