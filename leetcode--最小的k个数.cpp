https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 思路：建含有k个元素的大堆，遍历比较vector中的元素，比堆顶元素小就入堆
        // 设置返回数组
        vector<int> v;
        if(k<=0||k>arr.size()||arr.size()==0)   return v;

        // 设置一个优先级队列，STL中的优先级队列默认是大堆，最小topK问题刚好要用大堆
        priority_queue<int> q;
        // 循环遍历给的n个数
        for(int i = 0; i < arr.size(); ++i)
        {
            // 前k个直接入队
            if(i<k)
            {
                q.push(arr[i]);
            }
            else
            {
                // 剩下的和堆顶元素比较，若小于堆顶元素就把堆顶元素删除，再将此元素入队
                if(arr[i]<q.top())
                {
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }
        // 循环遍历将优先级队列(大堆)中的元素尾插入返回数组
        for(auto i = 0; i < k; ++i)
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};