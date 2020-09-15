https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        // 动态规划
        if(array.size()==0)    return -1;
        
        int sum=array[0];        // 定义以第i个元素结尾的连续字串最大和sum--初始把sum设为以第0个元素结尾的连续字串最大和
        int maxsum=array[0];     // 保存出现过的所有连续字串和中最大的
        for(int i=1;i<array.size();++i)
        {
            // 如果以第i-1个元素结尾的连续子串和大于0，则以第i个元素结尾的连续子串和为：以第i-1个元素结尾的连续子串和+第i个元素
            // 否则，以第i个元素结尾的连续子串和为：第i个元素(加一个小于0的数会变小)
            sum=sum>0?sum+array[i]:array[i];
            
            // 若以第i个元素结尾的连续子串和>当前保存的所有连续字串和中最大的，则用以第i个元素结尾的连续子串和替换，否则不换
            maxsum=sum>maxsum?sum:maxsum;
        }
        // 返回保存的所有连续字串和中最大的
        return maxsum;
    }
};