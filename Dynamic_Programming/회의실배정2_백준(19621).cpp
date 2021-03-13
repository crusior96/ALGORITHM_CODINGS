#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, answer;
int discuss[52] = {};

void max_disc(int num, int total) {
	if (num > N - 1) {
		answer = max(total, answer);
		return;
	}

	//생각해낸 DP
	//1. 이번 회의를 건너뛰고 다음 번 회의로 넘어간다
	//2. 이번 회의를 진행하고 2번 뒤에 있는 회의로 넘어간다
	max_disc(num + 1, total);
	max_disc(num + 2, total + discuss[num]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0;i < N;i++) {
		//어차피 연속된 회의를 할 수 없는 상황이고 정보가 오름차순으로 주어졌으므로
		//회의에 참여하는 사람 수만 저장해두는 것으로 한다
		cin >> discuss[i] >> discuss[i] >> discuss[i];
	}

	max_disc(0, 0);

	cout << answer << '\n';
	return 0;
}
