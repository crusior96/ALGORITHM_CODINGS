#include<iostream>
using namespace std;
int N, M, loc_x, loc_y, orders;
int maps[22][22] = {};
int dice[6] = { 0,0,0,0,0,0 };
int dice_temp[6] = { 0,0,0,0,0,0 };

//N*M의 크기짜리 지도가 있고, 모든 면이 비어있는 주사위가 있다고 가정하자
//주사위는 동서남북 총 4방향으로 움직일 수 있으며, 움직인 곳이 만약 지도 범위 바깥이라면 움직여지지 않는다
//해당 방향으로 움직이고 나서 주사위가 지도랑 닿는 부분이 0이 아닌 숫자라면
//해당 숫자를 주사위랑 닿은 부분에 옮겨적고 해당 위치의 지도값을 0으로 바꾼다
//해당 방향으로 움직이고 나서 주사위가 지도랑 닿는 부분이 0이라면
//해당 숫자를 주사위랑 닿은 부분에 적힌 숫자로 바꾸고 주사위랑 닿은 부분의 값은 0으로 바꾼다

//이때, 매 움직임마다 주사위의 윗면을 출력하라. 규칙에 위배되는 움직임일 경우엔 윗면을 출력 안해도 된다.

//1 : 동쪽, 2 : 서쪽, 3 : 북쪽, 4 : 남쪽
//주사위를 움직이는 함수. 움직임의 방향에 따라 작동 방식은 달라지지만 큰 틀엔 변함없다.
//dice_temp : 주사위를 움직였을 때, 주사위가 지니고 있던 값이 어떻게 변화하는지 이식하기 위한 중간다리 역할
//			  해당 배열에 저장된 값들은 나중에 dice 배열로 옮겨지게 된다.
void moveup(int idx, int idy, int order) {
	if (order == 1) {
		if (idy + 1 < M) {
			dice_temp[0] = dice[3];
			dice_temp[1] = dice[1];
			dice_temp[2] = dice[0];
			dice_temp[3] = dice[5];
			dice_temp[4] = dice[4];
			dice_temp[5] = dice[2];
			loc_y++;
			if (maps[loc_x][loc_y] == 0) {
				maps[loc_x][loc_y] = dice_temp[5];
			}
			else {
				dice_temp[5] = maps[loc_x][loc_y];
				maps[loc_x][loc_y] = 0;
			}
			cout << dice_temp[0] << '\n';
			for (int i = 0;i < 6;i++) {
				dice[i] = dice_temp[i];
			}
		}

	}
	else if (order == 2) {
		if (idy - 1 >= 0) {
			dice_temp[0] = dice[2];
			dice_temp[1] = dice[1];
			dice_temp[2] = dice[5];
			dice_temp[3] = dice[0];
			dice_temp[4] = dice[4];
			dice_temp[5] = dice[3];
			loc_y--;
			if (maps[loc_x][loc_y] == 0) {
				maps[loc_x][loc_y] = dice_temp[5];
			}
			else {
				dice_temp[5] = maps[loc_x][loc_y];
				maps[loc_x][loc_y] = 0;
			}
			cout << dice_temp[0] << '\n';
			for (int i = 0;i < 6;i++) {
				dice[i] = dice_temp[i];
			}
		}
	}
	else if (order == 3) {
		if (idx - 1 >= 0) {
			dice_temp[0] = dice[4];
			dice_temp[1] = dice[0];
			dice_temp[2] = dice[2];
			dice_temp[3] = dice[3];
			dice_temp[4] = dice[5];
			dice_temp[5] = dice[1];
			loc_x--;
			if (maps[loc_x][loc_y] == 0) {
				maps[loc_x][loc_y] = dice_temp[5];
			}
			else {
				dice_temp[5] = maps[loc_x][loc_y];
				maps[loc_x][loc_y] = 0;
			}
			cout << dice_temp[0] << '\n';
			for (int i = 0;i < 6;i++) {
				dice[i] = dice_temp[i];
			}
		}

	}
	else if (order == 4) {
		if (idx + 1 < N) {
			dice_temp[0] = dice[1];
			dice_temp[1] = dice[5];
			dice_temp[2] = dice[2];
			dice_temp[3] = dice[3];
			dice_temp[4] = dice[0];
			dice_temp[5] = dice[4];
			loc_x++;
			if (maps[loc_x][loc_y] == 0) {
				maps[loc_x][loc_y] = dice_temp[5];
			}
			else {
				dice_temp[5] = maps[loc_x][loc_y];
				maps[loc_x][loc_y] = 0;
			}
			cout << dice_temp[0] << '\n';
			for (int i = 0;i < 6;i++) {
				dice[i] = dice_temp[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> loc_x >> loc_y >> orders;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 0;i < orders;i++) {
		int order_num;
		cin >> order_num;
		moveup(loc_x, loc_y, order_num);
	}
	return 0;
}