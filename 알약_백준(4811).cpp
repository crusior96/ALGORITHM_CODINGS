#include<iostream>
#include<algorithm>
using namespace std;
long long int pills[31] = {};	//문자열의 갯수들이 모이는 곳.

//한 사람이 N개의 약을 먹는다고 가정하자. 이때 N의 범위는 30 이하의 자연수이다
//이 사람은 약 1개를 통째로 먹을 수도 있지만, 1개의 약을 반으로 쪼개 먹을 수도 있다
//이때 통째로 먹은 날을 A, 반으로 쪼개 먹은 날을 B라고 기록했을 경우
//N개의 약을 먹으면서 기록한 서로다른 결과값들이 모인 문자열의 갯수들을 구하여라
//테스트케이스는 최대 1000개이며 N의 값이 0으로 주어질 때 테스트케이스가 멈추게 된다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//상당히 기괴한 수열 체계를 가지고 있어서 구글링을 통해 문제를 해결할 수 있었다
	//1,1,2,5,14,42 순으로 시작된다 싶으면 이걸 사용해야 한다
	//점화식 상으론 0번째 항은 1, n번째항부턴 시그마 i = 0에서 n까지 i번째 항 * (n - i)번째 항으로 구할 수 있다
	//해당 문제 말고도 n쌍의 괄호로 만들 수 있는 다른 괄호외 갯수를 구한다거나, 정사각형으로 이루어진 평면에서 최단경로로
	//목적지에 가는 경우의 수 등을 구할 때 사용할 수 있다
	//단, 해당 수열은 30번째 항만 해도 엄청 크기 때문에 long long이나 long long int를 사용하는 것을 추천
	pills[0] = 1;
	pills[1] = 1;
	for (int i = 1;i <= 30;i++) {
		long long int tmp = 0;
		for (int j = 0;j <= i;j++) {
			tmp += pills[j] * pills[i - j];
		}
		pills[i + 1] = tmp;
	}

	bool done = true;
	int testcase = 0;
	while (done) {
		if (testcase == 1000) {
			break;
		}

		int Tc;
		cin >> Tc;

		if (Tc == 0) {
			done = false;
			break;
		}
		else {
			cout << pills[Tc] << '\n';
		}
		testcase++;
	}
	return 0;
}