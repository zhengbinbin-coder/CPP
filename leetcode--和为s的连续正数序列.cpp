https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/submissions/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 定义结果集
        vector<vector<int>> result;
        //不考虑负数情况
        //定义两个位置，表示起始和结束，low和high之间就是一段连续递增的序列
        //两个点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
        //采用闭区间方式进行解决

        // begin和end即是区间也是具体数值
        int begin = 1;
        int end = 2;

        while(begin<end)    // 至少包含两个数
        {
            // 1.求和  公式：(a0+an)* n/2,闭区间[begin,end]
            int sum = (begin+end)*(end-begin+1)/2;
            // 2.比较
            // 若这段序列的和sum==给定值，说明这段序列满足条件
            if(sum==target)
            {
                // 找到了一组,把begin-end这段区间的值插入到一个数组中
                vector<int> tmp;
                //这里是<= 要将[begin,end]包含begin和end插入到这个满足条件的序列tmp中
                for(int i=begin;i<=end;++i)     
                {
                    tmp.push_back(i);
                }
                // 再把这个数组插入到结果集中
                result.push_back(tmp);
                // 已经将以begin开始的序列插入了结果集，不可能再有以begin开始的序列满足条件，所以++begin从下一个位置继续找
                begin++;
            }
            // 若这段序列的和sum > 给定值，说明这段序列的和已经超了，将begin后挪，缩小区间
            else if(sum>target)
            {
                begin++;
            }
            // 若这段序列的和sum < 给定值，说明这段序列的和还不够sum，将end再后挪，扩大区间
            else
            {
                end++;
            }
        }
        return result;
    }
};