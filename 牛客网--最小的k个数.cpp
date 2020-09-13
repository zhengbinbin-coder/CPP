https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // 设置返回数组
        vector<int> v;    
        if(input.size()==0 || k<=0 || k>input.size())
        {
            return v;
        }
        // 设置一个优先级队列，STL中的优先级队列默认是大堆，最小topK问题刚好要用大堆
        priority_queue<int> q;
        // 循环遍历给的n个数
        for(int i=0;i<input.size();++i)
        {
            // 前k个直接入队
            if(i<k)
            {
                q.push(input[i]);
            }
            else
            {
                // 剩下的和堆顶元素比较，若小于堆顶元素就把堆顶元素删除，再将此元素入队
                if(input[i]<q.top())
                {
                    q.pop();
                    q.push(input[i]);
                }
            }
        }
        // 循环遍历将优先级队列(大堆)中的元素尾插入返回数组
        for(int j=0;j<k;++j)
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};