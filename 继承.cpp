#include<iostream>

using namespace std;

class Animal
{
public:
	void Eat()
	{
		cout << "�Է�" << endl;
	}
	void Sleep()
	{
		cout << "˯��" << endl;
	}
	void Speak()
	{
		cout << "�����" << endl;
	}
};

class Cat :public Animal
{
public:
	/*void Eat()
	{
		cout << "�Է�" << endl;
	}
	void Sleep()
	{
		cout << "˯��" << endl;
	}*/
	void Speak()
	{
		cout << "������" << endl;
	}
};

class Dog :public Animal
{
public:
	//void Eat()
	//{
	//	cout << "�Է�" << endl;
	//}
	//void Sleep()
	//{
	//	cout << "˯��" << endl;
	//}
	void Speak()
	{
		cout << "������" << endl;
	}
};

class Pig :public Animal
{
public:
	/*void Eat()
	{
		cout << "�Է�" << endl;
	}
	void Sleep()
	{
		cout << "˯��" << endl;
	}*/
	void Speak()
	{
		cout << "�ߺߺ�" << endl;
	}
};

class Father
{
public:
	Father()
	{
		_A = 100;
	}

	void func()
	{
		cout << "Base - func()����" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)����" << endl;
	}

public:
	int _A;
};

class Son : public Father 
{
public:
	Son()
	{
		_A = 200;
	}

	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
	void func()
	{
		cout << "Son - func()����" << endl;
	}
public:
	int _A;
};

int main()
{
	Son s;

	cout << "Son�µ�_A = " << s._A << endl;
	cout << "Base�µ�_A = " << s.Father::_A << endl;

	s.func();
	s.Father::func();
	s.Father::func(10);

	/*Cat c;
	c.Eat();
	c.Sleep();
	c.Speak();

	Dog d;
	d.Eat();
	d.Sleep();
	d.Speak();

	Pig p;
	p.Eat();
	p.Sleep();
	p.Speak();*/

	return 0;
}
