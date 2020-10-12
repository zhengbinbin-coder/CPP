https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
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
    string reverseLeftWords(string s, int n) {
        // 若需要左旋的次数=0，或s长度为0，直接return
        if(n==0 || s.size()==0)    return s;
        // 若字符串有6个字符，左旋7次等于左旋1次，因此将n%=字符串长度，得到实际需要左旋的次数
        n %= s.size();
        ReverseString(s,0,n-1);             // 先逆置前半部分
        ReverseString(s,n,s.size()-1);      // 再逆置后半部分
        ReverseString(s,0,s.size()-1);      // 再整体逆置
        return s;
    }
};