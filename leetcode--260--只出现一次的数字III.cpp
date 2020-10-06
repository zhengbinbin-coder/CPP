https://leetcode-cn.com/problems/single-number-iii/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 先整体异或，异或结果一定不为0
        // 而其中为1的比特位，要找的两个数据该位置上的数据一定不同(异或：相同为0，不同为1)，所以我们可以用该比特位进行分组
        // 分组的结果一定是，相同数据被分到了同一组，不同数据一定被分到了不同的组

        // 1.整体异或
        int result = nums[0];
        for(auto i = 1; i<nums.size(); ++i)     // 从第一个元素开始
        {
            result ^= nums[i];
        }

        // 2.根据题意，异或后的结果为两个只出现一次的元素异或的结果，一定不为0
        //  找该数据的第一个比特位为1的二进制位
        int flag = 1;           // 00000000 00000000 00000000 00000001
        int len = sizeof(int)*8;
        for(int i=0; i<len; ++i)
        {
            if(flag<<i & result)
            {
                flag <<=i;      // flag<<=i后，第i位为1
                break;
            }
        }

        // 3.分组异或
        int ret1=0;
        int ret2=0;
        for(int j =0; j<nums.size(); ++j)
        {
            // flag中为1的位，在data[j]中为0，将其分为同一组，依次异或，得到第一个只出现一次的数
            if(nums[j] & flag)
            {
                ret1 ^= nums[j];
            }
            // flag中为1的位，在data[j]中为1，将其分为同一组，依次异或，得到第二个只出现一次的数
            else
            {
                ret2 ^= nums[j];
            }
        }
        // 返回结果
        vector<int> v;
        v.push_back(ret1);
        v.push_back(ret2);
        return v;
    }
};