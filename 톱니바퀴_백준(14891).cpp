#include<iostream>
#include<string>
using namespace std;
int arr[5][9];

//4개의 톱니바퀴가 있다고 가정하자
//각각의 톱니바퀴는 8개의 톱니로 이루어져있으며, 각각의 톱니에는 N극인지 S극인지에 대한 정보가 들어있다
//각각의 톱니들은 왼쪽 톱니(9시방향)와 오른쪽 톱니(3시방향)가 서로 닿게끔 위치돼있다
//이 톱니바퀴들은 K번의 회전 입력을 부여받는데, 회전 입력은 회전 방향과 회전을 시작 할 톱니바퀴로 이루어져있다
//어떤 톱니바퀴가 회전할 때, 해당 톱니바퀴랑 닿은 부분의 다른 톱니바퀴의 톱니가 서로 다른 극이면
//그 톱니바퀴는 회전하는 톱니바퀴랑은 다른 방향으로 회전하게 된다
//K번의 회전 입력이 들어온 다음의 톱니바퀴 상태를 출력하라


//톱니 바퀴 번호와 회전방향이 주어졌을 때 톱니 돌리기와 관련된 함수
//톱니바퀴 회전 체크에 필요한건 a[i][2]과 a[i][6]임을 명심하자
void turnit(int num, int turn_w) {
	int turn_1 = 0;
	int turn_2 = 0;
	int turn_3 = 0;
	int turn_4 = 0;		//각각 1 ~ 4번 톱니의 회전방향을 암시한다

	//num값에 따라 톱니바퀴의 화전유무 및 회전방향 체크 순서가 달라진다
	//num이 1이면 그와 연결된 2, 3, 4번 순서대로 체크되고
	//2이면 그와 연결된 4는 따로 체크하고 3과 2 순서대로 체크하게 된다
	//즉, 마주하는 톱니바퀴와의 회전상태를 먼저 체크한다는 뜻
	//이때, 회전방향이 체크되지 않은 부분은 그와 연결된 톱니바퀴의 회전방향을 체크 할 필요가 없다는 점을 알아두자
	if (num == 1) {
		turn_1 = turn_w;
		if (arr[1][2] != arr[2][6]) {
			if (turn_1 == -1) {
				turn_2 = 1;
			}
			else if (turn_1 == 1) {
				turn_2 = -1;
			}
		}

		if (turn_2 != 0) {
			if (arr[2][2] != arr[3][6]) {
				if (turn_2 == -1) {
					turn_3 = 1;
				}
				else if (turn_2 == 1) {
					turn_3 = -1;
				}
			}
		}

		if (turn_3 != 0) {
			if (arr[3][2] != arr[4][6]) {
				if (turn_3 == -1) {
					turn_4 = 1;
				}
				else if (turn_3 == 1) {
					turn_4 = -1;
				}
			}
		}
	}
	else if (num == 2) {
		turn_2 = turn_w;
		if (arr[1][2] != arr[2][6]) {
			if (turn_2 == -1) {
				turn_1 = 1;
			}
			else if (turn_2 == 1) {
				turn_1 = -1;
			}
		}

		if (arr[2][2] != arr[3][6]) {
			if (turn_2 == -1) {
				turn_3 = 1;
			}
			else if (turn_2 == 1) {
				turn_3 = -1;
			}
		}

		if (turn_3 != 0) {
			if (arr[3][2] != arr[4][6]) {
				if (turn_3 == -1) {
					turn_4 = 1;
				}
				else if (turn_3 == 1) {
					turn_4 = -1;
				}
			}
		}
	}
	else if (num == 3) {
		turn_3 = turn_w;
		if (arr[3][2] != arr[4][6]) {
			if (turn_3 == -1) {
				turn_4 = 1;
			}
			else if (turn_3 == 1) {
				turn_4 = -1;
			}
		}

		if (arr[3][6] != arr[2][2]) {
			if (turn_3 == -1) {
				turn_2 = 1;
			}
			else if (turn_3 == 1) {
				turn_2 = -1;
			}
		}

		if (turn_2 != 0) {
			if (arr[2][6] != arr[1][2]) {
				if (turn_2 == -1) {
					turn_1 = 1;
				}
				else if (turn_2 == 1) {
					turn_1 = -1;
				}
			}
		}
	}
	else if (num == 4) {
		turn_4 = turn_w;
		if (arr[4][6] != arr[3][2]) {
			if (turn_4 == -1) {
				turn_3 = 1;
			}
			else if (turn_4 == 1) {
				turn_3 = -1;
			}
		}

		if (turn_3 != 0) {
			if (arr[3][6] != arr[2][2]) {
				if (turn_3 == -1) {
					turn_2 = 1;
				}
				else if (turn_3 == 1) {
					turn_2 = -1;
				}
			}
		}

		if (turn_2 != 0) {
			if (arr[2][6] != arr[1][2]) {
				if (turn_2 == -1) {
					turn_1 = 1;
				}
				else if (turn_2 == 1) {
					turn_1 = -1;
				}
			}
		}
	}

	//1 ~ 4번 톱니바퀴들의 회전 관련 숫자가 다 입력된 다음
	//입력받은 회전 숫자가 1이면 시계방향으로, -1이면 시계 반대방향으로 돌아가게 한다
	if (turn_1 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[1][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[1][i] = tmp[i - 1];
		}
		arr[1][0] = tmp[7];
	}
	else if (turn_1 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[1][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[1][i] = tmp[i + 1];
		}
		arr[1][7] = tmp[0];
	}

	if (turn_2 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[2][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[2][i] = tmp[i - 1];
		}
		arr[2][0] = tmp[7];
	}
	else if (turn_2 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[2][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[2][i] = tmp[i + 1];
		}
		arr[2][7] = tmp[0];
	}

	if (turn_3 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[3][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[3][i] = tmp[i - 1];
		}
		arr[3][0] = tmp[7];
	}
	else if (turn_3 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[3][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[3][i] = tmp[i + 1];
		}
		arr[3][7] = tmp[0];
	}

	if (turn_4 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[4][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[4][i] = tmp[i - 1];
		}
		arr[4][0] = tmp[7];
	}
	else if (turn_4 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[4][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[4][i] = tmp[i + 1];
		}
		arr[4][7] = tmp[0];
	}
}

int pointchecker() {
	int multiplier = 1;
	int tmp = 0;
	for (int i = 1;i <= 4;i++) {
		if (arr[i][0] == 1) {
			tmp += multiplier;
		}

		multiplier = multiplier * 2;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int K, answer;
	for (int i = 1;i <= 4;i++) {
		string temp;
		cin >> temp;
		for (int j = 0;j < 8;j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	cin >> K;
	for (int i = 0;i < K;i++) {
		int target, turnway;
		cin >> target >> turnway;
		turnit(target, turnway);
	}
	answer = pointchecker();
	cout << answer << '\n';
	return 0;
}