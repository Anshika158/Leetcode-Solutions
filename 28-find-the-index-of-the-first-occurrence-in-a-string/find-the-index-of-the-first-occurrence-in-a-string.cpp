class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();
        if(n==0) return -1;
        // if(n==1){
        //     for(int i=0 ; i<m ; i++){
        //         if(haystack[i]==needle[0]){
        //             return i;
        //         }
        //     }
        // }
        for(int i=0 ; i<m ; i++){
           int j=0;
           while(j<n && haystack[i+j]==needle[j]){
            j++;
           }
           if(j==n) return i;
        }
        return -1;
    }
};