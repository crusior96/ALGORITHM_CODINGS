#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
long long int N, P, Q, X, Y;
unordered_map<long long, unsigned long long> infi;

//무한수열(1351)과 유사하지만, 살짝 다른 문제
//N의 범위가 달라졌을 뿐 만 아니라, X와 Y라는 새로운 변수가 추가됐기 때문에 시간을 더욱 단축해야 한다
//이에 다른 자료구조에 대해 알아보게 된 결과, unordered_map이라는 자료구조에 대해 알 수 있게 됐다
//이외에도 또 다른 종류의 map이 있는데, 해당 부분에 관해선 추후에 다뤄보도록 하자

unsigned long long calc(long long  a) {
	if (a <= 0) {
		return 1;
	}


	if (infi[a]) {
		return infi[a];
	}

	return infi[a] = calc(a / P - X) + calc(a / Q - Y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P >> Q >> X >> Y;
	cout << calc(N) << '\n';
	return 0;
}