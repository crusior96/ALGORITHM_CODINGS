#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
int maps[52][52] = {};		//미로의 구성을 저장
int brokes[52][52] = {};	//검은방을 흰 방으로 바꾸게 되는 최소 횟수가 저장되는 곳
int visited[52][52] = {};	//방문 여부를 따지는 배열
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

//최대 50*50칸의 미로를 만든 다 할 때, 벽은 0으로 기입하고 빈 공간은 1로 기입한다 하자
//벽을 최소한 조금만 없애는 방식으로 이동할 수 있는 경우가 있다면, 미로를 탈출했을 때 그 때의 제거된 벽의 갯수를 구하여라
//단, 미로는 최단거리로 이동하는 방식이 아니라 벽을 최소한으로 없애는 방식으로 이동한다
//미로를 탈출하는 조건은 우하단에 도착했을 때이다

struct task {
	int x, y, combo;
};

//해당 문제는 bfs 이론을 사용하여 풀었다
//인접한 미로의 칸으로 이동한 다음, 해당 칸이 방문을 이미 한 곳인 경우, 해당 칸이 방문을 한 적이 없는 경우
//해당 칸이 검은 방이거나 흰 방인경우 등등을 고려해서 문제를 풀어나가게 된다
void bfs() {
	queue<task> q;
	q.push({ 0,0,0});
	brokes[0][0] = 0;
	visited[0][0] = 1;
	while (!q.empty()) {
		int tmp_x = q.front().x;
		int tmp_y = q.front().y;
		int cmb = q.front().combo;  //검은방을 흰 방으로 바꾸게 되는 횟수
		q.pop();

		for (int i = 0;i < 4;i++) {
			int tmp_cmb = cmb;	
			int tmp_dx = tmp_x + dx[i];
			int tmp_dy = tmp_y + dy[i];
			if (tmp_dx < 0 || tmp_dx >= N || tmp_dy < 0 || tmp_dy >= N) {
				continue;
			}

			//검은방이라면 흰 방으로 바꾼 횟수를 증가시켜준다
			if (maps[tmp_dx][tmp_dy] == 0) {
				tmp_cmb++;
			}

			//이미 방문하게 된 곳이라면 해당 위치의 brokes 배열값과
			//현재까지의 쿼리에서 검은방을 흰 방으로 바꾼 횟수를 비교한다
			//brokes 배열에서 꺼내온 값이 현재까지의 바꾼 횟수보다 크면, 현재 값을 대신 대입해버린다
			if (visited[tmp_dx][tmp_dy] == 1) {
				if (brokes[tmp_dx][tmp_dy] > tmp_cmb) {
					brokes[tmp_dx][tmp_dy] = tmp_cmb;
					q.push({ tmp_dx, tmp_dy, tmp_cmb });
				}
				else {
					continue;
				}
			}
			//방문을 한 적이 없는 곳이라면 해당 위치의 brokes 배열값을
			//현재까지의 쿼리에서 검은방을 흰 방으로 바꾼 횟수로 대입하고
			//visited 배열값을 1로 지정해버린다
			else {
				brokes[tmp_dx][tmp_dy] = tmp_cmb;
				visited[tmp_dx][tmp_dy] = 1;
				q.push({ tmp_dx,tmp_dy,tmp_cmb });
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0;j < N;j++) {
			maps[i][j] = tmp[j] - 48;
		}
	}

	bfs();
	cout << brokes[N - 1][N - 1] << '\n';

	return 0;
}