#include<iostream>
using namespace std;


int N;
int arr[21][21] = {};	//arr[i][j] : i에서 j로 가는데 걸리는 최단시간
int floid[21][21] = {};	//floid[i][j] : i에서 j로 가는데 걸리는 최단시간인 arr[i][j]가 정말 최단시간인지에 대해 체크하는 값들의 배열

//N개의 도시들이 있다고 가정하자. 각각의 도시들은 서로 이어져 있다.
//N*N의 도표에 각각의 도시들간 최단 거리를 구해놨다고 가정하자. 해당 값들은 도시에 남은 도로들을 정렬해서 얻은 값들이다.
//이때, 현재 남아있는 도시들 사이의 도로들의 거리 값의 총합 중 최솟값을 구하여라.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	int res = 0;
	int answer = 0;

	//플로이드 와샬의 개념을 응용한 문제풀이
	//만약 도시 i -> j로 이동하는 거리가 i -> k -> j와 같이 다른 도시를 거쳐가는 거리보다 크거나 같다면 최단거리가 아니라는 뜻이며
	//행여나 크다면 나올 수 없는 값이기 때문에 answer에 -1입력하고, 같다면 문제 조건에 맞지 않기 때문에 최단거리 도로로 취급하지 않는다
	for (int k = 0;k < N;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (i == j || j == k || k == i) {
					continue;
				}
				else if (arr[i][j] > arr[j][k] + arr[k][i]) {
					floid[i][j] = -1;
					res = -1;
					break;
				}
				else if (arr[i][j] == arr[j][k] + arr[k][i]) {
					floid[i][j] = 1;
				}
			}
		}
	}

	if (res == -1) {
		cout << -1 << '\n';
	}
	else if (res != -1) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (floid[i][j] == 0) {
					answer += arr[i][j];
				}
			}
		}
		//현재 answer내에는 arr값이 2배 적용됐으므로 2로 나눠줘야 한다
		cout << answer / 2 << '\n';
	}


	return 0;
}