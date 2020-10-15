https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
https://leetcode-cn.com/problems/reverse-words-in-a-string/
class Solution {
public:
    // 字符串逆置函数
    void ReverseString(string& str,int begin,int end)
    {
        while(begin<end)
        {
            swap(str[begin],str[end]);
            ++begin;
            --end;
        }
    }
    string reverseWords(string s) {
        // 解决思路：先以空格为单位将每个单词逆置，再整体逆置,再删除多余的空格
        // 若s长度为0，直接返回
        if(s.size()==0)    return s;
        
        // 定义两个指针标记单个单词的头尾
        int i=0;
        int j=0;
        // 计算s长度
        int len=s.size();
        while(j<len)
        {
            // 当单个单词的尾指针小于s长度，并且尾指针不为空格时，后挪尾指针，直到遇到空格
            while(j<len && !isspace(s[j]))    j++;
            // 逆置这个单词
            ReverseString(s,i,j-1);
            // 当单个单词的尾指针小于str长度，并且尾指针为空格时，后挪尾指针，跳过所有空格，直到遇到新单词的首个字符
            while(j<len && isspace(s[j]))    j++;
            // 把新单词的收个字符位置交给头指针，继续循环找这个单词
            i=j;
        }
        // 找到最后一个单词后，尾指针已经因＞str的长度而跳出循环，还未逆置，因此将它逆置
        ReverseString(s,i,j-1);

        // 把所有单个单词已经逆置完的字符串->头上的空格全部删除
        int m=0;
        while(isspace(s[m]))
        {
            s.erase(m,1);
        }
        // 重新计算字符串长度
        int len1= s.size();
        // 再将整个字符串整体逆置
        ReverseString(s, 0,len1-1);

        // 再把整体逆置后的字符串->头上的空格全部删除
        int n=0;
        while(isspace(s[n]))
        {
            s.erase(n,1);
        }

        // 再重新计算长度，把字符串中连续的空格删到只剩下一个
        int len2= s.size();
        int k=0;
        while(k<len2)
        {
            // 若k位置和k+1位置都为空格，则删除k位置的空格
            // 此时k+1位置的挪到了k位置，因此不能++k，而是要继续判断
            if(isspace(s[k]) && isspace(s[k+1]))
            {
                s.erase(k,1);
            }
            // 只有不符合k位置和k+1位置都为空格这个条件时，才能++k
            else
            {
                ++k;
            }
        }
        return s;
    }
};