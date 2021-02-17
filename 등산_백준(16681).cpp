#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, long long> P;
vector<P> adj[200001];				//인접 행렬끼리의 정보가 저장된다. 시작지점 & 도착지점 & 사이의 거리가 저장된다.
long long height[100001] = {};
long long Home_len[100001] = {};
long long Camp_len[100001] = {};
bool visited[100001] = { 0 };
long long sum[200001] = {};

int N, lane, D, E;
//각각 지도에 표시된 도착지점의 갯수, 지점을 잇는 경로의 갯수, 거리 비례 체력 소모량, 높이 비례 성취감 획득량을 의미한다

//등산을 하려하는데 시작점(1)에서 시작하여 도착지점(N)까지 이동하려한다
//등산을 할 수 있는 경로가 lane개 주어져있을 때 얻을 수 있는 최대 성취감을 출력하라
//조건에 맞춰서 성취감을 얻을 수 없다면 Impossible 출력

//문제에서 쓰인 다익스트라 알고리즘
//거리 비례 체력 소모량을 고려해서 문제풀이에 쓴다
void daik(int start, long long len[]) {
	memset(visited, 0, sizeof(visited));
	priority_queue<P, vector<P>, greater<P>> PQ;
	len[start] = 0;
	PQ.push(P(0, start));

	while (!PQ.empty()) {
		int now;
		now = PQ.top().second;
		PQ.pop();

		while (!PQ.empty() && visited[now]) {
			now = PQ.top().second;
			PQ.pop();
		}

		if (visited[now])
			break;

		visited[now] = true;

		for (auto& s : adj[now]) {
			int next = s.second;
			long long d = s.first;
			if (height[now] < height[next]) {
				if (len[now] + d * D < len[next]) {
					len[next] = len[now] + d * D;
					PQ.push(P(len[next], next));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long answer = -1000000000000;	

	cin >> N >> lane >> D >> E;
	for (int i = 1;i <= N;i++) {
		cin >> height[i];
		Home_len[i] = Camp_len[i] = 1000000000000;
	}



	for (int i = 0;i < lane;i++) {
		int s, e, len;
		cin >> s >> e >> len;
		adj[s].push_back(P(len, e));
		adj[e].push_back(P(len, s));
	}

	//다익스트라를 2번 진행한다. 각각 집에서 출발할 때와 도착지점에서 출발할 때로 진행한다
	//양방향으로 이동할 수 있는만큼 도착지점에서 출발지점으로 이동할 때도 찾으면 최단거리를 찾을 수도 있다
	daik(1, Home_len);
	daik(N, Camp_len);

	for (int i = 2;i < N;i++) {
		if (Home_len[i] == 1000000000000 || Camp_len[i] == 1000000000000) {
			continue;
		}
		else {
			sum[i] = height[i] * E - Camp_len[i] - Home_len[i];
			if (answer < sum[i]) {
				answer = sum[i];
			}
		}
	}

	if (answer == -1000000000000) {
		cout << "Impossible" << '\n';
	}
	else {
		cout << answer << '\n';
	}
	return 0;
}