class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int longest=0;
        int n=nums.size();
        int last_small = INT_MIN ;
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]-1 == last_small){
                count++;
                last_small = nums[i];
            }else if(nums[i]!= last_small){
                count=1;
                last_small=nums[i];
            }
            longest=max(longest , count);
        }
        return longest;
    } 
};
