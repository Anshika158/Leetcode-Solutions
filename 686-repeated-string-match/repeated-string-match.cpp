class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count=1;
        string repeated = a;
        while(b.size()>repeated.size()){
            repeated+=a;
            count++;
        }
        if(repeated.find(b)!=string::npos){
            return count;
        }
        repeated+=a;
        count++;
        if(repeated.find(b)!=string::npos){
            return count;
        }
        return -1;
    }
};