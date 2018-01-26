/*
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方.
*/
#include<iostream>
using namespace std;
int Power(double base,int exponent)
{
	if(exponent==0)
		return 1;
	else if(exponent<0)
		return 1/base*(Power(base,exponent+1));
	else
		return base*(Power(base,exponent-1));
}
int main()
{
	double base;
	int exponent;
	cin >> base >> exponent ;
	int result=Power(base,exponent);
	cout << result << endl;

	return 0;
}