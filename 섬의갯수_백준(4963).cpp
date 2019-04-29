#include<iostream>
#include<cstring> // 백준에서의 코드채점기는 memset를 사용할 때 이 헤더를 추가해야만 한다. 안그래서 컴파일에러가 발생했었다.

//최대 50*50칸의 지도에 섬이 표시되어있다.
//이때, 섬과 섬 사이에 이동할수 있는 방법이 있다면 그 섬들은 하나의 섬으로 간주한다.
//한 지도 위에 있는 섬의 갯수들을 구하는 것이 이번 문제.
//지난번의 flood_fill 알고리즘과는 달리, 대각선 방향으로도 이동할 수 있다.
using namespace std;
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int checked[51][51] = {}; //flood_fill 알고리즘이 진행된 적 있는지를 입력해두는 배열
int sea[51][51] = {}; // 섬이 있다면 1, 아니면 0을 입력
int cnt = 0;
int G, S;

void island(int x, int y)
{
	checked[x][y] = 1;
	for (int k = 0;k < 8;k++) // 현재 위치를 기준으로 8개 방향에 섬이 있는지 없는지를 체크한다.
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if ((0 <= nx && nx < G) && (0 <= ny && ny < S))
		{
			if (checked[nx][ny] == 0 && sea[nx][ny] == 1)
			{
				island(nx, ny);
			}
		}
	}
}
int main()
{
	//지도 길이의 가로(S)와 세로(G)의 값이 0, 0인경우 while문이 종료된다.
	bool showtime = true;
	while(showtime)
	{
		memset(checked, 0, sizeof(checked));
		memset(sea, 0, sizeof(sea));
		cnt = 0;
		//배열과 변수를 초기화해준다. 
		cin >> S >> G;
		if (G == 0 && S == 0)
		{
			return 0;
		}
		else
		{
			for (int j = 0;j < G;j++)
			{
				for (int k = 0;k < S;k++)
				{
					cin >> sea[j][k];
				}
			}

			for (int j = 0;j < G;j++)
			{
				for (int k = 0;k < S;k++)
				{
					if (sea[j][k] == 1 && checked[j][k] == 0) // 지도상에 섬이 있고, flood_fill 알고리즘이 진행된 적 없는 곳이라면
					{
						cnt++;
						island(j, k);
					}
				}
			}
			cout << cnt << endl;
		}
	}

	return 0;
}