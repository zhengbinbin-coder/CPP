#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<list>
#include<string>

int main()
{
	//// �������͵ĳ�ʼ��
	//int x1 = { 42 };
	//int x2{ 42 };

	//// ��̬����ĳ�ʼ��
	//int* arr = new int[3]{ 5,6,7 };

	//// �����ĳ�ʼ��
	//vector<char> v = { 'a','*','b' };
	//list<char> l{ 'c','d' };
	//map<int, char> m{ {1,'x'},{42,'*'} };

	//// �Զ������͵��б��ʼ��
	//class People
	//{
	//public:
	//	People(int age,string sex):_age(age),_sex(sex)
	//	{ }
	//private:
	//	int _age;
	//	string _sex;
	//};
	//People p{ 20,"��" };


	//// ����һ��map��������ʼ��������
	//std::map<std::string, std::string> dict{ {"sort", "����"}, {"search","����"} };

	//// ʹ�õ�������������, ����������̫����
	////std::map<std::string, std::string>::iterator it = dict.begin();
	//// ʹ��auto�Զ��Ƶ������������ͣ���д�����ͻ�ܷ���
	//auto it = dict.begin();
	//while (it != dict.end())
	//{
	//	cout << it->first << " " << it->second << endl;
	//	++it;
	//}

	//// ����һ��int���͵�vector��������ʼ��������
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,0 };
	//// ʹ�÷�Χforѭ��������ӡ
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//// ȡ�����е�Ԫ�����θ�ֵ��e����˶�e�����޸Ĳ���ı������е�Ԫ��
	//for (auto e : v)
	//{
	//	e *= 2;
	//}
	//// ���������۴�Ķ���ʱ������ʹ��&
	//vector<string> vs = { "sort","search","find","swap" };
	//for (const auto& e : vs)
	//{
	//	cout << e << " ";
	//}

	return 0;
}