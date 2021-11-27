#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int M, N;

//M개의 정점과 N개의 간선이 있다고 가정하자
//N개의 간선은 시작점과 도착점, 비용으로 이루어져있고 양방향 통행이 가능하다
//1번 정점에서 출발하여 N번 정점으로 도착한다고 가정할 때
//최단 비용으로 도착할 때의 비용을 구하여라


//간선으로 사용할 때 입력되는 값들에 대한 정의
struct node {
	int end;
	int val;
};

vector<node>way_length[50002];	//way_length[i] : i번 정점과 연결된 다른 간선들에 대한 정보가 포함돼있다
int dist[50002] = {};			//dist[i] : i까지 도착하는 데 필요한 최소비용. 조건에 따라 갱신된다.

//다익스트라가 진행되는 함수
void daik() {
	//우선순위 큐 지정 및 처음 시작하는 곳의 좌표값인 1과 현재까지 소모된 비용인 0을 입력해둔다
	priority_queue<pair<int, int>>pq;
	pq.push({ 0, 1 });

	//pq가 빌 때까지 작업을 진행한다
	while (!pq.empty()) {
		//top위치에 있던 node와 관련해서 도착 지점과 도착 비용을 얻어낸 후 pop한다
		int now_node = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		//이후 도착 지점까지 가는데 소모되는 현 시점의 최소비용과
		//이번 경로를 추가해서 만들어지는 새로운 비용을 비교한다
		//이후 현 시점의 최소비용이 더 작다면, 해당 위치의 val을 현 시점의 최소비용으로 대체하고
		//해당 이동 간선을 pq에 다시 추가한다
		for (int i = 0;i < way_length[now_node].size();i++) {
			int new_val = dist[now_node] + way_length[now_node][i].val;
			int before_val = dist[way_length[now_node][i].end];

			if (new_val < before_val) {
				dist[way_length[now_node][i].end] = new_val;
				pq.push({ -1 * new_val, way_length[now_node][i].end });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool done = true;


	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		node tmp_node, tmp_node2;
		tmp_node.end = e;
		tmp_node.val = cost;
		tmp_node2.end = s;
		tmp_node2.val = cost;
		//방향이 양방향인만큼 2번의 간선 추가를 진행하며
		//목적지를 서로 바꿔가면서 진행하면 된다
		way_length[s].push_back(tmp_node);
		way_length[e].push_back(tmp_node2);
	}


	//초기값을 지정하여 이후 최솟값으로 대체해준다
	for (int i = 1;i <= M;i++) {
		dist[i] = 1000000000;
	}

	dist[1] = 0;
	daik();


	cout << dist[M] << '\n';


	return 0;
}