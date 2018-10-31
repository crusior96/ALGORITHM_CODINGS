#include<iostream>
#include<queue>
using namespace std;

//N���� ��ǻ�Ͱ� M������ �����Ʈ�� ���� ä�� �ִ�.
//ù��°(1��)��ǻ�Ͱ� �����̷����� ������ ���, ��θ� ���� ������ �� �ִ� ��ǻ�ʹ� �� ����ΰ�?
//��μ������ : N1, N2 (N1�� N2�� ���� ����Ǿ��ִٴ� ��)


int main()
{
	queue<int> VIRUS;
	int CPU[102][102] = {};
	int INFECTED[102] = {};
	int sum = 0;
	int N, M, tmp1, tmp2;
	cin >> N >> M;
	for (int i = 1;i <= M;i++)
	{
		cin >> tmp1 >> tmp2;
		CPU[tmp1][tmp2] = 1;
		//��θ� 2�����迭�� �����صд�. ��ΰ� �����ϸ� 1, �ƴϸ� 0.
	}

	VIRUS.push(1);
	INFECTED[1] = 1;
	//������ ������ 1���̶� �ִ� ��ǻ�ʹ� VIRUS ť�� �����صд�.

	while (!VIRUS.empty())
	{
		int current = VIRUS.front();
		VIRUS.pop();

		//������ ���� �ִ� ��ǻ�͸� �ϳ��� pop�Ѵ�.
		//������ ��ǻ�Ͱ� �ϳ��� ��λ� �����Ѵٸ�, ������ ��ǻ�͵� ������ ������ ó��.
		//VIRUS ť�� �����صд�.
		//VIRUS ť�� �ִ� ��� ��ǻ�͵��� ����Ͽ� �������� ��, �� �̻� �ٸ� ��ǻ�Ͱ� ���� �� �� ���������� �ݺ��Ѵ�.
		for (int i = 1;i <= N;i++)
		{
			if (CPU[current][i] && !INFECTED[i])
			{
				INFECTED[i] = 1;
				VIRUS.push(i);
				sum++;
			}
			else if (CPU[i][current] && !INFECTED[i])
			{
				INFECTED[i] = 1;
				VIRUS.push(i);
				sum++;
			}
		}
	}

	cout << sum << endl;


	return 0;
}