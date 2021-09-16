#include<iostream>
using namespace std;

//N개의 막대기들이 있다고 가정하자
//이들을 ans_s부터 시작해서 ans_e까지 잘랐을 때 나오는 구간들의 합이 M인 경우를 찾아야한다
//만약 그런 경우가 많다면, ans_s가 제일 작은 값을 출력하면 되고, 없다면 0, 0을 출력하면 된다
//구간의 길이는 좌표상의 시작 부분과 끝 부분을 모두 포함한다

int N, M;
int arr[1000003] = {};	//arr[i] : N개의 막대기들이 나열됐을때, 0에서부터 i번째 위치에 들어가있는 막대기들이 차지하는 구간의 갯수
						//		   부분합을 사용하기 위해 막대기의 시작 부분을 1 추가하고 끝부분을 1 감소시킨다
						//		   이를 통해 특정 구간안에 포함된 막대기들의 구간의 갯수를 구할 수 있게된다
int main() {
	int maxi = -1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		int s_idx, e_idx;
		cin >> s_idx >> e_idx;


		arr[s_idx + 1]++;
		arr[e_idx + 1]--;
	}

	for (int j = 1;j <= 1000000;j++) {
		arr[j] += arr[j - 1];
	}

	//투 포인터를 사용하여 M만큼의 막대기 요소가 존재하는지를 찾는다
	//O(N)의 복잡도를 가지고 있으며 N의 값이 최대 100만이기 때문에 큰 무리가 없다
	//또한 막대기의 시작과 끝 부분을 포함해서 계산해야 하기 때문에 변수처리에 주의해야한다
	int s, e, ans_s, ans_e;
	s = 0;
	e = 0;
	ans_s = 0;
	ans_e = 0;
	long long int total = 0;
	while (true) {

		if (total > M) {
			total -= arr[++s];
		}
		else if (total < M) {
			total += arr[++e];
		}
		else if (total == M) {
			ans_s = s;
			ans_e = e;
			break;
		}


		if (e == 1000001) {
			break;
		}

	}
	cout << ans_s << " " << ans_e << '\n';
	return 0;
}