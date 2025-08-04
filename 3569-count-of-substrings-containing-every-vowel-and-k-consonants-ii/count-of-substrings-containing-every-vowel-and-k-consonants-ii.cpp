#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' ||ch=='o' ||ch=='u' ;
    }

    long long countOfSubstrings(string word, int k) {

       int n= word.size();

       vector<long long>lastSeen(n);  // store index value where last time consonant is seen
        int lastConsIdx = n;

       for(int i=n-1 ; i>= 0 ; i--){
        char ch = word[i];
         lastSeen[i]=lastConsIdx;
        if(!isVowel(word[i])){
           lastConsIdx=i;
         }
       }
       int cons=0;
       long long i=0 , j=0 ; // pointer for sliding window

       unordered_map<char , int> freq;  // store vowel if map size = 5 we get all vowel

       long long result=0;  // store final result

        while(j<n){
                if(isVowel(word[j])) freq[word[j]]++;
                else  cons++;

                while(cons>k){
                    if(isVowel(word[i])) {
                        freq[word[i]]--;
                        if(freq[word[i]]==0) freq.erase(word[i]);
                    }else{
                        cons--;
                    }
                    i++;
                }
                // window is valid
                while(freq.size()==5 && cons==k){
                    int idx = lastSeen[j];
                    result+= (idx-j);
                    char ch=word[i];
                    if(isVowel(ch)) {
                        freq[ch]--;
                        if(freq[ch]==0) freq.erase(ch);
                    }
                    else{
                        cons--;
                    } 
                    i++;
                }
                j++;
            }
        return result;
    }
};
