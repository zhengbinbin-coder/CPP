#if 0
//和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
//
//1月1日：元旦
//1月的第三个星期一：马丁·路德·金纪念日
//2月的第三个星期一：总统节
//5月的最后一个星期一：阵亡将士纪念日
//7月4日：美国国庆
//9月的第一个星期一：劳动节
//11月的第四个星期四：感恩节
//12月25日：圣诞节
//现在给出一个年份，请你帮忙生成当年节日的日期。
//输入描述 :
//输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。
//
//输出描述 :
//对应每一组数据，以“YYYY - MM - DD”格式输出当年所有的节日日期，每个日期占一行。
//每组数据之后输出一个空行作为分隔。
//
#include<iostream>
using namespace std;

int WeekToDay(int y, int m, int c, int w, bool B)
{
	//输入哪年、哪月、第几周、星期几、正数还是倒数
	int d, week, i;
	if (m == 1 || m == 2)
	{
		m += 12;	//在基姆拉尔森计算公式中，把一月和二月看成是上一年的十三月和十四月
		y--;		//例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
	}
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
	{
		//B：正数/倒数    
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//基姆拉尔森公式
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
		printf("%d-05-%02d\n", y, WeekToDay(y, 1, 3, 1, 0));//倒数第一个星期一，所以用0
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}

//所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an, 
//并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
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

//NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//现在给你一段时间区间，请你帮他计算总收益有多少。
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

//NowCoder号称自己已经记住了1 - 100000之间所有的斐波那契数。
//为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。
//当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	long a[100001] = { 1, 2 };
	for (int i = 2; i < 100001; i++)
		a[i] = (a[i - 1] % 1000000 + a[i - 2] % 1000000) % 1000000;//求余除100000的意思是让数列中的值保留原来的6位尾数
	while (cin >> n) //循环输入n
	{
		if (n < 25)//加上判断，此时的数列值就是100000的分界处
		{
			cout << a[n - 1] << endl;//直接输出
		}
		else
			printf("%06ld\n", a[n - 1]);//输出后六位
		cout << endl;
	}
	return 0;
}

//一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。
//对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
//输入：	abcde a3
//		aaaaaa  aa
//输出：	0
//		3
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char a[1000], b[1000];
	int i, j, stra, strb, k, p, l; //i，j循环，stra，strb代表长度，k记录i的位置，p记录a[]，b[]是否全部,l代表多少个
	while (scanf("%s", a) != EOF)//当a有输入时 
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
		for (i = 0; i < stra; i++) //寻找从某个字符开始相同
		{
			if (a[i] == b[0])
			{
				k = i;
				for (j = 0, p = 0; j < strb; j++, k++)
				{
					if (a[k] == b[j])
					{
						p++;//记录相同字符个数 
					}
					if (p == strb)//看是否全部相同 
					{
						l++;
						i = i - 1 + strb;//将i的位置调到下此开始的前面一个字符位置，因为有i++ 
					}
				}
			}
		}
		printf("%d\n", l);
	}
	return 0;
}

//NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。
//于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
//现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。
//
//输入描述 :
//测试数据包括多组。
//每组数据包含两个整数from和to(1≤from≤to≤80)，分别代表开店的第from天和第to天。
//
//输出描述 :
//对应每一组输入，输出从from到to这些天里（包含from和to两天），需要做多少份早餐。
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;

int main(int argc, const char* argv[])
{
	//建立一张表，用于记录斐波那契数列的各项值，需要使用long long，否则会溢出
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

//NowCoder每天要给许多客户写电子邮件正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开。如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
//现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
//输入描述：输入包含多组数据。
//			每组数据的第一行是一个整数n（1≤n≤128），表示后面有n个姓名。
//			紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
//输出描述：对应每一组输入，输出一行收件人列表。
//示例：输入：
//			3
//			Joe
//			Quan，William
//			Letendre，Bruce
//			2
//			Leon
//			Kewell
//		输出：
//			Joe，“Quan，William”，“Letendre，Bruce”
//			Leon，Kewell
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
	while (std::cin >> n) //接收数字
	{
		std::cin.get(); //处理回车
		std::string name;
		for (int i = 0; i < n; i++) //名字分别处理
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //找到逗号或者空格，就要加双引号
			{
				quote = true;
			}
			if (quote)
			{
				putchar('\"'); //putchar效率更高
			}
			std::cout << name;
			if (quote)

			{
				putchar('\"');
			}
			if (i == n - 1) //如果已经是最后一个字符串，那就补回车，否则加逗号和空格
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

//一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
//
//输入描述 :
//测试数据包括多组，每组一行，为整数n(1≤n≤90)。
//
//输出描述 :
//对应输出第n天有几只兔子(假设没有兔子死亡现象)。
//示例1
//输入
//1
//2
//输出
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

//今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
//待所有字条加入完毕，每人从箱中取一个字条； 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
//现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？
//输入描述：输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）
//输出描述：对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率
//示例 : 输入 2 输出 50.00%
//解题思路 这是一道典型的错排算法，就是当 有 n 个对象的时候，保证每一个对象都不在自己原来的位置上的方法有 D(N) 种
//它的通项 : D(n) = (n - 1)[D(n - 2) + D(n - 1)], 特殊的D(1) = 0, D(2) = 1;
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	long long d[22] = { 0, 0, 1 };
	// 错排数量，预留第一项为 0 ，配合下文中输入的 n
	long long f[22] = { 0, 1, 2 };
	// 阶 乘
	for (int i = 3; i < 22; i++)
	{
		d[i] = (i - 1) * (d[i - 2] + d[i - 1]);// 错排的递推公式
		f[i] = i * f[i - 1]; // 阶乘的递推公式
	}
	int n;
	while (cin >> n)
	{
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// 用 100.0 来把结果处理成 double ，保留两位小数
	}
	return 0;
}

//NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性
//比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。现在给你一串抄送列表，
//请你判断目标用户是否在抄送列表中
//
//输入描述：输入有多组数据，每组数据有两行。第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包
//含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。第二行只包含一个姓名，是待查找的用户
//的名字（姓名要完全匹配）。长度不超过16个字符。
//
//输出描述：如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，
//输出“Important!”，表示这封邮件需要被优先处理。
//
//输入
//Joe, Kewell, Leon
//Joe
//“Letendre, Bruce”, Joe, “Quan, William”
//William
//输出
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

//数据库连接池：
//Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。
//为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中
//没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会
//被放入连接池中，供后续请求使用。现在提供你处理请求的日志，请你分析一
//下连接池最多需要创建多少个连接。
//
//输入描述：输入包含多组数据，每组数据第一行包含一个正整n（1≤n≤1000），表示请求的数量。
//紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。
//输出描述：对应每一组数据，输出连接池最多需要创建多少个连接。
//输入
//6
//A connect
//A disconnect
//B connect
//C connect
//B disconnect
//C disconnect
//输出
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

//mkdir:工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。
//例如要创建目录“ / usr / local / bin”，就需要此次创建“ / usr”、“ / usr / local”以及“ / usr / local / bin”。
//好在，Linux下mkdir提供了强大的“ - p”选项，只要一条命令“mkdir - p / usr / local / bin”就能自动创建需要的上级目录。
//现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir - p”命令。
//
//输入描述：输入包含多组数据。每组数据第一行为一个正整数 n(1≤n≤1024)。
//紧接着 n 行，每行包含一个待创建的目录名，目录名仅由数字和字母组成，长度不超过 200 个字符。
//
//输出描述：对应每一组数据，输出相应的、按照字典顺序排序的 “mkdir - p” 命令。每组数据之后输出一个空行作为分隔。
//输入
//3
/// a
/// a / b
/// a / b / c
//3
/// usr / local / bin
/// usr / bin
/// usr / local / share / bin
//输出
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
		//将类似字符串经过排序，放在一起
		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1、两串相同
			// 2、前串是后串的子串，而且后串后一位是 '/'
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

//红与黑：描述有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
//你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。
//请写一个程序，计算你总共能够到达多少块黑色的瓷砖。输入包括多个数据集合。
//每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。
//在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
//1）‘.’：黑色的瓷砖；
//2）‘#’：白色的瓷砖；
//3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
//当在一行中读入的是两个零时，表示输入结束。
//输出对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
//
//样例输入
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
//样例输出
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

//蘑菇阵：现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1, 1), B在(n, m)。现在A想要拜访B，
//由于她只想去B的家，所以每次她只会走(i, j + 1)或(i + 1, j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格)
//问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
//
//输入描述 :第一行N，M，K(1 ≤ N, M ≤ 20, k ≤ 100), N, M为草地大小，接下来K行，每行两个整数x，y，代表(x, y)处有一个蘑菇。
//输出描述 :输出一行，代表所求概率(保留到2位小数)
//
//输入
//2 2 1
//2 1
//输出
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
		int has[25][25];//有无蘑菇
		double dp[25][25];//能够到达每个格子的概率
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

//字符串计数：求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。
//输入描述 :每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）
//输入
//ab ce 1 2
//输出
//56
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
	//根据题中给出的例子，这个字符串只包含小写字母，不然答案就不应该是56了
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		//只包含小写字母的字符串可以看成26进制的数制
		//将s1和s2补长到len2长度
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
		//所有字符串最后都不包含是s2自身，所以最后要减1；
		cout << result - 1 << endl;
	}
	return 0;
}

//最长公共子序列:我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
//例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
//现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。
//
//输入描述 :输入包含多组数据。每组数据包含两个字符串m和n，它们仅包含字母，并且长度不超过1024。
//
//输出描述 :对应每组输入，输出最长公共子序列的长度。
//
//输入例子 :
//abcfbc abfcab
//programming contest
//abcd mnp
//输出例子 :
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
		// 初始化边界
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
		// 计算
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

//发邮件(排错问题)：NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。
//于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？即没有人收到属于自己的邮件。
//
//输入描述：输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
//输出描述 :对应每一组数据，输出一个正整数，表示无人收到自己邮件的种数。
//
//输入  2 3
//输出  1 2
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

//最长上升子序列:广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，
//			   请你帮忙找出身高依次递增的子序列。 例如队伍的身高数据是（1、7、3、5、9、4、8），
//			   其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
//输入描述 :输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。
//		  紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。
//输出描述 :对应每一组数据，输出最长递增子序列的长度。
//
//输入例子 :7
//		    1 7 3 5 9 4 8
//		    6
//		    1 3 5 2 4 6
//输出例子 :4
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

//解读密码：nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。
//因此他要对这些敏感信息进行混淆，比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
//现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息。
//
//输入描述：输入有多行。每一行有一段经过加密的信息（其中可能包含空格），并且原始信息长度不确定。
//输出描述：输出每段信息中数字信息。
//
//输入
//$Ts!47 & s456 a23 + B9k
//输出
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

//走迷宫:NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
//	   现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？
//输入描述 :输入包含多组数据。每组数据包含一个10 * 10，由“#”和“.”组成的迷宫。
//		 其中“#”代表墙；“.”代表通路。入口在第一行第二列；出口在最后一行第九列。
//		 从任意一个“.”点都能一步走到上下左右四个方向的“.”点。
//输出描述 :对应每组数据，输出从入口到出口最短需要几步。
//
//
//输入		#.########			#.########
//			#........#			#........#
//			#........#			########.#
//			#........#			#........#
//			#........#			#.########
//			#........#			#........#
//			#........#			########.#
//			#........#			#........#
//			#........#			#.######.#
//			########.#			########.#
//输出:	16 30

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

void dfs(int x, int y)//从起点第一行第二列出发深搜 
{
	if (x < 0 || x >= 10 || y < 0 || y >= 10) return;//越过数组范围程序返回 
	if (x == 9 && y == 8)//满足条件时取得两者中的最小值 
	{
		minLen = min(minLen, totalLen);
		return;
	}
	if (s[x][y] == '#') return;//遇到#号停止搜素 
	if (minLen <= totalLen) return;//找到一条路径的长度总和已经超过当前的已经找到的最短路径，则返回 
	a[x][y] = 1;//标记此位置已经被访问 
	totalLen++;//路径加一 
	if (x - 1 >= 0 && s[x - 1][y] == '.' && !a[x - 1][y]) dfs(x - 1, y);//向上搜索 
	if (x + 1 < 10 && s[x + 1][y] == '.' && !a[x + 1][y]) dfs(x + 1, y);//向下搜索 
	if (y - 1 >= 0 && s[x][y - 1] == '.' && !a[x][y - 1]) dfs(x, y - 1);//向右搜索 
	if (y + 1 < 10 && s[x][y + 1] == '.' && !a[x][y + 1]) dfs(x, y + 1);//向左搜索 
	totalLen--;//回退（回溯） 
	a[x][y] = 0;//回退 
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

//电话号码：上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
//例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。同理，TUT - GLOP就代表888 - 4567、310 - GINO代表310 - 4466。
//NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，请你帮他转换成数字形式的号码，并去除重复的部分。
//
//输入描述 :
//输入包含多组数据。
//每组数据第一行包含一个正整数n（1≤n≤1024）。
//紧接着n行，每行包含一个电话号码，电话号码仅由连字符“ - ”、数字和大写字母组成。
//没有连续出现的连字符，并且排除连字符后长度始终为7（美国电话号码只有7位）。
//
//输出描述 :
//对应每一组输入，按照字典顺序输出不重复的标准数字形式电话号码，即“xxx - xxxx”形式。
//每个电话号码占一行，每组数据之后输出一个空行作为间隔符。
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

//骆驼命名法：从C / C++转到Java的程序员，一开始最不习惯的就是变量命名方式的改变。
//C语言风格使用下划线分隔多个单词，例如“hello_world”；而Java则采用一种叫骆驼命
//名法的规则：除首个单词以外，所有单词的首字母大写，例如“helloWorld”。
//请你帮可怜的程序员们自动转换变量名。
//
//输入描述
//输入包含多组数据。每组数据一行，包含一个C语言风格的变量名。每个变量名长度不超过100。
//
//输出描述
//对应每一组数据，输出变量名相应的骆驼命名法。
//
//输入
//hello_world
//nice_to_meet_you
//输出
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

//对字符串中的所有单词进行倒排。
//1、每个单词是以26个大写或小写英文字母构成；
//2、非构成单词的字符均视为单词间隔符；
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//4、每个单词最长20个字母；
//
//输入描述：
//输入一行以空格来分隔的句子
//
//输出描述：
//输出句子的逆序
//
//输入：I am a student
//
//输出：student a am I
//
//思路：
//依次遍历，将字符连接组成字符串，直到遇到不满足要求的字符，将字符串压入容器，字符串清零，再继续遍历组成字符串，直到遍历完全为止
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

//乒乓球筐：nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？
//
//输入描述 :输入有多组数据。每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，即相同类型的乒乓球为相同的大写字母。字符串长度不大于10000。
//
//输出描述 :每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
//
//输入例子 :ABCDFYE CDE
//	      ABCDGEAS CDECDE
//
//输出例子 : Yes
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

//查找兄弟单词：实现一个可存储若干个单词的字典。用户可以：
//1、在字典中加入单词
//2、查找指定单词在字典中的兄弟单词个数
//3、查找指定单词的指定序号的兄弟单词，指定序号指字典中兄弟单词按字典顺序排序后的序号（从1开始）
//4、清空字典中所有单词
//
//定义、格式说明：
//单词：由小写英文字母组成，不含其它字符
//兄弟单词：给定一个单词X，如果通过任意交换单词中字母的位置得到不同的单词Y，那么定义Y是X的兄弟单词
//字典顺序：两个单词（字母按照自左向右顺序），先以第一个字母作为排序的基准，如果第一个字母相同，就用第二个字母为基准，如果第二个字母相同就以
//第三个字母为基准。依此类推，如果到某个字母不相同，字母顺序在前的那个单词顺序在前。如果短单词是长单词从首字母开始连续的一部分，短单词顺序在前
//举例：bca是abc的兄弟单词；abc与abc是相同单词，不是兄弟单词
//
//规格：
//0 <= 字典中所含单词个数 <= 1000
//1 <= 单词所含字母数 <= 50
//注：测试用例保证，接口中输入不会超出如上约束
//
//输入描述 :
//先输入字典中单词的个数，再输入n个单词作为字典单词。
//输入一个单词，查找其在字典中兄弟单词的个数
//再输入数字n
//
//输出描述 :
//根据输入，输出查找到的兄弟单词的个数
//
//示例1
//输入
//3 abc bca cab abc 1
//输出
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
//有误

//打印寒冰射手·艾希的详细信息
#include<iostream>
using namespace std;
int main()
{
	cout << "英雄名称：寒冰射手·艾希" << endl;
	cout << "伤害：56\t\t攻击距离：600\n"
		<< "护甲：15.5（+3.4）\t魔抗30（+0.0）\n"
		<< "生命值：395（+79）\t生命回复：0.9（+0.11）" << endl;
	system("pause");
	return 0;
}

//数组中出现次数超过一半的数字:数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
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

//合唱团：有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
//要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
//
//输入描述 :每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n(1 <= n <= 50)，表示学生的个数，接下来的一行，
//		  包含 n 个整数，按顺序表示每个学生的能力值 ai（ - 50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d(1 <= k <= 10, 1 <= d <= 50)。
//输出描述 :输出一行表示最大的乘积。
//
//输入：3
//	  7 4 7
//	  2 50
//输出：49
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

//马戏团:搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和
//	大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗
//	汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团
//	长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简
//	单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你
//	手上也拿到了这样一份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
//
//输入描述 :首先一个正整数N，表示人员个数。之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
//
//输出描述 :正整数m，表示罗汉塔的高度。
//
//输入例子 :
//6
//1 65 100
//2 75 80
//3 80 100
//4 60 95
//5 82 101
//6 81 70
//输出例子:4
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

//左右最值最大差:给定一个长度为N(N>1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，右部分A[K + 1..N - 1]，K可以取值的范围
//是[0, N - 2]。求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？给定整数数组A和数组的大小n，请返回题目所求的答案。
//
//测试样例：[2, 7, 3, 1, 1], 5
//返回：6
//
//分析：不管从哪分隔，其中有一部分的最大值肯定是整个数组的最大值max，而要是两部分差值最大，就要使不包含max的那部分最大值最小。首先，找到数组中的最大值max。
//
//我们来分析一下max的位置会对结果造成什么影响：当max在索引为0的位置，此时不管从哪里分隔，左部分的最大数值一定为max, 而右部分一定包含A[n - 1], 
//当A[n - 1]为最小值时，我们肯定是在A[n - 1]的前面分隔，保证A[n - 1]是右部分最大值，使得如【7, 3, 1】，在1前面分隔，此时最大差值为max - A[n - 1]。
//当max在索引为n - 1的位置, 同理，最大差值为max - A[0]。如果max在中甲的位置，那我们就取max - A[0]、max - A[n - 1]的最大差值
//总结以上情况：最大差值 = Math.max(max - A[0]、max - A[n - 1])
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
	//输出整形的最大值
	//cout << INT_MAX << endl;

	////强制以小数的方式显示
	//cout << fixed;
	////控制显示的精度
	//cout << setprecision(2);
	//double doubleNum = 100.0 / 3.0;
	//cout << doubleNum *1000000<< endl;

	system("pause");
	return 0;
}

//互换两个变量的值
#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "请输入第一个数a：" << endl;
	cin >> a;
	cout << "请输入第二个数b：" << endl;
	cin >> b;

	//显示交换前的两个数
	cout << endl << "交换前" << endl << "a为：" << a << endl << "b为：" << b << endl;

	//交换两个数的值
	c = a;
	a = b;
	b = c;

	//显示交换后的两个数
	cout << endl << "交换后" << endl << "a为：" << a << endl << "b为：" << b << endl;

	system("pause");
	return 0;
}

//小写字母转换为大写字母
#include<iostream>

using namespace std;

int main()
{
	char a;
	cout << "请输入一个小写字符：" << endl;
	cin >> a;

	a -= 32;
	cout << "转换后为:" << endl << a << endl;

	system("pause");
	return 0;
}

//数据类型的大小
#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("数据类型的大小：");//修改标题栏
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

	cout << "\a" << endl;//  \a--蜂鸣
	system("pause");
	return 0;
}

//蜂鸣--比较好玩
#include<iostream>
using namespace std;

int main()
{
	cout << "\a" << endl;//  \a--蜂鸣
	system("pause");
	return 0;
}

//设定打印的字符宽度
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double a1 = 155;
	double a2 = 486;
	double a3 = 848;
	//设定打印的字符宽度-----默认右对齐
	cout << setw(8) << a1
		<< setw(8) << a2
		<< setw(8) << a3 << endl;
	//设定左对齐
	cout << left;
	//设定填充
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
	SetConsoleTitle("关系运算符的运行结果：");
	cout << "15大于78吗？" << (15 > 78) << endl;
	cout << "15小于78吗？" << (15 < 78) << endl;

	cout << boolalpha;//把bool值显示为true或false
	cout << "15大于78吗？" << (15 > 78) << endl;
	cout << "15小于78吗？" << (15 < 78) << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	//判断某个月份有几天
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
		cout << "31天" << endl;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "30天" << endl;
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
		cout << "小人本住在苏州的城边\t" << "第" << n << "遍" << endl;
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
	//打印月历
	//请使用for循环打印1997年7月的月历
	//已知：1997年7月1日（星期二），香港回归举国同庆
	//1.定义变量
	int day = 31;          //7月一共有31天
	int dayOfWeek = 2;     //7月第一天是周二
	cout << "一\t二\t三\t四\t五\t六\t日" << endl;
	//打印\t   周几-1
	for (int i = 0; i < dayOfWeek - 1; i++)
	{
		cout << "\t";
	}
	//打印日子
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
	//求1-100之间的偶数和
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
	SetConsoleTitle("输入一个数，求各位数字之和");
	//输入一个数，求各位数字之和
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
	SetConsoleTitle("数组：");
	int array[] = { 15, 55, 7, 88, 62, 626, 63, 48 };
	//打印数组

	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	//求最大元素及下标
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
	cout << "数组中的最大元素是：" << max << endl;
	cout << "最大元素的下标是：" << maxIndex << endl;

	//求最小元素及下标
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
	cout << "数组中的最小元素是：" << min << endl;
	cout << "最小元素的下标是：" << minIndex << endl;

	//求奇数的个数和偶数的个数
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
	cout << "奇数的个数是：" << jCount << endl;
	cout << "偶数的个数是：" << oCount << endl;

	//查找输入的数字在数组中的下标，没有找到则返回-1
	int x;            //用户要查找的数字
	int xIndex = -1;  //用户查找的数的下标
	cout << "请输入要查找的数字：" << endl;
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
	SetConsoleTitle("冒泡排序：");
	int array[] = { 15, 55, 7, 88, 62, 626, 63, 48 };
	int len = sizeof(array) / sizeof(array[0]);
	//打印数组
	cout << "排序前的数组是：";
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	//排序
	int temp;
	//外层循环控制轮数
	for (int i = 0; i < len - 1; i++)
	{
		//内层循环控制每轮的比较和交换
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
	cout << "排序后的数组是：";
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
	SetConsoleTitle("选择排序：");
	int array[] = { 15, 55, 7, 88, 62, 626, 63, 48 };
	int len = sizeof(array) / sizeof(array[0]);
	//打印数组
	cout << "排序前的数组是：";
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	//排序
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
	cout << "排序后的数组是：";
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
	SetConsoleTitle("数组元素的删除和插入：");
	double num[99];		//数组的大小一旦确定，就无法修改
	int numCount = 0;		//当前数组中的元素个数
	double insertNum;		//要插入的数值
	int insertIndex = 0;	//默认插入到第一个元素位置
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
	cout << "排序后：" << endl;
	for (int i = 0; i < numCount; i++)
	{
		cout << num[i] << "\t";
	}
	cout << endl;

	//插入
	cout << "请输入要插入的数字：";
	cin >> insertNum;
	insertIndex = numCount;
	//1.找到第一个比插入数字大的位置insertIndex
	for (int i = 0; i < numCount; i++)
	{
		if (insertNum > num[i])
		{
			insertIndex = i;
			break;
		}
	}
	//2.从最后一个元素开始，将数字复制到后面一个元素中
	for (int i = numCount - 1; i >= insertIndex; i--)
	{
		num[i + 1] = num[i];
	}
	//3.将要插入的数字赋值给下标为insertIndex的元素
	num[insertIndex] = insertNum;
	//4.将数组的总长度+1
	numCount++;
	cout << "插入后：" << endl;
	for (int i = 0; i < numCount; i++)
	{
		cout << num[i] << "\t";
	}
	cout << endl;

	//删除
	//1.找到要删除的元素下标
	double deleteNum;
	int deleteIndex = INT_MIN;
	cout << "请输入要删除的数字：";
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
		cout << "没有找到要删除的元素，删除失败！" << endl;
	}
	else
	{
		//2.从找到的下标开始，后面一个元素赋值给前面一个元素
		for (int i = deleteIndex; i < numCount - 1; i++)
		{
			num[i] = num[i + 1];
		}
		//3.总长度-1
		numCount--;
		cout << "删除后：" << endl;
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
	SetConsoleTitle("二维数组：");
	string stu_names[]{ "刘备", "关羽", "张飞" };
	string course_names[]{ "语文", "数学", "英语" };
	const int ROW = 3;
	const int COL = 3;
	double scores[ROW][COL];
	for (int i = 0; i < ROW; i++)//外层循环控制学生
	{
		for (int j = 0; j < COL; j++)//内层循环控制课程
		{
			cout << "请输入";
			cout << stu_names[i] << "的" << course_names[j] << "成绩：";
			cin >> scores[i][j];
		}
	}
	//打印结果
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
	SetConsoleTitle("vector基本操作：");
	vector<double> vec_double = { 98.5, 67.9, 43.6, 32.9 };
	//向容器中插入数字
	vec_double.push_back(100.8);//在容器尾部插入一个数字
	//遍历1
	for (int i = 0; i < vec_double.size(); i++)
	{
		cout << vec_double[i] << endl;
	}
	//容器的通用遍历方法：使用迭代器--iterator
	//迭代器的基本用法
	vector<double>::iterator it;//得到迭代器对象--实际上是一个指针对象！
	//从第一个元素开始迭代

	//排序
	sort(vec_double.begin(), vec_double.end());
	//逆序
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
	SetConsoleTitle("指针：");
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
	SetConsoleTitle("引用：");
	double num = 1024.5;
	double& ptr_num = num;
	cout << &ptr_num << endl;
	cout << &num << endl;
	//测试ptr_num和num的地址是否相同,相同返回真,不同返回假
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
	SetConsoleTitle("指针数组：");
	int arrays[]{ 15, 30, 45, 51, 78 };
	int* p_array = arrays;
	for (int i = 0; i < 5; i++)
	{
		cout << *(p_array + i) << endl;//指针未被被移动
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *p_array++ << endl;//指针已经被移动
	}
	system("pause");
	return 0;
}

#include<iostream>
#include<Windows.h>
using namespace std;

//体积计算公式如下：
//长方体：长×宽×高
int calc_cuboid()//计算长方体体积
{
	int a, b, c;
	cout << "请输入长方体的长、宽、高" << endl;
	cin >> a >> b >> c;
	return a * b * c;
}

int main()
{
	SetConsoleTitle("函数：计算长方体体积：");
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
	SetConsoleTitle("指针与引用：");
	int num1 = 10, num2 = 5;
	swap1(num1, num2);
	cout << "执行swap1后：" << num1 << "\t" << num2 << endl;
	swap2(&num1, &num2);
	cout << "执行swap2后：" << num1 << "\t" << num2 << endl;
	swap3(num1, num2);
	cout << "执行swap3后：" << num1 << "\t" << num2 << endl;

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
	temp = *p1;//p解引用,代表p所指向空间的值
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

//使用重载实现数组的排序
void _sort(int[], int len);
void _sort(float[], int len);
void _sort(double[], int len);
void _show(int[], int len);
void _show(float[], int len);
void _show(double[], int len);

int main()
{
	SetConsoleTitle("用函数重载实现数组排序：");
	int i_nums[] = { 56, 54, 12, 89, 43 };
	float f_nums[] = { 78.0f, 5.7f, 42.8f, 99.1f };
	double d_nums[] = { 78.9, 23.6, 77.8, 98.5, 33.3 };

	cout << "排序前：";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));
	_sort(i_nums, sizeof(i_nums) / sizeof(int));
	cout << "排序后：";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));

	cout << "排序前：";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));
	_sort(f_nums, sizeof(f_nums) / sizeof(float));
	cout << "排序后：";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));

	cout << "排序前：";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));
	_sort(d_nums, sizeof(d_nums) / sizeof(double));
	cout << "排序后：";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));

	system("pause");
	return 0;
}

//数组作为参数传递时，会自动降为指针
void _sort(int nums[], int len)
{
	int temp;
	//cout << "sizeof(nums) = " << sizeof(nums) << endl;//这里量的大小是指针的大小，而不是数组的大小
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
//函数重载
#include<iostream>
#include<Windows.h>
#include"LandOwner.hpp"
using namespace std;

int main()
{
	LandOwner* ptr_landOwner1 = new LandOwner();
	LandOwner* ptr_landOwner2 = new LandOwner("专业斗地主");
	LandOwner* ptr_landOwner3 = new LandOwner("周扒皮");

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
//this指针
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
		return *this;	//函数返回类型为对象本身时,需要返回它的this指针
	}

	void test()
	{
		cout << "this指针里面存放的地址是什么" << this << endl;
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
	//此时没有对象 this->实例化对象的首地址
	Student::lazy();//可以调用，说明静态成员函数是先于对象存在的
	Student s;		//实例化了一个s对象	
	s.lazy();
	s.setAge(22);				//将年龄设置为22
	cout << s.getAge() << endl;	//得到student的年龄
	cout << "Student类的大小是：" << sizeof(Student) << endl;	//打印Student类的大小
	s.test();
	cout << "s 实例对象的地址：" << &s << endl;

	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

//加号运算符重载
#include<iostream>

using namespace std;

class Person
{
public:

	//成员函数重载+号
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

//全局函数重载+号
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//函数重载的版本
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

	//成员函数重载的本质调用
	Person p3 = p1.operator+(p2);

	//全局函数重载的本质调用
	Person p4 = operator+(p1, p2);

	//Person p3 = p1 + p2;//以上两种本质调用可简化为本式

	//运算符重载也可以发生函数重载
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

//深浅拷贝
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person的有参构造函数调用" << endl;
	}

	//自己实现拷贝构造函数,解决浅拷贝带来的问题
	Person(const Person& person)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = person.m_Age;
		//m_Height = person.m_Height;编译器默认实现的代码,只做了简单的值拷贝
		//深拷贝操作
		m_Height = new int(*person.m_Height);
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
	int* m_Height;//身高，开辟在堆区
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

//在堆区开辟数据
#include<iostream>
using namespace std;

int* func()
{
	//利用new关键字,可以将数据开辟到内存堆区
	//new关键字创建好内存后,返回的是该数据类型的指针,需要用指针去接收
	int* p = new int(10);	//指针p在栈上,new的数据10在堆上;
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
	//在堆区创建double类型的数据
	//new对象返回的是对应类型的指针，需要用指针去接收
	double* p = new double(18.25);
	return p;
}

void test1()
{
	double* p = func();
	cout << *p << endl;
	//利用关键字delete释放
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
	cout << endl;
	//cout << *p << endl;	//已经释放，无法访问
}

void test2()
{
	//创建10浮点型数据的数组，在堆区
	float* p = new float[10];	//10代表有10个元素

	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 50.5;	//给这10个元素赋值 50.5-59.5
	}

	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << "  ";
	}
	cout << endl;

	//释放堆区数组
	//释放数组的时候,需要加[]才可以
	delete[]p;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}

//赋值运算符重载
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}

	//重载 赋值运算符
	Person& operator=(Person& p)
	{
		//编译器提供浅拷贝
		//m_Age = p.m_Age;

		//应该先判断是否有属性在堆区,如果有，先释放干净然后再深拷贝
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

//类对象作为类成员
#include<iostream>
#include<string>
using namespace std;

//手机类
class Phone
{
public:

	Phone(string pName)
	{
		cout << "Phoen类的构造函数调用" << endl;
		m_PName = pName;
	}

	~Phone()
	{
		cout << "Phoen类的析构函数调用" << endl;
	}

	//手机品牌名
	string m_PName;
};

//人类
class Person
{
public:

	//Phone m_Phone = pName--隐式转换法
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person类的构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person类的析构函数调用" << endl;
	}

	//姓名
	string m_Name;
	//手机
	Phone m_Phone;

};

//当B类对象作为A类成员，构造的时候先构造B类对象，再构造A类
//						析构的时候先析构A类对象，再析构B类
void test1()
{
	Person p("张三", "小米10");

	cout << p.m_Name << "拿着：" << p.m_Phone.m_PName << endl;
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

//房子类
class Building
{
	////goodGay全局函数是Building的好朋友，可以访问Building中的私有成员
	friend void goodGay(Building* zhangsanbuilding);

public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom;

private:
	string m_BedRoom;
};

//全局函数(好基友)
void goodGay(Building* zhangsanbuilding)//传进来房子类的一个实例化对象:张三的房子
{
	cout << "好基友全局函数 正在访问：" << zhangsanbuilding->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问：" << zhangsanbuilding->m_BedRoom << endl;
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
	//GoodGay类是本类的好朋友,可以访问本类的私有成员
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
	void visit();//参观函数 访问Building中的属性

	Building* building;
};

//类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友正在访问:" << building->m_SittingRoom << endl;
	cout << "好基友正在访问:" << building->m_BedRoom << endl;
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

	void visit1();	//让visit1函数可以访问Building中的私有成员
	void visit2();	//让visit2函数不能访问Building中的私有成员

	Building* building;
};

class Building
{
	//告诉编译器 GoodGay类下的visit1成员函数作为本类的好朋友,可以访问私有成员
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
	cout << "visit1函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit1函数正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit2函数正在访问：" << building->m_BedRoom << endl;//visit2不是Building类的友元函数,无法访问Building类的私有成员
}

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
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

//template<class T> void _sort(T t_array[], int len);早期写法
template<typename T> void _sort(T t_array[], int len);
template<typename T> void _show(T t_array[], int len);

int main()
{
	SetConsoleTitle("用函数模板实现不同数据类型的数组排序：");
	int i_nums[] = { 56, 54, 12, 89, 43 };
	float f_nums[] = { 78.0f, 5.7f, 42.8f, 99.1f };
	double d_nums[] = { 78.9, 23.6, 77.8, 98.5, 33.3 };
	string s_nums[] = { "关羽", "张飞", "黄忠" };

	cout << "排序前：";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));
	_sort(i_nums, sizeof(i_nums) / sizeof(int));
	cout << "排序后：";
	_show(i_nums, sizeof(i_nums) / sizeof(i_nums[0]));

	cout << "排序前：";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));
	_sort(f_nums, sizeof(f_nums) / sizeof(float));
	cout << "排序后：";
	_show(f_nums, sizeof(f_nums) / sizeof(f_nums[0]));

	cout << "排序前：";
	_show(d_nums, sizeof(d_nums) / sizeof(d_nums[0]));
	_sort(d_nums, sizeof(d_nums) / sizeof(double));
	cout << "排序后：";
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
	SetConsoleTitle("用函数模板实现不同数据类型的两个数字比较大小,并返回较大的：");
	int ia = 5, ib = 6;
	float fa = 5.1, fb = 6.1;
	double da = 5.22, db = 6.22;
	cout << _result(ia, ib) << endl;
	cout << _result(fa, fb) << endl;
	cout << _result(da, db) << endl;
	system("pause");

	return 0;
}

//继承
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

//多态
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()	//不加virtual时,此空类大小为1字节,加了之后产生一个指针,大小变为4字节
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//执行说话函数
//地址早绑定  在编译阶段就确定了函数的地址
//如果想执行猫说话,那这个函数地址就不能早绑定,需要在运行阶段绑定
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

//多态案例--制作饮品
#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入陶瓷杯" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

//制作茶
class Tee :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮怡宝" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入玻璃杯" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入柠檬和枸杞" << endl;
	}
};

//制作函数
void doWork(AbstractDrinking& abs)
{
	abs.makeDrink();
	delete& abs;
}

void test()
{
	//制作咖啡
	doWork(*new Coffee);
	cout << "-----------------------------------" << endl;
	//制作茶
	doWork(*new Tee);
}

int main()
{
	test();
	system("pause");
	return 0;
}

//虚析构和纯虚析构
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:

	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}

	//利用虚析构可以解决父类释放子类对象时,释放不干净的问题
	//virtual ~Animal()
	//{
	//	cout << "Animal的虚析构函数调用" << endl;
	//}

	//纯虚析构 需要声明 也需要实现
	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;

	//纯虚函数
	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:

	Cat(string name)
	{
		cout << "Cat的构造函数调用" << endl;
		m_Name = new string(name);
	}

	~Cat()
	{
		cout << "Cat的析构函数调用" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	string* m_Name;
};

void test()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构的时候,不会调用子类的析构函数,导致子类如果有堆区属性,就会出现内存泄漏
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








































