#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//N���� ���������� R���� �̵���Ʈ�� �ִٰ� ��������
//������ ������������ Ư�� ������ �����۵��� �����Ѵ�
//���ΰ��� M�� ���� �Ÿ��ɷ��� ������ ������, ���� �Ÿ� �ȿ� �ִ� �����۵��� ���� �� �ִ�
//�̶�, ���ΰ��� N���� �������� �� �� ���� �����ؼ� ���� �� �ִ� �ִ� ������ ������ ���Ͽ���

struct node {
	int end;
	int val;
};

int N, M, R;
int items[101] = {};
int total_item = 0;
vector<node>adj[100001];
int dist[102] = {};



//�켱����ť�� ����ϴ� ����� ���ͽ�Ʈ�� ���
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
	//������ ������ӿ� ����
	for (int i = 0;i < R;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		adj[s - 1].push_back(node{ e - 1,cost });
		adj[e - 1].push_back(node{ s - 1,cost });
	}
	//��� �������� ������ �� ���� �� �ִ�
	//�������� ������ �ִ����� �˱� ���� ��� ������ ���ͽ�Ʈ�� �Լ��� �����Ѵ�
	//���ͽ�Ʈ�� �Լ��� ��������� ��� dist�迭 ���� ������ �����Ÿ� M�� ���ؼ�
	//ȸ�� ������ ���������� �Ǵ��Ѵ�
	//M ������ �Ÿ����̶�� ȸ�� ������ �������� �ȴ�
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