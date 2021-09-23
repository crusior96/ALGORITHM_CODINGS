#include<iostream>
using namespace std;
int R, C;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[22][22] = {};
bool checker[27] = {};
bool visited[22][22] = {};
int maxi = -1;

//대문자 알파벳으로 이루어진 R * C의 map이 있다고 가정하자
//map은 좌상단에서 시작하게 되며, 시작 부분서부터 지나간 알파벳들 중 이미 지나간 알파벳을 지나갈 수 없다고 가정하자
//이때 해당 map에서 최대한 지나갈 수 있는 알파벳의 갯수를 모두 구하여라
//DFS를 사용하여 풀어낸 문제 + 재귀가 나름 쓰이는 문제

//DFS가 진행되는 함수
//현 시점에서 이동한 알파벳의 수를 갱신할 수 있다면 maxi로 갱신한다
void search_route(int x, int y, int moved) {

	checker[arr[x][y] - 'A'] = true;
	visited[x][y] = true;

	if (maxi <= moved) {
		maxi = moved;
	}

	//DFS를 진행하면서 현 시점까지 checker에 해당되지 않는 알파벳이면서
	//해당 map을 방문하지 않아 visited에 해당되지 않는 좌표계라면 search_route를 해당 좌표를 기준으로 다시 진행한다
	for (int i = 0;i < 4;i++) {
		int idx = x + dx[i];
		int idy = y + dy[i];
		if ((idx >= 0 && idx < R) && (idy >= 0 && idy < C)) {
			if (checker[arr[idx][idy] - 'A'] != true && visited[idx][idy] != true) {
				search_route(idx, idy, moved + 1);
			}
		}
	}
	//내부에 있는 함수들이 모두 진행 된 다음, true 부분을 다시 false로 돌려준다
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