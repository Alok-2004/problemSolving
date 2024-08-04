class MyQueue {
public:

    stack<int>main, helper;

    int reverse(bool remove){
        
        while(!main.empty()){
            helper.push(main.top());
            main.pop();
        }

        int result = helper.top();
        if(remove == true) helper.pop();

        while(!helper.empty()){
            main.push(helper.top());
            helper.pop();
        }

        return result;
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(main.size() == 1){
            int x = main.top();
            main.pop();
            return x;
        }
        else{
            int result = reverse(true);
            return result;
        }
    }
    
    int peek() {
        if(main.size() == 1){
            int x = main.top();
            return x;
        }
        else{
            int result = reverse(false);
            return result;
        }
    }
    
    bool empty() {
        return main.empty();
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
