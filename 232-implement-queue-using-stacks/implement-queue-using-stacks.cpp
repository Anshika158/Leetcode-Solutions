class MyQueue {
    private: stack <int> input , output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        cout<<"the element pushed is "<<x <<endl;
        input.push(x);

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        if(input.empty()){
            cout<<"The stack is empty"<<endl;
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
       if(input.empty()){
        cout<<"The stack is Empty"<<endl;
        exit(0);
       }
       int val =input.top();
       return val;
    }
    
    bool empty() {
        return input.empty();
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