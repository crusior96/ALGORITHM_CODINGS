#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N, idx;
int maxi = -1;
long long int answer = 0;
//roads[i] : i���� roads[i].first���� �����ϴ� �� roads[i].second��ŭ�� �Ÿ��� ������ �ִٴ� ���̴�
vector<pair<int, int>> roads[10002];
//checked[i] : i���� dfsŽ���� �̹� �Ϸ�ƴٴ� ��
bool checked[10002];
//total_dist[i] : ��ġ i������ �Ÿ�
int total_dist[10002] = {};

//Ʈ�� �ڷᱸ������ Ʈ���� �����̶�, ������ �� �� ������ �Ÿ� �� ���� �� ���� ���Ѵٰ� �� ��
//N���� ������ �־����� �ش� ������ �̾��� �ٸ� ������ ���� ������ �־����� �ȴ�
//�� ó���� ������ ��ȣ, �� ���� ���ӵǴ� 2�� ���� ������ ���� ������ �̾��� ������ ��ġ �׸��� �� �Ÿ��� �־�����
//������ ������ �Է��̶�� -1�� �Էµǰ� ����ȴ�
//�̷��� �������� ���� Ʈ���� ������ ���Ͽ���


//DFSŽ���� ����Ǵ� �κ�
//�Ű������� Ž���� ����Ǵ� ���� ������ ��ǥ�� ���� �������� �����ϴ� �� �ɸ� cost�� �޴´�
void dfs(int s, int cost) {
	for (int i = 0;i < roads[s].size();i++) {
		//���� ���������� ���� ������ ������ �� �ִٸ�
		//�ش� ��ġ�� ��ǥ �� �Ÿ��� �޴´�
		int next = roads[s][i].first;
		int nextcost = roads[s][i].second;

		//�ش� ��ġ�� Ž���� ������� ���� ���̶��
		//�ش� ��ġ���� �� �Ű��������� �����ϰ� �̾�޾� �� DFS�� �����Ѵ�
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
	for (int i = 1;i < N;i++) {
		int start, dest, len;
		cin >> start >> dest >> len;
		roads[start].push_back({ dest,len });
		roads[dest].push_back({ start,len });
	}

	checked[1] = true;
	total_dist[1] = 0;
	//������ ������ DFS Ž���� �����Ѵ�
	//checked�迭�� total_dist�� �⺻���� ���� �����صд�
	dfs(1, total_dist[1]);

	//���� ���� 1�������� ���� �� ���� ��ġ�� ������ ã�Ƴ��� �װ������� �Ÿ��� �˾Ƴ���
	for (int i = 1;i <= N;i++) {
		if (total_dist[i] >= maxi) {
			maxi = total_dist[i];
			idx = i;
		}
	}
	
	//���� ������ ��� �ʱ�ȭ��Ų���� DFS�� �ѹ� �� �����Ѵ�
	for (int i = 1;i <= N;i++) {
		checked[i] = false;
		total_dist[i] = 0;
	}

	//�̶� DFS�� ����Ǵ� ������ ������ ã�� '���� 1�������� ���� �� ����'�� �ȴ�
	//��, ������ ��ġ���� ���� �� ���� ���� ã��, �� ���� �ش� ��ġ���� ���� �� ���� ã�ԵǸ�
	//�� ������ �Ÿ��� ���� �� �Ÿ���� ���� �� �� �ְ� �ȴ�
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