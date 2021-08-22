#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<string>
using namespace std;

//맨해튼 거리를 구하고 지점간 좌표값을 저장하기 위해 사용한 구조체
struct location {	
	int x;
	int y;
};
int checker[102] = {};				//해당 지점을 도착했는지에 대해 체크. 0이면 도달X, 1이면 도달O
vector<location> location_list;		//지점들의 좌표값들을 저장해둔다
vector<int> ways[102] = {};			//지점간 이동할 수 있는 경로들만을 저장해둔 vector

//집에서 출발 할 때 맥주를 20개 들고 출발할 수 있고, 50미터를 이동할 때 마다 맥주 1개를 소모해야 한다
//편의점에선 맥주를 리필할 수 있고 최대 20개까지만 가능하며 편의점은 총 N개 존재한다
//각 좌표 사이의 거리는 맨해튼 거리로 계산한다
//이때 집에서 맥주축제의 현장까지 맥주를 마시면서 도착할 수 있는지 구하여라
//만약 이동하면서 맥주를 못 마시게 된다면 그 순간 실패하게 된다
//좌표값 입력의 순서는 집 - 편의점들 - 맥주 축제 순이다


//현재 지점을 기준으로 도착할 수 있는 다른 지점을 탐색한다
//기본적으로 dfs를 사용함
void dfs(int now) {
	checker[now] = 1;
	for (int i = 0;i < ways[now].size();i++) {
		if (checker[ways[now][i]] == 0) {
			dfs(ways[now][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		memset(checker, 0, sizeof(checker));
		memset(ways, 0, sizeof(ways));
		int N;
		cin >> N;
		int tmp1, tmp2;
		location loc1, loc2;
		cin >> tmp1 >> tmp2;
		loc1.x = tmp1;
		loc1.y = tmp2;
		location_list.push_back(loc1);

		for (int j = 0;j < N;j++) {
			cin >> tmp1 >> tmp2;
			location loc;
			loc.x = tmp1;
			loc.y = tmp2;
			location_list.push_back(loc);
		}

		cin >> tmp1 >> tmp2;
		loc2.x = tmp1;
		loc2.y = tmp2;
		location_list.push_back(loc2);

		//문제 조건에 맞게 각각의 좌표들 사이의 맨해튼거리를 측정, 1000 이하인 것들만 경로로써 인식하고 저장한다
		for (int j = 0;j < N + 1;j++) {
			for (int k = j + 1;k < N + 2;k++) {
				if (abs(location_list[j].x - location_list[k].x) + abs(location_list[j].y - location_list[k].y) <= 1000) {
					ways[j].push_back(k);
					ways[k].push_back(j);
				}
			}
		}

		dfs(0);
		string answer = "happy";

		//목적지에 도착할 수 있으면 happy, 아니면 sad 출력
		if (checker[N + 1] == 0) {
			answer = "sad";
		}

		cout << answer << '\n';

		while (location_list.empty() == false) {
			location_list.pop_back();
		}
	}
}