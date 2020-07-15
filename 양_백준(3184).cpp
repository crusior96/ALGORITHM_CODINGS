#include<iostream>
#include<string>
using namespace std;

//가로 * 세로의 길이가 각각 garo, sero인 지도가 있다고 가정하자. 지도상에는 울타리 '#'과 공터'.', 늑대'v', 양'o'가 있다.
//각각의 울타리로 인해 나누어진 공간속에 양이 늑대의 수보다 많다면 늑대들이 다 사라지고
//늑대의 수가 양의 수 이상으로 존재한다면 양들이 다 사라지게 된다.
//최종적으로 남은 양과 늑대들의 수를 출력하라.


char maps[251][251] = {};		//지도
int checker[251][251] = {};		//DFS의 진행여부를 저장하는곳
int wolf = 0;					//주어진 지도내에 조건에 알맞게 구한 늑대의 수
int lamb = 0;					//주어진 지도내에 조건에 알맞게 구한 양의 수
int t_wolf = 0;					//나뉘어진 구역내에 있는 늑대의 수
int t_lamb = 0;					//나뉘어진 구역내에 있는 양의 수
int garo, sero;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


//DFS함수
void dfs(int idx, int idy) {
	checker[idx][idy] = 1;
	//flood_fill 알고리즘을 활용하여 '#'로 둘러싸인 내부에 대한 탐색을 진행한다
	//탐색한 곳이 '#'인 경우엔 dfs 탐색을 종료하는 방식으로 진행한다
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
			//dfs가 진행되지 않은 곳이면서 늑대 혹은 양이 있는 위치인경우
			//해당 종의 갯수를 1 증가시킨다음 dfs탐색을 진행한다.
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

			//해당 구역내에 있는 양과 늑대들의 수를 비교하여
			//양의 수가 많으면 해당 구역내의 양의 수를 정답으로 출력할 양 변수에 더해주고
			//그렇지 않다면 해당 구역내의 늑대의 수를 정답으로 출력할 늑대 변수에 더해준다
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