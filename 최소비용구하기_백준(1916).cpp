#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> P;

//N���� ����������� G���� �����뼱�� �ִٰ� ��������
//������ �����뼱���� ������ �����̴µ� �ʿ��� ����� �����Ѵ�
//start��° ���������忡�� end��° ���������忡 �����ϱ���� �Ҹ��ϴ� �ּҺ���� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, G, start, end;
	vector<P> adj[1001];		//Ư�� ����������κ��� ������ �� �ִ� �ش絵������ �� �� �Ÿ��� �����صд�
	priority_queue<P, vector<P>, greater<P>> PQ;
	bool visited[1001] = { 0 };	//�湮���� üũ
	int distance[1001];			//Ư�� ����������κ��� ������ ���������忡 �����ϱ����� �ִܰŸ� ����
	fill(distance, distance + 1001, 100000000);

	cin >> N;
	cin >> G;
	
	for (int i = 0;i < G;i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s - 1].push_back(P(e - 1, w));
	}
	cin >> start >> end;
	start--;
	end--;
	distance[start] = 0;


	PQ.push(P(0, start));
	//���ͽ�Ʈ�� �˰��� ����
	while (!PQ.empty()) {
		int idx;
		do {
			idx = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[idx]);//PQ�� ��ų� �湮�ߴ� idx�� do�� �ִ� ���� pass
		//�湮�� ������ ���ٸ� ����
		if (visited[idx])
			break;

		visited[idx] = true;	//�ش� idx��° visited�� �湮������ �켱������ üũ
								//�ش� idx��° ���������忡�� ������ �� �ִ� ��� ������ ���� �ִܰŸ��� üũ�Ѵ�
		for (auto &p : adj[idx]) {
			int next = p.first;
			int dist = p.second;

			//���ο� �ִܰŸ��� �߰��ѰŶ�� PQ������ ������ ���Ž����ش�
			if (distance[next] > distance[idx] + dist) {
				distance[next] = distance[idx] + dist;
				PQ.push(P(distance[next], next));
			}
		}
	}

	cout << distance[end] << '\n';
	return 0;
	
}