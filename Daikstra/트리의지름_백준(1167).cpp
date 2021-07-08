#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N, idx;
int maxi = -1;
long long int answer = 0;
vector<pair<int, int>> roads[100001];
bool checked[100001];
int total_dist[100001] = {};

//어떠한 트리에 여러 노드들이 있고 그 사이에 간격들이 주어진다 가정하자
//임의의 두 노드 사이의 거리값들 중 나올 수 있는 최대 거리를 구하여라


//dfs함수가 진행되는부분
//현재 노드를 기준으로 다른 노드로 향할 수 있는 곳이 있으며, 거리 check가 된 곳이 아니라면
//dfs함수를 맨 처음 시작했을때 지정한 시작점에서부터 다음 노드까지의 거리를 저장해주고 checked를 true로 진행한 후 dfs를 진행해준다
//dfs함수를 진행 한 다음 만약 최대깊이까지 들어온 경우라면 함수를 종료하면서 위에서부터 다시 checked를 false로 돌려준다
void dfs(int s, int cost) {
	for (int i = 0;i < roads[s].size();i++) {
		int next = roads[s][i].first;
		int nextcost = roads[s][i].second;
		if (checked[next] == false) {
			cost += nextcost;
			total_dist[next] = cost;
			checked[next] = true;
			dfs(next, cost);
			checked[next] = false;
			cost -= nextcost;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int start;
		cin >> start;
		while (1) {
			int dest, len;
			cin >> dest;
			if (dest == -1) {
				break;
			}
			else {
				cin >> len;
				roads[start].push_back({ dest,len });
			}
		}
	}


	//우선적으로 임의 노드에서부터 가장 거리가 먼 노드를 구한다
	//임의 노드로부터 가장 거리가 먼 곳은 다른 노드들 사이에 구한 임의의 거리들도 가장 멀 것이기 때문이다
	//그래서 임의 노드를 1로 지정한 다음 가장 먼 노드를 구한다
	checked[1] = true;
	total_dist[1] = 0;
	dfs(1, total_dist[1]);

	for (int i = 1;i <= N;i++) {
		if (total_dist[i] >= maxi) {
			maxi = total_dist[i];
			idx = i;
		}
	}

	for (int i = 1;i <= N;i++) {
		checked[i] = false;
		total_dist[i] = 0;
	}

	//가장 먼 노드를 idx에 저장한 다음, 해당 노드를 기준으로 dfs를 다시 돌려준다
	maxi = -1;
	checked[idx] = true;
	dfs(idx, total_dist[idx]);

	for (int i = 1;i <= N;i++) {
		if (total_dist[i] >= maxi) {
			maxi = total_dist[i];
		}
	}
	answer = maxi;
	cout << answer << '\n';
	return 0;

}