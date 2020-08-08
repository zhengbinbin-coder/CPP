#include<iostream>
#include<mutex>

using namespace std;

// 只能在堆上创建对象的类
// 1.构造函数私有
// 2.封装静态公有接口在堆上创建对象
// 3.拷贝构造封掉
class HeapOnly
{
public:
	// 成员函数需要对象调用，但没创建对象无法调用，因此设为静态成员函数,外部通过类名调用
	static HeapOnly* CreateHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}
private:
	// 构造函数放在私有区，不让外部调用，创建对象时通过类内公有接口调用此函数创建
	HeapOnly(){ }
	// 拷贝构造封掉，防止对象被拷贝到栈上创建
	HeapOnly(const HeapOnly&) = delete;
};

// 只能在栈上创建对象的类
// 方法1：构造函数设为私有，创建时通过公有接口实现
class StackOnly1
{
public:
	static StackOnly1 CreateStackObj()
	{
		return StackOnly1();
	}
private:
	StackOnly1(){ }
};
// 方法二：定制new并放在私有区
class StackOnly2
{
public:
	StackOnly2(){ }
private:
	// 定制new，并放在私有区，防止调用
	void* operator new(size_t size);
	void operator delete(void* p);
};

// 不能被拷贝的类
class CopyBan
{
public:
	CopyBan(){ }
private:
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};

// 不能被继承的类--final修饰
class NonInherit final
{

};

//int main()
//{
//	HeapOnly* p1 = HeapOnly::CreateHeapObj();
//	StackOnly1 s1 = StackOnly1::CreateStackObj();
//	StackOnly2 s2 = StackOnly2();
//	CopyBan cp;
//
//	return 0;
//}

//// 饿汉模式
//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		return _sInst;
//	}
//private:
//	// 构造函数私有化
//	Singleton(){ }
//	// 拷贝构造函数封掉
//	Singleton(const Singleton&) = delete;
//
//	static Singleton _sInst;
//};
//
//Singleton Singleton::_sInst;	// main函数之前就创建初始化了这个实例对象--对象在静态区

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		/*
		1.存在线程安全问题
		if (_spInst == nullptr)	
		{
			_spInst = new Singleton;
		}
		return *_spInst;
		*/

		/*
		2.解决了线程安全问题，但第一个线程创建好了实例之后，后面的线程进来虽然不创建实例，仍然需要加锁解锁
		_smtx.lock();			// 加锁
		if (_spInst == nullptr)
		{
			_spInst = new Singleton;
		}
		_smtx.unlock();			// 解锁
		return *_spInst;
		*/

		// 饿汉模式有线程安全问题，需要加锁
		// 3.双检查解决锁的效率问题
		if (_spInst == nullptr)		// 解决效率问题，后面的线程发现已有实例就不进去，防止加锁解锁
		{
			_smtx.lock();			// 加锁
			if (_spInst == nullptr)	// 解决线程安全问题
			{
				_spInst = new Singleton;
			}
			_smtx.unlock();
		}
		return *_spInst; 
	}
private:
	// 构造函数私有化
	Singleton(){ }
	// 拷贝构造函数封掉
	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
	static mutex _smtx;
};

Singleton* Singleton::_spInst = nullptr;		// main函数之前就创建初始化指针
mutex Singleton::_smtx;

class A
{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	A* pa = new	A;
	B* pb = new B;
	// 父指针 = 子指针 这个是直接就支持的切片，可以不算转换
	pa = pb;

	// 子指针 = 父指针 这里需要转换，且一般这样的转换是不合适的，特殊情况下才需要
	// B* p = (B*)pa;	// 这样的转换并不安全	
	B* p = dynamic_cast<B*>(pa);	// 这样转是安全的--若pa是B*类型的对象就可以成功，若pa是A*类型的对象，就失败返回NULL


	int a = 10;
	double b = static_cast<double>(a);		// 相关类型、相近类型(意义类似的类型)之间的转换

	int c = 10;
	int* pc = &c;
	int path = reinterpret_cast<int>(pc);	// 不相关类型之间的转换

	const int d = 2;
	int* pd = const_cast<int*>(&d);			// 去掉const属性的转换
	*pd = 3;



	return 0;
}