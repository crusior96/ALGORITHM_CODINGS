#include<iostream>
#include<algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int maps[501][501] = {};	//�� ��ǥ�� �����ϴ� �볪������ ����
int curr[501][501] = {};	//�� ��ǥ���� dfs�� �������� �� Ž���� �� �ִ� �ִ� �Ÿ�

int N;
int answer = 0;

//� �Ҵ��� maps���� �ִ� �볪������ �Դ´� ��������
//�볪���� �Դ� ��Ģ�� �� ��ġ���� �� ���� �볪���� �ִ� ���� �ִٸ�
//�� ������ ���ư��鼭 �����ϴ� �볪���� ��� �Դ� ���̴�
//�̶� maps�� �ִ� �볪���� �������� ���� �ִ� �� �� �̵��� �� �ִ��� ���Ͽ���


//dfs + dp�� ���� �Լ�
//�ܼ��� dfs�� ����ϰ� �ȴٸ� �ߺ��Ǵ� ��θ� Ž���ϰ� �ż� Ÿ�Ӿƿ��� ����
//���� Ư�� ��ġ���� ������ �� �ִ� �ִ� �Ÿ��� �̹� �������ֱ� ������
//���� �̹� dfs Ž���� �Ϸ� �� ��ġ��� �ش� ��ġ�� �ִ� curr���� return���ִ� ������� �����Ѵ�
int dfs(int x, int y) {
	int idx;
	int idy;
	
	//dfs Ž���� �Ϸ�� ���̶�� curr[x][y] return
	if (curr[x][y] != 0) {
		return curr[x][y];
	}

	//ó�� dfsŽ���� �ϴ� ���̶�� �ش� ��ġ�� 1�� �����Ѵ�
	curr[x][y] = 1;
	
	//�����¿� �̵� ��, maps�� ���� �ȿ� �ְ� �볪���� ��������� �� ���� ���� ������ ���̶��
	//curr[x][y]�� ���� ���� ��ġ�� ���� dfs�� �����ϴ� ���ο� ��ġ�� �� + 1 �� �ִ����� �����ȴ�
	//�̸� ���� ���� curr[x][y] = 1�� ������ �� �� �ִ�. �ϴ� Ž���Ǵ� �ű������� �ڱ��ڽ� �������� 1�� Ȯ���ϱ� ����.
	for (int i = 0;i < 4;i++) {
		idx = x + dx[i];
		idy = y + dy[i];
		if (idx >= 0 && idy >= 0 && idx < N && idy < N) {
			if (maps[x][y] < maps[idx][idy]) {
				curr[x][y] = max(curr[x][y], dfs(idx, idy) + 1);
			}
		}
	}

	return curr[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> maps[i][j];
		}
	}

	//�� ��ġ���� dfs�� �۵����� ����
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			answer = max(answer, dfs(i, j));
		}
	}

	cout << answer << '\n';

	return 0;
}