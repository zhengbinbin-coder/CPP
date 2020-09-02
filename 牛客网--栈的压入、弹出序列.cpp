https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?
 class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 若两序列有空，或长度不等，直接returnfalse
        if(pushV.size()==0||popV.size()==0||pushV.size()!=popV.size())
            return false;
        stack<int> st;
        int i=0;
        int j=0;
        for(;i<pushV.size();++i)
        {
            // 向栈里压入一个压入序列的元素
            st.push(pushV[i]);
            
            // 当栈不为空并且栈顶元素=弹出序列当前元素时，出栈并将弹出序列当前位置向后移
            while(!st.empty()&& st.top() == popV[j])
            {
                st.pop();
                j++;
            }
        }
        // 最后若栈刚好为空则压入与弹出序列能对应，否则无法对应
        return st.empty();
    }
};