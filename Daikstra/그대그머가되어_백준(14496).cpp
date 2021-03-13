#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int, int>> arr[10002] = {};
int dist[10002];

//어떠한 문자 A와 B가 주어진다고 가정하자
//A를 B로 변환시키려고 하는데 바로 변환은 안되고, 주어진 E개의 변환 방식을 따라서 변환하는 방법으로 해야한다
//모든 변환방식은 양방향으로 진행할 수 있다
//이때 최소한의 변환 횟수로 A를 B로 바꾸자


//이 문제를 한참 헤맸던 이유 : 시작점과 끝점 두 군데에서 다익스트라를 진행했는데
//							 무슨 이유에서인지 답안이 제대로 안 나왔다
//							 결국 한 방향에서 다익스트라를 진행했는데 거기선 제대로 나와서 신기하다
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int V, E, start, ending; //V는 노드, E는 엣지입니다.
	bool checked = false;
	cin >> start >> ending;
	cin >> V >> E;

	for (int i = 0;i < E;i++)
	{
		int from, to; // from은 출발점, to는 도착점, val은 그 사이에 음수가 아닌 거리비용입니다.
		cin >> from >> to;
		arr[from].push_back({ to,1 });
		arr[to].push_back({ from,1 });
	}

	fill(dist, dist + V + 1, 10005);
	priority_queue<pair<int, int>> que;
	que.push({ 0,start });
	dist[start] = 0;
	//우선순위 큐(여기선 que)의 모든 값을 0으로 초기화시키고, 시작점에서의 최단거리값을 0으로 지정한다.
	//다익스트라가 진행되는 곳
	while (!que.empty())
	{
		int cost = -que.top().first; //다음 방문할 점의 dist값
		int here = que.top().second; //here를 방문할 점의 번호값

		que.pop();

		for (int i = 0;i < arr[here].size();i++)
		{
			int next = arr[here][i].first;
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				que.push({ -dist[next],next });
			}

		}

	}



	if (start == ending) {
		cout << 0 << '\n';
	}
	else {
		if (dist[ending] == 10005) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[ending] << '\n';
		}
	}

	return 0;
}
