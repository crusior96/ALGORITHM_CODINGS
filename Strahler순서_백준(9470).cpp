#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;

int K, M, P;	//���� Tc��ȣ(�߿����� �ʴ�), ����� ��, ������ ���� �ǹ��Ѵ�.


//K���� �׽�Ʈ���̽��� M���� ���, P���� �������� �ִٰ� ��������.
//��� A���� B�� ���� �� Strahler ���� �����ϰ� �Ǵµ�
//������ �� ���� ���ϱ⸸ �ϴ� ��忡���� Strahler ���� 1�� �����Ǹ�
//�ٸ� ������ ���, ���� ��尪�� i�� ���� 1���� i, 2�� �̻��̸� i+1�� �����ǰ� �ش簪�� �ִ����� �����Ѵ�.
//�̷����ؼ� ������ �� �ִ� �ִ� Strahler���� ����϶�.
//��, ���������� ���̰� �Ǵ� ���� �� ���� 1���� �����ȴ�.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int indegree[1002] = {};		//������ ���� ������ ����Ǵ� �迭
		int lines[1002] = {};			//������ ���� ������ ����Ǵ� �迭
		pair<int, int> p[1002];			//p[i]<first, second> : ���� i������ Strahler���� ���� first�̸�, �ش� ���� second��ŭ �ο��޾Ҿ���
		vector<int> adj[1002] = {};		//�α� �������� ������踦 ������ ����
		queue<int> Q;					//���� ���Ŀ� ���� ť
		int answer = 0;
		cin >> K >> M >> P;
		for (int j = 0;j < P;j++) {
			int s, e;
			cin >> s >> e;
			indegree[e]++;
			adj[s].push_back(e);
		}

		for (int j = 1;j <= M;j++) {
			if (indegree[j] == 0) {
				p[j] = pair<int, int>(1, 1);	//������ ���� ���� ���� ������ Strahler�� 1�� �����Ѵ�.
				Q.push(j);
			}
		}

		//�������� + ������ Ư������ �����ؾ� �ؼ� �� ������ ����������
		//pair�� �� ������ �ִٸ� ũ�� ��������.
		for (int j = 1;j <= M;j++) {
			if (Q.empty())
			{
				break;
			}

			int now = Q.front();
			Q.pop();
			lines[j] = now;
			for (int next : adj[now]) {
				//���� ������ p.first���� �̾����� ������ p.first������ ũ�ٸ� ����
				if (p[next].first < p[now].first) {
					p[next] = pair<int, int>(p[now].first, 1);
				}
				//�׷��� �ʰ� ���� ���� ���̶�� �̾����� ������ p.second��++
				else if (p[next].first == p[now].first) {
					p[next].second++;
				}

				//�ش������� �� �̻� �޾Ƶ��̴� ������ ���� ��
				//p.second ���� 2 �̻��̸� p.first���� 1 ������Ų ä�� �����Ѵ�.
				if (--indegree[next] == 0) {
					if (p[next].second > 1) {
						p[next] = pair<int, int>(p[next].first + 1, 1);
					}
					Q.push(next);
				}
			}
		}

		for (int j = 1;j <= M;j++) {
			if (answer < p[j].first) {
				answer = p[j].first;
			}
		}

		cout << K << " " << answer << '\n';
	}
	return 0;
}