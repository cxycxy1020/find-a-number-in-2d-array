#include <iostream>
#include <vector>
using namespace std;
bool Find(int target, vector<vector<int> > array)
{
	//empty�ж�vector�����Ƿ�Ϊ�գ����Ϊ�գ�empty�ķ���ֵΪtrue
		if (array.empty())
			return false;
		//_length����array���������
		int _length = array.size();
		//�������±���ÿһ��
		for (int i = 0; i < _length; i++)
		{
			//�ж�ĳһ���Ƿ�Ϊ��
			if (array[i].empty())
				continue;
			//���target�ȵ�i�е���СֵС,target����������ĵ�i����
			else if (target >= array[i][0])
			{   
				//���target�ȵ�i�е����ֵС��target����������ĵ�i����
				if (target <= array[i][array[i].size() - 1])
				{
					//�Ӻ���ǰ����ÿһ�е�Ԫ��
					for (int j = array[i].size() - 1; j >= 0; j--)
					{
						if (target == array[i][j])return true;
						//����Ӻ���ǰ��û�к�target��ȵ�Ԫ�أ�ȴ�����˱�target���Ԫ�أ������ж�����ĵ�i����û��target
						else if (target > array[i][j])break;
					}
				}
		    //���target�ȵ�i�е����ֵ��target������������ĵ�i���У��������������i��֮�������
				else 
				{
					continue;
				}
			}
			//���target�ȵ�i�е���СֵС����Ϊ�Ǵ������±����������ÿһ�У�����˵�������ά������û��target
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