#include<iostream>
using namespace std;

//M*N ũ���� ������ �ִٰ� ��������
//�ش� ������ U, D, L, R�� ǥ��������� ������ ��ġ�� ���� ��, �Ʒ�, ����, ���������� �̵��ϰ� �ȴ�
//�̶�, �̷��� �������� ������ Ȥ�� ����Ŭ�� �������� �ʰԲ� ������ ������ �����ϰ��� �Ѵ�
//�׷��ٸ�, ������ ������ �� �� �����ؾ� ����Ŭ�� ������ �ʰ� �ɱ�?


struct start_point {
	int start_x;
	int start_y;
};

start_point start_arr[1001][1001] = {};		//start_arr[x][y] : (x,y)���� �ִ� ����Ŭ�� ���� ������ �����صд�
											//				    �� ���� ���� ���� ����Ŭ�� �ش� ��ġ ����Ŭ�� ���� �� �ִ�
int checker[1001][1001] = {};
char maps[1001][1001] = {};
int M, N;
int answer = 0;


//���� ��ǥ�� ������ �ִ� ����Ŭ�� ���� ������ ���� ��ǥ�� ��ġ�� ����� �Լ�
//maps���� ���Ͽ� �� ��ǥ�� �������� �̵����� ���� ��츦 ã�� �� ����
//Ž���� ����� ��ġ�� �ƴ϶�� �ش� ��ġ�� start_arr ���� origin_x�� y�� �����ϰ� �̵� �� �����ϴ� ��ǥ�� �������� search�� �����Ѵ�
//Ž���� ����ƴ� ��ġ���, �ش� ��ġ�� ����Ŭ �������� ���� ��ġ�� �������� ���Ѵ�
//������ ����Ŭ�� �´ٸ�, answer���� �ø���, �ش� ����Ŭ�� �� �̻� �߰����� ����Ŭ ��ǥ�� ������ �ʰԵȴ�
//�׷��� �ʴٸ�, ���� �ٸ� ����Ŭ�� ���������� �ǹ��ϰ� �ȴ�
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
			//Ž���� ������� ���� ���� �������� DFS�� �����ϰ� �ȴ�
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