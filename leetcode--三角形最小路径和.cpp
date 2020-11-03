https://leetcode-cn.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 若三角形为空，直接返回0
        if(triangle.empty())    return 0;
        /*
        // 动态规划--自顶向下
        // 定义数组的行
        int row = triangle.size();
        // 直接在原二维数组上计算到达当前位置的最短路径和
        // 第一行元素直接等于到第一行这个点的路径和，从第二行开始遍历
        for(int i =1; i<row;++i)
        {
            // 遍历第i行的每个元素，计算到达这个元素的最短路径
            for(int j=0;j<=i;++j)
            {
                // 如果j=0，说明是这行第一个元素，只能由上一行同一列的元素到达
                if(j==0)
                {
                    triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                }
                // 如果i=j，说明是这行的最后一个元素，只能由上一行上一列的元素到达
                else if(i==j)
                {
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                }
                // 既不是这行第一个元素也不是这行最后一个元素，可以由 上一行上一列元素 和 上一行本列元素 到达
                else
                {
                    triangle[i][j] = min(triangle[i-1][j-1],triangle[i-1][j]) + triangle[i][j];
                }
            }
        }
        // 选出 到达最后一行的各个元素的最短路径和 中的 最小的一个，返回它
        int result = triangle[row-1][0];    // row是行，最后一行下标为row-1
        for(int k = 1; k < row; ++k)
        {
            result = min(triangle[row-1][k], result);
        }
        return result;
        */

        // 动态规划--自底向上
        int line = triangle.size();
        // 从最后一行每个元素 到 最后一行的最短距离 为 这个元素值本身，因此不需要定义初始状态
        // 从倒数第二行开始遍历
        for(int i = line-2; i >= 0; --i)
        {
            // 遍历这行的每个元素,求它们到最后一行的最短距离
            for(int j=0;j<=i;j++)
            {
                // 当前元素到最后一行的最短距离 = 下一行同列元素和下一行下一列元素到最后一行的最短距离中较小者 + 当前元素
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};