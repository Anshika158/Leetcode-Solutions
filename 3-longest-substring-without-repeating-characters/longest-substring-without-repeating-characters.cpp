// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxans = 0;
//         int size = s.size();
//         if(size==0){
//             return 0;
//         }
//         for(int i = 0 ; i<size ; i++){
//             unordered_set<char> set;
//             for(int j = i ; j<size ; j++){
//                 if(set.find(s[j]) !=set.end()){
//                     maxans = max(maxans  , j-i);
//                     break;
//                 }
//                 set.insert(s[j]);
//             }
//             maxans = max(maxans , (int)set.size());
//         }
//         return maxans;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int left =0 , right = 0 ;
        int length = 0;
        int size = s.size();
        while(right<size){
            if(mpp[s[right]] != -1){
                left = max(mpp[s[right]]+1 , left);
            }
                mpp[s[right]]=right;
                length=max(length , right-left+1);
                right++;
            
           
        }
         return length;
    }
};