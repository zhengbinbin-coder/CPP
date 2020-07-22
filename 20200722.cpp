//leetcode��������˳��ʹ����λ��ż��ǰ��(����������λ�ÿ��Ըı�)
//https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        // �����±�<���±�ʱ��ִ��ѭ��
        while (left < right)
        {
            // ���±�<���±겢�����±�Ԫ��Ϊ����ʱ�����±�++(��Ҫһֱ�������±�<���±�)
            // while(left<right && nums[left]%2==1)    ++left;
            while (left < right && (nums[left] & 1))     ++left;

            // ���±�<���±겢�����±�Ԫ��Ϊż��ʱ�����±�--(��Ҫһֱ�������±�<���±�)
            // while(left<right && nums[right]%2==0)   ++right;
            while (left < right && !(nums[right] & 1))    --right;

            // ����ʱ���±���Ȼ<���±꣬�򽻻�����Ԫ��
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


// ţ�ͣ���������˳��ʹ����λ��ż��ǰ��(����������λ�ò��ܸı�)
//https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?
class Solution {
public:
    void reOrderArray(vector<int>& array) {
        if (array.size() == 0)    return;
        int k = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            //if(array[i]%1==1)      //����һ������
            if (array[i] & 1)
            {
                int tmp = array[i];    //���������ҵ�������
                int j = i;
                while (j > k)           //k��j֮��Ϊż������
                {
                    array[j] = array[j - 1];    //��ż�������������
                    --j;
                }
                array[k] = tmp;    //�����µ���������kλ��
                ++k;             //kλ������ƶ�һλ
            }
        }
    }
};

// leetcode-�����г���һ�������
//https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
// //����map��ʹ��<���֣�����>��ӳ���ϵ�����ͳ��ÿ���ַ����ֵĴ���
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        // int half = nums.size()/2;   // ��������һ���ж���
        // unordered_map<int,int> m;
        // for(int i = 0; i < nums.size(); ++i)
        // {
        //     // ��nums[i]
        //     auto it = m.find(nums[i]);
        //     // ����m�У�������nums[i]��value
        //     if(it != m.end())   m[nums[i]]++;           
        //     // ��������˵���״γ��֣����벢��nums[i]��value����Ϊ1
        //     else    m.insert(make_pair(nums[i],1));
        //     // ��nums[i]�������������һ�룬ֱ�ӷ���
        //     if(m[nums[i]]>half)    return nums[i];
        // }
        // return 0;
//     }
// };

// //���򣬳��ִ����������֣�һ�����м�λ�á�Ȼ�����м���ֵ����ֳ��ֵĴ����Ƿ����Ҫ��
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int half = nums.size()/2;
//         sort(nums.begin(),nums.end());  // ����������
//         int count = 0;                  // �������count
//         for(int i = 0; i < nums.size(); ++i)    // ��������
//         {
//             // ������鵱ǰԪ��==�����м�Ԫ�ؾ�++count
//             if(nums[i] == nums[half])   count++;
//         }
//         if(count > half)    return nums[half];  // ���count>����һ��ͷ����м�Ԫ��
//         return 0;
//     }
// };

//ÿ��ȥ��������ͬ�����֣������ڳ���һ�������������ʣ�µ�1��2������һ��Ϊ���ִ�������
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];  //����һ��Ԫ����Ϊ��׼
        int times = 1;      //������ͬ���ֵĸ���
        for (int i = 1; i < nums.size(); ++i)
        {
            if (times == 0)    //�����ͬ���ֵĸ���==0��˵����ͬ���ֵ�������
            {
                ret = nums[i];     //�������û�׼
                times = 1;           //����������Ϊ1
            }
            //�����ǰԪ�غͻ�׼��ͬ������ͬ���ִ���++
            else if (nums[i] == ret)    times++;
            //�ߵ�����˵����ǰԪ�غͻ�׼��ͬ�������໥��������ͬ���ִ���--
            else times--;
        }

        // �ߵ���������ڳ���һ������֣���һ����ret
        // �������飬�ó�ret���ֵĴ���
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)    // ��������
        {
            if (nums[i] == ret)   count++;
        }
        return count > nums.size() / 2 ? ret : 0;
    }
};