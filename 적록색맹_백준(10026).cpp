#include<iostream>
#include<string>
using namespace std;


//R,G,B 3���� ����� �̷���� �׸��� N*N¥�� �ǿ� �׷����ִ�.
//1*1�� ���簢���� �������� �׸��� ��������������, 3���� ����� ���� �̷���� ������ ������ ���Ͽ���.
//�̶�, ���ϻ����� ����� R�� G�� ���������� ���δ�.

char maps[102][102] = {};	//�׸��� ����Ǵ� �迭
int checked[102][102] = {};	//������ �ƴ� ����� DFSŽ������ �������. Ž���� �Ǿ����� 1�� ����ȴ�.
int checked2[102][102] = {};//������ ����� DFSŽ������ �������. Ž���� �Ǿ����� 1�� ����ȴ�.
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;

//������ �ƴ� ����� DFS
void normal(int a, int b, char x)
{
	//DFSŻ������ : DFSŽ���� �̹� ����Ǿ��� ���̸� ��������
	if (checked[a][b] != 1)
	{
		checked[a][b] = 1;
		for (int i = 0;i < 4;i++)
		{
			int temp_x = a + dx[i];
			int temp_y = b + dy[i];
			//�����¿�� ���� 1ĭ �̵��� ��ǥ�� N*N�� �����ȿ� ������
			if ((temp_x >= 0 && temp_x < N) && (temp_y >= 0 && temp_y < N))
			{
				char temp = maps[temp_x][temp_y];
				//������ �߰��� ����� ���� ���ϰ��
				if (temp == x)
				{
					normal(temp_x, temp_y, temp);
				}
			}
		}
	}
}

//������ ����� DFS
void abnormal(int a, int b, char x)
{
	if (checked2[a][b] != 1)
	{
		checked2[a][b] = 1;
		for (int i = 0;i < 4;i++)
		{
			int temp_x = a + dx[i];
			int temp_y = b + dy[i];
			if ((temp_x >= 0 && temp_x < N) && (temp_y >= 0 && temp_y < N))
			{
				char temp = maps[temp_x][temp_y];
				//���ϻ����� ��쿣 'R'�� 'G'�� ���������� �ν��ϹǷ�
				//for������ ������ǥ�� ���� ������ǥ�� ���� �Ѵ� 'B'�̰ų�
				//������ǥ�� ���� ������ǥ�� ���� �Ѵ� 'B'�� �ƴ� ��츦 ã�´�.
				if (x == 'B' && temp == 'B')
				{
					abnormal(temp_x, temp_y, temp);
				}
				else if (x != 'B'&&temp != 'B')
				{
					abnormal(temp_x, temp_y, temp);
				}
			}
		}
	}
}

int main()
{
	int case1 = 0;
	int case2 = 0;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> maps[i][j];
		}
	}

	//DFSŽ���� �ȵ� ���̶�� �� ��ġ�� ��ǥ �� ������ normal�Լ��� �Է��Ѵ�.
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (checked[i][j] == 0)
			{
				case1++;
				normal(i, j, maps[i][j]);
			}
		}
	}

	//DFSŽ���� �ȵ� ���̶�� �� ��ġ�� ��ǥ �� ������ abnormal�Լ��� �Է��Ѵ�.
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (checked2[i][j] == 0)
			{
				case2++;
				abnormal(i, j, maps[i][j]);
			}
		}
	}

	cout << case1 << " " << case2 << endl;
	return 0;
}