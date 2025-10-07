class Solution {
public:
    bool hasD(string a , string b){
        int hashM[26]={0};
        for(int i=0 ; i<a.size() ; i++){
            if(hashM[a[i]-'a']>0) return true; //aa bb cc case

            hashM[a[i]-'a']=1;
        }
        for(int i=0 ; i<b.size() ; i++){
            if(hashM[b[i]-'a'] > 0) return true;
        }
        int temp[26]={0};
        for(int i=0 ; i<b.size() ; i++){
            if(temp[b[i]-'a']>0) return true;
            temp[b[i]-'a']=1;
        }
        return false;
    }
    
    int solve(vector<string>&arr ,int idx , int n, string result , unordered_map<string , int>&mpp){
        if(idx==n) return result.length();

        int include=0 ;
        int exclude=0;
        if(mpp.find(result)!=mpp.end()){
            return mpp[result];
        }
        if(hasD(result,arr[idx])){
            exclude=solve(arr,idx+1,n,result,mpp);
        }else{
            include = solve(arr,idx+1,n,result+arr[idx],mpp);

            exclude = solve(arr,idx+1,n,result , mpp);
        }
        return mpp[result]=max(include , exclude);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string result="";
        unordered_map<string , int>mpp;
        return solve(arr , 0 , n , result , mpp);
    }
};