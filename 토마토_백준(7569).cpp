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
int tomato[101][101][101] = {};	//토마토의 상태를 저장하는 곳. 토마토가 익었다면 1, 안익었다면 0, 벽이라면 -1 저장
int d[101][101][101] = {};		
//해당 위치 토마토의 익은 시간을 기록하는 곳. 방문 가능하지만 방문한 적 없다면 -1,
//방문 불가능한 곳이면 0, 방문을 했다면 해당 위치까지 도달하는데 걸린 최단시간이 기록된다.
int M, N, O;

void bfs() {
	//원래 이 부분, queue내에 pair써서 3개자료 저장하는 식으로 했는데 그러니 너무 복잡하고
	//토마토가 익는 부분을 찾거나 지정하는 인덱싱 과정 중에 실수가 자주 발생했다
	//이에 그냥 차라리 구조체 xyz를 만들어서 x축 y축 z축에 넣을 자료들을 가독성있게 저장했다.
	//사용한 알고리즘은 flood_fill 알고리즘이며 익숙하게 설명한 적이 많으니 생략한다.
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

//가로, 세로, 높이가 각각 M, N, O인 토마토 저장박스가 있다고 가정하자
//해당 토마토 저장박스에는 토마토가 있는데 익어있다면 1, 토마토가 있는데 안익어있다면 0, 벽이 있다면 -1이 저장된다
//익은 토마토 상/하/좌/우/위/아래에 익지 않은 토마토가 있다면 1일후에 그 토마토는 익게 된다.
//모든 토마토들이 익는 날짜를 구하여라. 단, 토마토가 1개라도 못 익는다면 -1을 출력하면 된다.

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

	//삼중 for문을 돌려서 답안 찾기 및 익지 않은 토마토가 있는지 확인한다
	//답안에는 토마토가 최종적으로 익게 된 최장 소요시간을 저장한다
	//만약 익지 않은 토마토가 있다면 break를 하고 answer에 -1을 저장한다
	//또한 삼중 for문인 만큼 break용 변수 2군데에도 값을 지정해서 break를 지정한다.
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