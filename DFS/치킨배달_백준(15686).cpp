#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int maps[52][52] = {};
int M, N;
int answer;
bool selected_chicken[14];		//치킨거리를 잴 때, 선택된 치킨집인지 아닌지에 대한 정보가 들어가있다

//N * N개의 공간에 M개 이상의 치킨집이 있다고 가정하자
//각각의 공간값들은 0 = 빈공간 / 1 = 집 / 2 = 치킨집을 의미한다
//이때 '치킨거리'란, 각각의 집에서 최단거리로 도달할 수 있는 치킨집까지의 거리를 의미하며
//그 거리는 치킨집과 집 사이의 맨해튼 거리를 의미한다
//M개의 치킨집만을 운영할 수 있다고 가정할 때, 얻을 수 있는 최단 치킨거리를 구하여라

struct house {
	int h_idx;
	int h_idy;
};

struct chicken{
	int c_idx;
	int c_idy;
};

//각각 집과 치킨집의 위치에 대한 정보들을 저장한 벡터
vector<house>houselist;
vector<chicken>chickenlist;

//DFS를 사용하여 치킨거리를 구할 예정. idx는 선택될 or 선택하지 않고 넘길 치킨집 배열의 위치, sel은 현재까지 선택된 치킨집의 갯수이다
//chickenlist[idx]의 치킨집을 폐업하지 않는다면 selected_chicken값을 false, 아니면 true로 저장해둔 채 진행한다
void dfs(int idx, int sel) {
	//sel 값이 M과 같아졌을때, 선택된 치킨집들을 기반으로 치킨거리를 잰다
	//각각 집들의 위치와 선택된 치킨집 사이의 맨해튼 거리를 종합하여 치킨거리를 모은다
	if (sel == M) {
		int temp_answer = 0;
		for (int i = 0;i < houselist.size();i++) {
			int len = 100000002;
			for (int j = 0;j < chickenlist.size();j++) {
				if (selected_chicken[j]) {
					int tmp_len = abs(houselist[i].h_idx - chickenlist[j].c_idx) + abs(houselist[i].h_idy - chickenlist[j].c_idy);
					len = min(len, tmp_len);
				}
			}
			temp_answer += len;
		}
		answer = min(answer, temp_answer);
		return;
	}

	//만약 idx값이 치킨집 갯수와 같은 상황이라면 종료한다
	if (idx == chickenlist.size()) {
		return;
	}

	selected_chicken[idx] = true;
	dfs(idx + 1, sel + 1);
	selected_chicken[idx] = false;
	dfs(idx + 1, sel);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 1) {
				house temp_house;
				temp_house.h_idx = i;
				temp_house.h_idy = j;
				houselist.push_back(temp_house);
			}
			else if (maps[i][j] == 2) {
				chicken temp_chick;
				temp_chick.c_idx = i;
				temp_chick.c_idy = j;
				chickenlist.push_back(temp_chick);
			}
		}
	}
	answer = 1000001;
	dfs(0, 0);

	cout << answer << '\n';
	return 0;
}
