class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size() , n=needle.size();

        int i=0;
        for(int i=0 ; i<m ; i++){
            int j=0;
            while(j<n && haystack[i+j]==needle[j]){  
                //i++; as it will not return the first index
                j++;
            }
            if(j==n) return i;
        }
        return -1;
    }
};
















//class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n=needle.size();
//         int m=haystack.size();
//         if(n==0) return -1;
//        
//         for(int i=0 ; i<m ; i++){
//            int j=0;
//            while(j<n && haystack[i+j]==needle[j]){
//             j++;
//            }
//            if(j==n) return i;
//         }
//         return -1;
//     }
// };