class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int m=s.size();
        int n=goal.size();
        if(m!=n) return false;
        if(m<2) return false;
        
        if(s==goal){
            //check for duplicates (if duplicates is their we can swap it as char in s and goal are same e.g s=aa and goal = aa)
            vector<int>freq(26,0);
            for(int i=0 ; i<m ; i++){
                freq[s[i]-'a']++;
                if(freq[s[i]-'a']>1) return true;
            }
            return false;
        }
        vector<int>diff;
        for(int i= 0 ;i<m ; i++){
            if(s[i]!=goal[i]) diff.push_back(i);
        }
        return (diff.size()==2 && s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]]);
    }
};