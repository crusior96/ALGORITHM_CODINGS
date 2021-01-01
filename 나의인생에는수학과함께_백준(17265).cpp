#include<iostream>
using namespace std;
int N;
char board[5][5] = {};
int maxi = -1000000;
int mini = 1000000;

//3*3 Ȥ�� 5*5 �������� ���ڿ� ������(+, -, *)���� �������ִ�
//�»�ܿ��� ���ϴ����� �ִܰŸ��� �̵��� ��, ������� ������ ���ڵ��� ��������
//�����ڿ� ���� ���ڵ��� ������ ����� �����Ѵ�[���� ���� ���� ��� X]
//�̶� ���� �� �ִ� �ִ� ������� �ּ� ������� ���Ͽ���


//bfs(���� ��ǥ, ���� ��ǥ, ������ ����, ��������� ��갪)
//calc�� 0�̸� �ش� ��ǥ���� �������� �ǹ�, ���� �����ӿ� ���� �����ڸ� ����޴´�
//calc�� 0�� �ƴϸ� �ش� ��ǥ���� ���������� �ǹ�, ���� �����ӿ� ���� ���ڿ� ����� ���� sol�� �����Ѵ�
//�� ������ �̷���� ���� ��ǥ�� �����δ�
//�׷��� ���ϴܿ� �����ϸ� �ش簪�� �������� �ִ��̳� �ּڰ��� ���Ѵ�.
void bfs(int x, int y, int calc, int sol) {
	if (x == N - 1 && y == N - 1) {
		if (maxi < sol) {
			maxi = sol;
		}

		if (mini > sol) {
			mini = sol;
		}
	}
	else {
		if (calc == 0) {
			if (x + 1 < N) {
				if (board[x + 1][y] == '+') {
					bfs(x + 1, y, 1, sol);
				}
				else if (board[x + 1][y] == '-') {
					bfs(x + 1, y, 2, sol);
				}
				else if (board[x + 1][y] == '*') {
					bfs(x + 1, y, 3, sol);
				}
			}

			if (y + 1 < N) {
				if (board[x][y + 1] == '+') {
					bfs(x, y + 1, 1, sol);
				}
				else if (board[x][y + 1] == '-') {
					bfs(x, y + 1, 2, sol);
				}
				else if (board[x][y + 1] == '*') {
					bfs(x, y + 1, 3, sol);
				}
			}
		}
		else {
			if (calc == 1) {
				if (x + 1 < N) {
					int tmp = board[x + 1][y] - '0';
					int tmp2 = sol + tmp;
					bfs(x + 1, y, 0, tmp2);
				}
				
				if (y + 1 < N) {
					int tmp = board[x][y + 1] - '0';
					int tmp2 = sol + tmp;
					bfs(x, y + 1, 0, tmp2);
				}
			}
			else if (calc == 2) {
				if (x + 1 < N) {
					int tmp = board[x + 1][y] - '0';
					int tmp2 = sol - tmp;
					bfs(x + 1, y, 0, tmp2);
				}

				if (y + 1 < N) {
					int tmp = board[x][y + 1] - '0';
					int tmp2 = sol - tmp;
					bfs(x, y + 1, 0, tmp2);
				}
			}
			else if (calc == 3) {
				if (x + 1 < N) {
					int tmp = board[x + 1][y] - '0';
					int tmp2 = sol * tmp;
					bfs(x + 1, y, 0, tmp2);
				}

				if (y + 1 < N) {
					int tmp = board[x][y + 1] - '0';
					int tmp2 = sol * tmp;
					bfs(x, y + 1, 0, tmp2);
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> board[i][j];
		}
	}

	//borad�� ����� ���ڷ� ��޵Ǵ� ���ڵ鿡�� ������ '0'�� ���ְ� int�� ������ ���� ��������.
	bfs(0, 0, 0, (board[0][0] - '0'));

	cout << maxi << " " << mini << '\n';
	return 0;
}