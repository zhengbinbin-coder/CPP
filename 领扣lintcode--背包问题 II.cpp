https://www.lintcode.com/problem/backpack-ii/description
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        // 动态规划
        // 若背包容量<1 或 体积数组为空 或 价值数组为空，直接返回0
        if(m<1 || A.empty() || V.empty())   return 0;
        // 设置初始状态(多加一行一列)
        int N = A.size()+1;
        int M = m+1;
        
        //初始化所有位置为0。第一行和第一列都为0--初始条件
        //第一行都为0表示前0个商品的价值，第一列都为0表示背包容量为0时，所能装的商品的价值
        vector<vector<int>> result(N,vector<int>(M,0));
        
        for(int i = 1;i<N;++i)
        {
            for(int j =1;j<M;++j)
            {   
                //第i个商品在A中对应的索引为i-1: i从1开始
                //如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
                if(A[i-1]>j)
                {
                    result[i][j]=result[i-1][j];
                }
                //如果可以装下，分两种情况，装或者不装
                //如果不装，则即为(i-1, j)
                //如果装，需要腾出放第i个物品大小的空间： j - A[i-1],
                //装入之后的最大价值即为(i - 1,j - A[i-1]) + 第i个商品的价值V[i - 1]
                //最后在装与不装中选出最大的价值
                else
                {
                    int newValue = result[i-1][j-A[i-1]]+V[i-1];
                    result[i][j]=max(newValue,result[i-1][j]);
                }
            }
        }
        return result[N-1][m];
    }
};