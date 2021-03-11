#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
long long indegree[32000] = {};
long long needed[1001][1001] = {};				//needed[i][j] : i ��ǰ�� ����µ� �ʿ��� j ��ǰ�� ������ ����ȴ�
vector<vector<pair<long long, long long>>> adj;	//adj.first, second : ���� �ʿ��� ��ǰ�� ���� �� �� ������ �ǹ��Ѵ�

//N���� ��ǰ�� �ְ� M���� ���谡 �ִٰ� ��������
//������ ��ǰ���� 1, 2 ... N�� ��ȣ�� �ο��ް� �Ǹ�
//������ ������� s, e, num���� ǥ���Ǹ� �̴� ��ǰ s�� ����µ� ���̴� ��ǰ e�� num�� �Ҹ�ȴٴ� ���̴�
//�̶� A�� ����µ� B�� �ʿ��ϸ� A�� '�߰���ǰ'�̶� Ī�ϰ�, A�� ����µ� ���� �ʿ����� �ʴٸ� A�� '�⺻��ǰ'�̶� Ī�Ѵ�
//�׷��ٸ� ��ǰ N�� ����µ� ���̴� �⺻ ��ǰ���� ������ �ּ� ������ �����Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	cin >> M;
	adj.resize(N + 1);
	for (int i = 0;i < M;i++) {
		long long s, e, num;
		cin >> s >> e >> num;
		indegree[s]++;
		pair<long long, long long> tmp_pair = make_pair(s, num);
		adj[e].push_back(tmp_pair);	//e�� num�� ����ؼ� s�� ����ٴ� ��
	}

	//�켱 �⺻��ǰ���� Q�� �Է��Ѵ�
	queue<int> Q;
	for (int i = 1;i <= N;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
			needed[i][i] = 1;
		}
	}

	//�⺻���� ���ͽ�Ʈ�� ����Ǵ� ����̱� �ѵ�
	//�ش� ��ǰ�� �ʿ�� �ϴ� �ٸ� ��ǰ�� �⺻ ��ǰ ����ǰ���� ���������� �����ִ� �۾��� �ʿ��ϴ�

	while (!Q.empty()) {
		long long idx = Q.front();
		Q.pop();
		for (auto p : adj[idx]) {
			//��ǰ idx�� �ʿ�� �ϴ� �ٸ� ��ǰ�鿡�� �ʿ� ��ǰ ��� �������� ��� �����ֱ� ���� �۾�
			//p.first�� ��ǰ idx�� �ʿ���ϴ� �ٸ� ��ǰ�� ��ȣ, p.second�� ��ǰ idx�� � �ʿ�� �ϴ��� �˷��ش�
			for (int i = 1;i <= N;i++) {
				needed[p.first][i] += needed[idx][i] * p.second;
			}
			indegree[p.first]--;

			if (indegree[p.first] == 0) {
				Q.push(p.first);
			}
		}
	}

	//���������� ��ǰ N�� �̷�µ� �⺻��ǰ i�� ��ŭ �ִ��� ����ϴ� �۾��̴�
	for (int i = 1;i <= N;i++) {
		if (needed[N][i]) {
			cout << i << " " << needed[N][i] << '\n';
		}
	}
	return 0;
}