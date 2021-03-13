#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;

int K, M, P;	//각각 Tc번호(중요하지 않다), 노드의 수, 간선의 수를 의미한다.


//K개의 테스트케이스와 M개의 노드, P개의 간선들이 있다고 가정하자.
//노드 A에서 B로 향할 때 Strahler 값을 적용하게 되는데
//들어오는 것 없이 향하기만 하는 노드에서의 Strahler 값은 1로 지정되며
//다른 노드들의 경우, 인접 노드값이 i인 것이 1개면 i, 2개 이상이면 i+1로 지정되고 해당값은 최댓값으로 저장한다.
//이렇게해서 추출할 수 있는 최대 Strahler값을 출력하라.
//단, 최종적으로 모이게 되는 정점 및 노드는 1개로 고정된다.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int indegree[1002] = {};		//정점에 대한 정보가 저장되는 배열
		int lines[1002] = {};			//간선에 대한 정보가 저장되는 배열
		pair<int, int> p[1002];			//p[i]<first, second> : 정점 i에서의 Strahler값은 현재 first이며, 해당 값은 second만큼 부여받았었다
		vector<int> adj[1002] = {};		//인근 정점과의 연결관계를 저장한 벡터
		queue<int> Q;					//위상 정렬에 사용될 큐
		int answer = 0;
		cin >> K >> M >> P;
		for (int j = 0;j < P;j++) {
			int s, e;
			cin >> s >> e;
			indegree[e]++;
			adj[s].push_back(e);
		}

		for (int j = 1;j <= M;j++) {
			if (indegree[j] == 0) {
				p[j] = pair<int, int>(1, 1);	//들어오는 간선 없는 곳은 최초의 Strahler로 1을 저장한다.
				Q.push(j);
			}
		}

		//위상정렬 + 문제의 특수룰을 적용해야 해서 좀 복잡한 구성이지만
		//pair를 잘 익히고 있다면 크게 문제없다.
		for (int j = 1;j <= M;j++) {
			if (Q.empty())
			{
				break;
			}

			int now = Q.front();
			Q.pop();
			lines[j] = now;
			for (int next : adj[now]) {
				//현재 정점의 p.first값이 이어지는 정점의 p.first값보다 크다면 갱신
				if (p[next].first < p[now].first) {
					p[next] = pair<int, int>(p[now].first, 1);
				}
				//그렇지 않고 서로 같은 값이라면 이어지는 정점의 p.second값++
				else if (p[next].first == p[now].first) {
					p[next].second++;
				}

				//해당정점이 더 이상 받아들이는 정점이 없을 때
				//p.second 값이 2 이상이면 p.first값을 1 증가시킨 채로 저장한다.
				if (--indegree[next] == 0) {
					if (p[next].second > 1) {
						p[next] = pair<int, int>(p[next].first + 1, 1);
					}
					Q.push(next);
				}
			}
		}

		for (int j = 1;j <= M;j++) {
			if (answer < p[j].first) {
				answer = p[j].first;
			}
		}

		cout << K << " " << answer << '\n';
	}
	return 0;
}
