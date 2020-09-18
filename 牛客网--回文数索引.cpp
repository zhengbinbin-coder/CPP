https://www.nowcoder.com/practice/b6edb5ca15d34b1eb42e4725a3c68eba?
#include<iostream>
#include<string>

using namespace std;

//验证是否为回文串
bool IsPalindrome(string s,int* begin,int* end)
{
    int i=0;
    int j=s.size()-1;
    bool flag=true;
    while(i<j)
    {
        // 当前下标小于后下标时，比较前后下标的元素，再把前下标后挪，后下标前挪
        // 若不相等直接跳出循环，将标志置为false
        if(s[i]!=s[j])
        {
            flag=false;
            break;
        }
        ++i;
        --j;
    }
    // 输出型参数，用作外部使用
    if(begin!=nullptr)    *begin=i;
    if(end!=nullptr)    *end=j;
    return flag;
}

int main()
{
    int n=0;
    cin>>n;        // 输入测试的字符串的个数
    while(n)   
    {
        string s;
        cin>>s;    // 当个数没减到0时，一直输入字符串
        int begin=0;
        int end=s.size()-1;
        // 输入一个字符串后，就判断是否是回文串，若是，直接输出-1
        if(IsPalindrome(s,&begin,&end))
        {
            cout<<-1<<endl;
        }
        else
        {
            // 若不是回文串，删掉end位置的字符
            s.erase(end,1);
            // 因为总会有一个合法的解，所以若删掉end位置的字符后是回文串，则输出end位置的下标，否则输出begin位置的下标
            if(IsPalindrome(s,nullptr,nullptr))
            {
                cout<<end<<endl;
            }
            else
            {
                cout<<begin<<endl;
            }
        }
        --n;
    }
    return 0;
}