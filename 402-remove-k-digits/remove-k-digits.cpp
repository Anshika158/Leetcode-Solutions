class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string result = "";

        for(char digit : num){
            while(!result.empty() && k > 0  && result.back()>digit){
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        // if there are still digit left to remove we will remove it from the end
        while(k>0 && !result.empty()){
            result.pop_back();
            k--;
        }
        //remove the leading zeros 
        while(!result.empty() && result[0]=='0'){
            result.erase(result.begin());
        }
        size_t nonZeroIndex = result.find_first_not_of('0');
        result = (nonZeroIndex == string::npos)?"0":result.substr(nonZeroIndex);
        return result;
    }
};