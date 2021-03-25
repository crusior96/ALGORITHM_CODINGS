#include<iostream>
#include<queue>
using namespace std;
int M, N, O;
char arr[1001][1001] = {};
int dist[1001][1001][15] = {};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//N*M�� ũ�⸦ ���� ����� �ִٰ� ��������
//�� ��� ������ �μ� �� �ִ� ���� ������ �ִ� O���̴�
//�� ��Ģ�� ��Ű�� ��Ȳ���� �»�� ����������� ���ϴ� ������������ �� �� �ִ� �ִ� �Ÿ��� ���Ͽ���
//������ �Ұ����� ���̸� -1�� ����Ѵ�


//�̷� ������ �̵��� �� ����Ǵ� ����
//x & y : ���� ��ġ, z : ���ݱ��� �μ� ���� ����
struct map {
	int x, y, z;
};


//�̹� ������ ����ϰ� �� BFS Ž�� �Լ�
//��� ����1�� ���ϸ� ���� �μ� �� �ִ� ������ �߰��� �͸� ����ϸ� �ȴ�
int bfs() {
	queue<map> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int temp_x = q.front().x;
		int temp_y = q.front().y;
		int temp_z = q.front().z;
		q.pop();
		//������ ���� �� ��� ����
		if (temp_x == M - 1 && temp_y == N - 1) {
			return dist[temp_x][temp_y][temp_z];
		}

		//BFSŽ���� �� ��, ���� �μ� �� ������ �μ��� �������� �����Ѵ�
		//�ִ� �Ÿ��� ���ϱ� ���� ������ ������
		for (int i = 0;i < 4;i++) {
			int temp_dx = temp_x + dx[i];
			int temp_dy = temp_y + dy[i];
			if (temp_dx < 0 || temp_dx >= M && temp_dy < 0 && temp_dy >= N) {
				continue;
			}
			if (dist[temp_dx][temp_dy][temp_z]) {
				continue;
			}
			if (arr[temp_dx][temp_dy] == '0') {
				dist[temp_dx][temp_dy][temp_z] = dist[temp_x][temp_y][temp_z] + 1;
				q.push({ temp_dx, temp_dy, temp_z });
			}
			if (arr[temp_dx][temp_dy] == '1' && (temp_z + 1) != (O + 1)) {
				dist[temp_dx][temp_dy][temp_z + 1] = dist[temp_x][temp_y][temp_z] + 1;
				q.push({ temp_dx,temp_dy,temp_z + 1 });
			}

		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> O;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	cout << bfs() << '\n';

	return 0;
}