class Solution {
public:
    string frequencySort(string s) {
        //Step 1 count frequencies
        unordered_map<char , int>freq;
        for(char c:s){
            freq[c]++;
        }
        //Step 2 put all the unique char in the vector
        vector<char> vs;
        for(auto &p : freq){
            vs.push_back(p.first);
        }
        //Step 3 Sort them according to their frequencies using frequency map
        sort(vs.begin() , vs.end() ,[&](char a , char b){
            return freq[a]>freq[b];
        });
        //Step 4 Built the String
        string result;
        for(char ch : vs){
            result.append(freq[ch],ch);
        }
        return result;
    }
};