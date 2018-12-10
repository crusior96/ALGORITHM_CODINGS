#include<iostream>
using namespace std;

//가로길이가 M이고 세로길이가 N인 미로가 있다. 각각의 미로를 구성하는 칸의 길이는 1이라고 하자.
//왼쪽 위에서 출발하여 오른쪽 아래쪽으로 도달하는 방법의 수를 구하고자 한다.
//이때, 각 칸에 입력된 숫자들 중, 현재 위치보다 낮은 숫자쪽으로만 이동할 수 있다.

int map[502][502] = {}; //칸에 적힌 숫자가 저장되는 배열
int ways[502][502] = {}; //각 위치까지 도달할 수 있는 방법의 수. 각 칸의 초기값을 -1로 저장해둔다.
int move_x[4] = {0,1,0,-1};
int move_y[4] = {1,0,-1,0};
int M, N;

int search(int x, int y)
{
	if (ways[x][y] != -1)
	{
		return ways[x][y];
		//시간의 절약을 위해, 현재까지 다다를 수 있는 방법의 수가 정해져있다면, 그 값을 돌려받는다.
	}
	if (x<0 || x>=M || y<0 || y>=N)
	{
		return 0;
		//지정된 크기의 배열 바깥의 값은 자동적으로 0을 제공하게 된다.
	}
	if (x == 0 && y == 0)
	{
		return 1;
		//배열의 크기가 1칸짜리인 경우엔 방법이 1가지 밖에 없으므로 1을 제공한다.
	}
	ways[x][y] = 0;
	//위 3가지 조건에 모두 해당하지 않는다면 ways값을 0으로 만든 후 for문을 실행한다.
	//현재 위치에서 4개의 인접한 값을 비교하게 되는데
	//그 값이 현재의 값보다 클 경우, 그 위치의 좌표를 search함수에 넣는다.
	for (int i = 0;i < 4;i++)
	{
		int nextx = x + move_x[i];
		int nexty = y + move_y[i];

		if (map[nextx][nexty] > map[x][y])
		{
			ways[x][y] += search(nextx, nexty);
		}
	}
	return ways[x][y];
}


int main()
{
	cin >> M >> N;
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> map[i][j];
			ways[i][j] = -1;
		}
	}
	//맨 오른쪽아래에서부터 DP가 시작되어 맨 왼쪽의에서의 search함수값을 받게 된다.
	cout << search(M - 1, N - 1)<<endl;
	return 0;
}