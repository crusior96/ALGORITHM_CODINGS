#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int indegree[32001];		//i번째 문제집을 풀기위한 우선순위의 갯수가 저장되는 곳
int lines[32001];			//풀어야 할 문제집들의 번호 순서가 저장되는 곳
vector<int> adj[100001];	//인접 행렬
priority_queue<int, vector<int>, greater<int>> Q;

//1번부터 M개까지의 문제들을 풀어야 한다고 가정하자
//이때, N개의 정보들이 주어지는데 이는 a를 먼저 풀어야 b를 풀기 쉽다는 정보이다
//가능하면 쉬운 문제부터 풀어야 할 경우, 1번부터 M번까지의 문제를 효율적으로 풀기 위한 순서를 출력하라

int main() {
	int M, N;
	cin >> M >> N;
	//해당 문제에선 위상정렬을 사용하기로 했다.
	//우선순위 조건이 없는 것들부터 Q에 push해주고
	//push된 값들중 해당 값을 우선순위로 가진 것들 중에 해당 값이 유일한 우선순위라면 Q에 push해준다
	//이런식으로 우선순위가 없어서 이젠 실행할 수 있는 것들을 실행하고 그것을 문제해결 순서로 지정하는것이 위상정렬이다
	for (int i = 0;i < N;i++) {
		int s, e;
		cin >> s >> e;
		indegree[e]++;
		adj[s].push_back(e);
	}

	for (int i = 1;i <= M;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 1;i <= M;i++) {
		if (Q.empty()) {
			break;
		}

		int now = Q.top();
		Q.pop();
		lines[i] = now;

		for (int next : adj[now]) {
			if (--indegree[next] == 0) {
				Q.push(next);
			}
		}

	}

	for (int i = 1;i <= M;i++) {
		cout << lines[i] << " ";
	}
	return 0;
}