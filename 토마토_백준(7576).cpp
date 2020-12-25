#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tomato[1001][1001] = {};
int d[1001][1001] = {};		//tomato[i][j]에 토마토가 자라나기까지 걸린 시간을 저장해두는 배열
int M, N;

//가로가 N, 세로가 M인 크기의 밭에 토마토가 자라고있다.
//토마토가 심어져있는곳은 1, 빈 땅은 0, 접근불가지역은 -1이라고 가정하자.
//토마토는 상하좌우 한 칸 인접한 곳으로 하루에 한번 자라날 수 있을때 이 토마토가 밭에 빈 땅이 없을때까지 자라는데 걸리는 시간을 구하여라.
//단, 빈 땅이 하나라도 남을경우 -1을 출력해준다.

int main()
{
	int answer = 0;
	cin >> M >> N;
	queue<pair<int, int>> q;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> tomato[i][j];
			d[i][j] = -1;
			if (tomato[i][j] == 1) //최초 토마토 생성지역엔 d 배열에 0을 저장해주고 queue에 좌표값을 push해준다.
			{
				d[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	//BFS알고리즘 사용
	while (!q.empty())
	{
		int temp_x = q.front().first;
		int temp_y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) //플러드 필 알고리즘 사용
		{
			int tx = temp_x + dx[i];
			int ty = temp_y + dy[i];
			if (tx >= 0 && tx < N&&ty >= 0 && ty < M)
			{
				//접근한 적이 없으며 tomato밭이 빈 땅일경우
				if (tomato[tx][ty] == 0 && d[tx][ty] == -1)
				{
					//그 위치의 좌표값을 queue에 입력해주고 이전 좌표까지 도달한 시간일수 + 1의 값을 d배열에 저장해준다.
					d[tx][ty] = d[temp_x][temp_y] + 1;
					q.push({ tx,ty });
				}
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			answer = max(answer, d[i][j]);
			//마지막으로 도달한 위치의 d배열 값을 answer에 저장해준다.
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (tomato[i][j] == 0 && d[i][j] == -1) //빈 땅이 있는경우
			{
				answer = -1;
			}
		}
	}
	cout << answer << endl;
	return 0;
}