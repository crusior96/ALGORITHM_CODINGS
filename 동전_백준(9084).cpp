#include<iostream>
using namespace std;
int T, C, price;
int coins[21] = {};
//T���� �׽�Ʈ���̽����� C���� �������� price�� ���� �����ϴ� ����� ���� ������ �Ѵ�.
//��, ����� ���� 2^31-1���� ���� ���̸� price�� ���� 1�� �����̴�.
int main()
{
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> C;
		for (int j = 0;j < C;j++)
		{
			cin >> coins[j];
		}
		cin >> price;
		int ways[10001] = {};
		ways[0] = 1;
		//������ ������ �� �ͺ��� ������������ �����Ǿ��ִٴ����� �̿��Ͽ�
		//������ ���� ���������� price���� �� �������θ� ������ �� �ִ����� Ȯ���Ѵ�.
		//������ �� �ִٸ�, ���� ��ġ���� ������ �� �ִ� ����� ���� ���� ��ġ�� �����ָ� �װ��� �ݺ� �� �����Ѵ�.
		//�׷��� ��� ������ ������ for���� �����Ų��.
		for (int j = 0;j < C;j++)
		{
			for (int k = coins[j];k <= price;k++)
			{
				ways[k] += ways[k - coins[j]];
			}
		}
		cout << ways[price] << endl;
	}
	return 0;
}