https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358?
leetcode--不同路径
https://leetcode-cn.com/problems/unique-paths/
class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        // write code here
        // 动态规划
        if(m<1 || n<1)    return 0;
        // 申请m*n的数组，全部初始化为1
        // 从v[0][0]位置 到 第一行任意位置都只有一条路径，到第一列任意位置也只有一条路径
        vector<vector<int>> v(m,vector<int>(n,1));
        // 遍历数组，从第二行开始
        for(int i=1;i<m;++i)
        {
            // 从第二列开始
            for(int j=1;j<n;j++)
            {
                // 从起始到v[i][j]位置的路径个数为到此位置的 同一行上一列位置的路径数 + 同一列上一行位置的路径数
                v[i][j]=v[i-1][j] + v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
};