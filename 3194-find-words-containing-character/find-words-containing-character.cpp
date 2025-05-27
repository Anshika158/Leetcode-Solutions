class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size(); vector<int>ans;
        for(int i=0 ; i<n ; i++){
            for(char y : words[i]){
             if(x==y){
                ans.push_back(i);
                break;
             }
            }
        }
        return ans;
    }
};