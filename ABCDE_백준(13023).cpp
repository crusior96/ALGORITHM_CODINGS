#include<iostream>
#include<vector>
using namespace std;
vector<int> friends[2002];
int possible = 0;

//A와 B가 알고, B와 C가 알고, C와 D가 알고, D와 E가 아는 상황을 찾고자 한다
//N명의 사람과 M명의 인물관계가 주어지게 될 경우
//해당 관계가 있다면 1, 아니면 0을 출력하라


//dfs가 진행되는 함수. 각 사람별로 관계가 있는 사람들을 찾아 진행한다
//변수는 각각 관계가 시작되는 번호, 현재 관계 탐색중인 번호, 누적된 관계 수, 관계 체크 여부가 저장된 배열이다
//tmp : 현재까지 연계된 관계의 수를 의미한다. 4번 관계가 되면 작업을 중단하고 1을 출력하게 한다
void dfs(int start_idx, int now_idx, int stacks, int check[]) {
	for (int i = 0;i < friends[now_idx].size();i++) {
		if (check[friends[now_idx][i]] == 0) {
			check[friends[now_idx][i]] = 1;
			int tmp = stacks + 1;
			if (tmp == 4) {
				possible = 1;
				break;
			}
			dfs(start_idx, friends[now_idx][i], tmp, check);
			//dfs진행 이후 check[friends[now_idx][i]]를 0으로 만들어야 start_idx에서의 탐색을 할 때
			//이미 start_idx에서 다른 루트로 진행되는 탐색으로 끼어들어 중복탐색을 하게 되는 경우를 막을 수 있다
			check[friends[now_idx][i]] = 0;
			if (possible == 1) {
				return;
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		friends[s].push_back(e);
		friends[e].push_back(s);
	}

	int idx = 0;
	while (possible == 0) {
		int checker[2002] = {};
		if (possible == 1) {
			break;
		}

		if (friends[idx].size() != 0) {
			checker[idx] = 1;
			dfs(idx, idx, 0, checker);
		}

		idx++;
		if (idx == N) {
			break;
		}
	}

	cout << possible << '\n';
	return 0;
}
