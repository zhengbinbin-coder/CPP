#if 0
//���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ�����ÿһ��ķż����ڶ�����ͬ������������£�
//
//1��1�գ�Ԫ��
//1�µĵ���������һ������·�¡��������
//2�µĵ���������һ����ͳ��
//5�µ����һ������һ��������ʿ������
//7��4�գ���������
//9�µĵ�һ������һ���Ͷ���
//11�µĵ��ĸ������ģ��ж���
//12��25�գ�ʥ����
//���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
//�������� :
//��������������ݣ�ÿ�����ݰ���һ��������year��2000��year��9999����
//
//������� :
//��Ӧÿһ�����ݣ��ԡ�YYYY - MM - DD����ʽ����������еĽ������ڣ�ÿ������ռһ�С�
//ÿ������֮�����һ��������Ϊ�ָ���
//
#include<iostream>
using namespace std;

int WeekToDay(int y, int m, int c, int w, bool B)
{
	//�������ꡢ���¡��ڼ��ܡ����ڼ����������ǵ���
	int d, week, i;
	if (m == 1 || m == 2)
	{
		m += 12;	//�ڻ�ķ����ɭ���㹫ʽ�У���һ�ºͶ��¿�������һ���ʮ���º�ʮ����
		y--;		//���������2004-1-10����ɣ�2003-13-10�����빫ʽ���㡣
	}
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
	{
		//B������/����    
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//��ķ����ɭ��ʽ
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}

int main()
{
	int y;
	while (cin >> y)
	{
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 1, 3, 1, 0));//������һ������һ��������0
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}

//��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an, 
//���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��������ֽ������ӡ�
#include<iostream>
using namespace std;
int main()
{
	int a;
	int i = 0;
	while (cin >> a)
	{
		cout << a << "=";
		i = 2;
		while (1)
		{
			if (a % i == 0)
			{
				cout << i;
				a = a / i;
				break;
			}
			++i;
		}
		while (a >= 2)
		{
			i = 2;
			while (1)
			{
				if (a % i == 0)
				{
					cout << "*";
					cout << i;
					a = a / i;
					break;
				}
				++i;
			}
		}
		cout << endl << endl;
	}
	return 0;
}

//NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
//���ڸ���һ��ʱ�����䣬������������������ж��١�
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>

using namespace std;

//1   2   3   4   5   6   7   8   9  10  11  12
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//1  2  3  4  5  6  7  8  9  10 11 12
int money[13] = { 0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2 };

bool CheckYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int main()
{
	int by, bm, bd;//begin
	int ey, em, ed;//end
	while (scanf("%d%d%d %d%d%d", &by, &bm, &bd, &ey, &em, &ed) != EOF)
	{
		int ny = by, nm = bm, nd = bd;
		if (CheckYear(ny))
		{
			month[2] = 29;
		}
		else
		{
			month[2] = 28;
		}
		int count = 0;
		count = count + money[nm];
		while (1)
		{
			if (ny >= ey)
			{
				if (ny > ey)
					break;
				if (nm >= em)
				{
					if (nm > em)
						break;
					if (nd >= ed)

					{
						break;

					}
				}
			}
			nd += 1;
			count += money[nm];
			if (nd > month[nm])
			{
				nd = 1;
				nm += 1;
				if (nm > 12)
				{
					nm = 1;
					ny += 1;
				}
				if (CheckYear(ny))
					month[2] = 29;
				else month[2] = 28;
			}
		}
		cout << count << endl;
	}
	return 0;
}

//NowCoder�ų��Լ��Ѿ���ס��1 - 100000֮�����е�쳲���������
//Ϊ�˿���������������һ����n������˵����n��쳲���������
//��Ȼ��쳲���������ܴ���ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ��
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	long a[100001] = { 1, 2 };
	for (int i = 2; i < 100001; i++)
		a[i] = (a[i - 1] % 1000000 + a[i - 2] % 1000000) % 1000000;//�����100000����˼���������е�ֵ����ԭ����6λβ��
	while (cin >> n) //ѭ������n
	{
		if (n < 25)//�����жϣ���ʱ������ֵ����100000�ķֽ紦
		{
			cout << a[n - 1] << endl;//ֱ�����
		}
		else
			printf("%06ld\n", a[n - 1]);//�������λ
		cout << endl;
	}
	return 0;
}

//һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ����
//���ڸ����Ļ�������С����������һ���ܴӻ������о����ܼ�������С�������أ�
//���룺	abcde a3
//		aaaaaa  aa
//�����	0
//		3
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char a[1000], b[1000];
	int i, j, stra, strb, k, p, l; //i��jѭ����stra��strb�����ȣ�k��¼i��λ�ã�p��¼a[]��b[]�Ƿ�ȫ��,l������ٸ�
	while (scanf("%s", a) != EOF)//��a������ʱ 
	{
		l = 0;
		if (a[0] == '#')
		{
			return 0;
		}
		else
		{
			scanf("%s", b);
		}
		stra = strlen(a);
		strb = strlen(b);
		for (i = 0; i < stra; i++) //Ѱ�Ҵ�ĳ���ַ���ʼ��ͬ
		{
			if (a[i] == b[0])
			{
				k = i;
				for (j = 0, p = 0; j < strb; j++, k++)
				{
					if (a[k] == b[j])
					{
						p++;//��¼��ͬ�ַ����� 
					}
					if (p == strb)//���Ƿ�ȫ����ͬ 
					{
						l++;
						i = i - 1 + strb;//��i��λ�õ����´˿�ʼ��ǰ��һ���ַ�λ�ã���Ϊ��i++ 
					}
				}
			}
		}
		printf("%d\n", l);
	}
	return 0;
}

//NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼���������ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
//���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
//���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���
//
//�������� :
//�������ݰ������顣
//ÿ�����ݰ�����������from��to(1��from��to��80)���ֱ������ĵ�from��͵�to�졣
//
//������� :
//��Ӧÿһ�����룬�����from��to��Щ�������from��to���죩����Ҫ�����ٷ���͡�
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;

int main(int argc, const char* argv[])
{
	//����һ�ű����ڼ�¼쳲��������еĸ���ֵ����Ҫʹ��long long����������
	long long FibTable[81] = { 0, 1, 1 };
	for (int i = 3; i < 81; ++i)
	{
		FibTable[i] = FibTable[i - 1] + FibTable[i - 2];
	}
	int start = 0, end = 0;
	while (scanf("%d %d", &start, &end) != -1)
	{
		long long result = 0;
		for (int i = start; i <= end; ++i)
		{
			result = result + FibTable[i];
		}
		printf("%lld\n", result);
	}
	return 0;
}

//NowCoderÿ��Ҫ�����ͻ�д�����ʼ���������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
//���ڸ���һ���ռ����������������������Ӧ���ռ����б�
//������������������������ݡ�
//			ÿ�����ݵĵ�һ����һ������n��1��n��128������ʾ������n��������
//			������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���
//�����������Ӧÿһ�����룬���һ���ռ����б�
//ʾ�������룺
//			3
//			Joe
//			Quan��William
//			Letendre��Bruce
//			2
//			Leon
//			Kewell
//		�����
//			Joe����Quan��William������Letendre��Bruce��
//			Leon��Kewell
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		string name;
		for (int i = 0; i < n; ++i)
		{
			getline(cin, name);
			if (n != n - 1)
			{
				if (name.find(',') != string::npos || name.find(' ') != string::npos)
				{
					cout << "\"" << name << "\"" << "," << " ";
				}
				else
				{
					cout << name << "," << " ";
				}
			}
			else
			{
				if (name.find(',') != string::npos || name.find(' ') != string::npos)
				{
					cout << "\"" << name << "\"" << endl;
				}
				else
				{
					cout << name << endl;
				}
			}
		}
	}
	return 0;
}

#include <iostream>
#include <string>
#include <cstdio>
int main()
{
	int n;
	while (std::cin >> n) //��������
	{
		std::cin.get(); //����س�
		std::string name;
		for (int i = 0; i < n; i++) //���ֱַ���
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //�ҵ����Ż��߿ո񣬾�Ҫ��˫����
			{
				quote = true;
			}
			if (quote)
			{
				putchar('\"'); //putcharЧ�ʸ���
			}
			std::cout << name;
			if (quote)

			{
				putchar('\"');
			}
			if (i == n - 1) //����Ѿ������һ���ַ������ǾͲ��س�������Ӷ��źͿո�
			{
				putchar('\n');
			}
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return 0;
}

//һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
//
//�������� :
//�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��
//
//������� :
//��Ӧ�����n���м�ֻ����(����û��������������)��
//ʾ��1
//����
//1
//2
//���
//1
//2
#include<iostream>
#include<string>
#include<vector>

int main()
{
	long long rabbit[90];
	rabbit[0] = 1;
	rabbit[1] = 2;
	for (int i = 2; i < 90; i++)
	{
		rabbit[i] = rabbit[i - 1] + rabbit[i - 2];
	}
	int num;
	while (std::cin >> num)
	{
		std::cout << rabbit[num - 1] << std::endl;
		std::cin.get();
	}
	return 0;
}

//���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
//����������������ϣ�ÿ�˴�����ȡһ�������� ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
//���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�
//������������������������ݣ�ÿ�����ݰ���һ��������n��2��n��20��
//�����������Ӧÿһ�����ݣ��ԡ�xx.xx%���ĸ�ʽ����������˻񽱵ĸ���
//ʾ�� : ���� 2 ��� 50.00%
//����˼· ����һ�����͵Ĵ����㷨�����ǵ� �� n �������ʱ�򣬱�֤ÿһ�����󶼲����Լ�ԭ����λ���ϵķ����� D(N) ��
//����ͨ�� : D(n) = (n - 1)[D(n - 2) + D(n - 1)], �����D(1) = 0, D(2) = 1;
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	long long d[22] = { 0, 0, 1 };
	// ����������Ԥ����һ��Ϊ 0 ���������������� n
	long long f[22] = { 0, 1, 2 };
	// �� ��
	for (int i = 3; i < 22; i++)
	{
		d[i] = (i - 1) * (d[i - 2] + d[i - 1]);// ���ŵĵ��ƹ�ʽ
		f[i] = i * f[i - 1]; // �׳˵ĵ��ƹ�ʽ
	}
	int n;
	while (cin >> n)
	{
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// �� 100.0 ���ѽ������� double ��������λС��
	}
	return 0;
}

//NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ��
//���Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ������ڸ���һ�������б�
//�����ж�Ŀ���û��Ƿ��ڳ����б���
//
//���������������ж������ݣ�ÿ�����������С���һ�г����б�����֮����һ�����Ÿ�������������а�
//���ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ����ڶ���ֻ����һ���������Ǵ����ҵ��û�
//�����֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���
//
//�������������ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ������
//�����Important!������ʾ����ʼ���Ҫ�����ȴ���
//
//����
//Joe, Kewell, Leon
//Joe
//��Letendre, Bruce��, Joe, ��Quan, William��
//William
//���
//Ignore
//Important!

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<string>names;
		size_t pos = 0;
		while (pos < line.length())
		{
			if (line[pos] == '\"')
			{
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1));
				pos = end + 2;
			}
			else
			{
				size_t end = line.find(",", pos + 1);
				if (end == -1)
				{
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1;
			}
		}
		getline(cin, line);
		if (names.end() == find(names.begin(), names.end(), line))
		{
			printf("Important!\n");
		}
		else
		{
			printf("Ignore\n");
		}
	}
	return 0;
}


//bool Erase(const K & key)
//{
//	size_t index = key%_tables.size();
//	Node*cur = _tables[index];
//	while (cur)
//	{
//		if (cur->_data.first == key)
//		{
//			if (prev == Null)
//			{
//				_tables[index] = cur->_next;
//			}
//			else
//			{
//				prev_next = cur_next;
//			}
//			delete cur;
//			cur = Null;
//			_dataNum--;
//			return true;
//		}
//		prev = cur;
//		cur = cur->next;
//	}
//	return false;
//}

#include<iostream>
using namespace std;
int main()
{
	cout << "hello,world" << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	cout << "hello,world" << endl;
	system("pause");
	return 0;
}

//���ݿ����ӳأ�
//Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲ
//Ϊ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���
//û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻ�
//���������ӳ��У�����������ʹ�á������ṩ�㴦���������־���������һ
//�����ӳ������Ҫ�������ٸ����ӡ�
//
//������������������������ݣ�ÿ�����ݵ�һ�а���һ������n��1��n��1000������ʾ�����������
//������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����
//�����������Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�
//����
//6
//A connect
//A disconnect
//B connect
//C connect
//B disconnect
//C disconnect
//���
//2
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> id >> con;
			if (con == "connect")
			{
				pool.insert(id);
			}
			else if (con == "disconnect")
			{
				pool.erase(id);
			}
			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}

//mkdir:�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ������
//����Ҫ����Ŀ¼�� / usr / local / bin��������Ҫ�˴δ����� / usr������ / usr / local���Լ��� / usr / local / bin����
//���ڣ�Linux��mkdir�ṩ��ǿ��ġ� - p��ѡ�ֻҪһ�����mkdir - p / usr / local / bin�������Զ�������Ҫ���ϼ�Ŀ¼��
//���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir - p�����
//
//������������������������ݡ�ÿ�����ݵ�һ��Ϊһ�������� n(1��n��1024)��
//������ n �У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ����� 200 ���ַ���
//
//�����������Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������� ��mkdir - p�� ���ÿ������֮�����һ��������Ϊ�ָ���
//����
//3
/// a
/// a / b
/// a / b / c
//3
/// usr / local / bin
/// usr / bin
/// usr / local / share / bin
//���
//mkdir - p / a / b / c
//mkdir - p / usr / bin
//mkdir - p / usr / local / bin
//mkdir - p / usr / local / share / bin
#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string>list(n);
		vector<bool>flag(n, true);
		for (int i = 0; i < n; ++i)
		{
			cin >> list[i];
		}
		sort(list.begin(), list.end());
		//�������ַ����������򣬷���һ��
		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1��������ͬ
			// 2��ǰ���Ǻ󴮵��Ӵ������Һ󴮺�һλ�� '/'
			if (list[i] == list[i + 1])
			{
				flag[i] = false;
			}
			else if (list[i].size() < list[i + 1].size()
				&& list[i] == list[i + 1].substr(0, list[i].size())
				&& list[i + 1][list[i].size()] == '/')
			{
				flag[i] = false;
			}
		}
		for (int i = 0; i < list.size(); ++i)
		{
			if (flag[i])
			{
				cout << "mkdir -p " << list[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}

//����ڣ�������һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש��
//��վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵĺ�ɫ��ש�ƶ���
//��дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש���������������ݼ��ϡ�
//ÿ�����ݼ��ϵĵ�һ������������W��H���ֱ��ʾx�����y�����ש��������W��H��������20��
//�ڽ�������H���У�ÿ�а���W���ַ���ÿ���ַ���ʾһ���ש����ɫ����������
//1����.������ɫ�Ĵ�ש��
//2����#������ɫ�Ĵ�ש��
//3����@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�
//����һ���ж������������ʱ����ʾ���������
//�����ÿ�����ݼ��ϣ��ֱ����һ�У���ʾ��ӳ�ʼλ�ó����ܵ���Ĵ�ש��(����ʱ������ʼλ�õĴ�ש)��
//
//��������
//6 9
//....#.
//.....# 
//......
//......
//......
//......
//......
//#@...# 
//.#..#.
//0 0
//�������
//45
#include<iostream>
using namespace std;
#define MAX_W 20
#define MAX_H 20

int W, H;
int step = 0;

char room[MAX_W][MAX_H];
const int direc[4][2] = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };

int dfs(const int& row, const int& col)
{
	room[row][col] = '#';
	++step;
	for (int d = 0; d < 4; ++d)
	{
		int curRow = row + direc[d][1];
		int curCol = col + direc[d][0];
		if (curRow >= 0 && curRow < H && curCol >= 0 && curCol < W && room[curRow][curCol] == '.')
		{
			dfs(curRow, curCol);
		}
	}
	return step;
}

int main()
{
	bool found;
	while (cin >> W >> H, W > 0)
	{
		step = 0;
		int row, col;
		for (row = 0; row < H; ++row)
		{
			for (col = 0; col < W; ++col)
			{
				cin >> room[row][col];
			}
		}
		found = false;
		for (row = 0; row < H; ++row)
		{
			for (col = 0; col < W; ++col)
			{
				if (room[row][col] == '@')
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		cout << dfs(row, col) << endl;
	}
	return 0;
}

//Ģ������������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1, 1), B��(n, m)������A��Ҫ�ݷ�B��
//������ֻ��ȥB�ļң�����ÿ����ֻ����(i, j + 1)��(i + 1, j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����)
//�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
//
//�������� :��һ��N��M��K(1 �� N, M �� 20, k �� 100), N, MΪ�ݵش�С��������K�У�ÿ����������x��y������(x, y)����һ��Ģ����
//������� :���һ�У������������(������2λС��)
//
//����
//2 2 1
//2 1
//���
//0.50
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int i, j;
		int has[25][25];//����Ģ��
		double dp[25][25];//�ܹ�����ÿ�����ӵĸ���
		memset(has, 0, sizeof(has));
		memset(dp, 0, sizeof(dp));
		int x, y;
		for (i = 0; i < k; ++i) {
			cin >> x >> y;
			has[x][y] = 1;
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if (i == 1 && j == 1) { dp[1][1] = 1; continue; }
				if (has[i][j]) { dp[i][j] = 0; continue; }
				if (i == n && j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; continue; }
				if (i == n) { dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; continue; }
				if (j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; continue; }
				if (i == 1) { dp[i][j] = dp[i][j - 1] * 0.5; continue; }
				if (j == 1) { dp[i][j] = dp[i - 1][j] * 0.5; continue; }
				dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
			}
		}
		cout << fixed << setprecision(2) << dp[n][m] << endl;
	}
	return 0;
}

//�ַ������������ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��
//�������� :ÿ�����ݰ���s1������С��100����s2������С��100����len1��С��100000����len2������len1��С��100000��
//����
//ab ce 1 2
//���
//56
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
	//�������и��������ӣ�����ַ���ֻ����Сд��ĸ����Ȼ�𰸾Ͳ�Ӧ����56��
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		//ֻ����Сд��ĸ���ַ������Կ���26���Ƶ�����
		//��s1��s2������len2����
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		vector<int>array;
		for (int i = 0; i < len2; i++)
		{
			array.push_back(s2[i] - s1[i]);
		}
		int result = 0;
		for (int i = len1; i <= len2; i++)
		{
			for (int k = 0; k < i; k++)
			{
				result += array[k] * pow(26, i - 1 - k);
			}
		}
		//�����ַ�����󶼲�������s2�����������Ҫ��1��
		cout << result - 1 << endl;
	}
	return 0;
}

//�����������:�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ�����������
//�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
//���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�
//
//�������� :��������������ݡ�ÿ�����ݰ��������ַ���m��n�����ǽ�������ĸ�����ҳ��Ȳ�����1024��
//
//������� :��Ӧÿ�����룬�������������еĳ��ȡ�
//
//�������� :
//abcfbc abfcab
//programming contest
//abcd mnp
//������� :
//4
//2
//0

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int aLength = A.length();
		int bLength = B.length();
		vector<vector<int>>dp(aLength, vector<int>(bLength, 0));
		// ��ʼ���߽�
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < aLength; i++)
		{
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < bLength; j++)
		{
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}
		// ����
		for (int i = 1; i < aLength; i++)
		{
			for (int j = 1; j < bLength; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[aLength - 1][bLength - 1] << endl;
	}
	return 0;
}

//���ʼ�(�Ŵ�����)��NowCoderÿ��Ҫ���ܶ��˷��ʼ�����һ�������ַ������ʼ����ѷ���A���ʼ�������B���ѷ���B���ʼ�������A��
//��������˼����Ҫ��n���˷��ʼ�����ÿ���˽��յ�1���ʼ�������£��ж���������������˶��յ��˴�����ʼ�����û�����յ������Լ����ʼ���
//
//������������������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����
//������� :��Ӧÿһ�����ݣ����һ������������ʾ�����յ��Լ��ʼ���������
//
//����  2 3
//���  1 2
#include<iostream>
using namespace std;
int main()
{
	long long der[21] = { 0, 0, 1 };
	int i;
	for (i = 3; i < 21; i++)
	{
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
	}
	int n;
	while (cin >> n)
	{
		cout << der[n] << endl;
	}
	return 0;
}

//�����������:�㳡��վ��һ֧���飬����������ȫ�����ص�Ť������ӣ����������ǵ�������ݣ�
//			   �����æ�ҳ�������ε����������С� ����������������ǣ�1��7��3��5��9��4��8����
//			   �������ε������������У�1��7������1��3��5��9������1��3��4��8���ȣ�������ĳ���Ϊ4��
//�������� :��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000����
//		  �����ŵڶ��а���n��������m��1��n��10000�������������ÿλ��Ա����ߡ�
//������� :��Ӧÿһ�����ݣ��������������еĳ��ȡ�
//
//�������� :7
//		    1 7 3 5 9 4 8
//		    6
//		    1 3 5 2 4 6
//������� :4
//		    4
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int m = n;
		int val;
		int* a = new int[n];
		int k = 0;
		while (m--)
		{
			cin >> val;
			a[k++] = val;
		}
		int max = 1;
		int* b = new int[n];
		for (int i = 0; i < k; i++)
		{
			b[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (a[j] < a[i])
				{
					if (b[j] + 1 > b[i])
					{
						b[i] = b[j] + 1;
						if (max < b[i])
						{
							max = b[i];
						}
					}
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}

//������룺nowcoderҪ�����ѽ���һЩ���е���Ϣ���������ĵ绰����ȡ�
//�����Ҫ����Щ������Ϣ���л����������������м����һЩ����ķ��ţ�������������һ�����롣
//���������æ����һ����򣬽�����nowcoder�Ƕ����յ�����Ϣ����ȡ���м����õ���Ϣ��
//
//���������������ж��С�ÿһ����һ�ξ������ܵ���Ϣ�����п��ܰ����ո񣩣�����ԭʼ��Ϣ���Ȳ�ȷ����
//������������ÿ����Ϣ��������Ϣ��
//
//����
//$Ts!47 & s456 a23 + B9k
//���
//47456239
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		int len = s.length();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}

//���Թ�:NowCoder��ϲ�����ֳ����Թ���Ϸ������С����Ǳ���˭���߳��Թ���
//	   ���ڰ��Թ��ĵ�ͼ���㣬���ܰ����������߳��Թ���Ҫ���ٲ���
//�������� :��������������ݡ�ÿ�����ݰ���һ��10 * 10���ɡ�#���͡�.����ɵ��Թ���
//		 ���С�#������ǽ����.������ͨ·������ڵ�һ�еڶ��У����������һ�еھ��С�
//		 ������һ����.���㶼��һ���ߵ����������ĸ�����ġ�.���㡣
//������� :��Ӧÿ�����ݣ��������ڵ����������Ҫ������
//
//
//����		#.########			#.########
//			#........#			#........#
//			#........#			########.#
//			#........#			#........#
//			#........#			#.########
//			#........#			#........#
//			#........#			########.#
//			#........#			#........#
//			#........#			#.######.#
//			########.#			########.#
//���:	16 30

#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstring>
using namespace std;

char s[10][10];
int a[10][10];
int minLen;
int totalLen;

int min(int a, int b)
{
	return a > b ? b : a;
}

void dfs(int x, int y)//������һ�еڶ��г������� 
{
	if (x < 0 || x >= 10 || y < 0 || y >= 10) return;//Խ�����鷶Χ���򷵻� 
	if (x == 9 && y == 8)//��������ʱȡ�������е���Сֵ 
	{
		minLen = min(minLen, totalLen);
		return;
	}
	if (s[x][y] == '#') return;//����#��ֹͣ���� 
	if (minLen <= totalLen) return;//�ҵ�һ��·���ĳ����ܺ��Ѿ�������ǰ���Ѿ��ҵ������·�����򷵻� 
	a[x][y] = 1;//��Ǵ�λ���Ѿ������� 
	totalLen++;//·����һ 
	if (x - 1 >= 0 && s[x - 1][y] == '.' && !a[x - 1][y]) dfs(x - 1, y);//�������� 
	if (x + 1 < 10 && s[x + 1][y] == '.' && !a[x + 1][y]) dfs(x + 1, y);//�������� 
	if (y - 1 >= 0 && s[x][y - 1] == '.' && !a[x][y - 1]) dfs(x, y - 1);//�������� 
	if (y + 1 < 10 && s[x][y + 1] == '.' && !a[x][y + 1]) dfs(x, y + 1);//�������� 
	totalLen--;//���ˣ����ݣ� 
	a[x][y] = 0;//���� 
}

int main()
{
	while (scanf("%s", s[0]))
	{
		for (int i = 1; i < 10; i++)
		{
			scanf("%s", s[i]);
		}
		minLen = 1 << 30;
		totalLen = 0;
		memset(a, 0, sizeof(a));
		dfs(0, 1);
		cout << minLen << endl;
	}
	return 0;
}

//�绰���룺��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ��
//���繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT - GLOP�ʹ���888 - 4567��310 - GINO����310 - 4466��
//NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�
//
//�������� :
//��������������ݡ�
//ÿ�����ݵ�һ�а���һ��������n��1��n��1024����
//������n�У�ÿ�а���һ���绰���룬�绰����������ַ��� - �������ֺʹ�д��ĸ��ɡ�
//û���������ֵ����ַ��������ų����ַ��󳤶�ʼ��Ϊ7�������绰����ֻ��7λ����
//
//������� :
//��Ӧÿһ�����룬�����ֵ�˳��������ظ��ı�׼������ʽ�绰���룬����xxx - xxxx����ʽ��
//ÿ���绰����ռһ�У�ÿ������֮�����һ��������Ϊ�������
#include<iostream>
#include<string>
#include<set>
using namespace std;

string AtoS(string s2, string s1)
{
	string s = "";
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] >= '0' && s2[i] <= '9')
		{
			s.push_back(s2[i]);
		}
		else if (s2[i] == '-')
		{
			continue;
		}
		else
		{
			char b = s1[s2[i] - 'A'];
			s.push_back(b);
		}
	}
	string ret1 = s.substr(0, 3);
	string ret2 = s.substr(3, 4);
	s = "";
	s += ret1;
	s.push_back('-');
	s += ret2;
	return s;
}

int main()
{
	string s1 = "22233344455566677778889999";
	int n;
	while (cin >> n)
	{
		set<string>data;
		for (int i = 0; i < n; i++)
		{
			string a;
			cin >> a;
			string s = AtoS(a, s1);
			data.insert(s);
		}
		for (auto& e : data)
		{
			cout << e << endl;
		}
		cout << endl;
	}
	return 0;
}

//��������������C / C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣
//C���Է��ʹ���»��߷ָ�������ʣ����硰hello_world������Java�����һ�ֽ�������
//�����Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
//���������ĳ���Ա���Զ�ת����������
//
//��������
//��������������ݡ�ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100��
//
//�������
//��Ӧÿһ�����ݣ������������Ӧ��������������
//
//����
//hello_world
//nice_to_meet_you
//���
//helloWorld
//niceToMeetYou
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		string res;
		for (int i = 0; i <= s.size(); ++i)
		{
			if (s[i] == '_')
			{
				s[i + 1] = s[i + 1] - 32;
			}
			else
			{
				res = res + s[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}

//���ַ����е����е��ʽ��е��š�
//1��ÿ����������26����д��СдӢ����ĸ���ɣ�
//2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
//3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
//4��ÿ�������20����ĸ��
//
//����������
//����һ���Կո����ָ��ľ���
//
//���������
//������ӵ�����
//
//���룺I am a student
//
//�����student a am I
//
//˼·��
//���α��������ַ���������ַ�����ֱ������������Ҫ����ַ������ַ���ѹ���������ַ������㣬�ټ�����������ַ�����ֱ��������ȫΪֹ
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	vector<string>data;
	while (getline(cin, str))
	{
		string temp;
		for (int i = 0; i < str.size(); i++)
		{
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			{
				temp += str[i];
			}
			else
			{
				if (temp.size() > 0)
				{
					data.push_back(temp);
					temp.clear();
				}
			}
		}
		if (temp.size() > 0)
			data.push_back(temp);
		reverse(data.begin(), data.end());
		for (int i = 0; i < data.size() - 1; i++)
			cout << data[i] << ' ';
		cout << data[data.size() - 1] << endl;
	}
	return 0;
}

//ƹ�����nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ�����������Ҫ�б�A���Ƿ������B�������е����࣬����ÿ���������������B���е�����������ô���أ�
//
//�������� :�����ж������ݡ�ÿ�����ݰ��������ַ���A��B������A����B���е�ƹ����ÿ��ƹ������һ����д��ĸ��ʾ������ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ���ַ������Ȳ�����10000��
//
//������� :ÿһ�������Ӧһ����������B�����������������A�ж��У�����ÿ�����������������A���������Yes�������������No����
//
//�������� :ABCDFYE CDE
//	      ABCDGEAS CDECDE
//
//������� : Yes
//		     No
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char str1[10001] = { '\0' }, str2[10001] = { '\0' };
	while (scanf("%s %s", str1, str2) != -1)
	{
		int table[26] = { 0 };
		for (int i = (int)strlen(str1); i >= 0; --i)
		{
			table[str1[i] - 'A'] += 1;
		}
		bool flag = true;
		for (int i = (int)strlen(str2); i >= 0; --i)
		{
			if (--table[str2[i] - 'A'] < 0)
			{
				flag = false;
				break;
			}
		}
		printf("%s\n", (flag ? "Yes" : "No"));
	}
	return 0;
}

//�����ֵܵ��ʣ�ʵ��һ���ɴ洢���ɸ����ʵ��ֵ䡣�û����ԣ�
//1�����ֵ��м��뵥��
//2������ָ���������ֵ��е��ֵܵ��ʸ���
//3������ָ�����ʵ�ָ����ŵ��ֵܵ��ʣ�ָ�����ָ�ֵ����ֵܵ��ʰ��ֵ�˳����������ţ���1��ʼ��
//4������ֵ������е���
//
//���塢��ʽ˵����
//���ʣ���СдӢ����ĸ��ɣ����������ַ�
//�ֵܵ��ʣ�����һ������X�����ͨ�����⽻����������ĸ��λ�õõ���ͬ�ĵ���Y����ô����Y��X���ֵܵ���
//�ֵ�˳���������ʣ���ĸ������������˳�򣩣����Ե�һ����ĸ��Ϊ����Ļ�׼�������һ����ĸ��ͬ�����õڶ�����ĸΪ��׼������ڶ�����ĸ��ͬ����
//��������ĸΪ��׼���������ƣ������ĳ����ĸ����ͬ����ĸ˳����ǰ���Ǹ�����˳����ǰ������̵����ǳ����ʴ�����ĸ��ʼ������һ���֣��̵���˳����ǰ
//������bca��abc���ֵܵ��ʣ�abc��abc����ͬ���ʣ������ֵܵ���
//
//���
//0 <= �ֵ����������ʸ��� <= 1000
//1 <= ����������ĸ�� <= 50
//ע������������֤���ӿ������벻�ᳬ������Լ��
//
//�������� :
//�������ֵ��е��ʵĸ�����������n��������Ϊ�ֵ䵥�ʡ�
//����һ�����ʣ����������ֵ����ֵܵ��ʵĸ���
//����������n
//
//������� :
//�������룬������ҵ����ֵܵ��ʵĸ���
//
//ʾ��1
//����
//3 abc bca cab abc 1
//���
//2
//bca
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int main()
//{
//	vector<string>s;
//	vector<string>temp;
//	string string1;
//	int n = 0;
//	int N;
//	cin >> N;
//	while (cin >> string1)
//	{
//		s.push_back(string1);
//		n++;
//		if (n == N)
//		{
//			break;
//		}
//	}
//	sort(s.begin(), s.end());
//	for (int i = 0; i < N; i++)
//	{
//		cout << s[i] << " ";
//	}
//	cout << "input the finding letter";
//	int index;
//	cin >> index;
//	int count = 0;
//	for (int i = 0; i < N; i++)
//	{
//		if (i != index - 1 && s[i] != s[index - 1])
//		{
//			string string2 = s[i];
//			sort(string2.begin(), string2.end());
//			cout << string2 << endl;
//			if (string2.compare(s[i]) != 0)
//			{
//				count++;
//				temp.push_back(s[i]);
//			}
//		}
//	}
//	cout << count << " ";
//	for (int i = 0; i < temp.size(); i++)
//	{
//		cout << temp[i] << " ";
//	}
//	return 0;
//}
//����

//��ӡ�������֡���ϣ����ϸ��Ϣ
#include<iostream>
using namespace std;
int main()
{
	cout << "Ӣ�����ƣ��������֡���ϣ" << endl;
	cout << "�˺���56\t\t�������룺600\n"
		<< "���ף�15.5��+3.4��\tħ��30��+0.0��\n"
		<< "����ֵ��395��+79��\t�����ظ���0.9��+0.11��" << endl;
	system("pause");
	return 0;
}

//�����г��ִ�������һ�������:��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
#include<iostream>
using namespace std;
int Serach(int arr[], int len)
{
	int count = 1;
	int result = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (count == 0)
		{
			result = arr[i];
			count = 1;
		}
		else if (result == arr[i])
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	return result;
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Serach(arr, sz);
	cout << ret << endl;
	system("pause");
	return 0;
}

//�ϳ��ţ��� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����
//Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
//
//�������� :ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n(1 <= n <= 50)����ʾѧ���ĸ�������������һ�У�
//		  ���� n ����������˳���ʾÿ��ѧ��������ֵ ai�� - 50 <= ai <= 50������������һ�а�������������k �� d(1 <= k <= 10, 1 <= d <= 50)��
//������� :���һ�б�ʾ���ĳ˻���
//
//���룺3
//	  7 4 7
//	  2 50
//�����49
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, k, d;
	long long int res;
	res = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> k;
	cin >> d;
	long long int fmax[11][50] = { 0 };
	long long int fmin[11][50] = { 0 };
	for (int j = 1; j <= k; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (j == 1)
			{
				fmax[j][i] = arr[i];
				fmin[j][i] = arr[i];
			}
			for (int p = 1; p <= d; p++)
			{
				if (i - p >= 0 && i - p < n)
				{
					fmax[j][i] = max(fmax[j][i], max(fmax[j - 1][i - p] * arr[i], fmin[j - 1][i - p] * arr[i]));
					fmin[j][i] = min(fmin[j][i], min(fmax[j - 1][i - p] * arr[i], fmin[j - 1][i - p] * arr[i]));
				}
			}
			res = max(res, fmax[k][i]);
		}
	}
	cout << res;
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
	system("pause");
	return 0;
}

//��Ϸ��:�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ����ʵı��ݽ��������ų�����
//	���������ǰ�������ۣ�С�����������˽⵽�� ��Ϸ���������һ���½�Ŀ������޺�����������Ϸ��Ա����
//	�����ݡ����ǵ���ȫ���أ�Ҫ����޺������У�վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ� ��
//	����Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬����ͷ����ΰ�����Ա�����⡣С�������������ܼ�
//	��������ͳ���˲�������޺������ݵ�������Ա��������أ����Һܿ��ҵ�������޺�������Ա���С� ������
//	����Ҳ�õ�������һ��������ر����ҳ����Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա���α��Ϊ1��N��
//
//�������� :����һ��������N����ʾ��Ա������֮��N�У�ÿ�����������ֱ��Ӧ��Ϸ��Ա��ţ����غ���ߡ�
//
//������� :������m����ʾ�޺����ĸ߶ȡ�
//
//�������� :
//6
//1 65 100
//2 75 80
//3 80 100
//4 60 95
//5 82 101
//6 81 70
//�������:4
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int w;
	int h;
	node(int _w, int _h) :w(_w), h(_h) {}
};

bool cmp(node first, node next)
{
	if (first.w != next.w)
	{
		return first.w < next.w;
	}
	else
	{
		return first.h > next.h;
	}
}

int main()
{
	int input;
	while (cin >> input)
	{
		int num, w, h;
		vector<node> vec;
		for (int i = 0; i < input; ++i)
		{
			cin >> num >> w >> h;
			node tmp(w, h);
			vec.push_back(tmp);
		}
		stable_sort(vec.begin(), vec.end(), cmp);
		vector<int>dq(input + 1, 0);
		dq[0] = 1;
		for (int i = 0; i < input; ++i)
		{
			dq[i] = 1;
			for (int j = 0; j < i; ++j)
			{
				if (vec[j].h <= vec[i].h && dq[j] + 1 >= dq[i])
				{
					dq[i] = dq[j] + 1;
				}
			}
		}
		int max = 0;
		for (int i = 0; i < dq.size(); ++i)
		{
			if (max < dq[i])
			{
				max = dq[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}

//������ֵ����:����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0..K]���Ҳ���A[K + 1..N - 1]��K����ȡֵ�ķ�Χ
//��[0, N - 2]������ô�໮�ַ����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�������������A������Ĵ�Сn���뷵����Ŀ����Ĵ𰸡�
//
//����������[2, 7, 3, 1, 1], 5
//���أ�6
//
//���������ܴ��ķָ���������һ���ֵ����ֵ�϶���������������ֵmax����Ҫ�������ֲ�ֵ��󣬾�Ҫʹ������max���ǲ������ֵ��С�����ȣ��ҵ������е����ֵmax��
//
//����������һ��max��λ�û�Խ�����ʲôӰ�죺��max������Ϊ0��λ�ã���ʱ���ܴ�����ָ����󲿷ֵ������ֵһ��Ϊmax, ���Ҳ���һ������A[n - 1], 
//��A[n - 1]Ϊ��Сֵʱ�����ǿ϶�����A[n - 1]��ǰ��ָ�����֤A[n - 1]���Ҳ������ֵ��ʹ���硾7, 3, 1������1ǰ��ָ�����ʱ����ֵΪmax - A[n - 1]��
//��max������Ϊn - 1��λ��, ͬ������ֵΪmax - A[0]�����max���м׵�λ�ã������Ǿ�ȡmax - A[0]��max - A[n - 1]������ֵ
//�ܽ��������������ֵ = Math.max(max - A[0]��max - A[n - 1])
public class MaxGap
{
	public int findMaxGap(int[] A, int n)
	{
		int max = A[0];
		for (int i = 1; i < n; i++)
		{
			if (A[i] > max)
			{
				max = A[i];
			}
		}
		int min = Math.min(A[0], a[n - 1]);
		return max - min;
	}
};

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	//������ε����ֵ
	//cout << INT_MAX << endl;

	////ǿ����С���ķ�ʽ��ʾ
	//cout << fixed;
	////������ʾ�ľ���
	//cout << setprecision(2);
	//double doubleNum = 100.0 / 3.0;
	//cout << doubleNum *1000000<< endl;

	system("pause");
	return 0;
}

//��������������ֵ
#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "�������һ����a��" << endl;
	cin >> a;
	cout << "������ڶ�����b��" << endl;
	cin >> b;

	//��ʾ����ǰ��������
	cout << endl << "����ǰ" << endl << "aΪ��" << a << endl << "bΪ��" << b << endl;

	//������������ֵ
	c = a;
	a = b;
	b = c;

	//��ʾ�������������
	cout << endl << "������" << endl << "aΪ��" << a << endl << "bΪ��" << b << endl;

	system("pause");
	return 0;
}

//Сд��ĸת��Ϊ��д��ĸ
#include<iostream>

using namespace std;

int main()
{
	char a;
	cout << "������һ��Сд�ַ���" << endl;
	cin >> a;

	a -= 32;
	cout << "ת����Ϊ:" << endl << a << endl;

	system("pause");
	return 0;
}

//�������͵Ĵ�С
#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("�������͵Ĵ�С��");//�޸ı�����
	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(long double) << endl;
	cout << sizeof(long long) << endl;

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{

	cout << "\a" << endl;//  \a--����
	system("pause");
	return 0;
}

//����--�ȽϺ���
#include<iostream>
using namespace std;

int main()
{
	cout << "\a" << endl;//  \a--����
	system("pause");
	return 0;
}

//�趨��ӡ���ַ����
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double a1 = 155;
	double a2 = 486;
	double a3 = 848;
	//�趨��ӡ���ַ����-----Ĭ���Ҷ���
	cout << setw(8) << a1
		<< setw(8) << a2
		<< setw(8) << a3 << endl;
	//�趨�����
	cout << left;
	//�趨���
	cout << setfill('_');
	cout << setw(8) << a1
		<< setw(8) << a2
		<< setw(8) << a3 << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("��ϵ����������н����");
	cout << "15����78��" << (15 > 78) << endl;
	cout << "15С��78��" << (15 < 78) << endl;

	cout << boolalpha;//��boolֵ��ʾΪtrue��false
	cout << "15����78��" << (15 > 78) << endl;
	cout << "15С��78��" << (15 < 78) << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	//�ж�ĳ���·��м���
	int month = 12;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cout << "31��" << endl;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "30��" << endl;
		break;
	case 2:
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	for (int n = 1; n <= 100; n++)
	{
		cout << "С�˱�ס�����ݵĳǱ�\t" << "��" << n << "��" << endl;
	}
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	for (int i = 1; i <= 100; i++)
	{
		n += i;
	}
	cout << n << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	//��ӡ����
	//��ʹ��forѭ����ӡ1997��7�µ�����
	//��֪��1997��7��1�գ����ڶ�������ۻع�ٹ�ͬ��
	//1.�������
	int day = 31;          //7��һ����31��
	int dayOfWeek = 2;     //7�µ�һ�����ܶ�
	cout << "һ\t��\t��\t��\t��\t��\t��" << endl;
	//��ӡ\t   �ܼ�-1
	for (int i = 0; i < dayOfWeek - 1; i++)
	{
		cout << "\t";
	}
	//��ӡ����
	for (int i = 1; i <= day; i++)
	{
		cout << i;
		if ((i + dayOfWeek - 1) % 7 == 0)
		{
			cout << "\n";
		}
		else
		{
			cout << "\t";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	//��1-100֮���ż����
	int sum = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 != 0)
		{
			continue;
		}
		sum += i;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("����һ���������λ����֮��");
	//����һ���������λ����֮��
	int sum = 0, n, a;
	cin >> n;
	do
	{
		a = n % 10;
		sum += a;
		n /= 10;
	} while (n > 0);
	cout << sum << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("���飺");
	int array[] = { 15, 55, 7, 88, 62, 626, 63, 48 };
	//��ӡ����

	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	//�����Ԫ�ؼ��±�
	int max = array[0];
	int maxIndex = 0;
	for (int i = 1; i < len; i++)
	{
		if (max < array[i])
		{
			max = array[i];
			maxIndex = i;
		}
	}
	cout << "�����е����Ԫ���ǣ�" << max << endl;
	cout << "���Ԫ�ص��±��ǣ�" << maxIndex << endl;

	//����СԪ�ؼ��±�
	int min = array[0];
	int minIndex = 0;
	for (int i = 1; i < len; i++)
	{
		if (min > array[i])
		{
			min = array[i];
			minIndex = i;
		}
	}
	cout << "�����е���СԪ���ǣ�" << min << endl;
	cout << "��СԪ�ص��±��ǣ�" << minIndex << endl;

	//�������ĸ�����ż���ĸ���
	int jCount = 0;
	int oCount = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] % 2 == 0)
		{
			oCount++;
		}
		else
		{
			jCount++;
		}
	}
	cout << "�����ĸ����ǣ�" << jCount << endl;
	cout << "ż���ĸ����ǣ�" << oCount << endl;

	//��������������������е��±꣬û���ҵ��򷵻�-1
	int x;            //�û�Ҫ���ҵ�����
	int xIndex = -1;  //�û����ҵ������±�
	cout << "������Ҫ���ҵ����֣�" << endl;
	cin >> x;
	for (int i = 0; i < len; i++)
	{
		if (x == array[i])
		{
			xIndex = i;
		}
	}
	cout << xIndex << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("ð������");
	int array[] = { 15, 55, 7, 88, 62, 626, 63, 48 };
	int len = sizeof(array) / sizeof(array[0]);
	//��ӡ����
	cout << "����ǰ�������ǣ�";
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	//����
	int temp;
	//���ѭ����������
	for (int i = 0; i < len - 1; i++)
	{
		//�ڲ�ѭ������ÿ�ֵıȽϺͽ���
		for (int j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "�����������ǣ�";
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("ѡ������");
	int array[] = { 15, 55, 7, 88, 62, 626, 63, 48 };
	int len = sizeof(array) / sizeof(array[0]);
	//��ӡ����
	cout << "����ǰ�������ǣ�";
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	//����
	int min = array[0];
	int minIndex = 0;
	int temp;
	for (int i = 0; i < len - 1; i++)
	{
		min = array[i];
		minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
			}
		}
		if (minIndex > i)
		{
			temp = array[minIndex];
			array[minIndex] = array[i];
			array[i] = temp;
		}
	}
	cout << "�����������ǣ�";
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("����Ԫ�ص�ɾ���Ͳ��룺");
	double num[99];		//����Ĵ�Сһ��ȷ�������޷��޸�
	int numCount = 0;		//��ǰ�����е�Ԫ�ظ���
	double insertNum;		//Ҫ�������ֵ
	int insertIndex = 0;	//Ĭ�ϲ��뵽��һ��Ԫ��λ��
	num[numCount++] = 45771;
	num[numCount++] = 42322;
	num[numCount++] = 40907;
	num[numCount++] = 40706;

	double temp;
	for (int i = 0; i < numCount; i++)
	{
		for (int j = 0; j < numCount - i - 1; j++)
		{
			if (num[j] < num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	cout << "�����" << endl;
	for (int i = 0; i < numCount; i++)
	{
		cout << num[i] << "\t";
	}
	cout << endl;

	//����
	cout << "������Ҫ��������֣�";
	cin >> insertNum;
	insertIndex = numCount;
	//1.�ҵ���һ���Ȳ������ִ��λ��insertIndex
	for (int i = 0; i < numCount; i++)
	{
		if (insertNum > num[i])
		{
			insertIndex = i;
			break;
		}
	}
	//2.�����һ��Ԫ�ؿ�ʼ�������ָ��Ƶ�����һ��Ԫ����
	for (int i = numCount - 1; i >= insertIndex; i--)
	{
		num[i + 1] = num[i];
	}
	//3.��Ҫ��������ָ�ֵ���±�ΪinsertIndex��Ԫ��
	num[insertIndex] = insertNum;
	//4.��������ܳ���+1
	numCount++;
	cout << "�����" << endl;
	for (int i = 0; i < numCount; i++)
	{
		cout << num[i] << "\t";
	}
	cout << endl;

	//ɾ��
	//1.�ҵ�Ҫɾ����Ԫ���±�
	double deleteNum;
	int deleteIndex = INT_MIN;
	cout << "������Ҫɾ�������֣�";
	cin >> deleteNum;
	for (int i = 0; i < numCount; i++)
	{
		if (deleteNum == num[i])
		{
			deleteIndex = i;
			break;
		}
	}
	if (deleteIndex == INT_MIN)
	{
		cout << "û���ҵ�Ҫɾ����Ԫ�أ�ɾ��ʧ�ܣ�" << endl;
	}
	else
	{
		//2.���ҵ����±꿪ʼ������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
		for (int i = deleteIndex; i < numCount - 1; i++)
		{
			num[i] = num[i + 1];
		}
		//3.�ܳ���-1
		numCount--;
		cout << "ɾ����" << endl;
		for (int i = 0; i < numCount; i++)
		{
			cout << num[i] << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("��ά���飺");
	string stu_names[]{ "����", "����", "�ŷ�" };
	string course_names[]{ "����", "��ѧ", "Ӣ��" };
	const int ROW = 3;
	const int COL = 3;
	double scores[ROW][COL];
	for (int i = 0; i < ROW; i++)//���ѭ������ѧ��
	{
		for (int j = 0; j < COL; j++)//�ڲ�ѭ�����ƿγ�
		{
			cout << "������";
			cout << stu_names[i] << "��" << course_names[j] << "�ɼ���";
			cin >> scores[i][j];
		}
	}
	//��ӡ���
	cout << "\t";
	for (int i = 0; i < COL; i++)
	{
		cout << course_names[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < ROW; i++)
	{
		cout << stu_names[i] << "\t";
		for (int j = 0; j < COL; j++)
		{
			cout << scores[i][j] << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>

using namespace std;

int main()
{
	SetConsoleTitle("vector����������");
	vector<double> vec_double = { 98.5, 67.9, 43.6, 32.9 };
	//�������в�������
	vec_double.push_back(100.8);//������β������һ������
	//����1
	for (int i = 0; i < vec_double.size(); i++)
	{
		cout << vec_double[i] << endl;
	}
	//������ͨ�ñ���������ʹ�õ�����--iterator
	//�������Ļ����÷�
	vector<double>::iterator it;//�õ�����������--ʵ������һ��ָ�����
	//�ӵ�һ��Ԫ�ؿ�ʼ����

	//����
	sort(vec_double.begin(), vec_double.end());
	//����
	reverse(vec_double.begin(), vec_double.end());
	for (it = vec_double.begin(); it != vec_double.end(); ++it)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("ָ�룺");
	double num = 1024.5;
	double* ptr_num = &num;
	cout << ptr_num << endl;
	cout << *ptr_num << endl;

	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("���ã�");
	double num = 1024.5;
	double& ptr_num = num;
	cout << &ptr_num << endl;
	cout << &num << endl;
	//����ptr_num��num�ĵ�ַ�Ƿ���ͬ,��ͬ������,��ͬ���ؼ�
	cout << boolalpha;
	cout << (&num == &ptr_num) << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("ָ�����飺");
	int arrays[]{ 15, 30, 45, 51, 78 };
	int* p_array = arrays;
	for (int i = 0; i < 5; i++)
	{
		cout << *(p_array + i) << endl;//ָ��δ�����ƶ�
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *p_array++ << endl;//ָ���Ѿ����ƶ�
	}
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

//������㹫ʽ���£�
//�����壺���������
int calc_cuboid()//���㳤�������
{
	int a, b, c;
	cout << "�����볤����ĳ�������" << endl;
	cin >> a >> b >> c;
	return a * b * c;
}

int main()
{
	SetConsoleTitle("���������㳤���������");
	cout << calc_cuboid() << endl;
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

void swap1(int, int);
void swap2(int*, int*);
void swap3(int&, int&);

int main()
{
	SetConsoleTitle("ָ�������ã�");
	int num1 = 10, num2 = 5;
	swap1(num1, num2);
	cout << "ִ��swap1��" << num1 << "\t" << num2 << endl;
	swap2(&num1, &num2);
	cout << "ִ��swap2��" << num1 << "\t" << num2 << endl;
	swap3(num1, num2);
	cout << "ִ��swap3��" << num1 << "\t" << num2 << endl;

	system("pause");
	return 0;
}

void swap1(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

void swap2(int* p1, int* p2)
{
	int temp;
	temp = *p1;//p������,����p��ָ��ռ��ֵ
	*p1 = *p2;
	*p2 = temp;
}

void swap3(int& ref1, int& ref2)
{
	int temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

#include<iostream>
#include<Windows.h>
using namespace std;

//ʹ������ʵ�����������
void _sort(int[], int len);
void _sort(float[], int len);
void _sort(double[], int len);
void _show(int[], int len);
void _show(float[], int len);
void _show(double[], int len);

int main()
{
	SetConsoleTitle("�ú�������ʵ����������");
	int i_nums[] = { 56, 54, 12, 89, 43 };
	float f_nums[] = { 78.0f, 5.7f, 42.8f, 99.1f };
	double d_nums[] = { 78.9, 23.6, 77.8, 98.5, 33.3 };

	cout << "����ǰ��";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));
	_sort(i_nums, sizeof(i_nums) / sizeof(int));
	cout << "�����";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));

	cout << "����ǰ��";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));
	_sort(f_nums, sizeof(f_nums) / sizeof(float));
	cout << "�����";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));

	cout << "����ǰ��";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));
	_sort(d_nums, sizeof(d_nums) / sizeof(double));
	cout << "�����";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));

	system("pause");
	return 0;
}

//������Ϊ��������ʱ�����Զ���Ϊָ��
void _sort(int nums[], int len)
{
	int temp;
	//cout << "sizeof(nums) = " << sizeof(nums) << endl;//�������Ĵ�С��ָ��Ĵ�С������������Ĵ�С
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

void _sort(float nums[], int len)
{
	float temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (nums[j] < nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

void _sort(double nums[], int len)
{
	double temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

void _show(int nums[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << ",";
	}
	cout << endl;
}

void _show(float nums[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << ",";
	}
	cout << endl;
}

void _show(double nums[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << ",";
	}
	cout << endl;
}

//#include<iostream>
//#include<string>
//using namespace std;
//
//void iquote(int x)
//{
//	cout << "\"" << x << "\t";
//}
//
//void iquote(double y)
//{
//	cout << "\"" << y << "\t";
//}
//
//void iquote(const char * str)
//{
//	cout << "\"" << str << "\t";
//}
//
//int main()
//{
//	int x=52;
//	double y=52.3;
//	const char * str = "aaa";
//	void iquote();
//	void iquote();
//	void iquote();
//	system("pause");
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
//��������
#include<iostream>
#include<Windows.h>
#include"LandOwner.hpp"
using namespace std;

int main()
{
	LandOwner* ptr_landOwner1 = new LandOwner();
	LandOwner* ptr_landOwner2 = new LandOwner("רҵ������");
	LandOwner* ptr_landOwner3 = new LandOwner("�ܰ�Ƥ");

	ptr_landOwner1->ShwoInfo();
	ptr_landOwner2->ShwoInfo();
	ptr_landOwner3->ShwoInfo();

	ptr_landOwner2->TouchCard(20);

	delete ptr_landOwner1;
	delete ptr_landOwner2;
	delete ptr_landOwner3;

	system("pause");
	return 0;
}
//////////////////////////////////////////////////////////////////////////////
//thisָ��
#include<iostream>

using namespace std;

class Student
{
public:
	int getAge()
	{
		return age;
	}

	Student setAge(int age)
	{
		this->age = age;
		cout << "age=" << age << endl;
		return *this;	//������������Ϊ������ʱ,��Ҫ��������thisָ��
	}

	void test()
	{
		cout << "thisָ�������ŵĵ�ַ��ʲô" << this << endl;
	}

	static void lazy()
	{
		cout << "i want to sleep" << endl;
	}

private:
	int age;

};

int main()
{
	//��ʱû�ж��� this->ʵ����������׵�ַ
	Student::lazy();//���Ե��ã�˵����̬��Ա���������ڶ�����ڵ�
	Student s;		//ʵ������һ��s����	
	s.lazy();
	s.setAge(22);				//����������Ϊ22
	cout << s.getAge() << endl;	//�õ�student������
	cout << "Student��Ĵ�С�ǣ�" << sizeof(Student) << endl;	//��ӡStudent��Ĵ�С
	s.test();
	cout << "s ʵ������ĵ�ַ��" << &s << endl;

	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

//�Ӻ����������
#include<iostream>

using namespace std;

class Person
{
public:

	//��Ա��������+��
	Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}

	int m_A;
	int m_B;
};

//ȫ�ֺ�������+��
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//�������صİ汾
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//��Ա�������صı��ʵ���
	Person p3 = p1.operator+(p2);

	//ȫ�ֺ������صı��ʵ���
	Person p4 = operator+(p1, p2);

	//Person p3 = p1 + p2;//�������ֱ��ʵ��ÿɼ�Ϊ��ʽ

	//���������Ҳ���Է�����������
	Person p5 = p1 + 100;

	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
	cout << endl;
	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;
	cout << endl;
	cout << "p5.m_A = " << p5.m_A << endl;
	cout << "p5.m_B = " << p5.m_B << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//////////////////////////////////////////////////////////////////////////

//��ǳ����
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person���вι��캯������" << endl;
	}

	//�Լ�ʵ�ֿ������캯��,���ǳ��������������
	Person(const Person& person)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_Age = person.m_Age;
		//m_Height = person.m_Height;������Ĭ��ʵ�ֵĴ���,ֻ���˼򵥵�ֵ����
		//�������
		m_Height = new int(*person.m_Height);
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person��������������" << endl;
	}

	int m_Age;
	int* m_Height;//��ߣ������ڶ���
};

void test1()
{
	Person p1(18, 160);
	cout << p1.m_Age << "  " << *p1.m_Height << endl;
	Person p2(p1);
	cout << p2.m_Age << "  " << *p2.m_Height << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}
////////////////////////////////////////////////////////////////////////

//�ڶ�����������
#include<iostream>
using namespace std;

int* func()
{
	//����new�ؼ���,���Խ����ݿ��ٵ��ڴ����
	//new�ؼ��ִ������ڴ��,���ص��Ǹ��������͵�ָ��,��Ҫ��ָ��ȥ����
	int* p = new int(10);	//ָ��p��ջ��,new������10�ڶ���;
	return p;
}

int main()
{
	int* p = func();
	cout << *p << endl;

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

double* func()
{
	//�ڶ�������double���͵�����
	//new���󷵻ص��Ƕ�Ӧ���͵�ָ�룬��Ҫ��ָ��ȥ����
	double* p = new double(18.25);
	return p;
}

void test1()
{
	double* p = func();
	cout << *p << endl;
	//���ùؼ���delete�ͷ�
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
	cout << endl;
	//cout << *p << endl;	//�Ѿ��ͷţ��޷�����
}

void test2()
{
	//����10���������ݵ����飬�ڶ���
	float* p = new float[10];	//10������10��Ԫ��

	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 50.5;	//����10��Ԫ�ظ�ֵ 50.5-59.5
	}

	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << "  ";
	}
	cout << endl;

	//�ͷŶ�������
	//�ͷ������ʱ��,��Ҫ��[]�ſ���
	delete[]p;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}

//��ֵ���������
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}

	//���� ��ֵ�����
	Person& operator=(Person& p)
	{
		//�������ṩǳ����
		//m_Age = p.m_Age;

		//Ӧ�����ж��Ƿ��������ڶ���,����У����ͷŸɾ�Ȼ�������
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	int* m_Age;
};

void test1()
{
	Person p1(22);
	Person p2(30);
	Person p3(40);
	p3 = p2 = p1;
	cout << *p1.m_Age << endl;
	cout << *p2.m_Age << endl;
	cout << *p3.m_Age << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//�������Ϊ���Ա
#include<iostream>
#include<string>
using namespace std;

//�ֻ���
class Phone
{
public:

	Phone(string pName)
	{
		cout << "Phoen��Ĺ��캯������" << endl;
		m_PName = pName;
	}

	~Phone()
	{
		cout << "Phoen���������������" << endl;
	}

	//�ֻ�Ʒ����
	string m_PName;
};

//����
class Person
{
public:

	//Phone m_Phone = pName--��ʽת����
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person��Ĺ��캯������" << endl;
	}

	~Person()
	{
		cout << "Person���������������" << endl;
	}

	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;

};

//��B�������ΪA���Ա�������ʱ���ȹ���B������ٹ���A��
//						������ʱ��������A�����������B��
void test1()
{
	Person p("����", "С��10");

	cout << p.m_Name << "���ţ�" << p.m_Phone.m_PName << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

//������
class Building
{
	////goodGayȫ�ֺ�����Building�ĺ����ѣ����Է���Building�е�˽�г�Ա
	friend void goodGay(Building* zhangsanbuilding);

public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

	string m_SittingRoom;

private:
	string m_BedRoom;
};

//ȫ�ֺ���(�û���)
void goodGay(Building* zhangsanbuilding)//�������������һ��ʵ��������:�����ķ���
{
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << zhangsanbuilding->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << zhangsanbuilding->m_BedRoom << endl;
}

void test1()
{
	Building building;
	goodGay(&building);
}

int main()
{
	test1();

	system("pause");
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

class Building
{
	//GoodGay���Ǳ���ĺ�����,���Է��ʱ����˽�г�Ա
	friend class GoodGay;
public:
	Building();

	string m_SittingRoom;
private:
	string m_BedRoom;

};

class GoodGay
{
public:

	GoodGay();
	void visit();//�ιۺ��� ����Building�е�����

	Building* building;
};

//����д��Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "�û������ڷ���:" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���:" << building->m_BedRoom << endl;
}

void test()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test();

	system("pause");
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

class Building;

class GoodGay
{
public:

	GoodGay();

	void visit1();	//��visit1�������Է���Building�е�˽�г�Ա
	void visit2();	//��visit2�������ܷ���Building�е�˽�г�Ա

	Building* building;
};

class Building
{
	//���߱����� GoodGay���µ�visit1��Ա������Ϊ����ĺ�����,���Է���˽�г�Ա
	friend void GoodGay::visit1();
public:
	Building();

	string m_SittingRoom;
private:
	string m_BedRoom;
};

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit1()
{
	cout << "visit1�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit1�������ڷ��ʣ�" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	//cout << "visit2�������ڷ��ʣ�" << building->m_BedRoom << endl;//visit2����Building�����Ԫ����,�޷�����Building���˽�г�Ա
}

Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

void test()
{
	GoodGay gg;
	gg.visit1();
	gg.visit2();
}

int main()
{
	test();
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

//template<class T> void _sort(T t_array[], int len);����д��
template<typename T> void _sort(T t_array[], int len);
template<typename T> void _show(T t_array[], int len);

int main()
{
	SetConsoleTitle("�ú���ģ��ʵ�ֲ�ͬ�������͵���������");
	int i_nums[] = { 56, 54, 12, 89, 43 };
	float f_nums[] = { 78.0f, 5.7f, 42.8f, 99.1f };
	double d_nums[] = { 78.9, 23.6, 77.8, 98.5, 33.3 };
	string s_nums[] = { "����", "�ŷ�", "����" };

	cout << "����ǰ��";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));
	_sort(i_nums, sizeof(i_nums) / sizeof(int));
	cout << "�����";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));

	cout << "����ǰ��";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));
	_sort(f_nums, sizeof(f_nums) / sizeof(float));
	cout << "�����";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));

	cout << "����ǰ��";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));
	_sort(d_nums, sizeof(d_nums) / sizeof(double));
	cout << "�����";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));

	_show(s_nums, 3);

	system("pause");
	return 0;
}

template<typename T>
void _sort(T t_array[], int len)
{
	T temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (t_array[j] > t_array[j + 1])
			{
				temp = t_array[j];
				t_array[j] = t_array[j + 1];
				t_array[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void _show(T t_array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << t_array[i] << ",";
	}
	cout << endl;
}

#include<iostream>
#include<Windows.h>
using namespace std;

template<typename T>
T _result(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	SetConsoleTitle("�ú���ģ��ʵ�ֲ�ͬ�������͵��������ֱȽϴ�С,�����ؽϴ�ģ�");
	int ia = 5, ib = 6;
	float fa = 5.1, fb = 6.1;
	double da = 5.22, db = 6.22;
	cout << _result(ia, ib) << endl;
	cout << _result(fa, fb) << endl;
	cout << _result(da, db) << endl;
	system("pause");

	return 0;
}

//�̳�
#include<iostream>
using namespace std;

class Base
{
public:
	int m_A = 100;
};

class A :public Base
{
public:
	int m_A = 200;
};

void test()
{
	A a;
	cout << a.Base::m_A << endl;
	cout << a.m_A << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}

//��̬
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()	//����virtualʱ,�˿����СΪ1�ֽ�,����֮�����һ��ָ��,��С��Ϊ4�ֽ�
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

//ִ��˵������
//��ַ���  �ڱ���׶ξ�ȷ���˺����ĵ�ַ
//�����ִ��è˵��,�����������ַ�Ͳ������,��Ҫ�����н׶ΰ�
void doSpeak(Animal& animal)
{
	animal.speak();
}

void test1()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}

int main()
{
	test1();
	system("pause");
	return 0;
}

//��̬����--������Ʒ
#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "�����մɱ�" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

//������
class Tee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "������" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���벣����" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "�������ʺ����" << endl;
	}
};

//��������
void doWork(AbstractDrinking& abs)
{
	abs.makeDrink();
	delete& abs;
}

void test()
{
	//��������
	doWork(*new Coffee);
	cout << "-----------------------------------" << endl;
	//������
	doWork(*new Tee);
}

int main()
{
	test();
	system("pause");
	return 0;
}

//�������ʹ�������
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:

	Animal()
	{
		cout << "Animal�Ĺ��캯������" << endl;
	}

	//�������������Խ�������ͷ��������ʱ,�ͷŲ��ɾ�������
	//virtual ~Animal()
	//{
	//	cout << "Animal����������������" << endl;
	//}

	//�������� ��Ҫ���� Ҳ��Ҫʵ��
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;

	//���麯��
	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal�Ĵ���������������" << endl;
}

class Cat :public Animal
{
public:

	Cat(string name)
	{
		cout << "Cat�Ĺ��캯������" << endl;
		m_Name = new string(name);
	}

	~Cat()
	{
		cout << "Cat��������������" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak()
	{
		cout << *m_Name << "Сè��˵��" << endl;
	}
	string* m_Name;
};

void test()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ����������ʱ��,��������������������,������������ж�������,�ͻ�����ڴ�й©
	delete animal;
}

int main()
{
	test();
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

template<class T, size_t N = 10>
class Array
{
public:
	T& operator[](size_t pos)
	{
		return _a[pos];
	}
private:
	T _a[N];
	size_t _size;
};

int main()
{
	Array<int> a1;		//10
	Array<int, 20000> a2;	//20000
	system("pause");
	return 0;
}
#endif

#include<iostream>
using namespace std;

int main()
{
	cout << "hello world" << endl;
	system("pause");
	return 0;
}








































