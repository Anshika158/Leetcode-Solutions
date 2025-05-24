class Solution {
public:
    string triangleType(vector<int>& nums) {
       sort(nums.begin() , nums.end());
       int a = nums[0] , b=nums[1] , c=nums[2];
       if(a+b<=c) return "none";
       set<int> st(nums.begin(), nums.end());
       if(st.size()==1) return "equilateral" ;
       else if(st.size()==2) return "isosceles";
       else return "scalene";
    }
};