#include<iostream>
#include<queue>

//최대 1000 * 1000의 크기인 M * N의 지도에 지나갈 수 있는 곳은 0, 지나갈 수 없는 곳은 1로 표기되어있다
//왼쪽 최상단과 오른쪽 최하단은 항상 0이고 왼쪽 최상단에서 오른쪽 최하단으로 이동하고자 한다
//편의상 벽을 1회까지는 돌파 가능하며, 여러 경우를 따져서 최소 횟수로 이동하는 거리를 구하여라
//단, 이동하지 못 하는 경우에는 -1을 출력하면 된다



using namespace std;
int M, N;
char arr[1001][1001] = {};
int dist[1001][1001][2] = {};	//거리가 저장되어지는 곳. 벽을 뚫었을 경우, [x][y][0]이 아닌 [x][y][1]에 저장되어진다
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct map {
	int x, y, z;
	//큐 자료구조에 3개의 정수를 입력하기 위해 임시로 만든 구조체
	//각각 x축, y축좌표 그리고 벽의 돌파 유무를 저장한다
};

int bfs() {
	//O(MN)의 시간복잡도를 가진다
	queue<map> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int temp_x = q.front().x;
		int temp_y = q.front().y;
		int temp_z = q.front().z;
		q.pop();
		//목표지점에 도달하면 dist값 출력
		if (temp_x == M - 1 && temp_y == N - 1) {
			return dist[temp_x][temp_y][temp_z];
		}

		for (int i = 0;i < 4;i++) {
			int temp_dx = temp_x + dx[i];
			int temp_dy = temp_y + dy[i];
			//x축과 y축 둘 중 아무거나 map의 범위초과시 제외
			if (temp_dx < 0 || temp_dx >= M && temp_dy < 0 && temp_dy >= N) {
				continue;
			}
			//이미 값이 입력되어 있는 곳이면 계산불필요
			if (dist[temp_dx][temp_dy][temp_z]) {
				continue;
			}
			//지나갈 수 있는 길이라면
			if (arr[temp_dx][temp_dy] == '0') {
				dist[temp_dx][temp_dy][temp_z] = dist[temp_x][temp_y][temp_z] + 1;
				q.push({ temp_dx, temp_dy, temp_z });
			}
			//지나갈 수 없지만 벽을 돌파한 적이 없다면
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