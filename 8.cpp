/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
// 1 2        3                4 = 2*2
// 1 2(1,1/2) 3(1,1,1/1,2/2,1) 5(1,1,1,1/2,2/1,2,1/2,1,1/1,1,2)
// 5 =2*2+1
// 8(1,1,1,1,1/1,1,1,2/1,1,2,1/1,2,1,1/2,1,1,1/1,2,2/2,1,2/2,2,1)
/*
哇哇哇
可以考虑，小青蛙每一步跳跃只有两种选择：
一是再跳一级阶梯到达第 i 级阶梯，此时小青蛙处于第 i-1 级阶梯；
或者再跳两级阶梯到达第 i 级阶梯，此时小青蛙处于第 i-2 级阶梯。
于是，i 级阶梯的跳法总和依赖于前 i-1 级阶梯的跳法总数f(i-1)和前 i-2 级阶梯的跳法总数f(i-2)。因为只有两种可能性，
所以，f(i)=f(i-1)+f(i-2)
*/
//fib  0 1 2 3 4 5 6
//     0 1 1 2 3 5 8
//0 1 2 3 4 5
//0 1 2 3 5 8
#include<iostream>
using namespace std;
int fib(int n)
{
	int result[2] = {0,1};
	if(n<2)
	{
		return result[n];
	}
	int fib_one = 0;
	int fib_two = 1;
	int fib_n = 0;
	for(int i=2;i<=n;i++)
	{
		fib_n = fib_one + fib_two;
		fib_one = fib_two;
		fib_two = fib_n;
	}
	return fib_n;
}

int sum_fib(int n)
{
	int result;
	if(n<4)
	{
		result =  n;
	}
	else
	{
		result = fib(n)+fib(n-1);
	}
	return result;
}

int sum_fib_recursive(int n)//emmmmm
{
	if(n<0)
		return 0;
	int fib[3] = {0,1,2};
	if(n<3)
		return fib[n];
	return sum_fib_recursive(n-1)+sum_fib_recursive(n-2);
}

int sum_fib_Non_recursive(int n)
{
	if(n<0)
		return 0;
	int fib[3] = {0,1,2};
	if(n<3)
		return fib[n];

	int total = 0;
	int element_one = 1;
	int element_two = 2;
	for(int i=3;i<=n;i++)
	{
		total = element_one + element_two;
		element_one = element_two;
		element_two = total;
	}
	return total;
}


int main()
{
	int n;
	cin >> n;
	cout << fib(n) << endl;
	cout << sum_fib(n) << endl; 
	cout << sum_fib_recursive(n) << endl;
	cout << sum_fib_Non_recursive(n) << endl;
	return 0;
}
