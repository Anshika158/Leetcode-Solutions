class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>st;
        // for(int i=0 ; i<nums.size() ; i++){
        //     st.insert(nums[i]);
        // }
        // int k=st.size();
        // int j=0;
        // for(int x : st){
        //     nums[j++]=x;
        // }
        // return k;
    int n=nums.size();
     int i = 0;
    for (int j = 1; j < n; j++) {
      if (nums[i] != nums[j]) {
      i++;
      nums[i] = nums[j];
      }
    }
      return i + 1;
    }
};