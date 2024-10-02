class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxans = 0;
        int size = s.size();
        if(size==0){
            return 0;
        }
        // if(s==" " || size==1){
        //     return 1;
        // }
        for(int i = 0 ; i<size ; i++){
            unordered_set<char> set;
            for(int j = i ; j<size ; j++){
                if(set.find(s[j]) !=set.end()){
                    maxans = max(maxans  , j-i);
                    break;
                }
                set.insert(s[j]);
            }
            maxans = max(maxans , (int)set.size());
        }
        return maxans;
    }
};