class Solution {
public:
    int countDigits(int num) {
        int count=0;
        int digit;
        int original=num;
        while(num>0){
            digit=num%10;
            if(digit!=0 && original%digit==0) count++;
            num/=10;
        }
        return count;
    }
};