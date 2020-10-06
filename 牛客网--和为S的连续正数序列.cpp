https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        // 定义结果集
        vector<vector<int>> result;
        //不考虑负数情况
        //定义两个位置，表示起始和结束，low和high之间就是一段连续递增的序列
        //两个点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
        //采用闭区间方式进行解决
        
        // low和high即是区间也是具体数值
        int low=1;
        int high=2;
        
        while(low<high)    // 至少包含两个数
        {
            // 1.求和  公式：(a0+an)* n/2,闭区间[low,high]
            int total = (low+high)*(high-low+1)/2;
            // 2.比较
            // 若这段序列的和total==给定值，说明这段序列满足条件
            if(sum==total)
            {
                // 找到了一组,把low-high这段区间的值插入到一个数组中
                vector<int> tmp;
                for(int i = low; i <= high; ++i)
                {
                    tmp.push_back(i);
                }
                // 再把这个数组插入到结果集中
                result.push_back(tmp);
                // 已经将以low开始的这段序列插入到了结果集，就不可能再有以low开始的序列满足条件，所以++low，从下一个位置继续找
                ++low;
            }
            // 若这段序列的和total < 给定值，说明这段序列的和还不够sum，将high再后挪，扩大区间
            else if(sum>total)
            {
                high++;
            }
            // 若这段序列的和total > 给定值，说明这段序列的和已经超了，将low后挪，缩小区间
            else
            {
                low++;
            }
        }
        return result;
    }
};