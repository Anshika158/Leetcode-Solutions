class Solution {
public:
    unordered_map<string , bool>mp;
    bool isConcat(string word , unordered_set<string>&st){
        int l = word.size();
        if(mp.find(word)!=mp.end()) return mp[word];
        for(int i=0 ; i<l ; i++){
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);
            if((st.find(prefix)!=st.end() && isConcat(suffix , st)) || (st.find(prefix)!=st.end() && st.find(suffix)!=st.end())) return mp[word]=true;

        }
        return mp[word]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st(begin(words),end(words));
        vector<string>result;
        mp.clear();
        int n=words.size();
        for(int i=0 ; i<n ; i++){
            string word = words[i];
            if(isConcat(word , st)){
                result.push_back(word);
            }
        }
        return result;
    }
};