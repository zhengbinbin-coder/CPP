#include <iostream>

using namespace std;

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣���쳣�׳���ͱ�����в���
//	if (b == 0)
//		throw "��������Ϊ0";	// �׳����쳣�������������͵Ķ��󣬴˴�Ϊ�����ַ���ָ��
//	else
//		return (a / b);
//}
//void Func()
//{
//	int* array = new int[10];		// newһ������
//
//	try								// �ѿ��ܷ����쳣�Ĵ���ŵ�tryģ����
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << Division(a, b) << endl;
//	}
//	catch (const char* errmsg)		// ����--����Ĳ��񲢲���Ϊ�˴����쳣����ֻ��Ϊ�������׳�
//	{
//		delete[] array;				// �����ڴ�й©����
//		throw errmsg;				// �����׳��쳣
//	}
//
//	// �������tryģ����ܻ��׳��������͵��쳣������Ҫ��֮��Ӧ��д����catchģ��ȥ����ͬ������쳣
//	// ���Ը�������������д��
//	catch (...)						// ����--����Ĳ��񲢲���Ϊ�˴����쳣����ֻ��Ϊ�������׳�
//	{
//		delete[] array;				// �����ڴ�й©����
//		throw ;						// �����׳��쳣
//	}
//	
//	delete[] array;					// delete����
//}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)		// �����׳����ַ���ָ��
//	{
//		cout << errmsg << endl;		// ���估�������
//	}
//	catch (...)		// �����������͵��쳣����ֹ�����쳣��ֹ������������֪������Ĵ���
//	{
//		cout << "δ֪�쳣" << endl;
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
	SmartPtr<int> sp(p);	// ʹ������ָ���p���󱣴�����

	throw exception();		// �쳣

	//delete[]p;			// ���ﲻ��Ҫ��ȥ�ֶ��ͷţ�p��������ʱ�����Զ���������ָ�������������p�ͷ�
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
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}


































