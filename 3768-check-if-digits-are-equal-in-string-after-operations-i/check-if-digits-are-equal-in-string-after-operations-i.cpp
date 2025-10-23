class Solution {
public:
    string check(string r){
        int n=r.size();
        string res="";
        for(int i=1 ; i<n ; i++){
            int sum = ((r[i-1]-'0')+(r[i]-'0'))%10;
            res+= to_string(sum);
        }
        return res;
    }
    bool hasSameDigits(string s) {
        string result = s ;
        while(result.size()>2){
            result=check(result);
        }
        // int n=s.size();
        // for(int i=1 ; i<n ; i++){
        //     int sum = ((s[i-1]-'0')+(s[i]-'0'))%10;
        //     result+= to_string(sum);
        // }
        return result[0]==result[1];
    }
};