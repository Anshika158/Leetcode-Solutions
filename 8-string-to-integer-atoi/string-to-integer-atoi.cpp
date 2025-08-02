class Solution {
public:
    int myAtoi(string s) {
        long long result=0;
        int i=0 ;
        int n =s.size();
        int sign=1;
        while(i<n && s[i]==' ' && s[i]!='-' && s[i] != '+' ){
            i++;//i=5
        }
        if( (s[i]=='-' || s[i]=='+')){
            sign= (s[i]=='-')?-1:1;//sign = -1
            i++;
        }
        while(i<n && isdigit(s[i])){
            result=result*10+(s[i]-'0');//res =4 * 10 + 2 = 42
            // if(result > INT_MAX){
            //     while(result > INT_MAX){
            //         result /=10;
            //     }
            // }
            // else if(sign*result < INT_MIN){
            //     while(sign*result < INT_MIN){
            //         result *=10;
            //     }
            // }
            if(sign*result>INT_MAX)return INT_MAX;
            if(sign*result<INT_MIN)return INT_MIN;

            i++;
        }
    return result*sign;
    }
};