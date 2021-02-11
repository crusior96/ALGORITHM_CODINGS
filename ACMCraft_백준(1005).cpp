#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int M, N, W;

//어떤 한 게임에 N개의 건물이 있고, 각각의 건물이 지어지기 위한 선행 건물 규칙이 M개 있다고 가정하자
//각각의 건물들에는 건설을 위해 필요한 고유 시간이 주어진다
//이때, 건물번호 W를 가진 건물을 건설하면 이긴다고 가정할 때, 각각의 테스트케이스마다 승리를 위한 최소 건물건설 시간을 출력하라

int main() {
	int Tc;
	cin >> Tc;
	//위상 정렬을 이용하여 문제를 풀어나갈 예정이다.
	for (int i = 0;i < Tc;i++) {
		queue<int> Q;						//위상정렬에 사용하게 될 자료구조 큐. 우선 조건이 없는 건물들부터 들어가게 된다.
		int building[1001] = {};			//각각의 건물만을 짓는데 필요한 시간
		int building_total[1001] = {};		//해당 건물을 짓는데 필요한 총 시간. 건물을 짓는데 필요한 조건들 다 포함된다.
		int indegree[1001] = {};			//각각의 건물들이 지어지귀 위해 필요한 건물들의 갯수
		vector<int> adj[1001];				//건물간에 건설규칙이 있음을 보이는 인접행렬. 조건은 한 건물에 여러 개가 적용될수도 있다.
		cin >> N >> M;
		for (int j = 1;j <= N;j++) {
			cin >> building[j];
		}
		for (int j = 0;j < M;j++) {
			int s, e;
			cin >> s >> e;
			indegree[e]++;
			adj[s].push_back(e);
		}
		cin >> W;

		for (int j = 1;j <= N;j++) {
			if (indegree[j] == 0) {
				Q.push(j);
			}
		}

		//우선 조건이 없는 건물들 혹은 우선 조건을 다 따진 건물들부터 위상정렬 작업을 진행한다
		while (indegree[W] != 0) {
			for (int j = 1;j <= N;j++) {
				int now = Q.front();
				Q.pop();
				
				//건물들은 동시에 건설될 수 있다. 가령 4번 건물 짓는데 2번과 3번이 필요하면, 2번과 3번을 동시에 지을수도 있는 것
				//그렇기 때문에 다음 건물을 짓는 데 필요한 총 시간을 max를 사용해서
				//현재의 건물을 짓는데 필요한 조건을 위한 모든 시간 + 현재의 건물을 짓는 시간 vs 다음 건물을 짓는데 필요한 조건을 위한 모든시간
				//둘 중 제일 큰 값을 building_total[next]에 저장한다
				for (int next : adj[now]) {
					building_total[next] = max(building[now] + building_total[now], building_total[next]);
					if (--indegree[next] == 0) {
						Q.push(next);
					}
				}
				
			}
		}

		cout << building_total[W] + building[W] << '\n';

	}

	return 0;
}