class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        if(k==1) return max(cardPoints[0] , cardPoints[size-1] );
        if(k==size) return accumulate(cardPoints.begin() ,cardPoints.end()  ,0);
        int l=0 , r=cardPoints.size() , lSum = 0 , rSum=0;
        while(l<k){
            lSum = lSum + cardPoints[l];
            l++;
        }
        int maxsum = lSum;
        for(int i = 0 ; i<k ; i++){
         lSum -= cardPoints[k-i-1];
         rSum += cardPoints[size-1-i];  
         maxsum = max(maxsum ,lSum+ rSum);
        }
         
        return maxsum;
    }
};