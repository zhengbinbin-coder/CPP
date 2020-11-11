https://www.nowcoder.com/practice/23462ed010024fcabb7dbd3df57c715e?

https://leetcode-cn.com/problems/minimum-path-sum/submissions/
class Solution {
public:
    /**
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& grid) {
        // write code here
		// 动态规划
        // 如果为空，返回0
        if(grid.empty())    return 0;
        // 获取行和列大小
        int m = grid.size();
        int n = grid[0].size();
        // 定义存放F(i,j)的数组，全部初始化为0
        vector<vector<int>> result(m,vector<int>(n,0));
        // 初始化第一行第一列的元素
        result[0][0] = grid[0][0];
        // 初始化第一行(i=0,j变化)
        for(int j = 1;j<n;++j)
        {
            result[0][j] = result[0][j-1] + grid[0][j];
        }
        // 初始化第一列(j=0，i变化)
        for(int i=1;i<m;++i)
        {
            result[i][0] = result[i-1][0] + grid[i][0];
        }
        // 从第二行开始算起
        for(int i = 1; i<m; ++i)
        {
            // 遍历第i行，从第二列开始算起
            for(int j = 1; j < n; ++j)
            {
                // 到当前元素最小路径 = 到同行上一列元素最小路径 与 到上一行同列元素最小路径 中较小者 + 当前元素值
                result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
            }
        }
        return result[m-1][n-1];
    }
};