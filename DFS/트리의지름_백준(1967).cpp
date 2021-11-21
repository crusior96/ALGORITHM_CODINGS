#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N, idx;
int maxi = -1;
long long int answer = 0;
//roads[i] : i에서 roads[i].first까지 도착하는 데 roads[i].second만큼의 거리가 벌어져 있다는 뜻이다
vector<pair<int, int>> roads[10002];
//checked[i] : i에선 dfs탐색이 이미 완료됐다는 뜻
bool checked[10002];
//total_dist[i] : 위치 i까지의 거리
int total_dist[10002] = {};

//트리 자료구조에서 트리의 지름이란, 임의의 두 점 사이의 거리 중 가장 긴 것을 뜻한다고 할 때
//N개의 정점이 주어지고 해당 정점과 이어진 다른 정점에 대한 정보가 주어지게 된다
//맨 처음엔 정점의 번호, 그 다음 연속되는 2개 쌍의 정수는 현재 정점과 이어진 정점의 위치 그리고 그 거리가 주어진다
//마지막 정보의 입력이라면 -1이 입력되고 종료된다
//이러한 정보들을 토대로 트리의 지름을 구하여라


//DFS탐색이 진행되는 부분
//매개변수로 탐색이 진행되는 현재 정점의 좌표와 현재 정점까지 도달하는 데 걸린 cost를 받는다
void dfs(int s, int cost) {
	for (int i = 0;i < roads[s].size();i++) {
		//현재 노정점에서 다음 정점에 도착할 수 있다면
		//해당 위치의 좌표 및 거리를 받는다
		int next = roads[s][i].first;
		int nextcost = roads[s][i].second;

		//해당 위치가 탐색이 진행되지 않은 곳이라면
		//해당 위치에서 위 매개변수들을 갱신하고 이어받아 또 DFS를 진행한다
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
	for (int i = 1;i < N;i++) {
		int start, dest, len;
		cin >> start >> dest >> len;
		roads[start].push_back({ dest,len });
		roads[dest].push_back({ start,len });
	}

	checked[1] = true;
	total_dist[1] = 0;
	//임의의 점에서 DFS 탐색을 진행한다
	//checked배열과 total_dist에 기본적인 값을 저장해둔다
	dfs(1, total_dist[1]);

	//현재 정점 1에서부터 가장 먼 곳에 배치된 정점을 찾아내고 그곳까지의 거리를 알아낸다
	for (int i = 1;i <= N;i++) {
		if (total_dist[i] >= maxi) {
			maxi = total_dist[i];
			idx = i;
		}
	}
	
	//이후 값들을 모두 초기화시킨다음 DFS를 한번 더 진행한다
	for (int i = 1;i <= N;i++) {
		checked[i] = false;
		total_dist[i] = 0;
	}

	//이때 DFS가 진행되는 정점은 위에서 찾은 '정점 1에서부터 가장 먼 정점'이 된다
	//즉, 임의의 위치에서 가장 먼 곳을 먼저 찾고, 그 다음 해당 위치에서 가장 먼 곳을 찾게되면
	//둘 사이의 거리가 가장 먼 거리라는 것을 알 수 있게 된다
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