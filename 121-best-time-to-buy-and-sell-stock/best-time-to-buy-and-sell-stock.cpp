class Solution {
public:
     int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int maxi =0 ;
        // for(int i=0 ; i<n ; i++){
        //     for(int j=i+1 ; j<n ; j++){
        //         if(prices[i]<prices[j]){
        //             maxi=max(maxi , prices[j]-prices[i]);
        //         }
        //     }
        // }
        // return maxi;


        int n=prices.size();
        int mini=INT_MAX;
        int profit=0;
        for(int i=0 ; i<n ; i++){
             mini=min(mini, prices[i]);
             profit=max(profit , prices[i]-mini);
        }
        return profit;
    }
};