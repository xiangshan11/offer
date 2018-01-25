/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
*/
#include<iostream>
#include<vector>
using namespace std;
//位运算，将1每次左移，和数字进行&运算，如果成功，则返回1
int NumberOf1(int  n)
{
	int result=0;
	int index=1;
	while(index!=0)
	{
        if((n & index)!=0)
            result++;
        index = index << 1;
    }
	return result;
}
//将整数通过方法转换为二进制数，然后统计其中1的数量

int main()
{
	int n;
	cin >> n;
	int result;
	result = NumberOf1(n);
	cout << result << endl;
	return 0;
}