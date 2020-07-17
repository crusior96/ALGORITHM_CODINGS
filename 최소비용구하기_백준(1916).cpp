#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> P;

//N개의 버스정류장과 G개의 버스노선이 있다고 가정하자
//각각의 버스노선에는 버스가 움직이는데 필요한 비용이 존재한다
//start번째 버스정류장에서 end번째 버스정류장에 도착하기까지 소모하는 최소비용을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, G, start, end;
	vector<P> adj[1001];		//특정 출발지점으로부터 도착할 수 있는 해당도착지점 및 그 거리를 저장해둔다
	priority_queue<P, vector<P>, greater<P>> PQ;
	bool visited[1001] = { 0 };	//방문여부 체크
	int distance[1001];			//특정 출발지점으로부터 각각의 버스정류장에 도착하까지의 최단거리 저장
	fill(distance, distance + 1001, 100000000);

	cin >> N;
	cin >> G;
	
	for (int i = 0;i < G;i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s - 1].push_back(P(e - 1, w));
	}
	cin >> start >> end;
	start--;
	end--;
	distance[start] = 0;


	PQ.push(P(0, start));
	//다익스트라 알고리즘 시작
	while (!PQ.empty()) {
		int idx;
		do {
			idx = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[idx]);//PQ가 비거나 방문했던 idx면 do에 있는 과정 pass
		//방문할 정점이 없다면 종료
		if (visited[idx])
			break;

		visited[idx] = true;	//해당 idx번째 visited에 방문했음을 우선적으로 체크
								//해당 idx번째 버스정류장에서 도착할 수 있는 모든 간선에 대해 최단거리를 체크한다
		for (auto &p : adj[idx]) {
			int next = p.first;
			int dist = p.second;

			//새로운 최단거리를 발견한거라면 PQ값으로 새로이 갱신시켜준다
			if (distance[next] > distance[idx] + dist) {
				distance[next] = distance[idx] + dist;
				PQ.push(P(distance[next], next));
			}
		}
	}

	cout << distance[end] << '\n';
	return 0;
	
}