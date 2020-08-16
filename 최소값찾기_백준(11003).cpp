#include<iostream>
#include<deque>
using namespace std;

int num[5000001] = {};				//입력받은 숫자들이 저장되는 부분
deque<pair<int, int>> finding_min;	//각각 num 배열내에 있는 숫자값과 저장된 순서위치를 의미한다

//N개의 숫자들이 나열돼있을 때, i - L + 1번째 숫자에서부터 i번째 숫자들 중 최솟값을 구하여라
//이때, 음수번째 숫자는 고려할 필요가 없다고 보면 된다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		cin >> num[i];
	}

	for (int i = 0;i < N;i++) {
		//새로이 입력받는 finding_min deque 범위내에서 문제를 해결한다

		//문제규칙상 i - L + 1번째 숫자에서 i번째 숫자까지에 있는 값들의 최솟값을 구하기 때문에
		//i - L보다 앞에 있는 숫자들은 미리 finding_min deque에서 제거한다
		if (!finding_min.empty() && finding_min.front().second <= i - L) {
			finding_min.pop_front();
		}

		//입력받은 finding_min deque내에서 num[i]의 값보다 큰 값들은 모두 finding_min에서 제거한다
		//그렇게해서 얻은 num[i]보다 작은 값부터는 finding_min에 남겨둔다
		while (!finding_min.empty() && finding_min.back().first > num[i]) {
			finding_min.pop_back();
		}

		//finding_min에 남은 값 중 최솟값을 저장한다
		//이때, 덱 내에 있는 값들은 오름차순으로 정렬되므로 해당 finding_min deque의 first값이 해당 구간의 최솟값이다
		finding_min.push_back(make_pair(num[i], i));
		cout << finding_min.front().first << " ";
	}
	cout << '\n';
	return 0;
}