#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int indegree[32001];		//i��° �������� Ǯ������ �켱������ ������ ����Ǵ� ��
int lines[32001];			//Ǯ��� �� ���������� ��ȣ ������ ����Ǵ� ��
vector<int> adj[100001];	//���� ���
priority_queue<int, vector<int>, greater<int>> Q;

//1������ M�������� �������� Ǯ��� �Ѵٰ� ��������
//�̶�, N���� �������� �־����µ� �̴� a�� ���� Ǯ��� b�� Ǯ�� ���ٴ� �����̴�
//�����ϸ� ���� �������� Ǯ��� �� ���, 1������ M�������� ������ ȿ�������� Ǯ�� ���� ������ ����϶�

int main() {
	int M, N;
	cin >> M >> N;
	//�ش� �������� ���������� ����ϱ�� �ߴ�.
	//�켱���� ������ ���� �͵���� Q�� push���ְ�
	//push�� ������ �ش� ���� �켱������ ���� �͵� �߿� �ش� ���� ������ �켱������� Q�� push���ش�
	//�̷������� �켱������ ��� ���� ������ �� �ִ� �͵��� �����ϰ� �װ��� �����ذ� ������ �����ϴ°��� ���������̴�
	for (int i = 0;i < N;i++) {
		int s, e;
		cin >> s >> e;
		indegree[e]++;
		adj[s].push_back(e);
	}

	for (int i = 1;i <= M;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 1;i <= M;i++) {
		if (Q.empty()) {
			break;
		}

		int now = Q.top();
		Q.pop();
		lines[i] = now;

		for (int next : adj[now]) {
			if (--indegree[next] == 0) {
				Q.push(next);
			}
		}

	}

	for (int i = 1;i <= M;i++) {
		cout << lines[i] << " ";
	}
	return 0;
}