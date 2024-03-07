class Solution {
public:
    int fib(int n) {
     if(n==0 ){
         return 0 ;
     }
     if (n==1){
         return 1;
     }
     int temp ;
     int t0=0;
     int t1=1;
     int i;
     for (i=2 ; i<=n ; i++){
         temp=t0+t1;
         t0=t1;
         t1=temp;
     }
     return temp;
       
    }
};