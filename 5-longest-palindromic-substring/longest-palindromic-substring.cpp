class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0 , maxl=0;
       for(int i=0 ; i<n ; i++){
        int left=i , right=i;
        while(left>=0 && right< n && s[left]==s[right] ){
            if(right-left+1 > maxl){
                start=left;
                maxl=right-left+1;
            }
            left--;
            right++;
        }
        // for even cases
        left=i ; right = i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1 > maxl){
                start=left;
                maxl=right-left+1;
            }
            left--;
            right++;
        }
       }
       return s.substr(start , maxl);
    }
};