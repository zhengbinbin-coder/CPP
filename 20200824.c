//#include<stdio.h>
//
////void swap1(int a, int b)
////{
////	int tmp = a;
////	a = b;
////	b = tmp;
////}
////
////void swap2(int* pa, int* pb)
////{
////	int tmp = *pa;
////	*pa = *pb;
////	*pb = tmp;
////}
//
//int main()
//{
//	//int i = 10;
//	//char c = 'y';
//
//	//int* pi = &i;
//	//char* pc = &c;
//
//	//printf("%d\n", sizeof(pi));	//32位平台输出4，64位平台输出8
//	//printf("%d\n", sizeof(pc));	//32位平台输出4，64位平台输出8
//
//	//// 定义一个double类型的指针变量，指向内存地址为0的空间
//	//double* pd = NULL;
//
//	//// 对空指针进行解引用操作进行访问，赋给double类型的变量
//	//// 此条语句执行出错，内存编号0 ~255为系统占用内存，不允许用户访问
//	//double d = *pd;	
//
//	//// 定义两个变量m和n，并为它们赋初始值
//	//int m = 10;
//	//int n = 20;
//
//	//// const修饰指针，指针的指向可以修改，但指向的值不能修改
//	//const int* pm = &m;
//	//pm = &n;	// 正确，指向可以修改
//	////*pm = 30;	// 报错，指向空间里的值(*pm)不可修改
//
//	//// const修饰常量：指针的指向不能修改，但指向的值可以修改
//	//int* const pn = &n;
//	////pn = &m;	// 报错，指向(pn)不可修改
//	//*pn = 40;	// 正确，指向空间里的值(*pn)可以修改
//
//	//int a = 10;
//	//int b = 20;
//
//	//swap1(a, b);					// 值传递交换a和b
//	//printf("a=%d b=%d\n", a, b);	// a与b并未发生交换
//
//	//swap2(&a, &b);					// 地址传递交换a和b
//	//printf("a=%d b=%d\n", a, b);	// a与b发生了交换
//
//	return 0;
//}
