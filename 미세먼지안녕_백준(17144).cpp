#include<iostream>
#include<queue>
using namespace std;

int mov_x[4] = {0,0,1,-1};
int mov_y[4] = {-1,1,0,0};
int clockway[4] = {2,1,3,0 };	//시계 방향 회전을 진행할 때 mov_x, y의 어느 값을 사용할 지 저장해둔 배열
int declockway[4] = {2,0,3,1};	//반시계 방향 회전을 진행할 때 mov_x, y의 어느 값을 사용할 지 저장해둔 배열
int maps[53][53] = {};			//현재 지도에 저장된 미세먼지 및 공기청정기의 배치 상황
int tmp_maps[53][53] = {};		//순환 작업을 진행할 때 maps에서 임시적으로 저장해두는 값들의 배열
int R, C, T;

//공기청정기의 윗부분에 대한 좌표 구조체
struct upside {
	int x;
	int y;
};

//공기청정기의 아랫부분에 대한 좌표 구조체
struct downside {
	int x;
	int y;
};

//미세먼지들의 정보를 큐에 저장하기 위해 만들어 둔 구조체
//미세먼지가 존재하는 위치와 미세먼지의 양이 저장된다
struct dusts {
	int x;
	int y;
	int amount;
};

upside u;
downside d;


//미세먼지가 확산하면 사용되는 함수
void spread() {
	queue<dusts> dust_q;
	//dust_q에 미세먼지가 존재하는 곳들을 모두 저장해둔다
	//다만, 해당 위치의 미세먼지 값이 4보다 커야만 한다. 4보다 작으면 확산 시 0이 된다.
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (maps[i][j] > 4) {
				dusts dmp;
				dmp.x = j;
				dmp.y = i;
				dmp.amount = maps[i][j];
				dust_q.push(dmp);
			}
		}
	}

	//dust_q가 비어있을 때 까지 확산을 진행한다
	while (dust_q.empty() == false) {
		dusts dust_temp = dust_q.front();
		dust_q.pop();

		
		int tmp_amount = dust_temp.amount;
		int now_spread = tmp_amount / 5;	//확산시 퍼지는 미세먼지의 값
		int ways = 4;						//확산할 수 있는 방향의 수

		for (int i = 0;i < 4;i++) {
			int idx = dust_temp.x + mov_x[i];
			int idy = dust_temp.y + mov_y[i];

			//확산하고자 하는 위치가 지도 밖이라면 ways를 줄인다
			if (idx >= 0 && idx < C && idy >= 0 && idy < R) {
				//확산하고자 하는 위치에 공기청정기가 있다면 ways를 줄인다
				if (maps[idy][idx] == -1) {
					ways--;
				}
				else {
					maps[idy][idx] += now_spread;
				}
			}
			else {
				ways--;
			}
		}

		//확산이 진행된 이후 남은 미세먼지의 값을 조정해둔다
		maps[dust_temp.y][dust_temp.x] -= now_spread * ways;
	}
}

//순환이 진행될 때 사용되는 함수
//공기청정기의 위치와 사용하게 될 순환방식이 저장된다
//공기청정기의 윗부분에서 순환은 반시계방향, 아랫부분에서 순환은 시계방향으로 이뤄지도록 한다
void circulate(int idx, int idy, int ways[4]) {
	int y = idy;
	int x = idx + 1;	//공기청정기의 다음 부분부터 순환이 진행된다

	maps[y][x] = 0;

	for (int i = 0;i < 4;i++) {
		//순환은 특정 방향을 기준으로 진행하다 2가지 조건이 발생하면 멈추고 다음 방향으로 진행한다
		//1. 해당 위치가 지도 밖인 경우
		//2. 해당 위치가 공기청정기의 위치 즉 순환이 한 바퀴 다 끝난 경우
		while (true) {
			int tmp_x = x + mov_x[ways[i]];
			int tmp_y = y + mov_y[ways[i]];

			if (!(0 <= tmp_y && tmp_y < R && 0 <= tmp_x && tmp_x < C)) {
				break;
			}

			if (idy == tmp_y && idx == tmp_x) {
				break;
			}

			//순환이 시작되기 전 미리 저장해둔 tmp_maps의 값들을 maps로 다시 옮긴다
			//이후 좌표값 또한 다음 순환을 위해 x와 y가 각각 tmp_x, tmp_y의 값을 이어받는다
			maps[tmp_y][tmp_x] = tmp_maps[y][x];
			y = tmp_y;
			x = tmp_x;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> T;
	int chk = 0;
	int answer = 0;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> maps[i][j];

			//공기청정기의 윗부분과 아랫부분의 좌표를 순차적으로 저장해둔다
			if (maps[i][j] == -1 && chk == 0) {
				u.x = j;
				u.y = i;
				chk = 1;
			}
			else if (maps[i][j] == -1 && chk != 0) {
				d.x = j;
				d.y = i;
			}
		}
	}

	for (int i = 0;i < T;i++) {
		spread();

		//확산이 진행된 이후의 상태를 tmp_maps에 저장해둔다
		//maps로 바로 옮기기보단 메모리도 충분하니 tmp_maps에 저장한 이후 maps로 갱신시키는게 편하다
		//변수를 변경하는 3단변경과 비슷하다고 생각하면될듯?
		for (int j = 0;j < R;j++) {
			for (int k = 0;k < C;k++) {
				tmp_maps[j][k] = maps[j][k];
			}
		}

		//이후 각각 반시계, 시계방향으로의 순환이 이루어지는데
		//순환이 이루어진 후의 값들은 maps에 다시금 저장된다
		circulate(u.x, u.y, declockway);
		circulate(d.x, d.y, clockway);
	}

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (maps[i][j] > 0) {
				answer += maps[i][j];
			}
		}
	}

	cout << answer << '\n';
	return 0;
}