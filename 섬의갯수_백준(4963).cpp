#include<iostream>
#include<cstring> // ���ؿ����� �ڵ�ä����� memset�� ����� �� �� ����� �߰��ؾ߸� �Ѵ�. �ȱ׷��� �����Ͽ����� �߻��߾���.

//�ִ� 50*50ĭ�� ������ ���� ǥ�õǾ��ִ�.
//�̶�, ���� �� ���̿� �̵��Ҽ� �ִ� ����� �ִٸ� �� ������ �ϳ��� ������ �����Ѵ�.
//�� ���� ���� �ִ� ���� �������� ���ϴ� ���� �̹� ����.
//�������� flood_fill �˰������ �޸�, �밢�� �������ε� �̵��� �� �ִ�.
using namespace std;
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int checked[51][51] = {}; //flood_fill �˰����� ����� �� �ִ����� �Է��صδ� �迭
int sea[51][51] = {}; // ���� �ִٸ� 1, �ƴϸ� 0�� �Է�
int cnt = 0;
int G, S;

void island(int x, int y)
{
	checked[x][y] = 1;
	for (int k = 0;k < 8;k++) // ���� ��ġ�� �������� 8�� ���⿡ ���� �ִ��� �������� üũ�Ѵ�.
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if ((0 <= nx && nx < G) && (0 <= ny && ny < S))
		{
			if (checked[nx][ny] == 0 && sea[nx][ny] == 1)
			{
				island(nx, ny);
			}
		}
	}
}
int main()
{
	//���� ������ ����(S)�� ����(G)�� ���� 0, 0�ΰ�� while���� ����ȴ�.
	bool showtime = true;
	while(showtime)
	{
		memset(checked, 0, sizeof(checked));
		memset(sea, 0, sizeof(sea));
		cnt = 0;
		//�迭�� ������ �ʱ�ȭ���ش�. 
		cin >> S >> G;
		if (G == 0 && S == 0)
		{
			return 0;
		}
		else
		{
			for (int j = 0;j < G;j++)
			{
				for (int k = 0;k < S;k++)
				{
					cin >> sea[j][k];
				}
			}

			for (int j = 0;j < G;j++)
			{
				for (int k = 0;k < S;k++)
				{
					if (sea[j][k] == 1 && checked[j][k] == 0) // ������ ���� �ְ�, flood_fill �˰����� ����� �� ���� ���̶��
					{
						cnt++;
						island(j, k);
					}
				}
			}
			cout << cnt << endl;
		}
	}

	return 0;
}