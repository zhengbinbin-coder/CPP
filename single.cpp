#include<iostream>
#include<mutex>

using namespace std;

// ֻ���ڶ��ϴ����������
// 1.���캯��˽��
// 2.��װ��̬���нӿ��ڶ��ϴ�������
// 3.����������
class HeapOnly
{
public:
	// ��Ա������Ҫ������ã���û���������޷����ã������Ϊ��̬��Ա����,�ⲿͨ����������
	static HeapOnly* CreateHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}
private:
	// ���캯������˽�����������ⲿ���ã���������ʱͨ�����ڹ��нӿڵ��ô˺�������
	HeapOnly(){ }
	// ��������������ֹ���󱻿�����ջ�ϴ���
	HeapOnly(const HeapOnly&) = delete;
};

// ֻ����ջ�ϴ����������
// ����1�����캯����Ϊ˽�У�����ʱͨ�����нӿ�ʵ��
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
// ������������new������˽����
class StackOnly2
{
public:
	StackOnly2(){ }
private:
	// ����new��������˽��������ֹ����
	void* operator new(size_t size);
	void operator delete(void* p);
};

// ���ܱ���������
class CopyBan
{
public:
	CopyBan(){ }
private:
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};

// ���ܱ��̳е���--final����
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

//// ����ģʽ
//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		return _sInst;
//	}
//private:
//	// ���캯��˽�л�
//	Singleton(){ }
//	// �������캯�����
//	Singleton(const Singleton&) = delete;
//
//	static Singleton _sInst;
//};
//
//Singleton Singleton::_sInst;	// main����֮ǰ�ʹ�����ʼ�������ʵ������--�����ھ�̬��

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		/*
		1.�����̰߳�ȫ����
		if (_spInst == nullptr)	
		{
			_spInst = new Singleton;
		}
		return *_spInst;
		*/

		/*
		2.������̰߳�ȫ���⣬����һ���̴߳�������ʵ��֮�󣬺�����߳̽�����Ȼ������ʵ������Ȼ��Ҫ��������
		_smtx.lock();			// ����
		if (_spInst == nullptr)
		{
			_spInst = new Singleton;
		}
		_smtx.unlock();			// ����
		return *_spInst;
		*/

		// ����ģʽ���̰߳�ȫ���⣬��Ҫ����
		// 3.˫���������Ч������
		if (_spInst == nullptr)		// ���Ч�����⣬������̷߳�������ʵ���Ͳ���ȥ����ֹ��������
		{
			_smtx.lock();			// ����
			if (_spInst == nullptr)	// ����̰߳�ȫ����
			{
				_spInst = new Singleton;
			}
			_smtx.unlock();
		}
		return *_spInst; 
	}
private:
	// ���캯��˽�л�
	Singleton(){ }
	// �������캯�����
	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
	static mutex _smtx;
};

Singleton* Singleton::_spInst = nullptr;		// main����֮ǰ�ʹ�����ʼ��ָ��
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
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	A* pa = new	A;
	B* pb = new B;
	// ��ָ�� = ��ָ�� �����ֱ�Ӿ�֧�ֵ���Ƭ�����Բ���ת��
	pa = pb;

	// ��ָ�� = ��ָ�� ������Ҫת������һ��������ת���ǲ����ʵģ���������²���Ҫ
	// B* p = (B*)pa;	// ������ת��������ȫ	
	B* p = dynamic_cast<B*>(pa);	// ����ת�ǰ�ȫ��--��pa��B*���͵Ķ���Ϳ��Գɹ�����pa��A*���͵Ķ��󣬾�ʧ�ܷ���NULL


	int a = 10;
	double b = static_cast<double>(a);		// ������͡��������(�������Ƶ�����)֮���ת��

	int c = 10;
	int* pc = &c;
	int path = reinterpret_cast<int>(pc);	// ���������֮���ת��

	const int d = 2;
	int* pd = const_cast<int*>(&d);			// ȥ��const���Ե�ת��
	*pd = 3;



	return 0;
}