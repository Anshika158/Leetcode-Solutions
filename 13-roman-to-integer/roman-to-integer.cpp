class Solution {
public:
    int romanToInt(string s) {
        map<char , int> mpp;
        mpp.insert({'I' , 1});
        mpp.insert({'V' , 5});
        mpp.insert({'X' , 10});
        mpp.insert({'L' , 50});
        mpp.insert({'C' , 100});
        mpp.insert({'D' , 500});
        mpp.insert({'M' , 1000});
        
        int answer=0;
        for(int i=0 ; i <s.size() ; i++){
            if(i+1<s.size() && mpp[s[i]]<mpp[s[i+1]]){
                answer+=mpp[s[i+1]]-mpp[s[i]];
                i++;
            }else{
                answer+=mpp[s[i]];
            }
        }
        return answer;
    }
};














// class Solution {
// public:
//     int romanToInt(string s) {
//         map<char , int > mpp;
//         mpp.insert({'I' , 1});
//         mpp.insert({'V' , 5});
//         mpp.insert({'X' , 10});
//         mpp.insert({'L' , 50});
//         mpp.insert({'C' , 100});
//         mpp.insert({'D' , 500});
//         mpp.insert({'M' , 1000});

//         int answer=0;
//         for(int i=0 ; i<s.size() ; i++){
//             if(i+1 < s.size() && mpp[s[i]]<mpp[s[i+1]]){
//                 answer+= mpp[s[i+1]]-mpp[s[i]];
//                 i++;
//             }else{
//                 answer+=mpp[s[i]];
//             }
//         }
//         return answer;
//     }
// };    