class Solution {
public:

    const int MOD = 1e9+7;
    long long modFun(long long base , long long exp , int mod){
        long long result = 1;
        while(exp>0){
            if(exp%2==1){
                result = (result*base)%MOD;
            }
            base = (base * base )%MOD;
            exp/=2;
        }
        return result;
        
    }

    int countGoodNumbers(long long n) {

        long long even = (n+1)/2;
        long long odd = n/2;

        long long evenOption = modFun(5 , even , MOD);
        long long oddOption = modFun(4 , odd ,MOD);

        return (evenOption*oddOption)%MOD;

    }
};