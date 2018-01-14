/*在一个二维数组中，
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
#include<iostream>
#include<vector>
using namespace std;

bool Find(int target,vector<vector<int> > array)
{
	int row_size = array.size();
	int col_size = array[0].size();
	cout << row_size << " " << col_size << endl ;

	int i,j;
	for(i=0;i<row_size;i++)
	{
		for(j=0;j<col_size;j++)
		{
			if(target == array[i][j])
				return true;
			if(target < array[i][j])
			{
				i--;
				continue;
			}
			if(target>array[i][j])
			{
				j++;
				continue;
			}
		}	
	}
	return false;
}

int main()
{
  vector<vector<int> > array = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12}, {13,14,15,16}};
  int target;
  cin>>target;
  cout<<Find(target,array)<<endl;
}
/*
1 2 8 9
2 4 9 12
4 7 10 13
6 8 11 15
*/
