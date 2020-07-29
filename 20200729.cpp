#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<atomic>

using namespace std;

//int main()
//{
//	// 最简单的lambda表达式，没有任何意义
//	[] {};
//
//	// 交换a和b的值，因为lambda函数是一个const函数，送一需要使用mutable取消其常量性
//	// 使用mutable修饰符时，参数列表不可省略(即使参数为空)
//	// 捕捉列表可由多个捕捉项组成，并以逗号分隔,但不允许变量重复传递
//	// 其实这段代码并不能实现a和b的值的交换，因为是传值调用的
//	int a = 3, b = 4;
//	[a, b]()mutable {int tmp = a; a = b; b = tmp; };
//
//	// 交换a，b的lambda表达式的正确写法---以传引用的方式捕捉a，b
//	[&a, &b] {int tmp = a; a = b; b = tmp; };
//	// 也可以不捕捉，直接传参数
//	[](int& a, int& b) {int tmp = a; a = b; b = tmp; };
//	// 也可以用引用传递捕捉所有变量
//	[&] {int tmp = a; a = b; b = tmp; };
//
//	int a = 3, b = 4;
//	// 借助auto将其赋值给一个变量
//	auto lambda_swap1 = [&a, &b] {int tmp = a; a = b; b = tmp; };
//	auto lambda_swap2 = [](int& a, int& b) {int tmp = a; a = b; b = tmp; };
//	auto lambda_swap3 = [&] {int tmp = a; a = b; b = tmp; };
//	// 调用上面三个变量
//	lambda_swap1();
//	lambda_swap2(a, b);		//lambda_swap2有参数列表
//	lambda_swap3();
//
//
//	return 0;
//}

//mutex _mtx;		// 定义互斥锁
//
//void f1(int n)
//{
//	_mtx.lock();	// 加锁
//	for (int i = 0; i < n; ++i)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//	}
//	_mtx.unlock();	// 解锁
//}

//struct F2
//{
//	void operator()(int n)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			cout << this_thread::get_id() << ":" << i << endl;
//		}
//	}
//};

//int main()
//{
//	thread t1;
//	thread t2(f1, 10);		// 函数指针的方式
//
//	F2 f2;
//	thread t3(f2, 10);		// 仿函数
//	thread t4(F2(), 10);	// 仿函数匿名对象
//
//	// lambda表达式--参数列表
//	thread t5([](int n)->void
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			cout << this_thread::get_id() << ":" << i << endl;
//		}
//	}, 10);	
//
//	//t1.join();	// t1只是创建了这个对象，没有执行什么操作，因此不能join;若要join可先给t1移动赋值
//	t2.join();
//	t3.join();
//	t4.join();
//	t5.join();
//
//	return 0;
//}

//int main()
//{
//	vector<thread> vt;
//	int n = 8;
//	vt.resize(n);	// 创建8个线程
//	for (int i = 0; i < n; ++i)
//	{
//		vt[i] = thread(f1, 4);	// 每个线程执行4次
//	}
//	for (auto& e : vt)
//	{
//		e.join();
//	}
//
//	return 0;
//}

//mutex _mtx;		// 定义互斥锁
//int x;
//
//void f1(int n)
//{
//	// 锁的粒度大，串行执行，速度较快
//	_mtx.lock();	// 加锁
//	for (int i = 0; i < n; ++i)
//	{
//		++x;
//	}
//	_mtx.unlock();	// 解锁
//
//	// 锁的粒度小，并行执行，速度反而变慢了不少
//	for (int i = 0; i < n; ++i)
//	{
//		_mtx.lock();	// 加锁
//		++x;
//		_mtx.unlock();	// 解锁
//	}
//}

atomic<int> x;

void f1(int n)
{
	for (int i = 0; i < n; ++i)
	{
		++x;
	}
}

int main()
{
	vector<thread> vt;
	int n = 8;
	vt.resize(n);	// 创建8个线程
	for (int i = 0; i < n; ++i)
	{
		vt[i] = thread(f1, 1000000);	// 每个线程执行1000000次
	}
	for (auto& e : vt)
	{
		e.join();
	}
	cout << x << endl;

	return 0;
}