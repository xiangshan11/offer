/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变
*/
#include<iostream>
#include<vector>
using namespace std;
void reOrderArray(vector<int> &array)
{
	vector<int> test;
	int size=array.size();
	for(int i=0;i<size;i++)
	{
		int a = array[i];
		if(a%2 != 0)
		{
			//cout << a << endl;
			test.push_back(a);
		}
	}
	//cout << endl;
	for(int i=0;i<size;i++)
	{
		int a = array[i];
		if(a%2 == 0)
		{
			//cout << a << endl;
			test.push_back(a);
		}
	}
	/*
	for(int i=0;i<size;i++)
	{
		cout << test[i] << " " ;
	}
	cout << endl;
	for(int i=0;i<size;i++)
	{
		cout << array[i] << " " ;
	}
	*/
	
	for(int i=0;i<size;i++)
	{
		array[i] = test[i];
	}
	
}

int main()
{
	//cout << 5%2 << endl;

	vector <int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	array.push_back(7);
	reOrderArray(array);
	int size = array.size();
	for(int i=0;i<size;i++)
	{
		cout << array[i] << " " ;
	}
	return 0;
}
/*
https://www.cnblogs.com/lixiaolun/p/5057332.html  ?!
*/