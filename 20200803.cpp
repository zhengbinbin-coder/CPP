#include<iostream>

using namespace std;

//// ȫ�ֳ���--����ڳ�����
//const int a = 10;
//const int b = 20;
//
//int main()
//{
//	// �ֲ�����--�����ջ��
//	const int c = 30;
//	const int d = 40;
//
//	return 0;
//}

int main()
{
	//// malloc��һ���СΪһ�����͵Ŀռ䣬����void*�ķ���ֵǿתΪint*,����int*���͵ı���p1
	//int* p1 = (int*)malloc(sizeof(int));

	//// malloc��һ���СΪ8�����͵Ŀռ䣬����void*�ķ���ֵǿתΪchar*,����char*���͵ı���p2
	//char* p2 = (char*)malloc(sizeof(int)*8);

	//// calloc��6���СΪһ�����͵Ŀռ䣬��6���ֽڣ�����ȫ����ʼ��Ϊ0��������void*�ķ���ֵǿתΪint*,����int*���͵ı���p3
	//int* p3 = (int*)calloc(6, sizeof(int));

	//// calloc��8���СΪ5�����͵Ŀռ�,��40���ֽڣ�����ȫ����ʼ��Ϊ0��������void*�ķ���ֵǿתΪchar*,����char*���͵ı���p4
	//char* p4 = (char*)calloc(5, sizeof(int) * 8);


	//
	//// malloc��һ���СΪ20�ֽڵĿռ䣬����void*�ķ���ֵǿתΪint*,����int*���͵ı���p5
	//int* p5 = (int*)malloc(20);
	//// ��p5���ڴ�����1000�ֽ�
	//p5 = (int*)realloc(p5, 1000);
	//// ������δ��뿴��û��ʲô���⣬��ʵ��Ȼ����ԭ����p5�ռ����û��������980�ֽڹ�realloc����
	//// ��realloc�����ڴ�������Ѱ��һ��1000�ֽڵ������ռ䣬��ԭ�ռ�����ݿ���ȥ���ٰ��¿ռ�����ָ�Ϊp5
	//// ��ʱԭ�ռ������û���ͷŵ�������С�Ķ���οռ���з��ʣ��ͻᷢ�����벻�������

	//// ��ȷ���÷��������ģ�
	//// malloc��һ���СΪ20�ֽڵĿռ䣬����void*�ķ���ֵǿתΪint*,����int*���͵ı���p6
	//int* p6 = (int*)malloc(20);
	//int* p7 = NULL;
	//// ��p6���ڴ�����1000�ֽ�,������p7
	//p7 = (int*)realloc(p6, 1000);
	//if (p7 != NULL)
	//{
	//	p6 = p7;	// �ٰ�p7��p6
	//}


	double* p = (double*)malloc(sizeof(int) * 40);
	free(p);

	return 0;
}