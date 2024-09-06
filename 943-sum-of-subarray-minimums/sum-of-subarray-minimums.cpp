class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      const int MOD = 1e9 + 7;
      int n = arr.size();

      //array to store distances to pervious and next less element
      vector<int> prev(n) , next(n);

      stack <int> st;
      
      // Calculation of less elements (PLE)
      for(int i=0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        prev[i]=st.empty()?i+1 : i-st.top();
        st.push(i);
      }

      //ckear the stack to for next less element
      while(!st.empty()){
        st.pop();
      }

      //calculation of nextless elemnt
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            next[i]=st.empty() ? n-i : st.top()-i;
            st.push(i);
        }  

        //calculate the result
        long long result = 0;
        for(int i=0 ; i<n ; i++){
            result = (result + (long long )arr[i] * prev[i] * next[i]) % MOD;
        }   
        return result; 
    }
};




  // int n = arr.size();
        // int sum = 0 ;
        // int MOD = 1e9 + 7;

        // for(int i= 0 ; i<n ; i++){
        //     for(int j = i ; j<n ; j++){
        //         int minElement=arr[i];
        //         for(int k=i+1 ; k<=j ; k++){
        //             minElement = min(minElement , arr[k]);
        //         }
        //         sum = (sum+minElement)%MOD;
        //     }
        // }
        // return sum;