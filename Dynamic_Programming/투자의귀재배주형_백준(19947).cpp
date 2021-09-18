#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

//적금 상품이 총 3개가 있는데 각각 1년, 3년, 5년짜리 상품이다
//각각의 이율은 5%, 20%, 35%이며 적금도중 다른 상품으로 갈아탈 수 있지만 중도해지 이율은 없다
//초기 자본과 기간이 주어진다면, 해당기간 내에 만들 수 있는 최대 금액을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int money, days;
	cin >> money >> days;
	int banks[12] = {};
	int answer;	
	banks[0] = money;
	if (days == 0) {
		answer = money;
	}
	else {
		//지독한 코테에 시달려 풀게 된 쉬운 DP문제
		//한편으론 코테에 간단한 유형의 DP문제도 많이 나왔기에 이런문제를 '빠르게' 푸는 게 중요하다

		//1년, 3년, 5년이 지나서 적금이 만기 됐을때의 경우를 지속적으로 비교하여
		//현재 시점에서의 금액 상태를 비교, 최댓값을 저장하는 방식으로 진행한다
		for (int i = 1;i <= days;i++) {
			int tmp1 = banks[i - 1] * 1.05;
			banks[i] = tmp1;

			if (i >= 3) {
				int tmp2 = banks[i - 3] * 1.2;
				banks[i] = max(banks[i], tmp2);
			}

			if (i >= 5) {
				int tmp3 = banks[i - 5] * 1.35;
				banks[i] = max(banks[i], tmp3);
			}
		}
		answer = banks[days];
	}
	cout << answer << '\n';
	return 0;
}