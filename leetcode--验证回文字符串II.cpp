https://leetcode-cn.com/problems/valid-palindrome-ii/
class Solution {
public:
    // 判断是否为回文串
    bool isPalindrome(string& s,int i,int j)
    {
        while(i<j)
        {
            // 当前下标小于后下标时，比较前后下标的元素，再把前下标后挪，后下标前挪
            // 若不相等直接跳出循环，返回false
            if(s[i]!=s[j])
            {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left=0;             // 定义左下标
        int right=s.size()-1;   // 定义右下标
        // 判断s是否为回文串
        while(left<right)
        {
            // 当左下标对应字符==右下标对应字符时，将左下标后挪，右下标前挪
            if(s[left]==s[right])
            {
                ++left;
                --right;
            }
            else
            {
                break;
            }
        }
        // 走出循环后，若左下标 超过或等于 右下标，则说明s是回文串，直接返回true
        if(left>=right)     return true;

        // 否则，若删掉左下标或右下标处的字符后，剩余字符为回文串，也可满足题意
        return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
    }
};