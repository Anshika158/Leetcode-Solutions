class Solution {
public:
    bool isSubsequence(string s, string t) {

//FOR SMALL TEST CASES
        // int i=0 , n1=s.size();
        // int j=0 , n2=t.size();

        // while(i<n1 && j<n2){
        //     if(s[i]==t[j]){
        //         i++;
        //     }
        //     j++;
        // }
        // return i==s.size();

// FOR LARGE TESTCASES OR WHERE MULTIPLE S ARE THERE
        int m=s.size();
        int n=t.size();

        int prev=-1;

        map<char ,vector<int>>mp;

        for(int i=0; i<n ; i++){
            mp[t[i]].push_back(i);
        }

        for(int i=0 ; i<m ; i++){
            char ch = s[i];
            if(mp.find(ch)==mp.end()) return false;
            
            vector<int>indices(mp[ch]);
            auto it = upper_bound(begin(indices) ,end(indices) , prev);

            if(it==indices.end()) return false;

            prev=*it;
        }
        return true;
    }
};