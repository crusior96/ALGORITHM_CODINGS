#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int M, N, Tc;
bool check_bfs[100001];			//������ Ʃ�� �������� �̵��� ���, 1�� ���ÿ��� ������� �� ������ ���õ鿡 ������ �� �ִ��� �����Ѵ�
bool check_bfs2[100001];		//������ Ʃ��� �ݴ�������� �̵��Ѵ� �����ϸ�, N��° ���ÿ��� ������� ��
								//������ ���õ鿡 ������ �� �ִ����� ���� ������ �����Ѵ�

//M���� ���ÿ� N���� �̵�Ʃ�갡 �ִٰ� ��������
//������ �̵�Ʃ��� ���������� �������� �� �������θ� �̵��ϴ� ������ ������ �ִ�
//�̶� ��� ���ÿ� ��ź�� ��ġ�������, ������ 1�� ���ÿ��� ����� �� ��ź�� ��� N��° ���ÿ��� ó���ؾ��Ѵ�
//��ź�� ó���ϴ� �� �����ߴ��� �����ߴ����� ���� ��°��� �ٸ����϶�.


//�Ϲ����� BFS�� ���ȴ�.
//�ش� BFS�� 1�� ������� ���ÿ��� �ٸ� ������ ���õ�� ���� �� �ִ��� ã�´�.
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

//�Ϲ����� BFS�� ���ȴ�
//�ش� BFS�� ��ź�� ó���ϴ� N��° ���ÿ��� �ٸ� ���÷� ���� �� �ִ����� ���� �����Ѵ�.
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
	vector<int>* graph = new vector<int>[M + 1];		//a���� b�� �̵������� Ʃ���� ������ ����
	vector<int>* graph2 = new vector<int>[M + 1];		//���������� �̵��� ���� ��쿡 ���� ������ �����Ѵ�

	for (int i = 0;i < N;i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph2[v].push_back(u);
	}

	//bfs�� ��� ������ �ð��ʰ��� ���ų� �޸��ʰ��� ���ų� �� �� �ϳ�����
	//�׷��� ������ 1������ ��ź�� ȸ���ϰ� N������ �����ϴ� ���� ��ƾ�̶��
	//1�������� N�������� ������ �� �ִ� �������� �� �� üũ�ϴ� ���� ���� �޸� & �ð� ������ �ȴ�
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