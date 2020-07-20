#include<iostream>

using namespace std;
#include<string>
#include<vector>

//class Animal
//{
//public:
//	virtual void Speak() final	// 动物类的Speak函数被final修饰，Cat类将无法对其进行重写
//	{
//		cout << "动物在说话" << endl;
//	}
//	virtual void Eat()
//	{
//		cout << "动物吃食物" << endl;
//	}
//};
//class Cat final:public Animal // Cat类被final修饰，OrangeCat类将无法继承Cat类
//{
//public:
//	/*void Speak() //编译错误，无法被重写
//	{
//		cout << "小猫在说话" << endl;
//	}*/
//	void Eat() override
//	{
//		cout << "小猫吃猫粮" << endl;
//	}
//};
////class OrangeCat:public Cat // 编译错误，无法从Cat类继承，因为它已被声明为"final"
////{
////public:
////};


class Student
{
public:
	Student(string name,int age):_name(name),_age(age)
	{ }
	// 禁止编译器生成默认的拷贝构造函数
	Student(const Student&) = delete;
	// 禁止编译器生成默认的等号赋值运算符重载
	Student& operator=(const Student&) = delete;
private:
	string _name;
	int _age;
};

// 假设有这样一个场景：我们需要使用str1创建str2
//string create_string()
//{
//	// 创建一个string类型的对象str1
//	string str1 = "hello";	
//
//	// 调用string的拷贝构造函数创建一个str2
//	string str2 = str1;		
//
//	// 这里实际是先把str1中的内容复制出来，再复制到str2中
//	// 这里的花销较大
//
//	// 我们最终需要的是str2，出了这个函数体后str1会自动销毁，
//	string str2;
//	str2.swap(str1);
//	return str2;
//}

string create_string()
{
	// 创建一个string类型的对象str1
	string str1 = "hello";
	
	// 创建一个空的str2，将str2和str1的内容进行交换，这样就可以节省拷贝的开销
	string str2;
	str2.swap(str1);
	return str2;
}

int main()
{
	/*Cat c;
	c.Eat();*/

	//// 最简单的lambda表达式，没有任何意义
	//[] {};

	//// 交换a和b的值，因为lambda函数是一个const函数，送一需要使用mutable取消其常量性
	//// 使用mutable修饰符时，参数列表不可省略(即使参数为空)
	//// 其实这段代码并不能实现a和b的值的交换，因为是传值调用的
	//int a = 3, b = 4;
	//[a, b]()mutable {int tmp = a; a = b; b = tmp; };

	//// 交换a，b的lambda表达式的正确写法---以传引用的方式捕捉a，b
	//[&a, &b] {int tmp = a; a = b; b = tmp; };
	//// 也可以不捕捉，直接传参数
	//[](int& a, int& b) {int tmp = a; a = b; b = tmp; };
	//// 也可以用引用传递捕捉所有变量
	//[&] {int tmp = a; a = b; b = tmp; };
	
	// 在下列代码中，当a表示的意义不同时，它的含义也不同
	//int a = 42;		// a为左值，42为右值	a是一个int类型的对象(C语言称为常量)，42是常量
	//char c = a;		// c为左值，a为右值		c是一个char类型的对象，a是值为42的常量
	
	
	string str1 = "hello";

	//// 左值引用
	//// 1.做参数
	//swap(T& a, T& b);							// 输出型参数
	//vector<int>& func(const vector<int> & v);	// 提高传递效率
	//// 2.做返回值
	//T& operator[](size_t index);				// 需要修改返回的对象
	//vector<T>& operator=(const vector<T> & v);	// 提高传递效率


	// 右值引用
	string str2 = move(str1);	// 等效于string str2 = (string &&) str1;  相当于把str1强转为了string&&类型的无名对象
	// 当使用了move后，编译器会对str1进行区分，若str1为左值会调用拷贝构造函数，若str1为右值则会调用移动构造函数
	

	return 0;
}