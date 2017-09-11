/*
*给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，
并输出结果。输入值小于1000. 如，输入为10，程序应该输出结果为2。
（共有两对质数的和为10，分别为（5,5）,（3,7））
*/


// 解题思路：1、求出所有质数；2、在质数数组中进行查找

// 参考1：http://www.oschina.net/code/snippet_781177_15476
// 参考2：http://www.cnblogs.com/python27/archive/2011/12/03/2274991.html  
// 我用的是我的笨办法，0(n方)的时间复杂度，第2种方法更简单点
#include <iostream>
#include <stdlib.h>
#define N 1000

using namespace std;

int a[N];

#if 0
void allPrim(int num)
{
	int n,i,j,m;
	int leap = 1, f = 0;
	//if(num %2 != 0)
	for(i=2;i<num;i++)
		for(j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				leap = 0;
				break;
			}
		}
		if(leap)
		{
			cout << i << endl;
			a[f] = i;
			f++;
		}
	for(i=0;i<f;i++)
	{
		cout << a[i] << endl;
	}
}

void allPrim1(int num)
{
	int n0,i=2,j=0;
	n0 = num;
	while(n0>i)
	{
		if(n0%i == 0)
		{
			cout << i;
			a[j]=i;
			j++;
			while(n0%i==0)
			{
				n0 /= i;
			}
		}
		i++;
	}
}
#endif

int allPrim2(int num)
{
	int j=0;
	for(int i=2;i<=num;i++) // 质数
		for(int k=2;k<=i;k++)  // 除数
		{	// 排除所有在i=k之前，能被k整除（余数为0）的数
			if(i%k ==0 && i!=k)
				break;
			// 输出所有在 i=k 且 i%k=0的数
			if(i%k == 0 && i == k)
			{
				a[j] = i;
				j++;
			}
		}

	//for(int k = 0;k<j;k++)
		//cout << a[k] << endl;
	return j;
}

int main()
{
	int value;
	int num;
	int count=0;//计数
//	allPrim(i);
//	allPrim1(i);
	cin >> value;
	num = allPrim2(value); // 质数个数
	//cout << num << endl;

//	for(int k = 0;k<num;k++)
//		cout << a[k] << endl;

//    cout << value << endl;
	// 两层循环比较一次
	for(int i=0;i<num;i++)
	{
		for(int j=i;j<=num;j++)  //我之前一直写的是j=0，导致2个for()循环没有生效
		{
			if(a[i] == value-a[j])
				//（5,5）,（3,7））
			{
				count++;
				cout <<'(' <<a[i] <<',' << a[j] <<')' ;
			}
		}
	}
	cout << count << endl;

	system("pause");
	return 0;
}