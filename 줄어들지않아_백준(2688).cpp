#include<iostream>
using namespace std;
long long int DP[66][10] = {};			//DP[i][j]의 의미 : i번째 자리에 j를 넣을 수 있는 경우의 수
long long int answer[101] = {};			//자릿수마다 규칙에 맞는 정수의 갯수들이 저장된다

//temp자리의 정수가 있다고 가정하자. 이 정수는 0으로 시작해도 된다
//왼쪽에서부터 오른쪽 자리로 갈 때, 왼쪽에 있는 자리값보다 오른쪽에 있는 자리값이 크거나 같아야한다
//이때, temp자리의 정수가 위의 조건을 만족할 수 있는 정수의 갯수는 총 몇개인가?

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0;i < 10;i++) {
		DP[1][i] = 1;
	}

	answer[1] = 10;
	
	//DFS 과정을 진행하여 DP의 값을 채우고 answer의 값 또한 채워나간다
	//점화식의 경우, DP[i][j](i번째 자리에 j가 올 경우의 수) = DP[i - 1][j] + sum(i-1번째 자리에 j가 온 경우의 수 + DP[i-1][j-1]의 값)
	//sum은 DP[i][j] 바로 앞 왼쪽자리에 오게될 값이 위의 규칙을 만족하는 경우의 수를 의미한다
	//그렇게 채워진 DP값에서 DP[i]내에 있는 모든 값들을 answer[i]에 합산해둔다
	for (int i = 2;i < 65;i++) {
		long long int sum = 0;
		for (int j = 0;j < 10;j++) {
			DP[i][j] = DP[i - 1][j] + sum;
			sum += DP[i - 1][j];
		}

		for (int j = 0;j < 10;j++) {
			answer[i] += DP[i][j];
		}
	}


	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		cout << answer[temp] << '\n';
	}
	return 0;
}