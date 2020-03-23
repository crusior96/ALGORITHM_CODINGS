#include<iostream>
#include<queue>

//�ִ� 1000 * 1000�� ũ���� M * N�� ������ ������ �� �ִ� ���� 0, ������ �� ���� ���� 1�� ǥ��Ǿ��ִ�
//���� �ֻ�ܰ� ������ ���ϴ��� �׻� 0�̰� ���� �ֻ�ܿ��� ������ ���ϴ����� �̵��ϰ��� �Ѵ�
//���ǻ� ���� 1ȸ������ ���� �����ϸ�, ���� ��츦 ������ �ּ� Ƚ���� �̵��ϴ� �Ÿ��� ���Ͽ���
//��, �̵����� �� �ϴ� ��쿡�� -1�� ����ϸ� �ȴ�



using namespace std;
int M, N;
char arr[1001][1001] = {};
int dist[1001][1001][2] = {};	//�Ÿ��� ����Ǿ����� ��. ���� �վ��� ���, [x][y][0]�� �ƴ� [x][y][1]�� ����Ǿ�����
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct map {
	int x, y, z;
	//ť �ڷᱸ���� 3���� ������ �Է��ϱ� ���� �ӽ÷� ���� ����ü
	//���� x��, y����ǥ �׸��� ���� ���� ������ �����Ѵ�
};

int bfs() {
	//O(MN)�� �ð����⵵�� ������
	queue<map> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int temp_x = q.front().x;
		int temp_y = q.front().y;
		int temp_z = q.front().z;
		q.pop();
		//��ǥ������ �����ϸ� dist�� ���
		if (temp_x == M - 1 && temp_y == N - 1) {
			return dist[temp_x][temp_y][temp_z];
		}

		for (int i = 0;i < 4;i++) {
			int temp_dx = temp_x + dx[i];
			int temp_dy = temp_y + dy[i];
			//x��� y�� �� �� �ƹ��ų� map�� �����ʰ��� ����
			if (temp_dx < 0 || temp_dx >= M && temp_dy < 0 && temp_dy >= N) {
				continue;
			}
			//�̹� ���� �ԷµǾ� �ִ� ���̸� �����ʿ�
			if (dist[temp_dx][temp_dy][temp_z]) {
				continue;
			}
			//������ �� �ִ� ���̶��
			if (arr[temp_dx][temp_dy] == '0') {
				dist[temp_dx][temp_dy][temp_z] = dist[temp_x][temp_y][temp_z] + 1;
				q.push({ temp_dx, temp_dy, temp_z });
			}
			//������ �� ������ ���� ������ ���� ���ٸ�
			if (arr[temp_dx][temp_dy] == '1' && temp_z == 0) {
				dist[temp_dx][temp_dy][1] = dist[temp_x][temp_y][temp_z] + 1;
				q.push({ temp_dx,temp_dy,1 });
			}

		}
	}
	return -1;
}

int main() {
	cin >> M >> N;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	cout << bfs() << '\n';

	return 0;
}