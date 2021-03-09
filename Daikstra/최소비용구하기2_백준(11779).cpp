#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int INF = 9876543231;
vector<pair<int, int>> arr[10005];			
vector<int>way_to_end;						//
int dist[10005] = {};		
int M, N, start, ender;

//M���� ���ÿ� N���� ���� ��ΰ� �ִٰ� ��������
//������ ���� ��ε鿡�� ������� ������, �׸��� �ش� ���� ���̸� �̵��ϴµ� ��� ����� �Էµȴ�
//�̶� ��� ������ ���������� �־����ٸ� �ش� ��α��� �̵��ϴ� �� ��� �ּ� ����
//�ش� ��α��� �̵��ϴ� �� �湮�ϴ� ������ ���� �� �� ��θ� ����϶�



//�Ϲ����� ���ͽ�Ʈ�� ����ϸ� �Ǳ� �ϴµ�
//�̵��ϴ� ��θ� �˾Ƶ־� �ϱ� ������ ���� ��η��� ��� ������� ���� �� ���� ��Ȳ�̸� way_to_end�� �����Ѵ�
//way_to_end[i] = j -> i ���ÿ� �湮�ϱ� �ٷ� ���� j ���ÿ��� ����ߴٴ� ��
int daik() {
	priority_queue<pair<int, int>> que;
	fill(dist, dist + M + 1, 9876543231);
	dist[start] = 0;
	que.push({ 0,start });

	while (!que.empty())
	{
		int cost = -que.top().first; 
		int here = que.top().second; 

		que.pop();

		if (cost > dist[here]) {
			continue;
		}
		for (int i = 0;i < arr[here].size();i++)
		{
			int next = arr[here][i].first;
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				way_to_end[next] = here;
				dist[next] = dist[here] + nextcost;
				que.push({ -dist[next],next });
			}

		}

	}
	return dist[ender];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		arr[s].push_back({ e,cost });
	}

	cin >> start >> ender;
	way_to_end.resize(M + 2, -1);
	way_to_end[start] = start;	//���� ��� Ž������ ���� �ϴ� ������ way_to_end ���� �����ϰ� �����ϴ� ���÷� �����صд�
	int basics = daik();	//���� ���ͽ�Ʈ�� ���� �� ������ �ִܰŸ�
	
	int cnt = 0;
	int roads[1005] = {};	//�ּ� ������� �̵����� ���� ���� ��ȣ���� ��� ������ ���� ����Ǵ°�

	//���� ��θ� roads�� �����Ѵ�. way_to_end���� ������ ���� -> �ش� ���� ���� �湮���� -> ... -> ����� ������ ��ȣ�� ����ȴ�
	//��ũ�� ����Ʈ���� ����� ��Ȳ�̱⶧���� ��ũ�� ������ ���缭 ������ ��ȣ���� �̾Ƴ���
	for (int idx = ender;idx != way_to_end[idx];idx = way_to_end[idx]) {
		roads[cnt] = idx;
		cnt++;
	}
	roads[cnt] = start;
	cnt++;

	cout << basics << '\n';
	cout << cnt << '\n';
	for (int i = cnt - 1;i >= 0;i--) {
		cout << roads[i] << " ";
	}
	return 0;
}