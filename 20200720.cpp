#include<iostream>

using namespace std;
#include<string>
#include<vector>

//class Animal
//{
//public:
//	virtual void Speak() final	// �������Speak������final���Σ�Cat�ཫ�޷����������д
//	{
//		cout << "������˵��" << endl;
//	}
//	virtual void Eat()
//	{
//		cout << "�����ʳ��" << endl;
//	}
//};
//class Cat final:public Animal // Cat�౻final���Σ�OrangeCat�ཫ�޷��̳�Cat��
//{
//public:
//	/*void Speak() //��������޷�����д
//	{
//		cout << "Сè��˵��" << endl;
//	}*/
//	void Eat() override
//	{
//		cout << "Сè��è��" << endl;
//	}
//};
////class OrangeCat:public Cat // ��������޷���Cat��̳У���Ϊ���ѱ�����Ϊ"final"
////{
////public:
////};


class Student
{
public:
	Student(string name,int age):_name(name),_age(age)
	{ }
	// ��ֹ����������Ĭ�ϵĿ������캯��
	Student(const Student&) = delete;
	// ��ֹ����������Ĭ�ϵĵȺŸ�ֵ���������
	Student& operator=(const Student&) = delete;
private:
	string _name;
	int _age;
};

// ����������һ��������������Ҫʹ��str1����str2
//string create_string()
//{
//	// ����һ��string���͵Ķ���str1
//	string str1 = "hello";	
//
//	// ����string�Ŀ������캯������һ��str2
//	string str2 = str1;		
//
//	// ����ʵ�����Ȱ�str1�е����ݸ��Ƴ������ٸ��Ƶ�str2��
//	// ����Ļ����ϴ�
//
//	// ����������Ҫ����str2����������������str1���Զ����٣�
//	string str2;
//	str2.swap(str1);
//	return str2;
//}

string create_string()
{
	// ����һ��string���͵Ķ���str1
	string str1 = "hello";
	
	// ����һ���յ�str2����str2��str1�����ݽ��н����������Ϳ��Խ�ʡ�����Ŀ���
	string str2;
	str2.swap(str1);
	return str2;
}

int main()
{
	/*Cat c;
	c.Eat();*/

	//// ��򵥵�lambda���ʽ��û���κ�����
	//[] {};

	//// ����a��b��ֵ����Ϊlambda������һ��const��������һ��Ҫʹ��mutableȡ���䳣����
	//// ʹ��mutable���η�ʱ�������б���ʡ��(��ʹ����Ϊ��)
	//// ��ʵ��δ��벢����ʵ��a��b��ֵ�Ľ�������Ϊ�Ǵ�ֵ���õ�
	//int a = 3, b = 4;
	//[a, b]()mutable {int tmp = a; a = b; b = tmp; };

	//// ����a��b��lambda���ʽ����ȷд��---�Դ����õķ�ʽ��׽a��b
	//[&a, &b] {int tmp = a; a = b; b = tmp; };
	//// Ҳ���Բ���׽��ֱ�Ӵ�����
	//[](int& a, int& b) {int tmp = a; a = b; b = tmp; };
	//// Ҳ���������ô��ݲ�׽���б���
	//[&] {int tmp = a; a = b; b = tmp; };
	
	// �����д����У���a��ʾ�����岻ͬʱ�����ĺ���Ҳ��ͬ
	//int a = 42;		// aΪ��ֵ��42Ϊ��ֵ	a��һ��int���͵Ķ���(C���Գ�Ϊ����)��42�ǳ���
	//char c = a;		// cΪ��ֵ��aΪ��ֵ		c��һ��char���͵Ķ���a��ֵΪ42�ĳ���
	
	
	string str1 = "hello";

	//// ��ֵ����
	//// 1.������
	//swap(T& a, T& b);							// ����Ͳ���
	//vector<int>& func(const vector<int> & v);	// ��ߴ���Ч��
	//// 2.������ֵ
	//T& operator[](size_t index);				// ��Ҫ�޸ķ��صĶ���
	//vector<T>& operator=(const vector<T> & v);	// ��ߴ���Ч��


	// ��ֵ����
	string str2 = move(str1);	// ��Ч��string str2 = (string &&) str1;  �൱�ڰ�str1ǿתΪ��string&&���͵���������
	// ��ʹ����move�󣬱��������str1�������֣���str1Ϊ��ֵ����ÿ������캯������str1Ϊ��ֵ�������ƶ����캯��
	

	return 0;
}