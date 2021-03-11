#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
long long indegree[32000] = {};
long long needed[1001][1001] = {};				//needed[i][j] : i 부품을 만드는데 필요한 j 부품의 갯수가 저장된다
vector<vector<pair<long long, long long>>> adj;	//adj.first, second : 각각 필요한 부품의 종류 및 그 갯수를 의미한다

//N개의 부품이 있고 M개의 관계가 있다고 가정하자
//각각의 부품들은 1, 2 ... N의 번호를 부여받게 되며
//각각의 관계들은 s, e, num으로 표현되며 이는 부품 s를 만드는데 쓰이는 부품 e가 num개 소모된다는 뜻이다
//이때 A를 만드는데 B가 필요하면 A는 '중간부품'이라 칭하고, A를 만드는데 뭐가 필요하지 않다면 A는 '기본부품'이라 칭한다
//그렇다면 부품 N을 만드는데 쓰이는 기본 부품들의 갯수를 최소 단위로 나열하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	cin >> M;
	adj.resize(N + 1);
	for (int i = 0;i < M;i++) {
		long long s, e, num;
		cin >> s >> e >> num;
		indegree[s]++;
		pair<long long, long long> tmp_pair = make_pair(s, num);
		adj[e].push_back(tmp_pair);	//e를 num개 사용해서 s를 만든다는 뜻
	}

	//우선 기본부품부터 Q에 입력한다
	queue<int> Q;
	for (int i = 1;i <= N;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
			needed[i][i] = 1;
		}
	}

	//기본적인 다익스트라가 진행되는 방식이긴 한데
	//해당 부품이 필요로 하는 다른 부품의 기본 부품 구성품들을 지속적으로 합해주는 작업이 필요하다

	while (!Q.empty()) {
		long long idx = Q.front();
		Q.pop();
		for (auto p : adj[idx]) {
			//부품 idx를 필요로 하는 다른 부품들에게 필요 부품 재료 갯수들을 계속 합해주기 위한 작업
			//p.first는 부품 idx를 필요로하는 다른 부품의 번호, p.second는 부품 idx를 몇개 필요로 하는지 알려준다
			for (int i = 1;i <= N;i++) {
				needed[p.first][i] += needed[idx][i] * p.second;
			}
			indegree[p.first]--;

			if (indegree[p.first] == 0) {
				Q.push(p.first);
			}
		}
	}

	//최종적으로 부품 N을 이루는데 기본부품 i가 얼마큼 있는지 출력하는 작업이다
	for (int i = 1;i <= N;i++) {
		if (needed[N][i]) {
			cout << i << " " << needed[N][i] << '\n';
		}
	}
	return 0;
}