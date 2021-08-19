#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int M, N;
int answer = 1;
vector<int> ways[10002] = {};	//��ε鿡 ���� �������� �Է�
int starts[10002] = {};			//i��° ��ǻ�Ϳ��� �ִ��� ��ŷ ������ ��ǻ�� ����	
int checker[10002] = {};		//�湮 ���θ� üũ�ϴ� �迭
int max_now = -1;				//�ִ��� ��ŷ�� �� �ִ� ��ǻ���� ����
int last = -1;

//��� ��ǻ�� A�� B�� �ŷ��ϴ� ���, B�� ��ŷ�ϸ� A�� ��ŷ�ǰ� �ȴٰ� ��������
//M���� ��ǻ�Ϳ� N���� �ŷ� ��θ� �����ް�, ��ǻ�ʹ� ���� 1��, 2��... M���� �ִٰ� ��������
//��� �� ��ǻ�͸� ��ŷ���� �� �ִ������� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����϶�
//��, �ִ������� ��ŷ�� �� �ִ� ��ǻ�͵��� ��ȣ�� ���������, ��� ��ȣ���� ������������ ����϶�


//dfs�� �����ؼ� ��ŷ�� �� �ִ� ��ο� �ִ� �ٸ� ��ǻ�͵���� Ž���� �����Ѵ�
//ó���� �� �κп��� ���� �ð��� ���ȴµ�, ����Ŭ�� �ִ� ��츦 üũ���� �ʾƼ� ������ �����
void dfs(int now) {
	checker[now] = 1;
	answer++;
	for (int i = 0;i < ways[now].size();i++) {
		if (checker[ways[now][i]] == 0) {
			dfs(ways[now][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		int s, e;
		cin >> s >> e;
		ways[e].push_back(s);
	}
	//�� ��ǻ�͸��� ��ŷ�� ������ �����ؼ� �ִ��� ��ŷ������ ������ ���Ѵ�
	for (int i = 1;i <= M;i++) {
		memset(checker, 0, sizeof(checker));
		answer = 0;
		dfs(i);
		//�ִ��� �� ȸ���� ������ �õ��Ѵ�
		if (answer > max_now) {
			max_now = answer;
		}
		starts[i] = answer;
	}
	//max_now�� ���� ��ǻ�� ��ȣ���� ����Ѵ�
	for (int i = 1;i <= M;i++) {
		if (starts[i] == max_now) {
			cout << i << " ";
		}
	}
	cout << '\n';
	return 0;
}