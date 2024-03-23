class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        int len = size+1;
        vector<int>temp(len);
        for(int i =0 ; i<len ; i++){
            temp[i]=i;
        }
        
        sort(nums.begin() , nums.end());
        int j;
        for(j =0 ; j<size ; j++){
            if(nums[j]==temp[j]){
                continue;
            }
            else{
                return temp[j];
                
            }
        }
        return size;
    }
};