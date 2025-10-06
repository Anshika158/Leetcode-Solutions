// class Solution {
// public:
// //USING RECURSION

//     bool isValid(string c){
//         int balance=0;
//         for(char s:c){
//             if(s=='(') balance++;
//             else balance-- ;
//             if(balance<0) return false;
//         }
//         return (balance==0);
//     }
//     void generateAll(string curr , int n , vector<string>&res){
//         if(curr.length()==2*n){
//             if(isValid(curr)){
//                 res.push_back(curr);
//                 return;
//             }
//         }
//         generateAll(curr+'(',n,res);
//         generateAll(curr+')',n,res);
//     }
//     vector<string> generateParenthesis(int n) {
//         //BRUTE FORCE APPROACH
//         vector<string>res;
//         generateAll("",n,res);
//         return res;
//     }
// };

class Solution {
public:
    void backtrack(string curr , int open , int close , int n , vector<string>&res){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n) backtrack(curr+'(' , open+1 , close , n , res);
        if(close<open) backtrack(curr+')' , open , close+1 , n , res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        backtrack("" , 0 , 0 , n , res);
        return res;
    }
};