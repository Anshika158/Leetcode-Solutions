class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n= asteroids.size();
        for(int i=0 ; i<n ; i++ ){
            int current= asteroids[i];
            bool destroyed = false;

            while(!st.empty() && st.top()>0 && current<0){

                // case1  : top is greater than current
                if(abs(st.top())==abs(current)){
                    // Both the asteroids will be destroyed
                    st.pop();
                    destroyed=true;
                    break;
                }else if(abs(st.top()) > abs(current) ){
                    destroyed=true;
                    break;
                }else{
                    st.pop();
                }
            }
            if(!destroyed){
                st.push(current);
            }
        }
        vector<int> output(st.size());
        for(int i = output.size()-1 ; i>=0 ; i--){
            output[i]=st.top();
            st.pop();
        }
        return output;

    //     stack <int> st1 , st2 ;
    //     int num =0 ;
    //     int n = asteroids.size();
    //     vector<int> output(n);
    //     int i=0;

    //     asteroids[i]>num ? st1.push(asteroids[i]) : st2.push(abs(asteroids[i]));

    //    while(!st1.empty() && !st2.empty()){
    //     if(st1.top()>st2.top()){
    //         output[i]=st1.top();
    //         i++;
    //         st2.pop();
    //     }else if(st1.top()==st2.top()){
    //         st1.pop();
    //         st2.pop();
    //     }else{
    //         output[i]=st2.top();
    //         i++;
    //         st1.pop();
    //     }
    //    }
    //    return output;



    }
};