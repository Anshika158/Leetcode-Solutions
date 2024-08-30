class MinStack {
public:
    stack<pair<int , int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        int mini;
        if(st.empty()){
            mini=val;
        }else{
            mini=min(st.top().second , val );
        }
        st.push({val,mini});
    }
    
    void pop() {
       st.pop();
        
    }
    
    int top() {
       return st.top().first; 
    }
    
    int getMin() {
        return st.top().second;
    }
};

// //APPROACH 2

// class MinStack {
// public:
//     stack<int> st;
//     int mini;
//     MinStack() {
//         while(st.empty()==false){
//             st.pop();
//         }
//         mini=INT_MAX;
//     }
    
//     void push(int val) {
//         int value = val;
//         if(st.empty()){
//             mini=value;
//             st.push(value);
//         }else{
//             if(value<mini){
//                 st.push(2*val*1LL - mini);
//                 mini=value;
//             }else{
//                 st.push(value);
//             }
//         }  
//     }
    
//     void pop() {
//         if(st.empty()){
//             return ;
//         }
//         int el =st.top();
//         st.pop();
//         if(el<mini){
//             mini = 2*mini - el ;
//         }
//     }
    
//     int top() {
//         if(st.empty()){
//             return -1;
//         }
//         int  el = st.top();
//         if(el<mini){
//             return mini;
//         }
//         return el;
//     }
    
//     int getMin() {
//         return mini;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
