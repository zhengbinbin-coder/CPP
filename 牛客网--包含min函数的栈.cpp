https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?
class Solution {
public:
    void push(int value) {
        _st.push(value);
        if(_min.empty()||_min.top()>=value)
        {
            _min.push(value);
        }
    }
    void pop() {
        int x=_st.top();
        _st.pop();
        if(_min.top()==x)
        {
            _min.pop();
        }
    }
    int top() {
        return _st.top();
    }
    int min() {
        return _min.top();
    }
private:
    stack<int> _st;
    stack<int> _min;
};