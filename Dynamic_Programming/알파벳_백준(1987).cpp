#include<iostream>
using namespace std;
int R, C;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[22][22] = {};
bool checker[27] = {};
bool visited[22][22] = {};
int maxi = -1;

//�빮�� ���ĺ����� �̷���� R * C�� map�� �ִٰ� ��������
//map�� �»�ܿ��� �����ϰ� �Ǹ�, ���� �κм����� ������ ���ĺ��� �� �̹� ������ ���ĺ��� ������ �� ���ٰ� ��������
//�̶� �ش� map���� �ִ��� ������ �� �ִ� ���ĺ��� ������ ��� ���Ͽ���
//DFS�� ����Ͽ� Ǯ� ���� + ��Ͱ� ���� ���̴� ����

//DFS�� ����Ǵ� �Լ�
//�� �������� �̵��� ���ĺ��� ���� ������ �� �ִٸ� maxi�� �����Ѵ�
void search_route(int x, int y, int moved) {

	checker[arr[x][y] - 'A'] = true;
	visited[x][y] = true;

	if (maxi <= moved) {
		maxi = moved;
	}

	//DFS�� �����ϸ鼭 �� �������� checker�� �ش���� �ʴ� ���ĺ��̸鼭
	//�ش� map�� �湮���� �ʾ� visited�� �ش���� �ʴ� ��ǥ���� search_route�� �ش� ��ǥ�� �������� �ٽ� �����Ѵ�
	for (int i = 0;i < 4;i++) {
		int idx = x + dx[i];
		int idy = y + dy[i];
		if ((idx >= 0 && idx < R) && (idy >= 0 && idy < C)) {
			if (checker[arr[idx][idy] - 'A'] != true && visited[idx][idy] != true) {
				search_route(idx, idy, moved + 1);
			}
		}
	}
	//���ο� �ִ� �Լ����� ��� ���� �� ����, true �κ��� �ٽ� false�� �����ش�
	checker[arr[x][y] - 'A'] = false;
	visited[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> arr[i][j];
		}
	}

	search_route(0, 0, 1);
	cout << maxi << '\n';
	return 0;
}