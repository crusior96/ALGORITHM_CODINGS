#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int M, N, Tc;
bool check_bfs[100001];			//지정된 튜브 방향으로 이동할 경우, 1번 도시에서 출발했을 때 각각의 도시들에 도착할 수 있는지 저장한다
bool check_bfs2[100001];		//지정된 튜브와 반대방향으로 이동한다 가정하면, N번째 도시에서 출발했을 때
								//각각의 도시들에 도착할 수 있는지에 대한 정보를 저장한다

//M개의 도시와 N개의 이동튜브가 있다고 가정하자
//각각의 이동튜브는 시작점에서 끝점으로 한 방향으로만 이동하는 구조를 가지고 있다
//이때 어떠한 도시에 폭탄이 설치됐을경우, 영웅은 1번 도시에서 출발한 후 폭탄을 들고 N번째 도시에서 처리해야한다
//폭탄을 처리하는 데 성공했는지 실패했는지에 따라 출력값을 다르게하라.


//일반적인 BFS가 사용된다.
//해당 BFS는 1번 출발지점 도시에서 다른 지점의 도시들로 향할 수 있는지 찾는다.
void bfs(int s, vector<int>graph[], bool check[]) {
	queue<int> q;
	q.push(s);
	check[s] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0;i < graph[temp].size();i++) {
			if (check[graph[temp][i]] == false) {
				q.push(graph[temp][i]);
				check[graph[temp][i]] = true;
			}
		}
	}
}

//일반적인 BFS가 사용된다
//해당 BFS는 폭탄을 처리하는 N번째 도시에서 다른 도시로 향할 수 있는지에 대해 조사한다.
void bfs2(int s, vector<int>graph[], bool check[]) {
	queue<int> q;
	q.push(s);
	check[s] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0;i < graph[temp].size();i++) {
			if (check[graph[temp][i]] == false) {
				q.push(graph[temp][i]);
				check[graph[temp][i]] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	vector<int>* graph = new vector<int>[M + 1];		//a에서 b로 이동가능한 튜브의 정보가 들어간다
	vector<int>* graph2 = new vector<int>[M + 1];		//역방향으로 이동할 때의 경우에 대한 정보를 저장한다

	for (int i = 0;i < N;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph2[v].push_back(u);
	}

	//bfs를 계속 돌리면 시간초과가 나거나 메모리초과가 나거나 둘 중 하나였다
	//그래서 어차피 1번에서 폭탄을 회수하고 N번으로 도착하는 것이 루틴이라면
	//1번에서도 N번에서도 도착할 수 있는 도시인지 한 번 체크하는 것이 제일 메모리 & 시간 절약이 된다
	bfs(1, graph, check_bfs);
	bfs2(M, graph2, check_bfs2);

	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int bomb;
		cin >> bomb;

		if (check_bfs[bomb] && check_bfs2[bomb]) {
			cout << "Defend the CTP" << '\n';
		}
		else {
			cout << "Destroyed the CTP" << '\n';
		}
	}


	return 0;
}