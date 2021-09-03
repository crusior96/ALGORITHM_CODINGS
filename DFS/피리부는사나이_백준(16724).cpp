#include<iostream>
using namespace std;

//M*N 크기의 공간이 있다고 가정하자
//해당 공간은 U, D, L, R로 표기돼있으며 각각의 위치에 따라 위, 아래, 왼쪽, 오른쪽으로 이동하게 된다
//이때, 이러한 움직임이 연속적 혹은 사이클을 구성하지 않게끔 막히는 공간을 지정하고자 한다
//그렇다면, 막히는 공간을 몇 개 지정해야 사이클을 만들지 않게 될까?


struct start_point {
	int start_x;
	int start_y;
};

start_point start_arr[1001][1001] = {};		//start_arr[x][y] : (x,y)내에 있는 사이클의 시작 지점을 저장해둔다
											//				    이 값을 통해 현재 사이클과 해당 위치 사이클을 비교할 수 있다
int checker[1001][1001] = {};
char maps[1001][1001] = {};
int M, N;
int answer = 0;


//현재 좌표가 가지고 있는 사이클의 시작 지점과 현재 좌표의 위치를 사용한 함수
//maps값을 비교하여 현 좌표를 기준으로 이동했을 때의 경우를 찾아 낸 다음
//탐색이 진행된 위치가 아니라면 해당 위치의 start_arr 값을 origin_x와 y로 지정하고 이동 시 도착하는 좌표를 기준으로 search를 진행한다
//탐색이 진행됐던 위치라면, 해당 위치의 사이클 시작점과 현재 위치의 시작점을 비교한다
//동일한 사이클이 맞다면, answer값을 늘리고, 해당 사이클은 더 이상 추가적인 사이클 좌표가 생기지 않게된다
//그렇지 않다면, 서로 다른 사이클이 마주했음을 의미하게 된다
void search(int origin_x, int origin_y, int x, int y) {
	checker[y][x] = 1;
	int tmp_x = x;
	int tmp_y = y;

	if (maps[y][x] == 'U') {
		if (tmp_y >= 0) {
			if (checker[tmp_y - 1][tmp_x] == 0) {
				start_arr[tmp_y - 1][tmp_x].start_x = origin_x;
				start_arr[tmp_y - 1][tmp_x].start_y = origin_y;
				search(origin_x, origin_y, tmp_x, tmp_y - 1);
			}
			else if (checker[tmp_y - 1][tmp_x] == 1 && start_arr[tmp_y - 1][tmp_x].start_y == origin_y && start_arr[tmp_y - 1][tmp_x].start_x == origin_x) {
				answer++;
			}
		}
	}
	else if (maps[y][x] == 'D') {
		if (tmp_y < M - 1) {
			if (checker[tmp_y + 1][tmp_x] == 0) {
				start_arr[tmp_y + 1][tmp_x].start_x = origin_x;
				start_arr[tmp_y + 1][tmp_x].start_y = origin_y;
				search(origin_x, origin_y, tmp_x, tmp_y + 1);
			}
			else if (checker[tmp_y + 1][tmp_x] == 1 && start_arr[tmp_y + 1][tmp_x].start_y == origin_y && start_arr[tmp_y + 1][tmp_x].start_x == origin_x) {
				answer++;
			}
		}
	}
	else if (maps[y][x] == 'L') {
		if (tmp_x > 0) {
			if (checker[tmp_y][tmp_x - 1] == 0) {
				start_arr[tmp_y][tmp_x - 1].start_x = origin_x;
				start_arr[tmp_y][tmp_x - 1].start_y = origin_y;
				search(origin_x, origin_y, tmp_x - 1, tmp_y);
			}
			else if (checker[tmp_y][tmp_x - 1] == 1 && start_arr[tmp_y][tmp_x - 1].start_y == origin_y && start_arr[tmp_y][tmp_x - 1].start_x == origin_x) {
				answer++;
			}
		}
	}
	else if (maps[y][x] == 'R') {
		if (tmp_x <= N - 1) {
			if (checker[tmp_y][tmp_x + 1] == 0) {
				start_arr[tmp_y][tmp_x + 1].start_x = origin_x;
				start_arr[tmp_y][tmp_x + 1].start_y = origin_y;
				search(origin_x, origin_y, tmp_x + 1, tmp_y);
			}
			else if (checker[tmp_y][tmp_x + 1] == 1 && start_arr[tmp_y][tmp_x + 1].start_y == origin_y && start_arr[tmp_y][tmp_x + 1].start_x == origin_x) {
				answer++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			//탐색이 진행되지 않은 값을 기준으로 DFS를 진행하게 된다
			if (checker[i][j] == 0) {
				start_arr[i][j].start_x = j;
				start_arr[i][j].start_y = i;
				search(j, i, j, i);
			}
		}
	}

	cout << answer << '\n';
	return 0;
}