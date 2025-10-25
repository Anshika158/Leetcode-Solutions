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

// //same logic using less loop 
// class Solution{
//     public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
//         int m = word1.size() , n = word2.size();
//         int w1l=0 , w2l=0 , i=0 , j=0 ;
//         while(w1l<m && w2l<n){
//             if(word1[w1l][i]!=word2[w2l][j]) return false;
//             i++;
//             j++;
//             if(i==word1[w1l].size()){
//                 i=0;
//                 w1l++;
//             }
//             if(j==word2[w2l].size()){
//                 j=0;
//                 w2l++;
//             }
//         }
//         return true;
//     }
// };