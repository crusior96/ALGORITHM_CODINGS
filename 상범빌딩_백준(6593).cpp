#include<iostream>
#include<queue>
#include<cstring>
#include<memory.h>
using namespace std;

//x���� ���� ���� y, ���� z�� �̷���� �ִ� ������ �ִٰ� ��������. 
//���� ��ġ���� �̵� �� �� �ִ� ������ ��, ��, ��, ��, ����, �Ʒ������� �̵��� �� ������
//�̵��� �� �ִ� ���� '.', �ƴѰ��� '#'���� �̷�����ִ�.
//S���� ����Ͽ� E�� Ż���ϴ� �ּ����� �̵��Ÿ��� ���Ͽ���.
//��, �̵��� �� �ִ� ����� ������ -1�� ����Ѵ�


char miro[31][31][31] = {};
int dist[31][31][31] = {};
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int x, y, z;

struct position {
	int nx, ny, nz;
};

//BFS�� ����� ����Ǯ��
//�������� �ٸ��� 2�������� �� �þ�ٴ� ���̰� ������
//Ż�������� 1���� �ƴ϶�� ���� ��������� �����Ǿ����� �ʴٴ� ���� ū �ݷʷ� �ۿ��Ѵ�.
int bfs(int tx,int ty,int tz) {
	queue<position> q;
	q.push({ tx,ty,tz });
	dist[tx][ty][tz] = 0;
	while (!q.empty()) {
		int temp_x = q.front().nx;
		int temp_y = q.front().ny;
		int temp_z = q.front().nz;
		q.pop();

		if (miro[temp_x][temp_y][temp_z] == 'E') {
			return dist[temp_x][temp_y][temp_z];
		}

		for (int i = 0;i < 6;i++) {
			int temp_dx = temp_x + dx[i];
			int temp_dy = temp_y + dy[i];
			int temp_dz = temp_z + dz[i];
			if (temp_dx < 0 || temp_dx >= x || temp_dy < 0 || temp_dy >= y || temp_dz < 0 || temp_dz >= z) {
				continue;
			}

			if (dist[temp_dx][temp_dy][temp_dz]) {
				continue;
			}

			//�̵� �� �� �ִ� ������ 1. �̵��� ������ ����ִ°� 2. ��������
			if (miro[temp_dx][temp_dy][temp_dz] == '.' || miro[temp_dx][temp_dy][temp_dz] == 'E') {
				dist[temp_dx][temp_dy][temp_dz] = dist[temp_x][temp_y][temp_z] + 1;
				q.push({ temp_dx,temp_dy,temp_dz });
			}
		}
	}
	return -1;
}

int main() {
	bool doit = true;
	while (doit) {
		//x, y, z�� 0, 0, 0�϶��� �׽�Ʈ���̽��� �����Ѵ�
		//�� ���� dist�� miro�� �ԷµǾ��� �����͵��� ������ �ʱ�ȭ ������� �Ѵ�.
		//��, ���ؿ� ������ ���� ������Ϸ� <memory.h>�� �߰�������Ѵ�.
		memset(dist, 0, sizeof(dist));
		memset(miro, 0, sizeof(miro));
		int px, py, pz;
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) {
			doit = false;
			break;
		}
		else {
			for (int i = 0;i < x;i++) {
				for (int j = 0;j < y;j++) {
					for (int k = 0;k < z;k++) {
						cin >> miro[i][j][k];
					}
				}
			}
		}

		for (int i = 0;i < x;i++) {
			for (int j = 0;j < y;j++) {
				for (int k = 0;k < z;k++) {
					//�������� ã�Ƽ� bfs�Լ��� �����Ѵ�
					if (miro[i][j][k] == 'S') {
						px = i;
						py = j;
						pz = k;
						break;
					}
				}
			}
		}

		int answer = bfs(px,py,pz);
		if (answer != -1) {
			cout << "Escaped in " << answer << " minute(s)." << '\n';
		}
		else if (answer == -1) {
			cout << "Trapped!" << '\n';
		}
	}
	return 0;
}

