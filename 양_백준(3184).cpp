#include<iostream>
#include<string>
using namespace std;

//���� * ������ ���̰� ���� garo, sero�� ������ �ִٰ� ��������. �����󿡴� ��Ÿ�� '#'�� ����'.', ����'v', ��'o'�� �ִ�.
//������ ��Ÿ���� ���� �������� �����ӿ� ���� ������ ������ ���ٸ� ������� �� �������
//������ ���� ���� �� �̻����� �����Ѵٸ� ����� �� ������� �ȴ�.
//���������� ���� ��� ������� ���� ����϶�.


char maps[251][251] = {};		//����
int checker[251][251] = {};		//DFS�� ���࿩�θ� �����ϴ°�
int wolf = 0;					//�־��� �������� ���ǿ� �˸°� ���� ������ ��
int lamb = 0;					//�־��� �������� ���ǿ� �˸°� ���� ���� ��
int t_wolf = 0;					//�������� �������� �ִ� ������ ��
int t_lamb = 0;					//�������� �������� �ִ� ���� ��
int garo, sero;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


//DFS�Լ�
void dfs(int idx, int idy) {
	checker[idx][idy] = 1;
	//flood_fill �˰����� Ȱ���Ͽ� '#'�� �ѷ����� ���ο� ���� Ž���� �����Ѵ�
	//Ž���� ���� '#'�� ��쿣 dfs Ž���� �����ϴ� ������� �����Ѵ�
	for (int i = 0;i < 4;i++) {
		int temp_x = idx + dx[i];
		int temp_y = idy + dy[i];
		if (checker[temp_x][temp_y] == 0 && maps[temp_x][temp_y] != '#'&&(temp_x >= 0 && temp_x < garo)&&(temp_y >= 0 && temp_y < sero)) {
			if (maps[temp_x][temp_y] == 'o') {
				t_lamb++;
				dfs(temp_x, temp_y);
			}
			else if (maps[temp_x][temp_y] == 'v') {
				t_wolf++;
				dfs(temp_x, temp_y);
			}
			else if (maps[temp_x][temp_y] == '.') {
				dfs(temp_x, temp_y);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> sero >> garo;
	for (int i = 0;i < sero;i++) {
		for (int j = 0;j < garo;j++) {
			cin >> maps[j][i];
		}
	}

	for (int i = 0;i < sero;i++) {
		for (int j = 0;j < garo;j++) {
			//dfs�� ������� ���� ���̸鼭 ���� Ȥ�� ���� �ִ� ��ġ�ΰ��
			//�ش� ���� ������ 1 ������Ų���� dfsŽ���� �����Ѵ�.
			if (checker[j][i] != 1) {
				if (maps[j][i] == 'v')
				{
					t_wolf++;
					dfs(j, i);
				}
				else if (maps[j][i] == 'o') {
					t_lamb++;
					dfs(j, i);
				}
			}

			//�ش� �������� �ִ� ��� ������� ���� ���Ͽ�
			//���� ���� ������ �ش� �������� ���� ���� �������� ����� �� ������ �����ְ�
			//�׷��� �ʴٸ� �ش� �������� ������ ���� �������� ����� ���� ������ �����ش�
			if (t_lamb > t_wolf) {
				lamb += t_lamb;
				t_lamb = 0;
				t_wolf = 0;
			}
			else if (t_lamb <= t_wolf) {
				wolf += t_wolf;
				t_lamb = 0;
				t_wolf = 0;
			}
		}
	}
	cout << lamb << " " << wolf << '\n';
	return 0;
}