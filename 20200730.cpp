#include <iostream>

using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常；异常抛出后就必须进行捕获
//	if (b == 0)
//		throw "除数不能为0";	// 抛出的异常可以是任意类型的对象，此处为常量字符串指针
//	else
//		return (a / b);
//}
//void Func()
//{
//	int* array = new int[10];		// new一个数组
//
//	try								// 把可能发生异常的代码放到try模块里
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << Division(a, b) << endl;
//	}
//	catch (const char* errmsg)		// 捕获--这里的捕获并不是为了处理异常，而只是为了重新抛出
//	{
//		delete[] array;				// 处理内存泄漏问题
//		throw errmsg;				// 重新抛出异常
//	}
//
//	// 若上面的try模块可能会抛出多种类型的异常，则需要与之对应的写多种catch模块去捕获不同种类的异常
//	// 所以更建议下面这种写法
//	catch (...)						// 捕获--这里的捕获并不是为了处理异常，而只是为了重新抛出
//	{
//		delete[] array;				// 处理内存泄漏问题
//		throw ;						// 重新抛出异常
//	}
//	
//	delete[] array;					// delete数组
//}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)		// 捕获抛出的字符串指针
//	{
//		cout << errmsg << endl;		// 对其及进行输出
//	}
//	catch (...)		// 捕获任意类型的异常，防止程序异常终止，但这样捕获不知道具体的错误
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr):_ptr(ptr)
	{}

	~SmartPtr()
	{
		delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

void Test()
{
	int* p = new int[10];
	SmartPtr<int> sp(p);	// 使用智能指针把p对象保存起来

	throw exception();		// 异常

	//delete[]p;			// 这里不需要再去手动释放，p出作用域时，会自动调用智能指针的析构函数将p释放
}

int main()
{
	try
	{
		Test();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	return 0;
}


































