#include<iostream>
#include<vector>
using namespace std;

int parent[100002] = {};		//각각의 노드에 대한 parent값이 저장되는 곳
bool visited[100002] = {};		//탐색이 진행된 곳
vector<int> tree[100002];		//간선들이 저장되는 곳

//1번 노드가 트리의 루트라고 가정하자
//N개의 노드가 존재하고 N-1개의 루트가 입력될때 각각의 노드의 부모를 출력하라


//현재 parentfinder 내에 들어온 노드값들을 parent로 지정 후, parentfinder 함수를 재귀하는 형식으로 이루어진다
//단, 이미 parent값이 지정된 노드값일 경우에는 과정생략
void parentfinder(int currNode) {
	visited[currNode] = true;

	for (int i = 0;i < tree[currNode].size();i++) {
		int nextNode = tree[currNode][i];

		if (visited[nextNode] == false) {
			parent[nextNode] = currNode;
			parentfinder(nextNode);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int start, end;
		cin >> start >> end;
		//현재 무엇이 parent이고 무엇이 child인지 모르는 상황이기 때문에
		//양방향으로 입력해준다
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	parentfinder(1);

	for (int i = 2;i <= N;i++) {
		cout << parent[i] << '\n';
	}

	return 0;

}