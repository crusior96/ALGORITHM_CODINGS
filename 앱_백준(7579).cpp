#include<iostream>
#include<algorithm>
using namespace std;
int memo[101];				//어플들의 메모리 용량이 저장되는 배열
int candi[101];				//어플들의 On Off 비용이 저장되는 배열
int total[101][10001];		//total[i][j] : i번째 앱 중 j만큼의 메모리를 확보했을때 얻는 최대비용

//N개의 어플이 실행되는 가운데 M 이상의 메모리를 확보하고자 한다
//이때, i번째 어플은 memo[i]의 메모리를 가지고 있고 어플을 키거나 끌때의 비용이 candi[i]이다
//그렇다면 최소한의 비용으로 M 이상의 메모리를 확보하는법을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> memo[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> candi[i];
	}

	int answer = 100000001;
	total[0][candi[0]] = memo[0];

	for (int i = 1;i < N;i++) {
		for (int j = 0;j <= 10000;j++) {	
			//각각의 어플들에 대해 i번째 어플을 비활성화 시킬때와 활성화 시킬때의 상태를 비교하여
			//max값을 total[i][j]에 저장한다
			if (j - candi[i] >= 0) {
				total[i][j] = max(total[i][j], total[i - 1][j - candi[i]] + memo[i]);
			}	
			total[i][j] = max(total[i][j], total[i - 1][j]);

			//M 이상의 메모리를 확보한 상황인경우
			//현재 상태까지 소모한 비용값과 answer 사이의 min값을 answer에 저장한다
			if (total[i][j] >= M) {
				answer = min(answer, j);
			}
		}
	}

	cout << answer << '\n';

	return 0;
}