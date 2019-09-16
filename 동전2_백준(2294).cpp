#include<iostream>
using namespace std;

//N���� ������ ������ ����Ͽ� K���� ������� �Ѵ�. (0 < N <=100 / 0 < K <= 10000)
//�̶�, ������ �������� ����� ���� �ּҷ� �� �� �� ���� ���Ͽ���. ������ ������ 10�� ������ ��ġ�� ���Ѵ�.
//���� K���� ������� ���ٸ� -1�� ����ϸ� �ȴ�.

int main()
{
	int N, K;
	unsigned long long int prices[101] = {};
	unsigned long long int ways[100001] = {};

	cin >> N >> K;

	for (int i = 1;i <= N;i++)
	{
		unsigned long long int temp;
		cin >> temp;
		prices[i] = temp;
	}

	//i���� ����� ���� �ּڰ��� ���ϱ����� �ش������� �������� 1���϶� 10������ ���� �� �ִ� �ּڰ��� 10���� + 1�� �� ����
	for (int i = 1;i <= K;i++)
	{
		ways[i] = 100001;
	}


	for (int i = 1;i <= N;i++)
	{
		//�� Ƚ���� �ּ�ȭ�ϱ� ���Ͽ� ���� ������ ��ġ ~ ��ǥ�������� �񱳹����� �����Ѵ�.
		for (int j = prices[i];j <= K;j++)
		{
			//j - prices[i] + 1�� �ǹ�
			//���� ��ġ�� �̹��� ����� ������ ���� ������ ��ġ��ŭ�� ��ġ���� �� ������ 1�� �� ����Ͽ�
			//�׸�ŭ�� �������Ƚ���� �����Ǿ����� �ǹ��Ѵ�.
			if (ways[j] <= ways[j - prices[i]] + 1)
			{
				ways[j] = ways[j];
			}
			else if(ways[j]>ways[j-prices[i]] + 1)
			{
				ways[j] = ways[j - prices[i]] + 1;
			}
		}
	}

	if (ways[K] == 100001)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ways[K] << endl;
	}
	return 0;
}