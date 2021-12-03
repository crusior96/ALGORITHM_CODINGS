#include<iostream>
#include<algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int maps[501][501] = {};	//각 좌표에 존재하는 대나무들의 갯수
int curr[501][501] = {};	//각 좌표에서 dfs를 진행했을 때 탐색할 수 있는 최대 거리

int N;
int answer = 0;

//어떤 팬더가 maps위에 있는 대나무들을 먹는다 가정하자
//대나무를 먹는 규칙은 현 위치보다 더 많은 대나무가 있는 곳이 있다면
//그 쪽으로 나아가면서 존재하는 대나무를 모두 먹는 것이다
//이때 maps에 있는 대나무의 정보들을 토대로 최대 몇 번 이동할 수 있는지 구하여라


//dfs + dp가 사용된 함수
//단순이 dfs만 사용하게 된다면 중복되는 경로를 탐색하게 돼서 타임아웃이 난다
//또한 특정 위치에서 도달할 수 있는 최대 거리는 이미 정해져있기 때문에
//만약 이미 dfs 탐색이 완료 된 위치라면 해당 위치에 있는 curr값을 return해주는 방식으로 진행한다
int dfs(int x, int y) {
	int idx;
	int idy;
	
	//dfs 탐색이 완료된 곳이라면 curr[x][y] return
	if (curr[x][y] != 0) {
		return curr[x][y];
	}

	//처음 dfs탐색을 하는 곳이라면 해당 위치를 1로 지정한다
	curr[x][y] = 1;
	
	//상하좌우 이동 시, maps의 범위 안에 있고 대나무가 상대적으로 더 많은 곳에 도착한 것이라면
	//curr[x][y]의 값은 현재 위치의 값과 dfs를 진행하는 새로운 위치의 값 + 1 중 최댓값으로 지정된다
	//이를 통해 위에 curr[x][y] = 1인 이유를 알 수 있다. 일단 탐색되는 신규지역은 자기자신 기준으로 1은 확보하기 때문.
	for (int i = 0;i < 4;i++) {
		idx = x + dx[i];
		idy = y + dy[i];
		if (idx >= 0 && idy >= 0 && idx < N && idy < N) {
			if (maps[x][y] < maps[idx][idy]) {
				curr[x][y] = max(curr[x][y], dfs(idx, idy) + 1);
			}
		}
	}

	return curr[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> maps[i][j];
		}
	}

	//매 위치마다 dfs를 작동시켜 본다
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			answer = max(answer, dfs(i, j));
		}
	}

	cout << answer << '\n';

	return 0;
}