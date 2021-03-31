#include<iostream>
using namespace std;
int N, M, loc_x, loc_y, orders;
int maps[22][22] = {};
int dice[6] = { 0,0,0,0,0,0 };
int dice_temp[6] = { 0,0,0,0,0,0 };

//N*M�� ũ��¥�� ������ �ְ�, ��� ���� ����ִ� �ֻ����� �ִٰ� ��������
//�ֻ����� �������� �� 4�������� ������ �� ������, ������ ���� ���� ���� ���� �ٱ��̶�� ���������� �ʴ´�
//�ش� �������� �����̰� ���� �ֻ����� ������ ��� �κ��� 0�� �ƴ� ���ڶ��
//�ش� ���ڸ� �ֻ����� ���� �κп� �Ű����� �ش� ��ġ�� �������� 0���� �ٲ۴�
//�ش� �������� �����̰� ���� �ֻ����� ������ ��� �κ��� 0�̶��
//�ش� ���ڸ� �ֻ����� ���� �κп� ���� ���ڷ� �ٲٰ� �ֻ����� ���� �κ��� ���� 0���� �ٲ۴�

//�̶�, �� �����Ӹ��� �ֻ����� ������ ����϶�. ��Ģ�� ����Ǵ� �������� ��쿣 ������ ��� ���ص� �ȴ�.

//1 : ����, 2 : ����, 3 : ����, 4 : ����
//�ֻ����� �����̴� �Լ�. �������� ���⿡ ���� �۵� ����� �޶������� ū Ʋ�� ���Ծ���.
//dice_temp : �ֻ����� �������� ��, �ֻ����� ���ϰ� �ִ� ���� ��� ��ȭ�ϴ��� �̽��ϱ� ���� �߰��ٸ� ����
//			  �ش� �迭�� ����� ������ ���߿� dice �迭�� �Ű����� �ȴ�.
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