#include<iostream>
#include<cstring>
using namespace std;
int field[101][101] = {}; //���� ���̰� ����Ǿ����� �迭.
int wet[101][101] = {}; //���� �� ������ üũ�ϴ� �迭. ���ٸ� 1, �ƴϸ� 0���� ����Ǿ�����.
int checked[101][101] = {}; //flood_fill �˰����� ����Ǿ��� �κ����� Ȯ���ϴ� �迭. Ȯ�εǾ����ٸ� 1, �ƴϸ� 0���� ����Ǿ�����.
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;
int N;

//N*N�� ���� �帶�� �´ٰ� ��������.
//N*N�� ������ �ִ� 100�� ���̸� ���� ������ �پ��ϰ� �����Ѵ�.
//�帶�� ���� �ִ� ���̱��� �������� ������ ���δٰ� ������ ��
//�� ����� ���� ������ ������ �̷�� �ִ� ������ ���Ͻÿ�
//��, �������� ���̴� 0���� 1�� �þ��, �������� ���� ���̰� ���ٸ� �� ���� ���� ���� �ȴ�.


//�÷��� ���� ����� �˰���. ���� ���ϴ� �������� �ֿ�Ǿ�����.
void flood_fill(int x, int y)
{
	checked[x][y] = 1;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ((0 <= nx && nx < N) && (0 <= ny && ny < N))
		{
			//flood_fill �Լ��� ����Ǿ��� ���� �ƴϸ� ���� ���� ���� �ƴ϶�� flood_fill�Լ��� ��������ش�.
			if (checked[nx][ny] == 0 && wet[nx][ny] == 0)
			{
				flood_fill(nx, ny);
			}
		}
	}
}

int main()
{
	int max = 0;
	//field�� �ִ� ���� ���̵� �� �ִ��� �����صδ� ����. 
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> field[i][j];
			if (max < field[i][j])
			{
				max = field[i][j];
			}
		}
	}

	//������ ���̰� 0�������� ���� �ִ� ���̱��� �ö󰡰� �ǹǷ� for���� 0 ~ max������ �ݺ��Ǿ����� �ȴ�.
	for (int i = 0;i <= max;i++)
	{
		memset(checked, 0, sizeof(checked));
		//������ ���̿� ���� flood_fill�Լ��� üũ�� ����, �ٸ� ������ ������ �� ������ flood_fill ���࿩�θ� üũ�ϱ� ���� checked �迭�� �ʱ�ȭ�����ش�.
		int temp = 0;
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (i >= field[j][k])
				{
					//���� ���̰� ������ ���� ���̺��� ���ų� ���ٸ�, ������ ���ٴ� ������ wet �迭�� 1�� �����صд�.
					//�� �迭�� ������ ���̰� �� ���� �������Ƿ� ���� �ʱ�ȭ���� �� �ʿ�� ����.
					wet[j][k] = 1;
				}
			}
		}

		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (wet[j][k] == 0 && checked[j][k] == 0)
				{
					temp++;
					flood_fill(j, k);
				}
			}
		}

		if (temp > answer)
		{
			answer = temp;
		}
	}

	cout << answer << endl;
	return 0;
}