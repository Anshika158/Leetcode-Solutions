class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gSize=g.size() , sSize=s.size() ,l=0 , r=0 ;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<sSize && r<gSize){
            if(g[r]<=s[l]){
                r++;
            }
            l++;
        }
        return r;

    }
};