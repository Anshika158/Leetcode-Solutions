// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         long long sum=0;
//         int n = nums.size();

//         for(int i=0 ; i<n ; i++){
//             int minval = nums[i] , maxval = nums[i];
//             for(int j=i+1; j<n ; j++){
//                 minval = min(minval , nums[j]);
//                 maxval = max(maxval , nums[j]);

//                 sum+=( maxval - minval );
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n = nums.size();

        long long sumMax = 0 , sumMin = 0 ;

        stack<int> stMaxPrev , stMaxNext;
        vector<int> prevGreater(n) , nextGreater(n);

        //finding previous greater for each element

        for(int i =0 ; i<n ; i++){
            while(!stMaxPrev.empty() && nums[stMaxPrev.top()]<=nums[i]){
                stMaxPrev.pop();
            }
            prevGreater[i]=stMaxPrev.empty()?-1 : stMaxPrev.top();
            stMaxPrev.push(i);
        }

        //finding next greater for each element

        for(int i = n-1 ; i>=0 ; i--){
            while(!stMaxNext.empty() && nums[stMaxNext.top()]<nums[i]){
                stMaxNext.pop();
            }
            nextGreater[i]= stMaxNext.empty() ? n : stMaxNext.top();
            stMaxNext.push(i);
        }

        for(int i=0 ; i< n ; i++){
            int left = i - prevGreater[i];
            int right = nextGreater[i]-i;
            sumMax+= (long long)nums[i]*left*right;
        }

        stack<int> stMinPrev , stMinNext;
        vector<int> prevSmaller(n) , nextSmaller(n);

        //finding previous smaller element
        for(int i = 0 ; i< n ; i++){
            while(!stMinPrev.empty() && nums[stMinPrev.top()]>=nums[i]){
                stMinPrev.pop();
            }
            prevSmaller[i]=stMinPrev.empty() ? -1 : stMinPrev.top();
            stMinPrev.push(i);
        }

        //finding the next smaller element

        for(int i = n-1 ; i>=0 ; i--){
            while(!stMinNext.empty() && nums[stMinNext.top()]>nums[i]){
                stMinNext.pop();
            }
            nextSmaller[i] = stMinNext.empty()? n : stMinNext.top();
            stMinNext.push(i); 
        }

        for(int i = 0 ; i<n ; i++){
            int left = i - prevSmaller[i];
            int right = nextSmaller[i] - i;

             sumMin += (long long )nums[i]*left*right;
        }
        return sumMax-sumMin;
       
    }
};