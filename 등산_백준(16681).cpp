#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, long long> P;
vector<P> adj[200001];				//���� ��ĳ����� ������ ����ȴ�. �������� & �������� & ������ �Ÿ��� ����ȴ�.
long long height[100001] = {};
long long Home_len[100001] = {};
long long Camp_len[100001] = {};
bool visited[100001] = { 0 };
long long sum[200001] = {};

int N, lane, D, E;
//���� ������ ǥ�õ� ���������� ����, ������ �մ� ����� ����, �Ÿ� ��� ü�� �Ҹ�, ���� ��� ���밨 ȹ�淮�� �ǹ��Ѵ�

//����� �Ϸ��ϴµ� ������(1)���� �����Ͽ� ��������(N)���� �̵��Ϸ��Ѵ�
//����� �� �� �ִ� ��ΰ� lane�� �־������� �� ���� �� �ִ� �ִ� ���밨�� ����϶�
//���ǿ� ���缭 ���밨�� ���� �� ���ٸ� Impossible ���

//�������� ���� ���ͽ�Ʈ�� �˰���
//�Ÿ� ��� ü�� �Ҹ��� ����ؼ� ����Ǯ�̿� ����
void daik(int start, long long len[]) {
	memset(visited, 0, sizeof(visited));
	priority_queue<P, vector<P>, greater<P>> PQ;
	len[start] = 0;
	PQ.push(P(0, start));

	while (!PQ.empty()) {
		int now;
		now = PQ.top().second;
		PQ.pop();

		while (!PQ.empty() && visited[now]) {
			now = PQ.top().second;
			PQ.pop();
		}

		if (visited[now])
			break;

		visited[now] = true;

		for (auto& s : adj[now]) {
			int next = s.second;
			long long d = s.first;
			if (height[now] < height[next]) {
				if (len[now] + d * D < len[next]) {
					len[next] = len[now] + d * D;
					PQ.push(P(len[next], next));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long answer = -1000000000000;	

	cin >> N >> lane >> D >> E;
	for (int i = 1;i <= N;i++) {
		cin >> height[i];
		Home_len[i] = Camp_len[i] = 1000000000000;
	}



	for (int i = 0;i < lane;i++) {
		int s, e, len;
		cin >> s >> e >> len;
		adj[s].push_back(P(len, e));
		adj[e].push_back(P(len, s));
	}

	//���ͽ�Ʈ�� 2�� �����Ѵ�. ���� ������ ����� ���� ������������ ����� ���� �����Ѵ�
	//��������� �̵��� �� �ִ¸�ŭ ������������ ����������� �̵��� ���� ã���� �ִܰŸ��� ã�� ���� �ִ�
	daik(1, Home_len);
	daik(N, Camp_len);

	for (int i = 2;i < N;i++) {
		if (Home_len[i] == 1000000000000 || Camp_len[i] == 1000000000000) {
			continue;
		}
		else {
			sum[i] = height[i] * E - Camp_len[i] - Home_len[i];
			if (answer < sum[i]) {
				answer = sum[i];
			}
		}
	}

	if (answer == -1000000000000) {
		cout << "Impossible" << '\n';
	}
	else {
		cout << answer << '\n';
	}
	return 0;
}