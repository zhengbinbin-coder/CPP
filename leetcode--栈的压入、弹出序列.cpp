https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty()||popped.empty())  return true;
        if(pushed.size()!=popped.size())    return false;
        
        stack<int> st;
        int i=0;
        int j=0;

        for(;i<pushed.size();++i)
        {
            // 向栈里压入一个压入序列的元素
            st.push(pushed[i]);

            // 当栈不为空并且栈顶元素=弹出序列当前元素时，出栈并将弹出序列当前位置向后移
            while(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                ++j;
            }
        }
        // 最后若栈刚好为空,则压入与弹出序列能对应，否则无法对应
        return st.empty();
    }
};