https://leetcode-cn.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            // 按位&计算1的个数
            // if(n & 1 == 1)
            // {
            //     count++;
            // }
            // n>>=1;

            // 每次按位&去除1位1
            n&=(n-1);
            count++;
        }
        return count;
    }
};