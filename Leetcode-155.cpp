/*
 * Problem 155: Min Stack
 * Language: C++
 */
class MinStack {
private:
    long long mini;
    stack<long long> s;
public:
    MinStack() {
    }
    
    void push(int value) {
        if(s.empty()){
            mini = value;
            s.push(value);
        }else if(mini <= value){
            s.push(value);
        }else{
            s.push(2LL * value - mini);
            mini = value;
        }
    }
    // -2 0 -3 + - / +
    
    void pop() {
        if(s.empty()) return;
        long long value = s.top(); s.pop();
        if(value < mini){
            mini = 2*mini-value;
        }
    }
    
    int top() {
        long long value = s.top();
        if(value < mini) return mini;
        return value;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */