//暴力求解：将数组遍历一遍，找出最小的元素
// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         int min=nums[0];
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]<min)
//             {
//                 min=nums[i];
//             }
//         }
//         return min;
//     }
// };

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty()) return NULL;

        int left=0;
        int right=numbers.size()-1;
        int mid=0;

        while(numbers[left]>=numbers[right])
        {
            if(right-left==1)
            {
                mid=right;
                break;
            }

            int mid = (left+right)/2;

            if(numbers[left]==numbers[right]&&numbers[left]==numbers[mid])  return ergodic(numbers);

            if(numbers[right] >= numbers[mid])  right=mid;
            if(numbers[left] <= numbers[mid])  left=mid;
        }
        return numbers[mid];
    }

    int ergodic(vector<int>& numbers)
    {
        int size = numbers.size();
        int min = numbers[0];
        for(int i = 1; i < size; i++)
        {
            if(numbers[i]<min)
            {
                min=numbers[i];
            }
        }
        return min;
    }
};
