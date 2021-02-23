#include<iostream>
#include<queue>
using namespace std;
char map[101][101];
bool visit[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;


//N*M�� ũ���� ���簢���� �̷ΰ� �ִ�.
//�̵��� �� �ִ°��� 1, �ƴѰ��� 0���� ǥ���Ҷ�, �̷��� ���ʻ�ܿ��� �������ϴ����ΰ��� �ִܰŸ��� ���϶�.

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));    //ù°pair ��ġ, ��°pair �����ΰŸ�
	visit[0][0] = 1;

	//BFS�� �̿��Ͽ� �̷��� ���κб��� �����Ѵ�.
	//DFS�� ����ϰ� �Ǹ� �̵������� 4������ ������ ������ �� �̷� ���κп� ������������ �ּڰ��� ����ϰ� �ȴ�.
	//�ݸ� BFS�� ������ �ð��� �̵��Ÿ��� ����ϱ� ������ ���� BFS�� ������ ������ �ִ� �̵��Ÿ��̴�.
	while (!q.empty()) {

		int x = q.front().first.second;
		int y = q.front().first.first;	//���� �̷� ���� (x,y)��ǥ���� �����ص� �����̴�.
		int z = q.front().second;		//(x,y) ��ǥ������ �̵��Ÿ�

		q.pop();

		//�̷��� �������� �������� ���, �̵��Ÿ��� ��ȯ�Ѵ�.
		if (x == M - 1 && y == N - 1)
			return z;

		for (int i = 0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) //�̷��� ������ ��� ��ġ�� ��ǥ���ΰ�?
				continue;
			if (visit[ny][nx] == 1) //�̹� �湮�߾��� ��ġ�ΰ�?
				continue;
			if (map[ny][nx] != '1') //�̷� ������ �̵��� �� �ִ� ��ġ�� ����ΰ�?
				continue;

			q.push(make_pair(make_pair(ny, nx), z + 1));
			visit[ny][nx] = 1;
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i<N; i++) {
		cin >> map[i];
	}
	cout << bfs();

	return 0;
}

