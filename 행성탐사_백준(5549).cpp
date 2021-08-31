#include<iostream>
using namespace std;
char map[1001][1001] = {};
int Jungle[1002][1002] = {};
int Ocean[1002][1002] = {};
int Iceland[1002][1002] = {};

//M*N의 크기를 가진 지도에 정글, 바다, 빙하지대의 종류를 표기한다고 가정하자
//정글은 J, 바다는 O, 빙하지대는 I라고 가정할 때
//좌표(sx, sy)서부터 (fx, fy)까지 있는 정글, 바다, 빙하지대의 갯수를 구하여라

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N, TC, sx, sy, fx, fy;
	cin >> M >> N;
	cin >> TC;

	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> map[i][j];
		}
	}

	//각 지대의 종류별로 구간 합 작업을 진행한다
	//해당 지대가 맞다면 2차원 배열에서의 구간합 작업에 1을 추가하고, 아니라면 그냥 작업을 진행한다
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (map[i][j] == 'J') {
				Jungle[i + 1][j + 1] = Jungle[i + 1][j] + Jungle[i][j + 1] - Jungle[i][j] + 1;
			}
			else {
				Jungle[i + 1][j + 1] = Jungle[i + 1][j] + Jungle[i][j + 1] - Jungle[i][j];
			}

			if (map[i][j] == 'O') {
				Ocean[i + 1][j + 1] = Ocean[i + 1][j] + Ocean[i][j + 1] - Ocean[i][j] + 1;
			}
			else {
				Ocean[i + 1][j + 1] = Ocean[i + 1][j] + Ocean[i][j + 1] - Ocean[i][j];
			}

			if (map[i][j] == 'I') {
				Iceland[i + 1][j + 1] = Iceland[i + 1][j] + Iceland[i][j + 1] - Iceland[i][j] + 1;
			}
			else {
				Iceland[i + 1][j + 1] = Iceland[i + 1][j] + Iceland[i][j + 1] - Iceland[i][j];
			}
		}
	}

	for (int i = 0;i < TC;i++)
	{
		int J_num = 0;
		int I_num = 0;
		int O_num = 0;
		cin >> sx >> sy >> fx >> fy;

		//각각의 지대에 대한 구간합을 구하는 공식
		//이 공식은 2차원 배열에서 꼭 쓰이니 숙지해 둘 것. 하다못해 그림이라도 연상하면 된다.
		J_num = Jungle[fx][fy] - Jungle[sx-1][fy] - Jungle[fx][sy-1] + Jungle[sx - 1][sy - 1];
		I_num = Iceland[fx][fy] - Iceland[sx-1][fy] - Iceland[fx][sy - 1] + Iceland[sx - 1][sy - 1];
		O_num = Ocean[fx][fy] - Ocean[sx - 1][fy] - Ocean[fx][sy - 1] + Ocean[sx - 1][sy - 1];
		cout << J_num << " " << O_num << " " << I_num << '\n';
	}
	return 0;
}