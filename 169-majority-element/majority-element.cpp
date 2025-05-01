class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0 ;
        int count = 0 ;
        for(int num : nums){
            if(count == 0){
                candidate=num;
            }
            if(num==candidate){
                count++;
            }else{
                count--;
            }
        }
        int count1=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==candidate){
                count1++;
            }
        }
        if(count1 > (nums.size()/2)){
            return candidate;
        }
        return -1;

    }
};