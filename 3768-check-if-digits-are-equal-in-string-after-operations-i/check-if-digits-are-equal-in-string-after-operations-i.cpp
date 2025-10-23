class Solution {
public:
    //string check(string r){
    //     int n=r.size();
    //     string res="";
    //     for(int i=1 ; i<n ; i++){
    //         int sum = ((r[i-1]-'0')+(r[i]-'0'))%10;
    //         res+= to_string(sum);
    //     }
    //     return res;
    // }
    bool hasSameDigits(string s) {
    //     string result = s ;
    //     while(result.size()>2){
    //         result=check(result);
    //     }
    //     return result[0]==result[1];
    int n=s.size();
    vector<int>digit(n);
    for(int i=0 ; i<n ; i++){
        digit[i]=s[i]-'0';
    }
    while(n>2){
        for(int i=0; i<n-1 ; i++){
            digit[i]=(digit[i]+digit[i+1])%10;
        }
        n--;
    }
    return digit[0]==digit[1];
    }
};