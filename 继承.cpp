#include<iostream>

using namespace std;

class Animal
{
public:
	void Eat()
	{
		cout << "吃饭" << endl;
	}
	void Sleep()
	{
		cout << "睡觉" << endl;
	}
	void Speak()
	{
		cout << "动物叫" << endl;
	}
};

class Cat :public Animal
{
public:
	/*void Eat()
	{
		cout << "吃饭" << endl;
	}
	void Sleep()
	{
		cout << "睡觉" << endl;
	}*/
	void Speak()
	{
		cout << "喵喵喵" << endl;
	}
};

class Dog :public Animal
{
public:
	//void Eat()
	//{
	//	cout << "吃饭" << endl;
	//}
	//void Sleep()
	//{
	//	cout << "睡觉" << endl;
	//}
	void Speak()
	{
		cout << "汪汪汪" << endl;
	}
};

class Pig :public Animal
{
public:
	/*void Eat()
	{
		cout << "吃饭" << endl;
	}
	void Sleep()
	{
		cout << "睡觉" << endl;
	}*/
	void Speak()
	{
		cout << "哼哼哼" << endl;
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
		cout << "Base - func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
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

	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
public:
	int _A;
};

int main()
{
	Son s;

	cout << "Son下的_A = " << s._A << endl;
	cout << "Base下的_A = " << s.Father::_A << endl;

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
