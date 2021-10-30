#include<iostream>
#include<queue>
using namespace std;
char map[101][101];
bool visit[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;


//N*M의 크기인 직사각형의 미로가 있다.
//이동할 수 있는곳은 1, 아닌곳은 0으로 표기할때, 미로의 왼쪽상단에서 오른쪽하단으로가는 최단거리를 구하라.

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));    //첫째pair 위치, 둘째pair 움직인거리
	visit[0][0] = 1;

	//BFS를 이용하여 미로의 끝부분까지 진행한다.
	//DFS를 사용하게 되면 이동가능한 4방향을 끝가지 진행한 후 미로 끝부분에 도달했을때의 최솟값을 출력하게 된다.
	//반면 BFS는 진행한 시간과 이동거리가 비례하기 때문에 일찍 BFS가 끝나는 순간이 최단 이동거리이다.
	while (!q.empty()) {

		int x = q.front().first.second;
		int y = q.front().first.first;	//각각 미로 위의 (x,y)좌표값을 저장해둔 변수이다.
		int z = q.front().second;		//(x,y) 좌표까지의 이동거리

		q.pop();

		//미로의 도착점에 도달했을 경우, 이동거리를 반환한다.
		if (x == M - 1 && y == N - 1)
			return z;

		for (int i = 0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) //미로의 범위를 벗어난 위치의 좌표값인가?
				continue;
			if (visit[ny][nx] == 1) //이미 방문했었던 위치인가?
				continue;
			if (map[ny][nx] != '1') //미로 내에서 이동할 수 있는 위치의 경로인가?
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

