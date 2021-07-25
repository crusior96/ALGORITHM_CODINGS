#include<iostream>
using namespace std;
long long int ways[100006][4] = {};

//정수 N이 주어졌을 때, 정수 N을 1, 2, 3의 합으로 나타내는 방법의 갯수를 구하여라
//이때, 순서가 다른 경우(1 + 3 / 3 + 1)은 서로 다른 별개의 방법으로 처리한다
//단, 연속해서 같은 수를 사용해서는 안된다
//기초적인 DP에 관한 문제이지만 그 기초가 없으면 못푼다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	//ways[a][b] : 숫자들을 더해가면서 a까지 만드는 경우의 수. 이때, 제일 최근에 더한 수는 b임을 나타낸다
	//하단에 있는 5가지 경우들은 각각 초기에 나올 수 있는 경우의 수이자 DP를 사용하기 위한 초기값이다
	ways[3][3] = 1;
	ways[2][2] = 1;
	ways[1][1] = 1;
	ways[3][1] = 1;
	ways[3][2] = 1;

	for (int i = 4;i <= 100000;i++) {
		//DP 작동방식
		//현 시점에서 1을 더하는 경우는 과거에 2 혹은 3을 더한 상황일 것
		//따라서 ways[i][a] = ways[i - 이번에 더할 수][a가 아닌 다른 수] + ways[i - 이번에 더할 수][a가 아닌 또 다른 수]
		//이런 식으로 전화식을 짜서 진행한다
		ways[i][1] = (ways[i - 1][2] + ways[i - 1][3]) % 1000000009;
		ways[i][2] = (ways[i - 2][1] + ways[i - 2][3]) % 1000000009;
		ways[i][3] = (ways[i - 3][1] + ways[i - 3][2]) % 1000000009;
	}

	for (int i = 0;i < Tc;i++) {
		int N;
		cin >> N;
		long long int answer = (ways[N][1] + ways[N][2] + ways[N][3]) % 1000000009;
		cout << answer << '\n';
	
	}
	return 0;
}