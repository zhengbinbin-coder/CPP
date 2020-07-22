//leetcode调整数组顺序使奇数位于偶数前面(调整后的相对位置可以改变)
//https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        // 当左下标<右下标时，执行循环
        while (left < right)
        {
            // 左下标<右下标并且左下标元素为奇数时，左下标++(需要一直保持左下标<右下标)
            // while(left<right && nums[left]%2==1)    ++left;
            while (left < right && (nums[left] & 1))     ++left;

            // 左下标<右下标并且右下标元素为偶数时，右下标--(需要一直保持左下标<右下标)
            // while(left<right && nums[right]%2==0)   ++right;
            while (left < right && !(nums[right] & 1))    --right;

            // 若此时左下标仍然<右下标，则交换两个元素
            if (left < right)
            {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return nums;
    }
};


// 牛客：调整数组顺序使奇数位于偶数前面(调整后的相对位置不能改变)
//https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?
class Solution {
public:
    void reOrderArray(vector<int>& array) {
        if (array.size() == 0)    return;
        int k = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            //if(array[i]%1==1)      //找下一个奇数
            if (array[i] & 1)
            {
                int tmp = array[i];    //保存最新找到的奇数
                int j = i;
                while (j > k)           //k和j之间为偶数序列
                {
                    array[j] = array[j - 1];    //将偶数序列整体后移
                    --j;
                }
                array[k] = tmp;    //把最新的奇数放在k位置
                ++k;             //k位置向后移动一位
            }
        }
    }
};

// leetcode-数组中超过一半的数字
//https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
// //定义map，使用<数字，次数>的映射关系，最后统计每个字符出现的次数
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        // int half = nums.size()/2;   // 算出数组的一半有多少
        // unordered_map<int,int> m;
        // for(int i = 0; i < nums.size(); ++i)
        // {
        //     // 找nums[i]
        //     auto it = m.find(nums[i]);
        //     // 若在m中，则自增nums[i]的value
        //     if(it != m.end())   m[nums[i]]++;           
        //     // 若不在则说明首次出现，插入并将nums[i]的value设置为1
        //     else    m.insert(make_pair(nums[i],1));
        //     // 若nums[i]次数大于数组的一半，直接返回
        //     if(m[nums[i]]>half)    return nums[i];
        // }
        // return 0;
//     }
// };

// //排序，出现次数最多的数字，一定在中间位置。然后检测中间出现的数字出现的次数是否符合要求
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int half = nums.size()/2;
//         sort(nums.begin(),nums.end());  // 对数组排序
//         int count = 0;                  // 定义次数count
//         for(int i = 0; i < nums.size(); ++i)    // 遍历数组
//         {
//             // 如果数组当前元素==数组中间元素就++count
//             if(nums[i] == nums[half])   count++;
//         }
//         if(count > half)    return nums[half];  // 如果count>数组一半就返回中间元素
//         return 0;
//     }
// };

//每次去掉两个不同的数字，若存在超过一半的数字则最终剩下的1或2个数字一定为出现次数最多的
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];  //将第一个元素作为基准
        int times = 1;      //定义相同数字的个数
        for (int i = 1; i < nums.size(); ++i)
        {
            if (times == 0)    //如果相同数字的个数==0，说明相同数字抵消完了
            {
                ret = nums[i];     //重新设置基准
                times = 1;           //将次数设置为1
            }
            //如果当前元素和基准相同，则相同数字次数++
            else if (nums[i] == ret)    times++;
            //走到这里说明当前元素和基准不同，可以相互抵消，相同数字次数--
            else times--;
        }

        // 走到这里，若存在超过一半的数字，则一定是ret
        // 遍历数组，得出ret出现的次数
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)    // 遍历数组
        {
            if (nums[i] == ret)   count++;
        }
        return count > nums.size() / 2 ? ret : 0;
    }
};