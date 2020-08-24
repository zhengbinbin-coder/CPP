#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

//int main()
//{
//	//int a = 10;			// ����һ��int���͵ı���a
//	//int& ra = a;		// ʹ�����ø�a��һ������ra
//
//	//printf("a=%d \nra=%d\n\n", a, ra);				// a��ra��ֵ��ͬ
//	//printf("a�ĵ�ַ:%p \nra�ĵ�ַ:%p\n", &a, &ra);	// a��ra�ĵ�ַ��ͬ
//
//	int a = 10;
//	int b = 20;
//	//int& ra;		// ������Ҫ��ʼ��
//	int& ra1 = a;
//	int& ra2 = a;
//
//	ra1 = b;		// ���Ǹ�ֵ�����������ǰ�ra1�޸�Ϊ��b������
//
//	return 0;
//}

void my_swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int& test_ref1(int& a)
{
	a += 1;
	return a;
}

// �������ؾֲ�����������
int& test_ref2(int a, int b)
{
	int k = a + b;
	return k;
}

class StudentScore
{
public:
	StudentScore(string name, int math)
	{
		this->_name = name;
		this->_math = math;
	}
public:
	string _name;
	int _math;
};

class math_than_60
{
public:
	bool operator()(StudentScore& s)
	{
		return s._math > 60;
	}
};

int main()
{
	vector<StudentScore> vs;

	StudentScore s1("aaa", 20);
	StudentScore s2("bbb", 50);
	StudentScore s3("ccc", 80);
	StudentScore s4("ddd", 60);
	StudentScore s5("eee", 70);

	vs.push_back(s1);
	vs.push_back(s2);
	vs.push_back(s3);
	vs.push_back(s4);
	vs.push_back(s5);

	// �ҵ���һ����ѧ�ɼ�����60��ѧ��
	vector<StudentScore>::iterator sit = find_if(vs.begin(), vs.end(), math_than_60());
	if (sit != vs.end())	cout << "������" << sit->_name << " " << "��ѧ�ɼ���" << sit->_math << endl;
	else					cout << "δ�ҵ�" << endl;

	// ͳ����ѧ�ɼ�>60��ѧ��������
	int n = count_if(vs.begin(), vs.end(), math_than_60());
	cout << "��ѧ�ɼ�>60��ѧ����������" << n << endl;


	
	

	//int a = 10;
	//int b = 20;

	//test_ref1(a);
	//cout << a << endl;

	//int& k = test_ref2(1, 2);	// ��1+2��ֵ����k��
	//test_ref2(3, 4);			
	//cout << k << endl;			// �����k������1+2��ֵ��������һ���е��õ�3+4��ֵ

	//my_swap(a, b);
	//cout << a << " " << b << endl;

	//vector<int> v;
	//v.push_back(1);
	//v.push_back(5);
	//v.push_back(3);
	//v.push_back(9);
	//v.push_back(4);
	//v.push_back(7);

	//vector<int>::iterator it = find(v.begin(), v.end(), 5);
	//if (it != v.end())	cout << "�ҵ��ˣ�" << *it << "\n" << endl;
	//else				cout << "δ�ҵ���\n" << endl;

	//list<char> l;
	//l.push_back('x');
	//l.push_back('x');
	//l.push_back('x');
	//l.push_back('x');
	//l.push_front('a');
	//l.push_front('a');
	//l.push_front('a');

	//int n = count(l.begin(), l.end(), 'x');
	//cout << n << endl;

	return 0;
}