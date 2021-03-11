#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> adj[1001];
int indegree[1001];
int onstage[1001];
queue<int> Q;


//1번부터 M번까지의 가수들이 있다고 가정하자
//N명의 PD들이 각각 지정한 num만큼의 가수들의 공연계획을 가지고 있다고 가정할 때
//PD들의 공연계획들을 모두 만족하는 공연순서들 중 아무거나 제시하라

//추가사항 : 상단에 있는 queue를 사용하지 않고 최소 힙을 사용하게 된다면
//			1차적으로 조건에 맞게 공연순서들을 나열하고 2차적으로 공연순서랑 무관한 부분에 관해 내림차순 정렬한다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N;
	cin >> M >> N;

	//문제 내에서 조건이 제시될 때 연결된 관계가 A - B 형식으로 2개만 나오는 것이 아니라
	//A - B - C와 같이 일렬로 나열되는 형식이기때문에 위와같이 표기한다
	//간혹가다 num이 1만 나오는 경우가 있는데 이때에는 adj나 indegree에 데이터 입력이 안되기 때문에 상관없다
	//이렇게 정렬한 값을 토대로 위상 정렬을 진행한다
	for (int i = 0;i < N;i++) {
		int num, s, e;
		cin >> num;
		cin >> s;
		for (int j = 1;j < num;j++) {
			cin >> e;
			indegree[e]++;
			adj[s].push_back(e);
			s = e;
		}	
	}


	for (int i = 1;i <= M;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 1;i <= M;i++) {
		if (Q.empty()) {
			cout << 0 << '\n';
			return 0;
		}

		int now = Q.front();
		Q.pop();
		onstage[i] = now;

		for (int next : adj[now]) {
			if (--indegree[next] == 0) {
				Q.push(next);
			}
		}
	}

	for (int i = 1;i <= M;i++) {
		cout << onstage[i] << '\n';
	}


	return 0;
}