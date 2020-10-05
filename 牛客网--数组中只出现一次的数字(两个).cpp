https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // 先整体异或，异或结果一定不为0
        // 而其中为1的比特位，要找的两个数据该位置上的数据一定不同(异或：相同为0，不同为1)，所以我们可以用该比特位进行分组
        // 分组的结果一定是，相同数据被分到了同一组，不同数据一定被分到了不同的组

        // 1.先整体异或
        int result = data[0];
        for(auto i=1; i<data.size(); ++i)
        {
            result ^= data[i];
        }
         
        // 2.找到第一个比特位为1的二进制位
        int flag = 1;        // 00000000 00000000 00000000 00000001
        int len = sizeof(int)*8;
        for(int i = 0; i < len; ++i)
        {
            if(((flag << i) & result))
            {
                flag <<= i;    // flag<<=i后，第i位为1
                break;
            }
        }
         
        // 3.分组异或
        *num1 = 0;
        *num2 = 0;
        for(int j = 0; j < data.size(); ++j)
        {
            // flag中为1的位，在data[j]中为0，将其分为同一组，依次异或，得到第一个只出现一次的数
            if((data[j] & flag))
            {
                *num1 ^= data[j];
            }
            // flag中为1的位，在data[j]中为1，将其分为同一组，依次异或，得到第二个只出现一次的数
            else
            {
                *num2 ^= data[j];
            }
        }

    }
};