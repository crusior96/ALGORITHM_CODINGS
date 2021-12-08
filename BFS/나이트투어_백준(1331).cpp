#include<iostream>
#include<string>
using namespace std;

struct knight_pair {
	int x;
	int y;
};

//knight_pair arr[i] : 나이트의 이동경로를 숫지로 만들어서 저장해둔 배열
knight_pair arr[37] = {};
int checker[7][7] = {};

//dx, dy : 나이트가 이동할 수 있는 경로들에 대한 정보를 저장해둔 배열
int dx[8][2] = { {0,1} ,{1,1},{1,1},{0,1},{0,-1},{-1,-1},{-1,-1},{0,-1} };
int dy[8][2] = { {-1,-1},{0,-1},{0,1},{1,1},{1,1},{0,1},{0,-1},{-1,-1} };

//체스판의 특정 위치에 있던 나이트는 체스판을 순회하면서 36번의 이동을 진행한다
//체스판은 총 6*6의 크기를 가지고 있다
//이 때 각각의 이동 시 도착지점은 한 번도 겹치면 안되며, 최종 목적지는 자신이 출발한 위치여야 한다
//이동 경로가 36개의 문자열로 주어진다면 해당 이동을 진행할 때 위의 규칙대로 진행이 되는지 밝혀내라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string knight_run;
	knight_pair k_tmp;
	//문자열로 주어지는데 A1이나 F5와 같이 체스판의 위치가 주어지게 된다
	//이에 따른 적절한 변환이 필요하다
	for (int i = 0;i < 36;i++) {
		cin >> knight_run;
		k_tmp.x = knight_run[0] - 'A';
		k_tmp.y = 5 - (knight_run[1] - '1');
		arr[i] = k_tmp;
	}

	//마지막으로 이동을 진행할 때의 목적지를 말이 맨 처음 있었던 곳으로 지정한다
	arr[36].x = arr[0].x;
	arr[36].y = arr[0].y;
 
	//36번의 이동동안 규칙에 위배되는 경우가 생긴다면 done은 false가 된다
	bool done = true;
	int idx = 0;
	while (done) {
		int chk = 0;
		for (int i = 0;i < 8;i++) {
			//현재 위치를 기준으로 이동할 수 있는 8개 방향에 대해서 모두 탐색을 진행한다
			//말판의 바깥으로 넘어가버리거나 이미 방문한 위치를 또 방문하는 경우가 아니라면 계속 진행한다
			if (arr[idx].x + dx[i][0] + dx[i][1] == arr[idx + 1].x && arr[idx].y + dy[i][0] + dy[i][1] == arr[idx + 1].y) {
				if (checker[arr[idx + 1].x][arr[idx + 1].y] == 0) {
					checker[arr[idx + 1].x][arr[idx + 1].y] = 1;
					idx++;
					chk = 1;
					break;
				}
			}
		}

		if (chk == 0) {
			done = false;
			break;
		}

		if (idx == 36) {
			break;
		}
	}


	if (done == false) {
		cout << "Invalid" << '\n';
	}
	else if(done == true){
		cout << "Valid" << '\n';
	}
	return 0;
}