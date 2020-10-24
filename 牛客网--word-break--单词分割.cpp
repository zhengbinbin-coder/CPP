https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?
#include<unordered_set>
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // 若字符串或单词组为空，直接返回false
        if(s.empty())    return false;
        if(dict.empty())    return false;
        
        // 定义一个存放bool类型的数组，数组第i个元素存放字符串前i个字符能否被分割
        vector<bool> can_break(s.size()+1,false);
        can_break[0]=true;    // 设置初始状态
        
        for(int i=1;i<=s.size();++i)
        {
            for(int j=i-1;j>=0;j--)
            {
                // F(i): true{j <i && F(j) && substr[j+1,i]能在词典中找到} OR false
                // 第j+1个字符的索引为j,所以用substr复制子字符串是从j位置开始复制，总共复制i-j个
                if(can_break[j] && dict.find(s.substr(j,i-j)) != dict.end())
                {
                    can_break[i]=true;
                    break;
                }
            }
        }
        // 返回数组中最后一个元素的bool值
        return can_break[s.size()];
    }
};