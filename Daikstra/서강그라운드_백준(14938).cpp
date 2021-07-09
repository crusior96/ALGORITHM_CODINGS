#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//N개의 낙하지점과 R개의 이동루트가 있다고 가정하자
//각각의 낙하지점에는 특정 갯수의 아이템들이 존재한다
//주인공은 M의 색적 거리능력을 가지고 있으며, 색적 거리 안에 있는 아이템들을 얻을 수 있다
//이때, 주인공이 N개의 낙하지점 중 한 곳에 도착해서 얻을 수 있는 최대 아이템 갯수를 구하여라

struct node {
	int end;
	int val;
};

int N, M, R;
int items[101] = {};
int total_item = 0;
vector<node>adj[100001];
int dist[102] = {};



//우선순위큐를 사용하는 방식의 다익스트라 사용
void daik(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int now_node = pq.top().second;

		int cost = -1 * pq.top().first;
		pq.pop();

		for (int i = 0;i < adj[now_node].size();i++) {
			int new_val = dist[now_node] + adj[now_node][i].val;
			int before_val = dist[adj[now_node][i].end];

			if (new_val < before_val) {
				dist[adj[now_node][i].end] = new_val;
				pq.push({ -1 * new_val,adj[now_node][i].end });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 0;i < N;i++) {
		cin >> items[i];
	}
	//간선이 양방향임에 유의
	for (int i = 0;i < R;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		adj[s - 1].push_back(node{ e - 1,cost });
		adj[e - 1].push_back(node{ s - 1,cost });
	}
	//어느 지점에서 내렸을 때 얻을 수 있는
	//아이템의 갯수가 최대인지 알기 위해 모든 곳에서 다익스트라 함수를 진행한다
	//다익스트라 함수의 결과값으로 얻는 dist배열 내의 값들을 색적거리 M과 비교해서
	//회수 가능한 아이템인지 판단한다
	//M 이하의 거리들이라면 회수 가능한 아이템이 된다
	for (int i = 0;i < N;i++) {
		int tmp_item = 0;
		for (int j = 0;j < N;j++) {
			dist[j] = 100000001;
		}
		dist[i] = 0;
		daik(i);
		for (int j = 0;j < N;j++) {
			if (dist[j] <= M) {
				tmp_item += items[j];
			}
		}
		if (tmp_item >= total_item) {
			total_item = tmp_item;
		}
	}
	cout << total_item << '\n';
	return 0;
}