#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tomato[1001][1001] = {};
int d[1001][1001] = {};		//tomato[i][j]�� �丶�䰡 �ڶ󳪱���� �ɸ� �ð��� �����صδ� �迭
int M, N;

//���ΰ� N, ���ΰ� M�� ũ���� �翡 �丶�䰡 �ڶ���ִ�.
//�丶�䰡 �ɾ����ִ°��� 1, �� ���� 0, ���ٺҰ������� -1�̶�� ��������.
//�丶��� �����¿� �� ĭ ������ ������ �Ϸ翡 �ѹ� �ڶ� �� ������ �� �丶�䰡 �翡 �� ���� ���������� �ڶ�µ� �ɸ��� �ð��� ���Ͽ���.
//��, �� ���� �ϳ��� ������� -1�� ������ش�.

int main()
{
	int answer = 0;
	cin >> M >> N;
	queue<pair<int, int>> q;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> tomato[i][j];
			d[i][j] = -1;
			if (tomato[i][j] == 1) //���� �丶�� ���������� d �迭�� 0�� �������ְ� queue�� ��ǥ���� push���ش�.
			{
				d[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	//BFS�˰��� ���
	while (!q.empty())
	{
		int temp_x = q.front().first;
		int temp_y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) //�÷��� �� �˰��� ���
		{
			int tx = temp_x + dx[i];
			int ty = temp_y + dy[i];
			if (tx >= 0 && tx < N&&ty >= 0 && ty < M)
			{
				//������ ���� ������ tomato���� �� ���ϰ��
				if (tomato[tx][ty] == 0 && d[tx][ty] == -1)
				{
					//�� ��ġ�� ��ǥ���� queue�� �Է����ְ� ���� ��ǥ���� ������ �ð��ϼ� + 1�� ���� d�迭�� �������ش�.
					d[tx][ty] = d[temp_x][temp_y] + 1;
					q.push({ tx,ty });
				}
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			answer = max(answer, d[i][j]);
			//���������� ������ ��ġ�� d�迭 ���� answer�� �������ش�.
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (tomato[i][j] == 0 && d[i][j] == -1) //�� ���� �ִ°��
			{
				answer = -1;
			}
		}
	}
	cout << answer << endl;
	return 0;
}