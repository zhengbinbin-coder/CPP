https://leetcode-cn.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = (x^y); //按位异或，相同为0不同为1
        int count=0;
        while(n)
        {
            // 按位&计算1的个数
            // if(n&1 == 1)
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