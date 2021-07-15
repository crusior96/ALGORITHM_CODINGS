#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int arr[10] = {};
int tmp[10002] = {};
int num[10002] = {};
vector<int> numbers;

//N개의 자연수중에서 M개를 고른 수열이 있다고 가정하자
//같은 수를 여러번 골라도 되지만 고른 수열은 비내림차순이어야 한다
//이 조건으로 만들 수 있는 모든 수열들을 출력하라


//백트래킹 방식을 사용해서 수열들을 구현한다
//back_track(int a, int b) : 수열을 만드는데 현재 a개의 숫자를 배치했고 조건이 원하는 수열의 길이는 b라는 뜻
//a == b이면 수열이 완성됐으니 출력하고, a != b이면 현재까지 만든 수열 뒤에 다른 숫자들을 넣으면서 진행한다
//a == b라서 수열이 완성된 이후에는 기존의 수열에서 pop_back()을 진행한 다음 다른 숫자를 넣어서 또 다른 경우의 수를 만든다
void back_track(int a, int b) {
	if (a == b) {
		for (int i = 0;i < numbers.size();i++) {
			cout << numbers[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0;i < N;i++) {
			if (numbers.back() <= num[i]) {
				numbers.push_back(num[i]);
				back_track(a + 1, b);
				numbers.pop_back();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		tmp[arr[i]] = 1;
	}
	
	sort(arr, arr + N);
	int idx = 0;
	//정렬된 숫자들을 토대로 어떤 숫자들이 있는지 파악한 다음
	//현재 존재하는 숫자들만 num 배열에 오름차순으로 저장해둔다
	for (int i = 0;i <= 10001;i++) {
		if (tmp[i] == 1) {
			num[idx] = i;
			idx++;
		}
	}
	//num배열에 있는 모든 숫자들을 토대로 먼저 순열에 입력한 다음 back_track을 진행한다
	for (int i = 0;i < idx;i++) {
		numbers.push_back(num[i]);
		back_track(1, M);
		numbers.pop_back();
	}
	return 0;
}