https://www.nowcoder.com/practice/ed2923e49d3d495f8321aa46ade9f873?

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return int整型
     */
    int numDistinct(string S, string T) {
        // write code here
        int row = S.size();
        int col = T.size();
        
        if(col==0)    return 1;
        if(row==0)    return 0;
        
        vector<vector<int>> numD(row+1, vector<int>(col+1, 0));
        // 初始化：F(i,0) = 1
        for(int i = 0; i <= row; ++i)    numD[i][0]=1;
        
        for(int i = 1; i <= row; ++i)
        {
            for(int j = 1; j <= col; ++j)
            {
                // 若S的第i个字符和T的第j个字符相同
                // 则把numD[i][j]更新为 从S的前i-1个字符中找T的前j-1个字符 加上 从S的前i-1个字符中找T的前j个字符
                if(S[i-1] == T[j-1])
                    numD[i][j] = numD[i-1][j-1] + numD[i-1][j];
                // 否则，说明S的第i个字符与T的第j个字符不同，则numD[i][j]的值退化为 从S的前i-1个字符中找T的前j个字符
                else
                    numD[i][j] = numD[i-1][j];
            }
        }
        return numD[row][col];
    }
};