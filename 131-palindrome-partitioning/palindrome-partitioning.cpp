class Solution {
public:
void findC(int ind , string s , vector<vector<string>>&res , vector<string>&path){
    int n=s.size();
    if(ind==n){
        res.push_back(path);
        return;
    }
    for(int i=ind ; i<n ; i++){
        if(isPalindrome(s,ind,i)){
            path.push_back(s.substr(ind,i-ind+1));
            findC(i+1,s,res,path);
            path.pop_back();
        }
    }
}
bool isPalindrome(string s , int start , int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>path;
        findC(0,s,res,path);
        return res;
    }
};