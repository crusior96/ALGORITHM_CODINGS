#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//�����̴� �Ϸ翡 �� �� �Ծ��� �ʵ��� ������ �ٸ����� ���� �ʴ´�.
//���� ������ ���� �� ���� ���� �� �ְ�, �� ���̶� �Ծ�߸� �ϴ� ������ �ִٸ�
//clothes ����ŭ�� ���� ������, ���� �Դ� ����� ������ ���϶�.
//���� �̸� �� ������ string���� �Է¹޴´�.

int main()
{
	int N, clothes;
	string cloth_type, cloth_name;
	
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> clothes;
		
		int cloth_type_num[30] = {}; 
		//���� ������ ���� �� ���� �ִ��� ����Ǿ����°�. ������ �迭 ĭ�� �� ������ ���� �� �� �ִ����� ��Ÿ�����ش�.
		int ways = 0; //���� ���� �� �ִ� ����� ����.
		int temp = 0;
		string cloth_type_depender[30] = {}; //���� ������ ����Ǿ����� ��.
		if (clothes == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			for (int j = 0;j < clothes;j++)
			{
				cin >> cloth_name >> cloth_type;
				cloth_type_depender[j] = cloth_type;
			}
			sort(cloth_type_depender, cloth_type_depender + clothes);
			//���� ������ �Է¹��� �迭�� ���Ľ�Ų��. ���� �ܾ���� ���� �̿��ϰ� �� ���̴�.
			cloth_type_num[0] = 1;
			//�ʱⰪ. �ּ��� �� ���� �־����� ������ ������ �� �ִ�.
			for (int j = 1;j < clothes;j++)
			{
				//�̿��� ���� ���� ���� ������ ���̸� ���� ��ġ�� �迭�� 1�� �����ְ�
				//�ٸ� ������� ���� ��ġ�� �迭�� �̵��� ��, �װ��� 1�� �����ش�.
				if (cloth_type_depender[j - 1] == cloth_type_depender[j])
				{
					cloth_type_num[temp]++;
				}
				else
				{
					temp++;
					cloth_type_num[temp]++;
				}
			}
			ways = cloth_type_num[0];
			for (int j = 1;j <= temp;j++)
			{
				ways = (ways + 1)*(cloth_type_num[j] + 1) - 1;
			}
			cout << ways << endl;
		}
	}

	return 0;
}