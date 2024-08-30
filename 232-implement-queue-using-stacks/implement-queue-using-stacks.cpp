class MyQueue {
    private: stack <int> input , output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // while(!input.empty()){
        //     output.push(input.top());
        //     input.pop();
        // }
        // cout<<"the element pushed is "<<x <<endl;
        // input.push(x);

        // while(!output.empty()){
        //     input.push(output.top());
        //     output.pop();
        // }

        //Approach 2
        cout<<"The Element is pushed "<<x<<endl;
        input.push(x);
    }
    
    int pop() {
        // if(input.empty()){
        //     cout<<"The stack is empty"<<endl;
        //     exit(0);
        // }
        // int val = input.top();
        // input.pop();
        // return val;

        //Approach 2
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
       if(output.empty()){
        while(input.size()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
       }
       int val =output.top();
       return val;
    }
    
    bool empty() {
        return output.empty()&&input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */