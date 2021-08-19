#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int M, N;
int answer = 1;
vector<int> ways[10002] = {};	//경로들에 대한 정보들을 입력
int starts[10002] = {};			//i번째 컴퓨터에서 최대한 해킹 가능한 컴퓨터 갯수	
int checker[10002] = {};		//방문 여부를 체크하는 배열
int max_now = -1;				//최대한 해킹할 수 있는 컴퓨터의 갯수
int last = -1;

//어떠한 컴퓨터 A가 B를 신뢰하는 경우, B를 해킹하면 A도 해킹되게 된다고 가정하자
//M개의 컴퓨터와 N개의 신뢰 경로를 제공받고, 컴퓨터는 각각 1번, 2번... M번이 있다고 가정하자
//어떠한 한 컴퓨터를 해킹했을 때 최대한으로 해킹할 수 있는 컴퓨터의 번호를 출력하라
//단, 최대한으로 해킹할 수 있는 컴퓨터들의 번호가 여러개라면, 모든 번호들을 오름차순으로 출력하라


//dfs를 실행해서 해킹할 수 있는 경로에 있는 다른 컴퓨터들로의 탐색을 진행한다
//처음엔 이 부분에서 많이 시간을 날렸는데, 사이클이 있는 경우를 체크하지 않아서 문제가 생겼다
void dfs(int now) {
	checker[now] = 1;
	answer++;
	for (int i = 0;i < ways[now].size();i++) {
		if (checker[ways[now][i]] == 0) {
			dfs(ways[now][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		int s, e;
		cin >> s >> e;
		ways[e].push_back(s);
	}
	//매 컴퓨터마다 해킹을 새로이 시작해서 최대한 해킹가능한 갯수를 구한다
	for (int i = 1;i <= M;i++) {
		memset(checker, 0, sizeof(checker));
		answer = 0;
		dfs(i);
		//최댓값은 매 회마다 갱신을 시도한다
		if (answer > max_now) {
			max_now = answer;
		}
		starts[i] = answer;
	}
	//max_now와 같은 컴퓨터 번호만을 출력한다
	for (int i = 1;i <= M;i++) {
		if (starts[i] == max_now) {
			cout << i << " ";
		}
	}
	cout << '\n';
	return 0;
}