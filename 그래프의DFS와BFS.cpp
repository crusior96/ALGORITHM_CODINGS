#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void dfs(int s, vector<int>graph[], bool check[]) {
	check[s] = true;
	cout << s << " ";
	for (int i = 0;i < graph[s].size();i++) {
		int next = graph[s][i];
		if (check[next] == false) {
			dfs(next, graph, check);
		}
	}
}

//bfs에서는 큐를 사용한다. 솔직히 bfs에서 가장 많이 애용되는 자료구조는 queue라고 생각된다.
void bfs(int s, vector<int>graph[], bool check[]) {
	queue<int> q;
	q.push(s);

	check[s] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 0;i < graph[temp].size();i++) {
			if (check[graph[temp][i]] == false) {
				q.push(graph[temp][i]);
				check[graph[temp][i]] = true;
			}
		}
	}
}

int main() {
	int nodes, lines, start;
	cin >> nodes >> lines >> start;

	/*
	c++에서는 이렇게 동적생성이 안된다
	그래서 밑에 new를 사용하는 방식으로 동적생성을 해야한다
	vector<int> graph[nodes + 1];
	*/
	vector<int>* graph = new vector<int>[nodes + 1];
	bool check_dfs[1001];
	bool check_bfs[1001];
	fill(check_dfs, check_dfs + nodes + 1, false);
	fill(check_bfs, check_bfs + nodes + 1, false);

	for (int i = 0;i < lines;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//순차적인 node 접근을 위해 node값들을 정렬한다
	for (int i = 1;i <= nodes;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(start, graph, check_dfs);
	cout << '\n';
	bfs(start, graph, check_bfs);
	return 0;
}