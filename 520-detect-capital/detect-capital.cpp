class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(char &ch : word ){
            if(isupper(ch)) count++;
        }
        if(count==0 || count==word.size() || (count==1 && isupper(word[0]))) return true;

        return false;
    }
};
//class Solution {
// public:
//     bool detectCapitalUse(string word) {
//         if(all_of(word.begin() , word.end() , :: isupper)){
//             return true;
//         }
//         if(all_of(word.begin() , word.end() , :: islower)){
//             return true;
//         }
//         if(isupper(word[0]) && all_of(word.begin()+1 , word.end() , ::islower )){
//             return true;
//         }
//         return false;
//     }
// };