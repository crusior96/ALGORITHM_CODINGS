#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N, idx;
int maxi = -1;
long long int answer = 0;
vector<pair<int, int>> roads[100001];
bool checked[100001];
int total_dist[100001] = {};

//��� Ʈ���� ���� ������ �ְ� �� ���̿� ���ݵ��� �־����� ��������
//������ �� ��� ������ �Ÿ����� �� ���� �� �ִ� �ִ� �Ÿ��� ���Ͽ���


//dfs�Լ��� ����Ǵºκ�
//���� ��带 �������� �ٸ� ���� ���� �� �ִ� ���� ������, �Ÿ� check�� �� ���� �ƴ϶��
//dfs�Լ��� �� ó�� ���������� ������ �������������� ���� �������� �Ÿ��� �������ְ� checked�� true�� ������ �� dfs�� �������ش�
//dfs�Լ��� ���� �� ���� ���� �ִ���̱��� ���� ����� �Լ��� �����ϸ鼭 ���������� �ٽ� checked�� false�� �����ش�
void dfs(int s, int cost) {
	for (int i = 0;i < roads[s].size();i++) {
		int next = roads[s][i].first;
		int nextcost = roads[s][i].second;
		if (checked[next] == false) {
			cost += nextcost;
			total_dist[next] = cost;
			checked[next] = true;
			dfs(next, cost);
			checked[next] = false;
			cost -= nextcost;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int start;
		cin >> start;
		while (1) {
			int dest, len;
			cin >> dest;
			if (dest == -1) {
				break;
			}
			else {
				cin >> len;
				roads[start].push_back({ dest,len });
			}
		}
	}


	//�켱������ ���� ��忡������ ���� �Ÿ��� �� ��带 ���Ѵ�
	//���� ���κ��� ���� �Ÿ��� �� ���� �ٸ� ���� ���̿� ���� ������ �Ÿ��鵵 ���� �� ���̱� �����̴�
	//�׷��� ���� ��带 1�� ������ ���� ���� �� ��带 ���Ѵ�
	checked[1] = true;
	total_dist[1] = 0;
	dfs(1, total_dist[1]);

	for (int i = 1;i <= N;i++) {
		if (total_dist[i] >= maxi) {
			maxi = total_dist[i];
			idx = i;
		}
	}

	for (int i = 1;i <= N;i++) {
		checked[i] = false;
		total_dist[i] = 0;
	}

	//���� �� ��带 idx�� ������ ����, �ش� ��带 �������� dfs�� �ٽ� �����ش�
	maxi = -1;
	checked[idx] = true;
	dfs(idx, total_dist[idx]);

	for (int i = 1;i <= N;i++) {
		if (total_dist[i] >= maxi) {
			maxi = total_dist[i];
		}
	}
	answer = maxi;
	cout << answer << '\n';
	return 0;

}