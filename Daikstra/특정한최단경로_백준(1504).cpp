#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> P;

//�̹��� N���� ����������� G���� �����뼱�� �ִٰ� ��������
//1��° ���������忡�� ����Ͽ� N��° ���������忡 �����ϰ����ϴµ�
//�߰������� mid1��° ����������� mid2��° ������������ �����ؾ߸� �Ѵ�
//���Ͱ��� ������� �̵����� ���, �ִܰŸ��� ���̸� ���ϰ� ���̸� �����ϸ� -1�� ����϶�
//��, �������� �־��� ������ ��������� �̵��� �����ϸ� �̵��߿� ��� ���� �����������̰� �ݺ��湮�� �����ϴ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, G, start, end, mid1, mid2;
	cin >> N >> G;
	start = 0;
	end = N - 1;
	int chk[4] = {};			//chk[i]��° ���������忡�� chk[i+1]��° ��������������� �̵��Ÿ��� ���ϱ� ���� ��ǥ
	int total_len = 0;			//1��° �̵���Ʈ�� ���� �� �ִ� �ִܰŸ�
	int total_len2 = 0;			//2��° �̵���Ʈ�� ���� �� �ִ� �ִܰŸ�
	vector<P> adj[801];	

	

	for (int i = 0;i < G;i++) {
		int s, e, w;
		cin >> s >> e >> w;
		//��������� �̵��� ������ �����̹Ƿ� ������Ͽ� ��߰� ������ġ�� �ٲ㰡�鼭 2�� �߰�������Ѵ�
		adj[s - 1].push_back(P(e - 1, w));
		adj[e - 1].push_back(P(s - 1, w));
	}

	cin >> mid1 >> mid2;
	chk[0] = start;
	chk[1] = mid1 - 1;
	chk[2] = mid2 - 1;
	chk[3] = end;

	//�����ϰ�, �־��� 3���� �ٽ� ������ ��ǥ���� ���ͽ�Ʈ�� �˰����� 3�� �����ָ� ��
	//����Ǯ�̰����� Ʋ�Ƚ��ϴٰ� ���� ���� ������ ������ ����� �� �о '�����'�̶�°��� ���Ʊ� ����


	//1��° -> mid1��° -> mid2��° -> end���� ���������� �̵���Ʈ

	for (int i = 0;i < 3;i++) {

		priority_queue<P, vector<P>, greater<P>> PQ;
		bool visited[801];
		int distance[801];
		fill(distance, distance + 801, 2400001);
		fill(visited, visited + 801, 0);
		distance[chk[i]] = 0;
		PQ.push(P(0, chk[i]));
		while (!PQ.empty()) {
			int idx;
			do {
				idx = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[idx]);
			if (visited[idx])
				break;

			visited[idx] = true;
			for (auto &p : adj[idx]) {
				int next = p.first;
				int dist = p.second;

				if (distance[next] > distance[idx] + dist) {
					distance[next] = distance[idx] + dist;
					PQ.push(P(distance[next], next));
				}
			}
		}

		if (distance[chk[i + 1]] == 2400001) {
			total_len = 0;
			break;
		}
		else {
			total_len += distance[chk[i + 1]];
		}
	}

	chk[0] = start;
	chk[1] = mid2 - 1;
	chk[2] = mid1 - 1;
	chk[3] = end;

	//1��° -> mid2��° -> mid1��° -> end��° ���������� �̵���Ʈ

	for (int i = 0;i < 3;i++) {

		priority_queue<P, vector<P>, greater<P>> PQ;
		bool visited[801];
		int distance[801];
		fill(distance, distance + 801, 2400001);
		fill(visited, visited + 801, 0);
		distance[chk[i]] = 0;
		PQ.push(P(0, chk[i]));
		while (!PQ.empty()) {
			int idx;
			do {
				idx = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[idx]);
			if (visited[idx])
				break;

			visited[idx] = true;
			for (auto &p : adj[idx]) {
				int next = p.first;
				int dist = p.second;

				if (distance[next] > distance[idx] + dist) {
					distance[next] = distance[idx] + dist;
					PQ.push(P(distance[next], next));
				}
			}
		}

		if (distance[chk[i + 1]] == 2400001) {
			total_len2 = 0;
			break;
		}
		else {
			total_len2 += distance[chk[i + 1]];
		}
	}

	
	if (total_len == 0 && total_len2 == 0) {
		cout << -1 << '\n';
	}
	else {
		if (total_len == 0 && total_len2 != 0) {
			cout << total_len2 << '\n';
		}
		else if (total_len != 0 && total_len2 == 0) {
			cout << total_len << '\n';
		}
		else {
			if (total_len >= total_len2) {
				cout << total_len2 << '\n';
			}
			else if (total_len < total_len2) {
				cout << total_len << '\n';
			}
		}
	}
	
	return 0;

}