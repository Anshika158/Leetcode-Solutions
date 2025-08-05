class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0 ||n==1) return n;
        int i=1;
        int count=0;
        while(i<=n){ //1<3   
              // 3>1
                n= n-i;   // 3-1 = 2    n==2 
                count++; //count=1  
            
            i++;  //i=2  
        }
        return count;
    }
};