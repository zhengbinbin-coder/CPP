https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?
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
    string ReverseSentence(string str) {
        // 解决思路：先以空格为单位将每个单词逆置，再整体逆置
        // 若str长度为0，直接返回
        if(str.size()==0)    return str;
        
        // 定义两个指针标记单个单词的头尾
        int i=0;
        int j=0;
        // 计算str长度
        int len=str.size();
        while(j<len)
        {
            // 当单个单词的尾指针小于str长度，并且尾指针不为空格时，后挪尾指针，直到遇到空格
            while(j<len && !isspace(str[j]))    j++;
            // 逆置这个单词
            ReverseString(str,i,j-1);
            // 当单个单词的尾指针小于str长度，并且尾指针为空格时，后挪尾指针，跳过所有空格，直到遇到新单词的首个字符
            while(j<len && isspace(str[j]))    j++;
            // 把新单词的收个字符位置交给头指针，继续循环找这个单词
            i=j;
        }
        // 找到最后一个单词后，尾指针已经因＞str的长度而跳出循环，还未逆置，因此将它逆置
        ReverseString(str,i,j-1);
        // 最后再将整个字符串整体逆置
        ReverseString(str, 0, j-1);
        return str;
    }
};
