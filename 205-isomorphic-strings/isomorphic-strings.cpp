class Solution {
public:
    bool isIsomorphic(string s, string t) {
    //     set<char> set1;
    //     set<char> set2 ;
    //     for(int i=0  ; i<s.size() ; i++){
    //         set1.insert(s[i]);
    //     }
    //     for(int j=0 ; j<s.size() ;j++){
    //         set2.insert(t[j]);
    //     }
    //     if(set1.size()==set2.size()){
    //         return true;
    //     }
    // return false;
    unordered_map<char , char> mppST;
    unordered_map<char , char> mppTS;
    for(int i=0 ; i<s.size() ; i++){
        if(mppST.find(s[i])!=mppST.end() && mppST[s[i]]!=t[i]){
                return false;
        }
        if(mppTS.find(t[i])!=mppTS.end() && mppTS[t[i]] != s[i]){
            return false;
        }
         mppST[s[i]]=t[i];
         mppTS[t[i]]=s[i];
    }
    return true;
    }
};