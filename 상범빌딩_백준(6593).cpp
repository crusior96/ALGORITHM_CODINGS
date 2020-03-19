#include<iostream>
#include<queue>
#include<cstring>
#include<memory.h>
using namespace std;

//x개의 층과 가로 y, 세로 z로 이루어져 있는 빌딩이 있다고 가정하자. 
//현재 위치에서 이동 할 수 있는 곳으로 상, 하, 좌, 우, 윗층, 아랫층으로 이동할 수 있으며
//이동할 수 있는 곳은 '.', 아닌곳은 '#'으로 이루어져있다.
//S에서 출발하여 E로 탈출하는 최소한의 이동거리를 구하여라.
//단, 이동할 수 있는 방법이 없으면 -1을 출력한다


char miro[31][31][31] = {};
int dist[31][31][31] = {};
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int x, y, z;

struct position {
	int nx, ny, nz;
};

//BFS를 사용한 문제풀이
//기존과는 다르게 2개방향이 더 늘어났다는 차이가 있으며
//탈출지점이 1개가 아니라는 점과 출발지점이 고정되어있지 않다는 점이 큰 반례로 작용한다.
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

			//이동 할 수 있는 조건은 1. 이동이 가능한 비어있는곳 2. 도착지점
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
		//x, y, z가 0, 0, 0일때에 테스트케이스를 종료한다
		//그 전에 dist와 miro에 입력되었던 데이터들을 꾸준히 초기화 시켜줘야 한다.
		//단, 백준에 제출할 때엔 헤더파일로 <memory.h>를 추가해줘야한다.
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
					//시작점을 찾아서 bfs함수에 전달한다
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

