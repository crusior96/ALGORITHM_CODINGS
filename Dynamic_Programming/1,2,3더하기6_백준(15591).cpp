#include<iostream>
using namespace std;

unsigned long long int arr[100002] = {};

//1, 2, 3 이 3개의 숫자만을 사용하여 어떤 숫자 i를 만드는 방법들을 arr[i]에 저장해둔다고 가정하자
//숫자를 사용하는 순서가 다르면 서로 다른 방법이라고 이야기할 수 있다
//다만 숫자를 더할 때 식에 배치하는 순서가 서로 대칭이어야 원하는 방법이라고 말할 수 있다
//1 ~ 100000의 숫자가 주어질 때, 해당 숫자를 만드는 방법을 1000000009로 나눈 나머지 값으로 출력하라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Tc;
	cin >> Tc;

	//DP를 풀기위한 초기값 + 규칙
	//최소한 3, 3을 사용하게 되는 6까지의 숫자값들을 초기값으로 지정해줘야한다
	//이후 규칙은 이전까지의 결과값들 중 1, 2, 3을 맨 끝에 추가해줬을 때 i가 나올 수 있다면 arr[i]에 arr[i-2], arr[i-4], arr[i-6]을
	//추가해주는 방식으로 점화식을 세워나가면 된다
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 2;
	arr[4] = 3;
	arr[5] = 3;
	arr[6] = 6;

	for (int i = 7;i <= 100000;i++) {
		arr[i] = (arr[i - 2] + arr[i - 4] + arr[i - 6]) % 1000000009;
	}

	for (int i = 0;i < Tc;i++) {
		int N;
		cin >> N;
		cout << arr[N] << '\n';
	}


	return 0;
}