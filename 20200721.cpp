#include<iostream>

using namespace std;

//// ţ�Ͷ�ά�����еĲ���
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

//// ţ����ת�������С����
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
//                //�޷��ж�Ŀ��������mid��࣬�����Ҳ����ǲ������Ա�����ʽ
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

//// leetcode��ת�������С����
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
//            // ֻ������Ԫ�أ��ǵڶ���һ������СԪ��
//            if (right - left == 1)
//            {
//                mid = right;
//                break;
//            }
//
//            int mid = (left + right) / 2;
//
//            // �������Ԫ��==�м�Ԫ��==���ұ�Ԫ�أ����޷����ֲ��ң�ֱ�ӱ�������
//            if (numbers[left] == numbers[right] && numbers[left] == numbers[mid])  return ergodic(numbers);
//
//            // �����ұ�Ԫ��>=�м�Ԫ�أ�˵����벿����������СԪ����ǰ�벿�֣�����С��Χ���м�Ԫ�ر�Ϊ���ұ�Ԫ��
//            if (numbers[right] >= numbers[mid])  right = mid;
//            // �������Ԫ��<=�м�Ԫ�أ�˵��ǰ�벿����������СԪ���ں�벿�֣�����С��Χ���м�Ԫ�ر�Ϊ�����Ԫ��
//            if (numbers[left] <= numbers[mid])  left = mid;
//        }
//        return numbers[mid];
//    }
//    // ��������
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
		throw "��������Ϊ0��";
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

	// ��������û��ƥ������͵��쳣����ֹ�����쳣��ֹ����������������쳣��֪����ʲôԭ��
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}