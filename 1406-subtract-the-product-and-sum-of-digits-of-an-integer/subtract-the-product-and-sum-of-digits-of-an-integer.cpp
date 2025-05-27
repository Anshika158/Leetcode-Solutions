class Solution {
public:
    int subtractProductAndSum(int n) {
        int product=1 , sum =0 , num=0;
        while(n>0){
            num=n%10;
            product*=num , sum+=num;
            n=n/10;
        }
        return product-sum;
    }
};