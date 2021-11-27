#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int M, N;

//M���� ������ N���� ������ �ִٰ� ��������
//N���� ������ �������� ������, ������� �̷�����ְ� ����� ������ �����ϴ�
//1�� �������� ����Ͽ� N�� �������� �����Ѵٰ� ������ ��
//�ִ� ������� ������ ���� ����� ���Ͽ���


//�������� ����� �� �ԷµǴ� ���鿡 ���� ����
struct node {
	int end;
	int val;
};

vector<node>way_length[50002];	//way_length[i] : i�� ������ ����� �ٸ� �����鿡 ���� ������ ���Ե��ִ�
int dist[50002] = {};			//dist[i] : i���� �����ϴ� �� �ʿ��� �ּҺ��. ���ǿ� ���� ���ŵȴ�.

//���ͽ�Ʈ�� ����Ǵ� �Լ�
void daik() {
	//�켱���� ť ���� �� ó�� �����ϴ� ���� ��ǥ���� 1�� ������� �Ҹ�� ����� 0�� �Է��صд�
	priority_queue<pair<int, int>>pq;
	pq.push({ 0, 1 });

	//pq�� �� ������ �۾��� �����Ѵ�
	while (!pq.empty()) {
		//top��ġ�� �ִ� node�� �����ؼ� ���� ������ ���� ����� �� �� pop�Ѵ�
		int now_node = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		//���� ���� �������� ���µ� �Ҹ�Ǵ� �� ������ �ּҺ���
		//�̹� ��θ� �߰��ؼ� ��������� ���ο� ����� ���Ѵ�
		//���� �� ������ �ּҺ���� �� �۴ٸ�, �ش� ��ġ�� val�� �� ������ �ּҺ������ ��ü�ϰ�
		//�ش� �̵� ������ pq�� �ٽ� �߰��Ѵ�
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
		//������ ������θ�ŭ 2���� ���� �߰��� �����ϸ�
		//�������� ���� �ٲ㰡�鼭 �����ϸ� �ȴ�
		way_length[s].push_back(tmp_node);
		way_length[e].push_back(tmp_node2);
	}


	//�ʱⰪ�� �����Ͽ� ���� �ּڰ����� ��ü���ش�
	for (int i = 1;i <= M;i++) {
		dist[i] = 1000000000;
	}

	dist[1] = 0;
	daik();


	cout << dist[M] << '\n';


	return 0;
}