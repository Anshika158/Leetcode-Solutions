class Solution {
public:
     int maxProfit(vector<int>& prices) {
    //     int maxi=0;
    //     for(int i=0 ; i<prices.size() ; i++){
    //         for(int j=i+1; j<prices.size() ; j++){
    //             if(prices[j]>prices[i]){
    //                  maxi=max(prices[j]-prices[i] ,maxi);
    //             }
    //         }
    //     }
    //     return maxi;

    int maxi = 0;
    int mini = INT_MAX;
    int n = prices.size();
    for(int i=0 ; i<n ; i++){
        mini = min(mini , prices[i]);
        maxi = max(maxi , prices[i]-mini);
    }
    return maxi;
    }
};