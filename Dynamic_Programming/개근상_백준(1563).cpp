#include<iostream>
using namespace std;
int N;
long long int time_checker[2002][2] = { 1 };	//time_checker[i][0] : 출석, time_checker[i][1] : 결석
long long int time_checker_non[2002] = { 0 };	//time_checker_non[i] : i번째 날에 지각함
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int answer;
	cin >> N;
	time_checker[1][0] = 1;
	time_checker[1][1] = 1;
	time_checker[2][0] = 2;
	time_checker[2][1] = 2;
	//지각을 단 한번도 하지 않을 때의 경우의 수들을 구하는 작업. 
	//이때 결석을 3번연속 하면 안 되므로 로직을 잘 짜야한다
	for (int i = 3;i <= N;i++) {
		time_checker[i][0] = time_checker[i - 1][0] + time_checker[i - 1][1];
		time_checker[i][1] = time_checker[i - 1][0] + time_checker[i - 2][0];
		if (time_checker[i][0] >= 1000000) {
			time_checker[i][0] %= 1000000;
		}

		if (time_checker[i][1] >= 1000000) {
			time_checker[i][1] %= 1000000;
		}
	}

	answer = time_checker[N][0] + time_checker[N][1];	//지각을 단 한번도 하지 않은 경우가 최초로 저장된다

	if (answer >= 1000000) {
		answer %= 1000000;
	}
	//이제 지각을 1회라도 하는 경우를 고려해서 진행한다
	//경우의 수는 각각 i를 기점으로 (0~i) , (i~N)까지의 경우의 수들을 각각 곱해주는 것을 i번째 날의 최초 지각 시점으로 잡는다.
	//해당 경우의 수들을 계속 answer에 저장한 후 조건에 맞게 바꿔준다
	for (int i = 1;i <= N;i++) {
		time_checker_non[i] = (time_checker[i - 1][0] + time_checker[i - 1][1]) * (time_checker[N - i][0] + time_checker[N - i][1]);
		if (time_checker_non[i] >= 1000000) {
			time_checker_non[i] %= 1000000;
		}
		answer += time_checker_non[i];
		if (answer >= 1000000) {
			answer %= 1000000;
		}
	}

	cout << answer << '\n';
	return 0;
}
