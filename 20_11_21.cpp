#include<iostream>
#include<stdio.h>

using namespace std;

//#pragma pack(4)
struct A
{
	char c;
	short s;
	int i;
	double d;
	char ch;
};
//#pragma pack()

int main()
{
	/*const char* s1 = "safafage";
	char s2[] = "ssagahhsafhahwefa";
	int arr[4];
	int arr1[sizeof(int)];*/

	A a;
	
	//cout << sizeof(a) << endl;

	cout << offsetof(A, i) << endl;
	
	return 0;
}