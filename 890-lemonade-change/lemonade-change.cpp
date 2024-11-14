class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size=bills.size();
       // unordered_map<int , int> mpp;
        int fiveCount=0 , tenCount=0 ;
        for(int bill:bills){
            if(bill==5){
                fiveCount++;
            }else if(bill==10){
                if(fiveCount>0){
                    fiveCount--;
                    tenCount++;
                }else return false;
            }else if(bill==20){
                if(tenCount>0 &&fiveCount>0){
                    tenCount--;
                    fiveCount--;
                }else if(fiveCount>=3){
                    fiveCount=fiveCount-3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};