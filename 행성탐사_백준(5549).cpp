#include<iostream>
using namespace std;
char map[1001][1001] = {};
int Jungle[1002][1002] = {};
int Ocean[1002][1002] = {};
int Iceland[1002][1002] = {};

//M*N�� ũ�⸦ ���� ������ ����, �ٴ�, ���������� ������ ǥ���Ѵٰ� ��������
//������ J, �ٴٴ� O, ��������� I��� ������ ��
//��ǥ(sx, sy)������ (fx, fy)���� �ִ� ����, �ٴ�, ���������� ������ ���Ͽ���

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N, TC, sx, sy, fx, fy;
	cin >> M >> N;
	cin >> TC;

	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> map[i][j];
		}
	}

	//�� ������ �������� ���� �� �۾��� �����Ѵ�
	//�ش� ���밡 �´ٸ� 2���� �迭������ ������ �۾��� 1�� �߰��ϰ�, �ƴ϶�� �׳� �۾��� �����Ѵ�
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (map[i][j] == 'J') {
				Jungle[i + 1][j + 1] = Jungle[i + 1][j] + Jungle[i][j + 1] - Jungle[i][j] + 1;
			}
			else {
				Jungle[i + 1][j + 1] = Jungle[i + 1][j] + Jungle[i][j + 1] - Jungle[i][j];
			}

			if (map[i][j] == 'O') {
				Ocean[i + 1][j + 1] = Ocean[i + 1][j] + Ocean[i][j + 1] - Ocean[i][j] + 1;
			}
			else {
				Ocean[i + 1][j + 1] = Ocean[i + 1][j] + Ocean[i][j + 1] - Ocean[i][j];
			}

			if (map[i][j] == 'I') {
				Iceland[i + 1][j + 1] = Iceland[i + 1][j] + Iceland[i][j + 1] - Iceland[i][j] + 1;
			}
			else {
				Iceland[i + 1][j + 1] = Iceland[i + 1][j] + Iceland[i][j + 1] - Iceland[i][j];
			}
		}
	}

	for (int i = 0;i < TC;i++)
	{
		int J_num = 0;
		int I_num = 0;
		int O_num = 0;
		cin >> sx >> sy >> fx >> fy;

		//������ ���뿡 ���� �������� ���ϴ� ����
		//�� ������ 2���� �迭���� �� ���̴� ������ �� ��. �ϴٸ��� �׸��̶� �����ϸ� �ȴ�.
		J_num = Jungle[fx][fy] - Jungle[sx-1][fy] - Jungle[fx][sy-1] + Jungle[sx - 1][sy - 1];
		I_num = Iceland[fx][fy] - Iceland[sx-1][fy] - Iceland[fx][sy - 1] + Iceland[sx - 1][sy - 1];
		O_num = Ocean[fx][fy] - Ocean[sx - 1][fy] - Ocean[fx][sy - 1] + Ocean[sx - 1][sy - 1];
		cout << J_num << " " << O_num << " " << I_num << '\n';
	}
	return 0;
}