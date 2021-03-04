#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int, int>> arr[10002] = {};
int dist[10002];

//��� ���� A�� B�� �־����ٰ� ��������
//A�� B�� ��ȯ��Ű���� �ϴµ� �ٷ� ��ȯ�� �ȵǰ�, �־��� E���� ��ȯ ����� ���� ��ȯ�ϴ� ������� �ؾ��Ѵ�
//��� ��ȯ����� ��������� ������ �� �ִ�
//�̶� �ּ����� ��ȯ Ƚ���� A�� B�� �ٲ���


//�� ������ ���� ��̴� ���� : �������� ���� �� �������� ���ͽ�Ʈ�� �����ߴµ�
//							 ���� ������������ ����� ����� �� ���Դ�
//							 �ᱹ �� ���⿡�� ���ͽ�Ʈ�� �����ߴµ� �ű⼱ ����� ���ͼ� �ű��ϴ�
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int V, E, start, ending; //V�� ���, E�� �����Դϴ�.
	bool checked = false;
	cin >> start >> ending;
	cin >> V >> E;

	for (int i = 0;i < E;i++)
	{
		int from, to; // from�� �����, to�� ������, val�� �� ���̿� ������ �ƴ� �Ÿ�����Դϴ�.
		cin >> from >> to;
		arr[from].push_back({ to,1 });
		arr[to].push_back({ from,1 });
	}

	fill(dist, dist + V + 1, 10005);
	priority_queue<pair<int, int>> que;
	que.push({ 0,start });
	dist[start] = 0;
	//�켱���� ť(���⼱ que)�� ��� ���� 0���� �ʱ�ȭ��Ű��, ������������ �ִܰŸ����� 0���� �����Ѵ�.
	//���ͽ�Ʈ�� ����Ǵ� ��
	while (!que.empty())
	{
		int cost = -que.top().first; //���� �湮�� ���� dist��
		int here = que.top().second; //here�� �湮�� ���� ��ȣ��

		que.pop();

		for (int i = 0;i < arr[here].size();i++)
		{
			int next = arr[here][i].first;
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				que.push({ -dist[next],next });
			}

		}

	}



	if (start == ending) {
		cout << 0 << '\n';
	}
	else {
		if (dist[ending] == 10005) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[ending] << '\n';
		}
	}

	return 0;
}