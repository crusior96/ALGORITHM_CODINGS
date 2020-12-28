#include<iostream>
#include<cmath>
using namespace std;
int N;
int answer = 0;
int cols[16] = {};	//cols[i] = temp -> i번째 퀸이 판에 놓여졌을 때, temp번째 판에 놓여져있음을 의미하는 행렬

//N*N칸의 판에 N개의 퀸을 놓으려고 한다
//이때 퀸들은 퀸의 이동경로상에 서로 겹쳐져있으면 안된다
//N개의 퀸을 놓을 때, 판에 퀸들을 놓을 수 있는 경우의 수들을 모두 구하여라
//일명 브루트포스로 유명한 문제 중 하나


//퀸들이 서로 이동경로가 겹치는지 아닌지 테스트하는 함수
//tmp번째 놓는 퀸의 cols[]값과 이전에 놓았던 퀸들의 cols[]값이 같은지
//아니면 tmp번째 놓는 퀸과 이전에 놓았던 퀸들이 대각선상에 있는지 테스트해서
//만약 겹친다면 false를, 안겹친다면 true를 출력한다
bool rule_check(int tmp) {
	for (int i = 0;i < tmp;i++) {
		if (cols[i] == cols[tmp] || abs(cols[tmp] - cols[i]) == tmp - i) {
			return false;
		}
	}
	return true;
}

//퀸을 x번 놓으면서 answer값을 구하는 재귀함수
//x가 N이 될 때마다 answer를 올려준다
void queen_check(int x) {
	if (x == N) {
		answer++;
	}
	else {
		for (int i = 0;i < N;i++) {
			cols[x] = i;
			if (rule_check(x)) {
				queen_check(x + 1);
			}
		}
	}
}

int main() {
	cin >> N;
	queen_check(0);
	cout << answer << '\n';
	return 0;
}