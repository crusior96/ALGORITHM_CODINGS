#include<iostream>
#include<vector>
using namespace std;
int M, N;
int arr[502][502] = {};
int checker[502][502] = {};
int answer = -1;
int temp = 0;
int block1[4][2] = {{0,0},{0,1},{1,0},{1,1}};									//네모 
int block2[2][4][2] = { {{0,0},{0,1},{0,2},{0,3}},{{0,0},{1,0},{2,0},{3,0}} };	//긴막대기
int block3[8][4][2] = { {{0,0},{0,1},{1,1},{2,1}},{{0,2},{1,0},{1,1},{1,2}},{{0,0},{1,0},{2,0},{2,1}},{{0,0},{0,1},{0,2},{1,0}},{{0,0},{0,1},{1,0},{2,0}},{{0,0},{0,1},{0,2},{1,2}},{{0,1},{1,1},{2,0},{2,1}},{{0,0},{1,0},{1,1},{1,2}} };
int block4[4][4][2] = { {{0,0},{1,0},{1,1},{2,0}},{{0,0},{0,1},{0,2},{1,1}},{{0,1},{1,0},{1,1},{1,2}},{{0,1},{1,0},{1,1},{2,1}} };
int block5[4][4][2] = { {{0,0},{0,1},{1,1},{1,2}},{{0,1},{1,0},{1,1},{2,0}},{{0,1},{0,2},{1,0},{1,1}},{{0,0},{1,0},{1,1},{2,1}} };

//4개의 블록이 이어져 있는 형상을 테트로미노라고 한다
//이때, N*M의 크기를 가진 지도에 숫자들이 있다고 가정하자
//테트로미노 하나를 지도 위에 올려뒀을 때 얻을 수 있는 제일 큰 숫자들의 합을 구하여라
//이때 테트로미노는 회전 및 대칭뒤집기를 해도 상관없다

//block1~5 : 좌상단 좌표를 기준으로 블록의 배치를 기록한다. 가령 (a, b)라고 한다면 좌상단 좌표로부터 a, b만큼 떨어졌다는 뜻이다
//calc1~5 : 기록해둔 좌표를 기준으로 해당 테트로미노를 지도상에 배치했을 때, 그 테트로미노로 얻을 수 있는 값들의 합을 구한다
//			그다음, 해당 값을 answer와 비교해서 최대값을 계속 저장해나간다

//원래는 DFS를 사용해도 되긴 하다. ㅗ자 모양인 테트로미노만 따로 조정해주고 나머지 테트로미노들은 DFS 및 백트래킹을 사용하면 된다.
//하지만 시간 자체를 비교해보면 미리 좌표상의 경고지정을 다 적어준 다음, 브루트포스를 사용하는 것이 더 빠른 결과로 나왔다.

void calc1(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 4;i++) {
		int idx = x + block1[i][1];
		int idy = y + block1[i][0];
		if (idx<0 || idx > N || idy<0 || idy>M) {
			tmp = 0;
			break;
		}
		else {
			tmp += arr[idy][idx];
		}
	}

	if (answer < tmp) {
		answer = tmp;
	}
}

void calc2(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 2;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block2[i][j][1];
			int idy = y + block2[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

void calc3(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 8;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block3[i][j][1];
			int idy = y + block3[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

void calc4(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 4;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block4[i][j][1];
			int idy = y + block4[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

void calc5(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 4;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block5[i][j][1];
			int idy = y + block5[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			calc1(j, i);
			calc2(j, i);
			calc3(j, i);
			calc4(j, i);
			calc5(j, i);
		}
	}


	cout << answer << '\n';
	return 0;
}