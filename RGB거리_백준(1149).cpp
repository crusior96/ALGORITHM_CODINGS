#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//�Ϸķ� N���� ���� �����Ǿ��ִµ�, �� ���� ����, �Ķ�, �ʷϻ����� ĥ�Ϸ��� �Ѵ�.
//���� �̿��ϴ� ���� ���� ����� ��ĥ�� �� ���ٴ� ������ �ִ�.
//���� N���� ���� ����, �Ķ�, �ʷϻ����� ĥ�ϴ� ����� ���� �ٸ���. �̶�, �ּ����� ������� ��� ���� ĥ�ϴ� �����?
//��, ó������ ������ ���� ���� �̿��� �ƴϴ�.

int get_min(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return a;
		else
			return c;
	}
	else
	{
		if (b <= c)
			return b;
		else
			return c;
	}
}

int main()
{
	//���κп� ��ĥ�� ����, �Ķ�, �ʷ����� ���� ��츦 �ʱⰪ���� �����Ͽ�
	//ó�� �κ����� �� �� ���� ��ĥ�ϴµ� ��� ����� ����س���.
	//costs�迭�� ��ĥ�� ����� ���� �����Ǵ� �����̸�, paints�迭�� ������ ���� 3���� ����� ��ĥ�� ���� ����� �����Ѵ�.
	int costs[1001][3] = {};
	int paints[1001][3] = {};
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			int temp;
			cin >> temp;
			paints[i][j] = temp;
		} 
	}

	costs[N - 1][0] = paints[N - 1][0];
	costs[N - 1][1] = paints[N - 1][1];
	costs[N - 1][2] = paints[N - 1][2];
	//�ʱⰪ ����.

	if (N <= 2)
	{
		int temp1 = get_min(paints[0][0], paints[0][1], paints[0][2]);
		int temp2 = get_min(paints[1][0], paints[1][1], paints[1][2]);
		cout << temp1 + temp2 << endl;
		//N�� 2���� �۰ų� ���� ��찡 �����̴�.
		//ó������ ���������� ���� �̿��� �ƴ϶�� ������ �ֱ� ������
		//ó������ �������������� ��ĥ�� �ּ� ����� �����ָ� �ȴ�.
	}
	else
	{
		for (int i = N;i > 0;i--)
		{
			{
				for (int j = 0;j < 3;j++)
				{
					costs[i - 1][j] = paints[i - 1][j] + min(costs[i][(j + 1) % 3], costs[i][(j + 2) % 3]);
					//N�� 2���� ū ��쿡 ����ȴ�.
					//i-1��° ���� � ����� ��ĥ�Ѵٸ�, i��° ������ �װ��� ������ �ٸ� ������ ��ĥ�� ��(2����) �ּ����� ����� �� ���� �����ش�.
				}
			}
		}
		cout << get_min(costs[0][0], costs[0][2], costs[0][1]) << endl;
		//���������� 1��° ������ �������� ��� �ּڰ��� ������ش�.
	}
	return 0;
}