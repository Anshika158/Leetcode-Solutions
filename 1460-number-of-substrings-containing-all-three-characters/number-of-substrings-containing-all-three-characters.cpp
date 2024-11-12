
    



class Solution {
public:
    int numberOfSubstrings(string s) {
        // int count = 0;
        // int n=s.size();
        // for(int i = 0 ; i<s.size() ; i++){
        //     int hash[3]={0};
        //     for(int j=i ; j<s.size() ; j++){
        //         hash[s[j]-'a']=1;
        //         if(hash[0]+hash[1]+hash[2]==3){
        //             count = count + (n-j);
        //             break;
        //         }
        //     }
        // }
        // return count;

        //BRUTE FORCE APPROACH
        
        int count = 0;
        int n=s.size();
        int lastSeen[3]={-1,-1,-1};
        for(int i = 0 ;i<n ; i++){
             lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
               int minLastSeen =  min({lastSeen[0],lastSeen[1],lastSeen[2]});
               count += (1+minLastSeen);
            }
        }
        return count;
        
    }
};