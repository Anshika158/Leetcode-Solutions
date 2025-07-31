class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
            for(int i=0 ; i<s.size() ; i++){
                char first=s[0];
                s.erase(s.begin());
                s.push_back(first);
                if(s==goal){
                    return true;
                }
            }
        return false;

        // OPTIMAL APPROACH
        //return (s.size() == goal.size() && (s+s).find(goal)!=string::npos);
    }
};