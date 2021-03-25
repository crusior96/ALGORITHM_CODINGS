#include<iostream>
#include<queue>
using namespace std;
int M, N, O;
char arr[1001][1001] = {};
int dist[1001][1001][15] = {};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//N*M의 크기를 가진 행렬이 있다고 가정하자
//이 행렬 내에서 부술 수 있는 벽의 갯수는 최대 O개이다
//위 규칙을 지키는 상황에서 좌상단 출발지점에서 우하단 도착지점으로 갈 수 있는 최단 거리를 구하여라
//도착이 불가능해 보이면 -1을 출력한다


//미로 내에서 이동할 때 저장되는 정보
//x & y : 현재 위치, z : 지금까지 부순 벽의 갯수
struct map {
	int x, y, z;
};


//이번 문제에 사용하게 될 BFS 탐색 함수
//사실 벽뿌1에 비하면 벽을 부술 수 있는 갯수가 추가된 것만 고려하면 된다
int bfs() {
	queue<map> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int temp_x = q.front().x;
		int temp_y = q.front().y;
		int temp_z = q.front().z;
		q.pop();
		//목적지 도착 시 답안 제공
		if (temp_x == M - 1 && temp_y == N - 1) {
			return dist[temp_x][temp_y][temp_z];
		}

		//BFS탐색을 할 때, 벽을 부술 수 있으면 부수는 방향으로 진행한다
		//최단 거리를 구하기 위한 행위로 간주함
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