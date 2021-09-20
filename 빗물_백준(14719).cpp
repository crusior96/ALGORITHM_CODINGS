#include<iostream>
using namespace std;
bool arr[502][502] = {};	//arr[j][i]가 1이라면, 가로기준 i, 세로기준 j가 되는 부분엔 블록이 있다는 뜻이다

//가로 N, 세로 M의 공간이 있다고 가정하자
//이때, 해당 공간 내에 있는 가로칸들 중 높이가 되는 부분들을 입력한다고 가정하자
//그렇게 표현된 블록들을 기준으로 비가 고일 때, 고이게 된 빗물들의 총량을 구하여라
//단순 구현 문제이지만 골드 5인게 조금은 의문. 그래서 빠르게 구현하는 것을 목표로 삼았다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N;
	int answer = 0;
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		int h;
		cin >> h;
		for (int j = 0;j < h;j++) {
			arr[j][i] = 1;
		}
	}

	//빗물측량과정
	//1. 특정 높이를 기준으로 가로map의 시작 인덱스에서 끝부분까지 향한다
	//2. 최초로 블록이 있음을 발견하게 된 부분을 idx에 입력한다
	//3. 이후 idx가 -1이 아닌 상황일 때, 그 다음 공간에 블록이 없으면 stk를 상승시킨다
	//4. 만약 블록이 있음을 발견하게 된다면 쌓인 stk를 answer에 더한 후 초기화, idx를 현재 위치로 재저장 한다
	for (int j = 0;j < M;j++) {
		int idx = -1;
		int stk = 0;
		for (int i = 0;i < N;i++) {
			if (arr[j][i] == 1 && idx == -1) {
				idx = i;
			}
			else if (arr[j][i] == 1 && idx != -1) {
				answer += stk;
				stk = 0;
				idx = i;
			}
			else if (arr[j][i] == 0 && idx != -1) {
				stk++;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}