#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int indegree[502];			//�ش� �ǹ��� ���µ� ������ �ٸ� �ǹ����� ������ �����
int build_time[502];		//build_time[i] : i��° �ǹ��� ���µ� �ʿ��� �ð�
int total_time[502];		//total_time[i] : i��° �ǹ��� ���� ���� �����Ģ ��� ��θ� ������ �ð�
vector<int> adj[502];		//�ش� �ǹ��� ���µ� ������ �ٸ� �ǹ��鿡 ���� ������ ������ �����
queue<int> Q;

//N���� �ǹ����� ������ �Ѵٰ� ��������
//������ �ǹ��鿡�� �ش� �ǹ��� ���µ� �ʿ��� �ð�, �ش� �ǹ��� ���� ���� ����� �� ����ǹ��� ���� ������ ����
//�ش� �����Է��� ���� -1�� ǥ���Ѵ�
//�̶� ��� �ǹ����� �� ���µ� �ʿ��� �ּ� �ð��� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	//���������� ����ϱ� ���� ���� ����
	for (int i = 1;i <= N;i++) {
		bool done = true;
		int time;
		cin >> time;
		build_time[i] = time;
		while (done) {
			int tmp;
			cin >> tmp;
			if (tmp == -1) {
				done = false;
				break;
			}
			indegree[i]++;
			adj[tmp].push_back(i);
		}
	}

	//���������� ����ϱ� ���� �ϴ� indegree���� 0�ΰͺ��� Q�� push�Ͽ� ���������� �����Ѵ�
	for (int i = 1;i <= N;i++) {
		if (indegree[i] == 0) {
			total_time[i] = build_time[i];
			Q.push(i);
		}
	}

	//�ش� �ǹ���ȣ�� ������ �ٸ� �ǹ����� ���� total_time�� ���� �ǹ��� ���µ� �ʿ��� �ð����� �߰��Ѵ�
	//�ش� �ǹ���ȣ�� ������ �ٸ� �ǹ����� indegree���� 0�̶�� Q�� push�ϰ� ���������� ����Ѵ�
	for (int i = 1;i <= N;i++) {
		int now = Q.front();
		Q.pop();
		for (int next : adj[now]) {
			total_time[next] = max(total_time[next], total_time[now] + build_time[next]);
			if (--indegree[next] == 0) {
				Q.push(next);
			}
		}	
	}

	for (int i = 1;i <= N;i++) {
		cout << total_time[i] << '\n';
	}
	return 0;
}