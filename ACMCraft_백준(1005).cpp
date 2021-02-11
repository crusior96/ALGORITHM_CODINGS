#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int M, N, W;

//� �� ���ӿ� N���� �ǹ��� �ְ�, ������ �ǹ��� �������� ���� ���� �ǹ� ��Ģ�� M�� �ִٰ� ��������
//������ �ǹ��鿡�� �Ǽ��� ���� �ʿ��� ���� �ð��� �־�����
//�̶�, �ǹ���ȣ W�� ���� �ǹ��� �Ǽ��ϸ� �̱�ٰ� ������ ��, ������ �׽�Ʈ���̽����� �¸��� ���� �ּ� �ǹ��Ǽ� �ð��� ����϶�

int main() {
	int Tc;
	cin >> Tc;
	//���� ������ �̿��Ͽ� ������ Ǯ��� �����̴�.
	for (int i = 0;i < Tc;i++) {
		queue<int> Q;						//�������Ŀ� ����ϰ� �� �ڷᱸ�� ť. �켱 ������ ���� �ǹ������ ���� �ȴ�.
		int building[1001] = {};			//������ �ǹ����� ���µ� �ʿ��� �ð�
		int building_total[1001] = {};		//�ش� �ǹ��� ���µ� �ʿ��� �� �ð�. �ǹ��� ���µ� �ʿ��� ���ǵ� �� ���Եȴ�.
		int indegree[1001] = {};			//������ �ǹ����� �������� ���� �ʿ��� �ǹ����� ����
		vector<int> adj[1001];				//�ǹ����� �Ǽ���Ģ�� ������ ���̴� �������. ������ �� �ǹ��� ���� ���� ����ɼ��� �ִ�.
		cin >> N >> M;
		for (int j = 1;j <= N;j++) {
			cin >> building[j];
		}
		for (int j = 0;j < M;j++) {
			int s, e;
			cin >> s >> e;
			indegree[e]++;
			adj[s].push_back(e);
		}
		cin >> W;

		for (int j = 1;j <= N;j++) {
			if (indegree[j] == 0) {
				Q.push(j);
			}
		}

		//�켱 ������ ���� �ǹ��� Ȥ�� �켱 ������ �� ���� �ǹ������ �������� �۾��� �����Ѵ�
		while (indegree[W] != 0) {
			for (int j = 1;j <= N;j++) {
				int now = Q.front();
				Q.pop();
				
				//�ǹ����� ���ÿ� �Ǽ��� �� �ִ�. ���� 4�� �ǹ� ���µ� 2���� 3���� �ʿ��ϸ�, 2���� 3���� ���ÿ� �������� �ִ� ��
				//�׷��� ������ ���� �ǹ��� ���� �� �ʿ��� �� �ð��� max�� ����ؼ�
				//������ �ǹ��� ���µ� �ʿ��� ������ ���� ��� �ð� + ������ �ǹ��� ���� �ð� vs ���� �ǹ��� ���µ� �ʿ��� ������ ���� ���ð�
				//�� �� ���� ū ���� building_total[next]�� �����Ѵ�
				for (int next : adj[now]) {
					building_total[next] = max(building[now] + building_total[now], building_total[next]);
					if (--indegree[next] == 0) {
						Q.push(next);
					}
				}
				
			}
		}

		cout << building_total[W] + building[W] << '\n';

	}

	return 0;
}