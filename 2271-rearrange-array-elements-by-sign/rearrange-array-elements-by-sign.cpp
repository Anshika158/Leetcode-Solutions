// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int positiveC = 0;
//         int negativeC = 0;
//         int n=nums.size();
//         for(int i=0 ; i<n ; i++){
//             if(nums[i]>0) positiveC++;
//             else negativeC++;
//         }
//         if(positiveC != negativeC) return nums;


//         vector<int>p;
//         vector<int>neg;
//         for(int i=0 ; i<n ; i++){
//             if(nums[i]>0)p.push_back(nums[i]);
//             else neg.push_back(nums[i]); 
//         }
//         for(int i=0 ; i<n/2 ; i++){
//             nums[2*i]=p[i];
//             nums[2*i+1]=neg[i];
//         }
//     return nums;
//     }
// };

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveC = 0;
        int negativeC = 0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i]>0) positiveC++;
            else negativeC++;
        }
        if(positiveC != negativeC) return nums;
        vector<int>ans(n , 0);
        int pId = 0 ;
        int nId =1 ;
        for(int i=0 ; i<n ; i++){
            if(nums[i]<0){
                ans[nId]=nums[i];
                nId+=2;
            }else{
                ans[pId]=nums[i];
                pId+=2;
            }
        }
        return ans;
    }
};