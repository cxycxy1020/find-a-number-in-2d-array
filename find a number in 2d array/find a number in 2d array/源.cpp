#include <iostream>
#include <vector>
using namespace std;
bool Find(int target, vector<vector<int> > array)
{
	//empty判断vector数组是否为空，如果为空，empty的返回值为true
		if (array.empty())
			return false;
		//_length代表array数组的行数
		int _length = array.size();
		//从上向下遍历每一行
		for (int i = 0; i < _length; i++)
		{
			//判断某一行是否为空
			if (array[i].empty())
				continue;
			//如果target比第i行的最小值小,target可能在数组的第i行中
			else if (target >= array[i][0])
			{   
				//如果target比第i行的最大值小，target可能在数组的第i行中
				if (target <= array[i][array[i].size() - 1])
				{
					//从后向前遍历每一列的元素
					for (int j = array[i].size() - 1; j >= 0; j--)
					{
						if (target == array[i][j])return true;
						//如果从后向前，没有和target相等的元素，却出现了比target大的元素，可以判断数组的第i行中没有target
						else if (target > array[i][j])break;
					}
				}
		    //如果target比第i行的最大值大，target不可能在数组的第i行中，但可能在数组第i行之后的行中
				else 
				{
					continue;
				}
			}
			//如果target比第i行的最小值小，因为是从上向下遍历的数组的每一行，所以说明这个二维数组中没有target
			else return false;
		}
		return false;
}

int main()
{
	int target;
	vector<vector <int>> array = { {1,3,5} ,{2,4,6}, {3,5,7} };
	cin >> target;
	cout<<(Find(target, array)?"true":"false");
	return 0;
}