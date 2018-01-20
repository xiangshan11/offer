/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
*/
#include<iostream>
#include<vector>
using namespace std;


int minNumberInRotateArray(vector<int> rotateArray)
{
	//cout << rotateArray.size() << endl;
	int result=0;
	int rotateArray_size = rotateArray.size();
	for(int i=0;i<rotateArray_size;i++)
	{
		if(i==rotateArray_size)
		{
			result = rotateArray[0];
			break;
		}
		else
		{
			if(rotateArray[i]<=rotateArray[i+1])
			{
				continue;
			}
			else
			{
				result = rotateArray[i+1];
				break;
			}
		}
	}
	return result;
}

int main()
{
	vector <int> rotateArray;
	rotateArray.push_back(3);
	rotateArray.push_back(4);
	rotateArray.push_back(5);
	rotateArray.push_back(2);
	rotateArray.push_back(2);

	int rotateArray_size = rotateArray.size();
	cout << rotateArray_size << endl;

	for(int i=0;i<rotateArray_size;i++)
	{
		cout << rotateArray[i] << " ";
	}
	cout << endl;

	int result = minNumberInRotateArray(rotateArray);
	cout << result << endl;

	return 0;
}