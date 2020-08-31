https://leetcode-cn.com/problems/min-stack/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _st.push(x);
        if(_min.empty()||_min.top()>=x)
        {
            _min.push(x);
        }
    }
    
    void pop() {
        int x = _st.top();
        _st.pop();
        if(_min.top()==x)
        {
            _min.pop();
        }
    }
    
    int top() {
        return _st.top();
    }
    
    int getMin() {
        return _min.top();
    }
private:
    stack<int> _st;
    stack<int> _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */