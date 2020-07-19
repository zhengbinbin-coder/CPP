#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<list>
#include<string>

int main()
{
	//// 内置类型的初始化
	//int x1 = { 42 };
	//int x2{ 42 };

	//// 动态数组的初始化
	//int* arr = new int[3]{ 5,6,7 };

	//// 容器的初始化
	//vector<char> v = { 'a','*','b' };
	//list<char> l{ 'c','d' };
	//map<int, char> m{ {1,'x'},{42,'*'} };

	//// 自定义类型的列表初始化
	//class People
	//{
	//public:
	//	People(int age,string sex):_age(age),_sex(sex)
	//	{ }
	//private:
	//	int _age;
	//	string _sex;
	//};
	//People p{ 20,"男" };


	//// 定义一个map容器并初始化其内容
	//std::map<std::string, std::string> dict{ {"sort", "排序"}, {"search","搜索"} };

	//// 使用迭代器遍历容器, 迭代器类型太繁琐
	////std::map<std::string, std::string>::iterator it = dict.begin();
	//// 使用auto自动推导迭代器的类型，书写起来就会很方便
	//auto it = dict.begin();
	//while (it != dict.end())
	//{
	//	cout << it->first << " " << it->second << endl;
	//	++it;
	//}

	//// 定义一个int类型的vector容器并初始化其内容
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,0 };
	//// 使用范围for循环遍历打印
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//// 取容器中的元素依次赋值给e，因此对e进行修改不会改变容器中的元素
	//for (auto e : v)
	//{
	//	e *= 2;
	//}
	//// 当拷贝代价大的对象时，尽量使用&
	//vector<string> vs = { "sort","search","find","swap" };
	//for (const auto& e : vs)
	//{
	//	cout << e << " ";
	//}

	return 0;
}