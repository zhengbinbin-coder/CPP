#include<iostream>

using namespace std;

//// 全局常量--存放在常量区
//const int a = 10;
//const int b = 20;
//
//int main()
//{
//	// 局部常量--存放在栈区
//	const int c = 30;
//	const int d = 40;
//
//	return 0;
//}

int main()
{
	//// malloc了一块大小为一个整型的空间，将其void*的返回值强转为int*,赋给int*类型的变量p1
	//int* p1 = (int*)malloc(sizeof(int));

	//// malloc了一块大小为8个整型的空间，将其void*的返回值强转为char*,赋给char*类型的变量p2
	//char* p2 = (char*)malloc(sizeof(int)*8);

	//// calloc了6块大小为一个整型的空间，共6个字节，将其全部初始化为0，并将其void*的返回值强转为int*,赋给int*类型的变量p3
	//int* p3 = (int*)calloc(6, sizeof(int));

	//// calloc了8块大小为5个整型的空间,共40个字节，将其全部初始化为0，并将其void*的返回值强转为char*,赋给char*类型的变量p4
	//char* p4 = (char*)calloc(5, sizeof(int) * 8);


	//
	//// malloc了一块大小为20字节的空间，将其void*的返回值强转为int*,赋给int*类型的变量p5
	//int* p5 = (int*)malloc(20);
	//// 将p5的内存扩大到1000字节
	//p5 = (int*)realloc(p5, 1000);
	//// 上面这段代码看似没有什么问题，其实不然；若原来的p5空间后面没有连续的980字节供realloc扩容
	//// 则realloc会在内存中重新寻找一块1000字节的连续空间，把原空间的数据拷进去，再把新空间的名字改为p5
	//// 此时原空间的数据没有释放掉，若不小心对这段空间进行访问，就会发生意想不到的情况

	//// 正确的用法是这样的：
	//// malloc了一块大小为20字节的空间，将其void*的返回值强转为int*,赋给int*类型的变量p6
	//int* p6 = (int*)malloc(20);
	//int* p7 = NULL;
	//// 将p6的内存扩大到1000字节,并赋给p7
	//p7 = (int*)realloc(p6, 1000);
	//if (p7 != NULL)
	//{
	//	p6 = p7;	// 再把p7给p6
	//}


	double* p = (double*)malloc(sizeof(int) * 40);
	free(p);

	return 0;
}