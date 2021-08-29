#include<iostream>
#include<queue>
using namespace std;

int arr[66][66] = {};			//배열에 저장된 숫자들의 값
int checked[66][66] = {};		//bfs를 통해 도착할 수 있는 공간을 1로 저장한다

//N*N 크기의 배열이 있다고 가정하자
//각각의 배열에는 0 이상의 숫자들이 적혀있으며, 우하단의 마지막 공간에만 -1이 적혀있다
//현재 배열에 있는 숫자를 기준으로 오른쪽 혹은 아래로만 움직일 수 있으며 배열의 최대 공간을 넘어설 경우, 탈락한다
//이때, 우하단의 마지막 공간으로 도달할 수 있는지에 대한 여부를 판단하라

struct now {
	int x;
	int y;
};

//문제풀이 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	queue<now> q;	//bfs를 사용하기 위한 큐
					//움직이기 전, 현재 위치의 좌표값을 저장해둔다
	now temp;
	temp.x = 0;
	temp.y = 0;
	q.push(temp);
	bool done = true;
	int answer = -1;
	while (done) {
		if (q.empty()) {
			done = false;
			break;
		}

		now tmp = q.front();
		int tmp_x = tmp.x;
		int tmp_y = tmp.y;
		checked[tmp_x][tmp_y] = 1;
		q.pop();

		//BFS 과정
		//1. 현재 위치가 우리가 원하는 종착지인가?
		//2. 아니라면, 현재 위치의 값이 0이 아닌가?
		//3. 아니라면, 현재 위치가 움직임을 체크 한 부분인가?
		//4. 아니라면, 현재 위치가 배열 내의 범위인가?
		//5. 그렇다면 좌표가 이동한 값을 q에 push한 다음 bfs를 진행한다

		//2번과 3번 과정을 통해 메모리가 초과하는 과정을 막을 수 있다
		if (tmp_x == N - 1 && tmp_y == N - 1) {
			answer = 1;
			done = false;
			break;
		}

		if (arr[tmp_x][tmp_y] != 0) {
			if (tmp_x + arr[tmp_x][tmp_y] < N) {
				if (checked[tmp_x + arr[tmp_x][tmp_y]][tmp_y] == 0) {
					checked[tmp_x + arr[tmp_x][tmp_y]][tmp_y] = 1;
					now tmp2;
					tmp2.x = tmp_x + arr[tmp_x][tmp_y];
					tmp2.y = tmp_y;
					q.push(tmp2);
				}
			}

			if (tmp_y + arr[tmp_x][tmp_y] < N) {
				if (checked[tmp_x][tmp_y + arr[tmp_x][tmp_y]] == 0) {
					checked[tmp_x][tmp_y + arr[tmp_x][tmp_y]] = 1;
					now tmp2;
					tmp2.x = tmp_x;
					tmp2.y = tmp_y + arr[tmp_x][tmp_y];
					q.push(tmp2);
				}
			}
		}
	}

	if (answer == 1) {
		cout << "HaruHaru" << '\n';
	}
	else {
		cout << "Hing" << '\n';
	}
	return 0;
}