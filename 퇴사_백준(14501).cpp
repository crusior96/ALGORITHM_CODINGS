#include<iostream>
#include<algorithm>
using namespace std;

int days[16];
int money[16];
int total[16];
int N;

//N일후에 퇴직하는 사람이 있다고 가정하자
//각각의 N일동안에는 해당 days만큼의 시간을 소요하여 money만큼의 돈을 벌 수 있다
//이때 최종적으로 벌 수 있는 돈의 최댓값을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int budget = 0;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> days[i] >> money[i];
	}

	for (int i = 1;i <= N;i++) {
		//상담을 할 수 있을만큼 근무일수가 남은경우
		if (i + days[i] <= N + 1) {
			//근무를 하여 돈을 벌었을 때랑 현재까지 계산한 total[i]의 값이랑 비교해서 최댓값 저장
			total[i + days[i]] = max(total[i] + money[i], total[i + days[i]]);
			budget = max(budget, total[i + days[i]]);
		}

		//근무를 하지 않았을 경우, 다음날의 total[i + 1]과 근무를 하지 않아서 이어지는 total[i]의 값이랑 비교해서 최댓값 저장
		total[i + 1] = max(total[i], total[i + 1]);
		budget = max(budget, total[i + 1]);
	}

	cout << budget << '\n';
	return 0;
}