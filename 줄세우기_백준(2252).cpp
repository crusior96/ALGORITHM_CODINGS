#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int indegree[32001];		//연계된 위상의 갯수 저장. indegree[i]의 값은 i와 연계된 위상의 갯수 의미
int lines[32001];			//줄서있는 학생들의 상태 저장. 맨 앞 1번서부터 저장함.
vector<int> adj[100001];	
queue<int> Q;

//N명의 학생들을 키 순서대로 줄을 세우려고한다
//이때, 두 학생들의 키에관한 관계가 M개 정도 나오게 되는데
//A B라는 관계는 A라는 학생이 B보다 앞에 서있어야 한다는 뜻이다
//왼쪽에서 오른쪽순으로 앞에 서있는것임을 의미한다면 줄섰을때 사람들의 배치상태를 출력하라

int main() {
	//위상정렬을 처음 사용해 본 문제
	//현재 정점의 위상값이 작은것부터 큰것 순서대로 정렬하는 방식이다
	int M, N;
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		int s, e;
		cin >> s >> e;
		indegree[e]++;
		adj[s].push_back(e);
	}



	//위상의 값이 0인 정점부터 Q에 저장한다
	for (int i = 1;i <= M;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 1;i <= M;i++) {
		//Q가 비는순간 정렬은 정지된다. 정렬 자체가 불가능함 의미
		if (Q.empty()) {
			break;
		}

		//위상 값이 0인것부터 lines 행렬에 저장해둔다.
		int now = Q.front();
		Q.pop();
		lines[i] = now;

		//위상값이 0이었던 정점돠 연계된 곳을 기준으로 다른 정점에 대해서도 탐색을 한다
		//모든 정점들의 위상값을 1 감소시키고 이때 위상값이 0이된 정점의 값을 Q에 저장한다
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