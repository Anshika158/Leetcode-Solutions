// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.length()==0){
//             return 0;
//         }
//         int maxAns = INT_MIN;
//         for(int i=0 ;i<s.length() ; i++){
//             unordered_set<int> hashmap;
//             for(int j=i ; j<s.length();j++){
//                 if(hashmap.find(s[j]) != hashmap.end()){
//                     maxAns=max(maxAns , j-i);
//                     break;
//                 }
//                 hashmap.insert(s[j]);
//             }
//         }
//     return maxAns;
//     }
// };

//OPTIMIZED SOLUTION 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int maxans = INT_MIN;
        int left=0 ; 
        unordered_set<int> set;
        for(int right = 0 ; right<s.length() ; right++){
            if(set.find(s[right])!=set.end()){
                while(left<right && set.find(s[right])!=set.end()){
                    set.erase(s[left]);
                    left++;
                }
            }
            set.insert(s[right]);
            maxans=max(maxans, right-left+1);
        }
        return maxans;
    }
};