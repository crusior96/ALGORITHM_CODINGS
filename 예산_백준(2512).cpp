#include<iostream>
#include<algorithm>
using namespace std;
int money[10002] = {};

//각각의 정책에 필요한 예산이 N개만큼 있다고 가정하자
//이때 현재 보유하고 있는 예산은 target이며 모든 예산을 배정할 수 없을경우엔 특정한 상한액만큼만 지불한다
//이 경우에 지불될 수 있는 최대의 상한액은 얼마인가 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	long long target, answer;
	//mini와 maxi는 각각 지불될 수 있는 최소 ~ 최대 예산 상한액을 의미한다
	//문제풀이시 한참동안 못풀은 이유는 최소 예산 상한액을 0이 아니라 예산목록인 money들 중 최솟값으로 정했기 때문
	int mini = 0;
	int maxi = 0;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> money[i];
		if (money[i] > maxi) {
			maxi = money[i];
		}
	}
	cin >> target;

	//이분탐색을 진행하여 최대상한액을 구한다
	//여기서 sum은 상한액을 mid로 정했을 때 모이게 되는 예산안
	while (mini <= maxi) {
		int mid = (mini + maxi) / 2;
		long long sum = 0;
		for (int i = 0;i < N;i++) {
			sum += min(money[i], mid);
		}

		//목표 예산안보다 작거나 같은 금액일 경우 answer에 임시저장하고 mini값을 변동시킨다
		//그렇지 않다면 maxi값을 변동시킨다
		//이후 계속 이분탐색을 진행해서 mini와 maxi값의 대소관계가 바뀔때까지 계속한다
		if (sum <= target) {
			answer = mid;
			mini = mid + 1;
		}
		else if (sum > target) {
			maxi = mid - 1;
		}
	}	

	cout << answer << '\n';
	return 0;
}