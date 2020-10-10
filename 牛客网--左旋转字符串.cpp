https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?
/*
// 方法一：一位一位地左旋
class Solution {
public:
    // 把字符串左旋一次的函数
    void _LeftRotateString(string& str)
    {
        // 保存第一个字符
        char c = str[0];
        int len = str.size();
        // 将除最后一个字符外的所有字符向左挪一位
        for(int i=0; i<len-1; ++i)
        {
            str[i]=str[i+1];
        }
        // 再将保存的第一个字符放到最后一个字符的位置
        str[len-1]=c;
    }
    string LeftRotateString(string str, int n) {
        // 若需要左旋的次数=0，或str长度为0，直接return
        if(n==0 || str.size()==0)    return str;
        // 若字符串有6个字符，左旋7次等于左旋1次，因此将n%=字符串长度，得到实际需要左旋的次数
        n %= str.size();
        // 左旋n次
        for(int i = 0; i < n; ++i)
        {
            _LeftRotateString(str);
        }
        return str;
    }
};
*/

// 方法二：先局部逆置，再整体逆置
// 示例：     abc123----左移两位
// 划分：     ab  c123
// 分别逆置：  ba  321c
// 整体逆置    c123ab----完成
class Solution {
public:
    // 逆置函数
    void ReverseString(string& str,int begin,int end)
    {
        while(begin<end)
        {
            swap(str[begin],str[end]);
            ++begin;
            --end;
        }
    }
    string LeftRotateString(string str, int n) {
        // 若需要左旋的次数=0，或str长度为0，直接return
        if(n==0 || str.size()==0)    return str;
        // 若字符串有6个字符，左旋7次等于左旋1次，因此将n%=字符串长度，得到实际需要左旋的次数
        n %= str.size();
        ReverseString(str,0,n-1);             // 先逆置前半部分
        ReverseString(str,n,str.size()-1);    // 再逆置后半部分
        ReverseString(str,0,str.size()-1);    // 再整体逆置
        return str;
    }
};