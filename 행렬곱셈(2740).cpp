#include<iostream>
using namespace std;

int arr1[101][101] = {};
int arr2[101][101] = {};
int ans[101][101] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N, O, P;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr1[i][j];
		}
	}

	cin >> O >> P;
	for (int i = 0; i < O; i++) {
		for (int j = 0; j < P; j++) {
			cin >> arr2[i][j];
		}
	}

	int idx = 0;
	int idy = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < P; j++) {
			int res = 0;
			for (int k = 0; k < N; k++) {
				res += arr1[i][k] * arr2[k][j];
			}
			ans[idy][idx] = res;
			idx++;
		}
		idx = 0;
		idy++;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < P; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}
