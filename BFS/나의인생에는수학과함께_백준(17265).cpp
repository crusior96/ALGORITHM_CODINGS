#include<iostream>
using namespace std;
int N;
char board[5][5] = {};
int maxi = -1000000;
int mini = 1000000;

//3*3 혹은 5*5 보드위에 숫자와 연산자(+, -, *)들이 나열돼있다
//좌상단에서 우하단으로 최단거리를 이동할 때, 현재까지 연산한 숫자들을 기준으로
//연산자와 다음 숫자들이 나오면 계산을 진행한다[곱셈 덧셈 순서 상관 X]
//이때 얻을 수 있는 최대 결과값과 최소 결과값을 구하여라


//bfs(세로 좌표, 가로 좌표, 연산자 종류, 현재까지의 계산값)
//calc가 0이면 해당 좌표값이 숫자임을 의미, 다음 움직임에 나올 연산자를 저장받는다
//calc가 0이 아니면 해당 좌표값이 연산자임을 의미, 다음 움직임에 나올 숫자와 계산한 값을 sol에 저장한다
//위 저장이 이루어진 이후 좌표를 움직인다
//그러다 우하단에 도착하면 해당값을 기준으로 최댓값이나 최솟값을 구한다.
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

	//borad에 저장된 숫자로 취급되는 숫자들에는 무조건 '0'을 빼주고 int로 저장한 다음 연산하자.
	bfs(0, 0, 0, (board[0][0] - '0'));

	cout << maxi << " " << mini << '\n';
	return 0;
}
