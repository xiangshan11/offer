/*
要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/
// 1 1 2 3 5 8 13   0???!!!!!
#include <iostream>
using namespace std;
int Fibonacci(int n)//内存超限:您的程序使用了超过限制的内存
{
	if(n==1||n==2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}
int Fibonacci2(int n)
{
	int result[2] = {0,1};
	if(n<2)
		return result[n];
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

int main()
{
	int n;
	cin >> n ;
	int result = Fibonacci2(n);
	cout << result << endl;
	return 0;
}