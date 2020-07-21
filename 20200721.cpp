#include<iostream>

using namespace std;

//// 牛客二维数组中的查找
//// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?
//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		int i = 0;
//		int j = array[0].size() - 1;
//		while (i < array.size() && j >= 0)
//		{
//			if (target < array[i][j])
//			{
//				j--;
//			}
//			else if (target > array[i][j])
//			{
//				i++;
//			}
//			else if (target == array[i][j])
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//};

//// 牛客旋转数组的最小数字
//// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?
//class Solution {
//public:
//    int minNumberInRotateArray(vector<int> rotateArray) {
//        if (rotateArray.size() == 0)
//            return 0;
//        int left = 0;
//        int right = rotateArray.size() - 1;
//        int mid = 0;
//        while (rotateArray[left] >= rotateArray[right]) {
//            if (right - left == 1) {
//                mid = right;
//                break;
//            }
//            mid = (left + right) >> 1;
//            if (rotateArray[mid] == rotateArray[left] && rotateArray[left] ==
//                rotateArray[right]) {
//                //无法判定目标数据在mid左侧，还是右侧我们采用线性遍历方式
//                int result = rotateArray[left];
//                for (int i = left + 1; i < right; i++) {
//                    if (result > rotateArray[i]) {
//                        result = rotateArray[i];
//                    }
//                }
//                return result;
//            }
//            if (rotateArray[mid] >= rotateArray[left]) {
//                left = mid;
//            }
//            else {
//                right = mid;
//            }
//        }
//        return rotateArray[mid];
//    }
//};

//// leetcode旋转数组的最小数字
//class Solution {
//public:
//    int minArray(vector<int>& numbers) {
//        if (numbers.empty()) return NULL;
//
//        int left = 0;
//        int right = numbers.size() - 1;
//        int mid = 0;
//
//        while (numbers[left] >= numbers[right])
//        {
//            // 只有两个元素，那第二个一定是最小元素
//            if (right - left == 1)
//            {
//                mid = right;
//                break;
//            }
//
//            int mid = (left + right) / 2;
//
//            // 若最左边元素==中间元素==最右边元素，就无法二分查找，直接遍历查找
//            if (numbers[left] == numbers[right] && numbers[left] == numbers[mid])  return ergodic(numbers);
//
//            // 若最右边元素>=中间元素，说明后半部分有序且最小元素在前半部分，则缩小范围让中间元素变为最右边元素
//            if (numbers[right] >= numbers[mid])  right = mid;
//            // 若最左边元素<=中间元素，说明前半部分有序且最小元素在后半部分，则缩小范围让中间元素变为最左边元素
//            if (numbers[left] <= numbers[mid])  left = mid;
//        }
//        return numbers[mid];
//    }
//    // 遍历查找
//    int ergodic(vector<int>& numbers)
//    {
//        int size = numbers.size();
//        int min = numbers[0];
//        for (int i = 1; i < size; i++)
//        {
//            if (numbers[i] < min)
//            {
//                min = numbers[i];
//            }
//        }
//        return min;
//    }
//};

int Division(int a, int b)
{
	if (b == 0)
		throw "除数不能为0！";
	else
		return (a / b);
}

void func()
{
	int x, y;
	cin >> x >> y;
	cout << Division(x, y) << endl;
}

int main()
{
	try
	{
		func();
	}
	catch (const char* error_message)
	{
		cout << error_message << endl;
	}

	// 捕获任意没有匹配的类型的异常，防止程序异常终止。但是这样捕获的异常不知道是什么原因
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	return 0;
}