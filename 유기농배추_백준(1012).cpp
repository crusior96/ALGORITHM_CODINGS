#include<iostream>
#include<algorithm>
using namespace std;
int radish[55][55] = {}; //������ ������ Ȯ���ϴ� �迭
int check[55][55] = {}; //�̹� �÷ε��� �Լ��� ������״��� Ȯ���صδ� �迭
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int cnt = 0;
int h, w;

//�÷ε� ���� �̿��Ͽ� ������ '����'�� ���ϴ� ����.
//h*w ũ���� ���� ���� ��, ���߰� �ɰ��� �ִ°��� 1, �ƴѰ����� 0���� �Է��Ѵٰ� ��������.
//����� ������ �̿��� ���� ���̴� �̵��� �� �ִٸ�, ������ �ּ��� �� �� ����ϸ� �ɱ�?

void flood_fill(int x, int y)
{
	check[x][y] = 1;
	for (int k = 0;k < 4;k++)
	{
		int nx = x + dr[k], ny = y + dc[k];
		if ((0 <= ny && ny < h) && (0 <= nx && nx < w))
			if (check[nx][ny] == 0 && radish[nx][ny] == 1)
			{
				flood_fill(nx, ny);
			}
	}
}

int main()
{
	int N, num, x, y;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		//Nȸ �ݺ��ؾ� �ϴ� �����̹Ƿ�, for���� �����Ҷ����� �ʱ�ȭ���ش�.
		memset(radish, 0, sizeof(radish));
		memset(check, 0, sizeof(check));
		cnt = 0;
		cin >> w >> h >> num;
		for (int j = 0;j < num;j++)
		{
			cin >> x >> y;
			radish[x][y] = 1;
		}


		for (int k = 0;k < w;k++)
		{
			for (int j = 0;j < h;j++)
			{
				//���߰� �ɰ����ְ� �÷ε� �� üũ�� �Ǿ����� ���� ��ġ���
				if (radish[k][j] == 1 && check[k][j] == 0)
				{
					//������ ���ƾ� �� ���ο� ����++
					//�÷ε� �� �Լ��� ��������ش�.
					cnt++;
					flood_fill(k, j);

				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}