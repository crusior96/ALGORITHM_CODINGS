#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
int maps[52][52] = {};		//�̷��� ������ ����
int brokes[52][52] = {};	//�������� �� ������ �ٲٰ� �Ǵ� �ּ� Ƚ���� ����Ǵ� ��
int visited[52][52] = {};	//�湮 ���θ� ������ �迭
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

//�ִ� 50*50ĭ�� �̷θ� ���� �� �� ��, ���� 0���� �����ϰ� �� ������ 1�� �����Ѵ� ����
//���� �ּ��� ���ݸ� ���ִ� ������� �̵��� �� �ִ� ��찡 �ִٸ�, �̷θ� Ż������ �� �� ���� ���ŵ� ���� ������ ���Ͽ���
//��, �̷δ� �ִܰŸ��� �̵��ϴ� ����� �ƴ϶� ���� �ּ������� ���ִ� ������� �̵��Ѵ�
//�̷θ� Ż���ϴ� ������ ���ϴܿ� �������� ���̴�

struct task {
	int x, y, combo;
};

//�ش� ������ bfs �̷��� ����Ͽ� Ǯ����
//������ �̷��� ĭ���� �̵��� ����, �ش� ĭ�� �湮�� �̹� �� ���� ���, �ش� ĭ�� �湮�� �� ���� ���� ���
//�ش� ĭ�� ���� ���̰ų� �� ���ΰ�� ����� ����ؼ� ������ Ǯ����� �ȴ�
void bfs() {
	queue<task> q;
	q.push({ 0,0,0});
	brokes[0][0] = 0;
	visited[0][0] = 1;
	while (!q.empty()) {
		int tmp_x = q.front().x;
		int tmp_y = q.front().y;
		int cmb = q.front().combo;  //�������� �� ������ �ٲٰ� �Ǵ� Ƚ��
		q.pop();

		for (int i = 0;i < 4;i++) {
			int tmp_cmb = cmb;	
			int tmp_dx = tmp_x + dx[i];
			int tmp_dy = tmp_y + dy[i];
			if (tmp_dx < 0 || tmp_dx >= N || tmp_dy < 0 || tmp_dy >= N) {
				continue;
			}

			//�������̶�� �� ������ �ٲ� Ƚ���� ���������ش�
			if (maps[tmp_dx][tmp_dy] == 0) {
				tmp_cmb++;
			}

			//�̹� �湮�ϰ� �� ���̶�� �ش� ��ġ�� brokes �迭����
			//��������� �������� �������� �� ������ �ٲ� Ƚ���� ���Ѵ�
			//brokes �迭���� ������ ���� ��������� �ٲ� Ƚ������ ũ��, ���� ���� ��� �����ع�����
			if (visited[tmp_dx][tmp_dy] == 1) {
				if (brokes[tmp_dx][tmp_dy] > tmp_cmb) {
					brokes[tmp_dx][tmp_dy] = tmp_cmb;
					q.push({ tmp_dx, tmp_dy, tmp_cmb });
				}
				else {
					continue;
				}
			}
			//�湮�� �� ���� ���� ���̶�� �ش� ��ġ�� brokes �迭����
			//��������� �������� �������� �� ������ �ٲ� Ƚ���� �����ϰ�
			//visited �迭���� 1�� �����ع�����
			else {
				brokes[tmp_dx][tmp_dy] = tmp_cmb;
				visited[tmp_dx][tmp_dy] = 1;
				q.push({ tmp_dx,tmp_dy,tmp_cmb });
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0;j < N;j++) {
			maps[i][j] = tmp[j] - 48;
		}
	}

	bfs();
	cout << brokes[N - 1][N - 1] << '\n';

	return 0;
}