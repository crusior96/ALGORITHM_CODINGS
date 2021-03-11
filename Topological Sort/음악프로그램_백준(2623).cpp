#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> adj[1001];
int indegree[1001];
int onstage[1001];
queue<int> Q;


//1������ M�������� �������� �ִٰ� ��������
//N���� PD���� ���� ������ num��ŭ�� �������� ������ȹ�� ������ �ִٰ� ������ ��
//PD���� ������ȹ���� ��� �����ϴ� ���������� �� �ƹ��ų� �����϶�

//�߰����� : ��ܿ� �ִ� queue�� ������� �ʰ� �ּ� ���� ����ϰ� �ȴٸ�
//			1�������� ���ǿ� �°� ������������ �����ϰ� 2�������� ���������� ������ �κп� ���� �������� �����Ѵ�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N;
	cin >> M >> N;

	//���� ������ ������ ���õ� �� ����� ���谡 A - B �������� 2���� ������ ���� �ƴ϶�
	//A - B - C�� ���� �Ϸķ� �����Ǵ� �����̱⶧���� ���Ͱ��� ǥ���Ѵ�
	//��Ȥ���� num�� 1�� ������ ��찡 �ִµ� �̶����� adj�� indegree�� ������ �Է��� �ȵǱ� ������ �������
	//�̷��� ������ ���� ���� ���� ������ �����Ѵ�
	for (int i = 0;i < N;i++) {
		int num, s, e;
		cin >> num;
		cin >> s;
		for (int j = 1;j < num;j++) {
			cin >> e;
			indegree[e]++;
			adj[s].push_back(e);
			s = e;
		}	
	}


	for (int i = 1;i <= M;i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 1;i <= M;i++) {
		if (Q.empty()) {
			cout << 0 << '\n';
			return 0;
		}

		int now = Q.front();
		Q.pop();
		onstage[i] = now;

		for (int next : adj[now]) {
			if (--indegree[next] == 0) {
				Q.push(next);
			}
		}
	}

	for (int i = 1;i <= M;i++) {
		cout << onstage[i] << '\n';
	}


	return 0;
}