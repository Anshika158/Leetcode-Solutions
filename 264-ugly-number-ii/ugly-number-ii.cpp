class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        int i1 , i2 ,i3 ;
        i1=i2=i3=1;

        arr[1]=1;
        for(int i=2 ; i<=n ; i++){
            int ugly1 = arr[i1]*2;
            int ugly2 = arr[i2]*3;
            int ugly3 = arr[i3]*5;
            
            int minUgly=min({ugly1 , ugly2 , ugly3});
            arr[i]=minUgly;
            //updating the pointer
            if(minUgly==ugly1) i1++;
            if(minUgly==ugly2) i2++;
            if(minUgly==ugly3) i3++;

        }
        return arr[n];
    }
};