class Solution {
public:
    int characterReplacement(string s, int k) {
        //BRYTE FORCE APPROACH
        int maxf = 0 , maxlen = 0 , changes =0 ;
        for(int i = 0 ; i<s.size() ; i++){
            int hash[26]={0};
            for(int j = i ; j<s.size() ; j++){
                hash[s[j]-'A']++;
                maxf=max(maxf , hash[s[j]-'A']);
                changes= (j-i+1)-maxf;
                if(changes<=k){
                    maxlen=max(maxlen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;

        // int size = s.size();
        // int maxf = 0, maxlen = 0, right = 0, left = 0;
        // int hash[26] = {0};

        // while (right < size) {
        //     hash[s[right] - 'A']++;
        //     maxf = max(maxf, hash[s[right] - 'A']);
        //     int changes = (right - left + 1) - maxf;
        //     while (changes > k) {
        //         hash[s[left] - 'A']--;
        //         left++;
        //         changes = (right - left + 1) - maxf;
        //     }
        //     maxlen = max(maxlen, right - left + 1);
        //     right++;
        // }

        // return maxlen;
    }
};
