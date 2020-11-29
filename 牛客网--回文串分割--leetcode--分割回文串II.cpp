https://www.nowcoder.com/practice/1025ffc2939547e39e8a38a955de1dd3?

https://leetcode-cn.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    
    //判断是否回文串
    bool isPal(string& s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    int minCut(string s) {
        // write code here
        if(s.length()==0)    return 0;
        int len = s.size();
        
        vector<int> cut;
        // F(i)初始化
        // F(0）= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果
        for(int i = 0; i < len+1; ++i)
        {
            cut.push_back(i-1);
        }
        
        for(int i = 1; i < len+1; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                // F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串
                // 从最长串判断，如果从第j+1到i为回文字符串
                // 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
                if(isPal(s,j,i-1))
                {
                    cut[i]=min(cut[j]+1,cut[i]);
                }
            }
        }
        return cut[len];
    }
};