#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

//int main()
//{
//	//int a = 10;			// 定义一个int类型的变量a
//	//int& ra = a;		// 使用引用给a起一个别名ra
//
//	//printf("a=%d \nra=%d\n\n", a, ra);				// a与ra的值相同
//	//printf("a的地址:%p \nra的地址:%p\n", &a, &ra);	// a与ra的地址相同
//
//	int a = 10;
//	int b = 20;
//	//int& ra;		// 报错，需要初始化
//	int& ra1 = a;
//	int& ra2 = a;
//
//	ra1 = b;		// 这是赋值操作，并不是把ra1修改为了b的引用
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

// 函数返回局部变量的引用
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

	// 找到第一个数学成绩大于60的学生
	vector<StudentScore>::iterator sit = find_if(vs.begin(), vs.end(), math_than_60());
	if (sit != vs.end())	cout << "姓名：" << sit->_name << " " << "数学成绩：" << sit->_math << endl;
	else					cout << "未找到" << endl;

	// 统计数学成绩>60的学生的数量
	int n = count_if(vs.begin(), vs.end(), math_than_60());
	cout << "数学成绩>60的学生的数量：" << n << endl;


	
	

	//int a = 10;
	//int b = 20;

	//test_ref1(a);
	//cout << a << endl;

	//int& k = test_ref2(1, 2);	// 把1+2的值存入k中
	//test_ref2(3, 4);			
	//cout << k << endl;			// 输出的k并不是1+2的值，而是上一行中调用的3+4的值

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
	//if (it != v.end())	cout << "找到了：" << *it << "\n" << endl;
	//else				cout << "未找到！\n" << endl;

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