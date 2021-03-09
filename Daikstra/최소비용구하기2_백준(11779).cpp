#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int INF = 9876543231;
vector<pair<int, int>> arr[10005];			
vector<int>way_to_end;						//
int dist[10005] = {};		
int M, N, start, ender;

//M개의 도시와 N개의 버스 경로가 있다고 가정하자
//각각의 버스 경로들에는 출발점과 도착점, 그리고 해당 지점 사이를 이동하는데 드는 비용이 입력된다
//이때 출발 지점과 도착지점이 주어진다면 해당 경로까지 이동하는 데 드는 최소 비용과
//해당 경로까지 이동하는 데 방문하는 도시의 갯수 및 그 경로를 출력하라



//일반적인 다익스트라를 사용하면 되긴 하는데
//이동하는 경로를 알아둬야 하기 때문에 다음 경로로의 비용 결과값이 갱신 될 만한 상황이면 way_to_end에 저장한다
//way_to_end[i] = j -> i 도시에 방문하기 바로 전에 j 도시에서 출발했다는 뜻
int daik() {
	priority_queue<pair<int, int>> que;
	fill(dist, dist + M + 1, 9876543231);
	dist[start] = 0;
	que.push({ 0,start });

	while (!que.empty())
	{
		int cost = -que.top().first; 
		int here = que.top().second; 

		que.pop();

		if (cost > dist[here]) {
			continue;
		}
		for (int i = 0;i < arr[here].size();i++)
		{
			int next = arr[here][i].first;
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				way_to_end[next] = here;
				dist[next] = dist[here] + nextcost;
				que.push({ -dist[next],next });
			}

		}

	}
	return dist[ender];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		arr[s].push_back({ e,cost });
	}

	cin >> start >> ender;
	way_to_end.resize(M + 2, -1);
	way_to_end[start] = start;	//도로 경로 탐사전에 시작 하는 도시의 way_to_end 값은 동일하게 시작하는 도시로 저장해둔다
	int basics = daik();	//최초 다익스트라 실행 시 나오는 최단거리
	
	int cnt = 0;
	int roads[1005] = {};	//최소 비용으로 이동했을 때의 도시 번호들이 경로 순서에 따라 저장되는곳

	//도로 경로를 roads에 저장한다. way_to_end에는 도착한 도시 -> 해당 도시 이전 방문도시 -> ... -> 출발한 도시의 번호가 저장된다
	//링크드 리스트같이 저장된 상황이기때문에 링크된 순서에 맞춰서 도시의 번호들을 뽑아낸다
	for (int idx = ender;idx != way_to_end[idx];idx = way_to_end[idx]) {
		roads[cnt] = idx;
		cnt++;
	}
	roads[cnt] = start;
	cnt++;

	cout << basics << '\n';
	cout << cnt << '\n';
	for (int i = cnt - 1;i >= 0;i--) {
		cout << roads[i] << " ";
	}
	return 0;
}