#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int INF = 9876543231;
vector<pair<int, int>> arr[10005];		//도시 사이의 도로에 대한 정보
vector<int>way_to_end;					//최초 다익스트라 실행 시 얻는 최단 경로에 대한 정보
int dist[10005] = {};
int city_blocked1 = 0;
int city_blocked2 = 0;
bool first_trial = true;				//최초 다익스트라 실행 여부
int M, N;

//M개의 도시와 그 사이들을 연결하는 도로에 대한 N개의 정보가 있다고 가정하자
//1번 도시에서 M번 도시로 도착하는 최단 시간을 basics라고 할 때
//특정 한 도로를 차단했을 때 basics로부터 얼마나 시간을 지연시킬 수 있을지에 대해 알아보고자 한다
//이때, 차단했을 때 아예 M번 도시로 도착할 수 없는 상황이라면 -1을 출력한다
//최대한 지연시킬 수 있는 시간을 출력하라

//입력받은 도로의 시작점과 끝점이 이번에 막고자 하는 도로의 시작점과 끝점이랑 같은지 체크하는 함수
//각각의 최단 경로들을 한번 씩 막으면서 다익스트라를 돌리고자 하는 의도로 만들어졌다
bool breakup(int s, int e) {
	if (city_blocked1 == s && city_blocked2 == e) {
		return true;
	}
	else if (city_blocked1 == e && city_blocked2 == s) {
		return true;
	}
	return false;
}

//흔한 다익스트라 함수이지만 최초 경로를 저장하거나 breakup함수가 진행되면서
//환경을 문제조건에 맞춰간다
int daik() {
	priority_queue<pair<int, int>> que;
	fill(dist, dist + M + 1, 9876543231);
	dist[1] = 0;
	que.push({ 0,1 });

	while (!que.empty())
	{
		int cost = -que.top().first; //다음 방문할 점의 dist값
		int here = que.top().second; //here를 방문할 점의 번호값

		que.pop();

		if (cost > dist[here]) {
			continue;
		}
		for (int i = 0;i < arr[here].size();i++)
		{
			int next = arr[here][i].first;
			if (breakup(here, next)) {
				continue;
			}
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				if (first_trial == true) {
					way_to_end[next] = here;
				}
				dist[next] = dist[here] + nextcost;
				que.push({ -dist[next],next });
			}

		}

	}
	return dist[M];
}

int main() {
	cin >> M >> N;
	way_to_end.resize(M + 1, -1);
	way_to_end[1] = 1;
	for (int i = 0;i < N;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		arr[s].push_back({ e,cost });
		arr[e].push_back({ s,cost });
	}
	int basics = daik();	//최초 다익스트라 실행 시 나오는 최단거리
	first_trial = false;	//최초 다익스트라를 실행했으므로 first_trial은 false로 돌린다

	int maxi = 0;	//최대 단축시간

	//way_to_end에서 목적지로 향하는 간선들의 정보를 하나씩 들고온다
	//들고 오는 순서는 최종적으로 목적지에 도착하는 간선이 우선이고, 최초로 출발하는 간선이 마지막이다
	for (int idx = M;idx != way_to_end[idx];idx = way_to_end[idx]) {
		city_blocked1 = idx;
		city_blocked2 = way_to_end[idx];
		maxi = max(maxi, daik());
		if (maxi == INF) {
			break;
		}
	}

	if (maxi == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << maxi - basics << '\n';
	}

	return 0;
}