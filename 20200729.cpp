#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<atomic>

using namespace std;

//int main()
//{
//	// ��򵥵�lambda���ʽ��û���κ�����
//	[] {};
//
//	// ����a��b��ֵ����Ϊlambda������һ��const��������һ��Ҫʹ��mutableȡ���䳣����
//	// ʹ��mutable���η�ʱ�������б���ʡ��(��ʹ����Ϊ��)
//	// ��׽�б���ɶ����׽����ɣ����Զ��ŷָ�,������������ظ�����
//	// ��ʵ��δ��벢����ʵ��a��b��ֵ�Ľ�������Ϊ�Ǵ�ֵ���õ�
//	int a = 3, b = 4;
//	[a, b]()mutable {int tmp = a; a = b; b = tmp; };
//
//	// ����a��b��lambda���ʽ����ȷд��---�Դ����õķ�ʽ��׽a��b
//	[&a, &b] {int tmp = a; a = b; b = tmp; };
//	// Ҳ���Բ���׽��ֱ�Ӵ�����
//	[](int& a, int& b) {int tmp = a; a = b; b = tmp; };
//	// Ҳ���������ô��ݲ�׽���б���
//	[&] {int tmp = a; a = b; b = tmp; };
//
//	int a = 3, b = 4;
//	// ����auto���丳ֵ��һ������
//	auto lambda_swap1 = [&a, &b] {int tmp = a; a = b; b = tmp; };
//	auto lambda_swap2 = [](int& a, int& b) {int tmp = a; a = b; b = tmp; };
//	auto lambda_swap3 = [&] {int tmp = a; a = b; b = tmp; };
//	// ����������������
//	lambda_swap1();
//	lambda_swap2(a, b);		//lambda_swap2�в����б�
//	lambda_swap3();
//
//
//	return 0;
//}

//mutex _mtx;		// ���廥����
//
//void f1(int n)
//{
//	_mtx.lock();	// ����
//	for (int i = 0; i < n; ++i)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//	}
//	_mtx.unlock();	// ����
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
//	thread t2(f1, 10);		// ����ָ��ķ�ʽ
//
//	F2 f2;
//	thread t3(f2, 10);		// �º���
//	thread t4(F2(), 10);	// �º�����������
//
//	// lambda���ʽ--�����б�
//	thread t5([](int n)->void
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			cout << this_thread::get_id() << ":" << i << endl;
//		}
//	}, 10);	
//
//	//t1.join();	// t1ֻ�Ǵ������������û��ִ��ʲô��������˲���join;��Ҫjoin���ȸ�t1�ƶ���ֵ
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
//	vt.resize(n);	// ����8���߳�
//	for (int i = 0; i < n; ++i)
//	{
//		vt[i] = thread(f1, 4);	// ÿ���߳�ִ��4��
//	}
//	for (auto& e : vt)
//	{
//		e.join();
//	}
//
//	return 0;
//}

//mutex _mtx;		// ���廥����
//int x;
//
//void f1(int n)
//{
//	// �������ȴ󣬴���ִ�У��ٶȽϿ�
//	_mtx.lock();	// ����
//	for (int i = 0; i < n; ++i)
//	{
//		++x;
//	}
//	_mtx.unlock();	// ����
//
//	// ��������С������ִ�У��ٶȷ��������˲���
//	for (int i = 0; i < n; ++i)
//	{
//		_mtx.lock();	// ����
//		++x;
//		_mtx.unlock();	// ����
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
	vt.resize(n);	// ����8���߳�
	for (int i = 0; i < n; ++i)
	{
		vt[i] = thread(f1, 1000000);	// ÿ���߳�ִ��1000000��
	}
	for (auto& e : vt)
	{
		e.join();
	}
	cout << x << endl;

	return 0;
}