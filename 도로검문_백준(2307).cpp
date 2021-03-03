#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int INF = 9876543231;
vector<pair<int, int>> arr[10005];		//���� ������ ���ο� ���� ����
vector<int>way_to_end;					//���� ���ͽ�Ʈ�� ���� �� ��� �ִ� ��ο� ���� ����
int dist[10005] = {};
int city_blocked1 = 0;
int city_blocked2 = 0;
bool first_trial = true;				//���� ���ͽ�Ʈ�� ���� ����
int M, N;

//M���� ���ÿ� �� ���̵��� �����ϴ� ���ο� ���� N���� ������ �ִٰ� ��������
//1�� ���ÿ��� M�� ���÷� �����ϴ� �ִ� �ð��� basics��� �� ��
//Ư�� �� ���θ� �������� �� basics�κ��� �󸶳� �ð��� ������ų �� �������� ���� �˾ƺ����� �Ѵ�
//�̶�, �������� �� �ƿ� M�� ���÷� ������ �� ���� ��Ȳ�̶�� -1�� ����Ѵ�
//�ִ��� ������ų �� �ִ� �ð��� ����϶�

//�Է¹��� ������ �������� ������ �̹��� ������ �ϴ� ������ �������� �����̶� ������ üũ�ϴ� �Լ�
//������ �ִ� ��ε��� �ѹ� �� �����鼭 ���ͽ�Ʈ�� �������� �ϴ� �ǵ��� ���������
bool breakup(int s, int e) {
	if (city_blocked1 == s && city_blocked2 == e) {
		return true;
	}
	else if (city_blocked1 == e && city_blocked2 == s) {
		return true;
	}
	return false;
}

//���� ���ͽ�Ʈ�� �Լ������� ���� ��θ� �����ϰų� breakup�Լ��� ����Ǹ鼭
//ȯ���� �������ǿ� ���簣��
int daik() {
	priority_queue<pair<int, int>> que;
	fill(dist, dist + M + 1, 9876543231);
	dist[1] = 0;
	que.push({ 0,1 });

	while (!que.empty())
	{
		int cost = -que.top().first; //���� �湮�� ���� dist��
		int here = que.top().second; //here�� �湮�� ���� ��ȣ��

		que.pop();

		if (cost > dist[here]) {
			continue;
		}
		for (int i = 0;i < arr[here].size();i++)
		{
			int next = arr[here][i].first;
			if (breakup(here, next)) {
				continue;
			}
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				if (first_trial == true) {
					way_to_end[next] = here;
				}
				dist[next] = dist[here] + nextcost;
				que.push({ -dist[next],next });
			}

		}

	}
	return dist[M];
}

int main() {
	cin >> M >> N;
	way_to_end.resize(M + 1, -1);
	way_to_end[1] = 1;
	for (int i = 0;i < N;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		arr[s].push_back({ e,cost });
		arr[e].push_back({ s,cost });
	}
	int basics = daik();	//���� ���ͽ�Ʈ�� ���� �� ������ �ִܰŸ�
	first_trial = false;	//���� ���ͽ�Ʈ�� ���������Ƿ� first_trial�� false�� ������

	int maxi = 0;	//�ִ� ����ð�

	//way_to_end���� �������� ���ϴ� �������� ������ �ϳ��� ���´�
	//��� ���� ������ ���������� �������� �����ϴ� ������ �켱�̰�, ���ʷ� ����ϴ� ������ �������̴�
	for (int idx = M;idx != way_to_end[idx];idx = way_to_end[idx]) {
		city_blocked1 = idx;
		city_blocked2 = way_to_end[idx];
		maxi = max(maxi, daik());
		if (maxi == INF) {
			break;
		}
	}

	if (maxi == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << maxi - basics << '\n';
	}

	return 0;
}