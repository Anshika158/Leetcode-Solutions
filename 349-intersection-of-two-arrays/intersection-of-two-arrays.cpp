class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        for(int i=0 ; i<nums1.size() ; i++){
            st.insert(nums1[i]);
        }
        set<int>result;
        for(int i=0 ; i<nums2.size() ; i++){
            if( st.find(nums2[i]) != st.end()){
                result.insert(nums2[i]);
            }

        }
        return vector<int>(result.begin() , result.end());
    }
};