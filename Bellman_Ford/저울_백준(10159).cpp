#include<iostream>
using namespace std;
int arr[102][102] = {};

//어떠한 물건이 N개 있다고 가정하자
//이때 M개의 관계표가 주어지는데 A B라면 A가 B보다 무겁다는 뜻이다
//주어진 정보만을 토대로 특정 물건이 다른 물건보다 확실하게 무겁거나 가벼운지를
//판단할 수 없는 물건의 갯수를 각각 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	cin >> M;

	//무게의 무거움에 대한 정보를 배열에 저장한다
	//arr[s][e] : s > e라면 1, 아니라면 0을 저장한다
	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		arr[s][e] = 1;
	}

	//벨만 포드 알고리즘을 사용하여 풀어냈다
	//a -> b && b -> c이면 a -> c임을 확신할 수 있다는 점에서 사용함
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				if (arr[j][i] && arr[i][k]) {
					arr[j][k] = 1;
				}
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		int answer = 0;
		//이후 j 가 i보다 무거운가에 대한 정보도 없고, i가 j보다 무거운가에 대한 정보도 없다면 answer를 1 증가시킨다
		//일반적인 경우엔 j가 i보다 무거울 때, i는 j보다 가벼운 경우 혹은 그 반대가 있는데
		//이 경우는 적어도 한 곳에서 누가 누구보다 무겁다에 대한 정보가 있기 때문에 상호간에 무거움에 대한 정보를 확실히 알 수 있다
		//이제 j가 i보다 무겁고 i가 j보다 무거운 경우는 없기 때문에 논외로 처리하게 된다
		for (int j = 1;j <= N;j++) {
			if (!arr[j][i] && !arr[i][j]) {
				answer++;
			}
		}
		cout << answer - 1 << '\n';
	}
	return 0;
}