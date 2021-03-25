#include<iostream>
#include<cstring>
#include<utility>
#include<set>
using namespace std;
int N, M;

//N*M의 크기를 가진 행렬이 있다고 가정하자
//벽인 부분을 1, 아닌 부분을 0이라고 가정할 때
//N*M인 맵 상에서 벽인 부분을 부쉈을 경우 해당 위치에서 탐색할 수 있는 땅의 크기를 구하여라
//당연하게도 벽이 아닌 부분은 부술 수가 없으니 0을 출력한다

struct land_info {
	int land_num = 0;
	int land_size = 0;
};

char arr[1002][1002] = {};			//N*M의 크기에 저장된 지도상태. 0이면 뚫린공간, 1이면 벽이다.
land_info lands[1002][1002] = {};	//해당 땅의 넓이 및 땅이 부여받은 땅번호를 저장한다
int checker[1002][1002] = {};
int land_infos[1000002] = {};		//0으로 구성된 땅들의 넓이에 대한 정보가 저장된다. 최초로 찾은 땅 부터 순차적으로 저장한다.
									//land_infos[i] : i번째 땅에 저장된 땅의 넓이
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;

void flood_fill(int y, int x, int nu) {
	checker[y][x] = 1;
	cnt++;
	for (int k = 0;k < 4;k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if ((0 < ny && ny <= N) && (0 <= nx && nx <= M)) {
			if (!checker[ny][nx] && arr[ny][nx] == '0') {
				lands[ny][nx].land_num = nu;
				flood_fill(ny, nx, nu);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt2 = 1;
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> arr[i][j];
		}
	}

	//flood_fill 함수를 사용해서 0으로만 이루어진 땅들의 넓이를 구한다
	//땅번호를 부여받지 않은 곳은 새로이 땅번호를 부여받고 그 땅번호가 가진 넓이를 해당 위치에 저장한다
	//땅번호를 부여받았지만 해당 위치가 넓이에 대한 정보가 없다면, 해당 땅번호가 가진 넓이를 해당 위치에 저장한다
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j] == '0' && lands[i][j].land_num == 0) {
				cnt = 0;
				flood_fill(i, j, cnt2);
				lands[i][j].land_size = cnt;
				lands[i][j].land_num = cnt2;
				land_infos[cnt2] = cnt;
				cnt2++;
			}
			else if (arr[i][j] == '0'&&lands[i][j].land_num != 0) {
				lands[i][j].land_size = land_infos[lands[i][j].land_num];
			}
		}
	}


	//이제 지도상에서 '1'로 저장된 부분을 부수고 탐색할 수 있는 땅의 넓이를 구한다
	//단, 출력 조건상 10으로 나눈 나머지이기 때문에 1을 더해준 다음(본인위치) 10으로 나머지를 구해주자
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j] == '1') {
				int tmp = 0;
				set<int> land_cnt;	//하드 코딩 막으려고 set 컨테이너를 썼다. 중복되는 땅 번호를 가진 부분이 더해지면 안되기 때문.
				//land_tmp : '1'인 곳을 기준으로 상하좌우에 있는 땅들의 땅번호값 저장
				//land_tmp2 : '1'인 곳을 기준으로 상하좌우에 있는 땅들의 땅크기값 저장
				int land_tmp[4] = { lands[i - 1][j].land_num, lands[i][j + 1].land_num, lands[i + 1][j].land_num,lands[i][j - 1].land_num };
				int land_tmp2[4] = { lands[i - 1][j].land_size, lands[i][j + 1].land_size, lands[i + 1][j].land_size, lands[i][j - 1].land_size };
				int tmp2 = 0;
				for (int k = 0;k < 4;k++) {
					if (k == 0) {
						tmp += land_tmp2[k];
						land_cnt.insert(land_tmp[k]);
					}
					else {
						if (land_cnt.count(land_tmp[k]) == 0) {
							tmp += land_tmp2[k];
							land_cnt.insert(land_tmp[k]);
						}
					}
				}
				
				cout << (tmp + 1) % 10;
			}
			else if (arr[i][j] == '0') {
				cout << 0;
			}
		}
		cout << '\n';
	}


	return 0;
}