#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
struct xyz {
	int z, y, x;
};


int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int tomato[101][101][101] = {};	//�丶���� ���¸� �����ϴ� ��. �丶�䰡 �;��ٸ� 1, ���;��ٸ� 0, ���̶�� -1 ����
int d[101][101][101] = {};		
//�ش� ��ġ �丶���� ���� �ð��� ����ϴ� ��. �湮 ���������� �湮�� �� ���ٸ� -1,
//�湮 �Ұ����� ���̸� 0, �湮�� �ߴٸ� �ش� ��ġ���� �����ϴµ� �ɸ� �ִܽð��� ��ϵȴ�.
int M, N, O;

void bfs() {
	//���� �� �κ�, queue���� pair�Ἥ 3���ڷ� �����ϴ� ������ �ߴµ� �׷��� �ʹ� �����ϰ�
	//�丶�䰡 �ʹ� �κ��� ã�ų� �����ϴ� �ε��� ���� �߿� �Ǽ��� ���� �߻��ߴ�
	//�̿� �׳� ���� ����ü xyz�� ���� x�� y�� z�࿡ ���� �ڷ���� �������ְ� �����ߴ�.
	//����� �˰����� flood_fill �˰����̸� �ͼ��ϰ� ������ ���� ������ �����Ѵ�.
	queue<xyz> q;

	for (int i = 0;i < O;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < M;k++) {
				if (tomato[i][j][k] == 1) {
					d[i][j][k] = 0;
					q.push({ i,j,k });
				}
			}
		}
	}

	while (!q.empty()) {
		int temp_z = q.front().z;
		int temp_y = q.front().y;
		int temp_x = q.front().x;
		q.pop();
		for (int i = 0;i < 6;i++) {
			int tx = temp_x + dx[i];
			int ty = temp_y + dy[i];
			int tz = temp_z + dz[i];
			if (tx >= 0 && tx < M&&ty >= 0 && ty < N&&tz >= 0 && tz < O) {
				if (tomato[tz][ty][tx] == 0 && d[tz][ty][tx] == -1) {
					tomato[tz][ty][tx] = 1;
					d[tz][ty][tx] = d[temp_z][temp_y][temp_x] + 1;
					q.push({ tz,ty,tx });
				}
			}
		}
	}
}

//����, ����, ���̰� ���� M, N, O�� �丶�� ����ڽ��� �ִٰ� ��������
//�ش� �丶�� ����ڽ����� �丶�䰡 �ִµ� �;��ִٸ� 1, �丶�䰡 �ִµ� ���;��ִٸ� 0, ���� �ִٸ� -1�� ����ȴ�
//���� �丶�� ��/��/��/��/��/�Ʒ��� ���� ���� �丶�䰡 �ִٸ� 1���Ŀ� �� �丶��� �Ͱ� �ȴ�.
//��� �丶����� �ʹ� ��¥�� ���Ͽ���. ��, �丶�䰡 1���� �� �ʹ´ٸ� -1�� ����ϸ� �ȴ�.

int main()
{
	memset(d, -1, sizeof(d));
	int answer = 0;
	cin >> M >> N >> O;
	for (int i = 0;i < O;i++)
	{
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < M;k++) {
				cin >> tomato[i][j][k];
			}
		}
	}

	bfs();

	//���� for���� ������ ��� ã�� �� ���� ���� �丶�䰡 �ִ��� Ȯ���Ѵ�
	//��ȿ��� �丶�䰡 ���������� �Ͱ� �� ���� �ҿ�ð��� �����Ѵ�
	//���� ���� ���� �丶�䰡 �ִٸ� break�� �ϰ� answer�� -1�� �����Ѵ�
	//���� ���� for���� ��ŭ break�� ���� 2�������� ���� �����ؼ� break�� �����Ѵ�.
	for (int i = 0;i < O;i++) {
		int condition1 = 0;
		int condition2 = 0;
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < M;k++) {
				if (tomato[i][j][k] == 0) {
					answer = -1;
					condition1 = 1;
					condition2 = 1;
					break;
				}

				if (d[i][j][k] > answer) {
					answer = d[i][j][k];
				}
			}
			if (condition1 == 1) {
				break;
			}
		}
		if (condition2 == 1) {
			break;
		}
	}

	cout << answer << '\n';
	return 0;
}