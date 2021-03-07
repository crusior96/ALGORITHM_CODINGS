#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//T번의 테스트케이스동안 나이트가 (nx,ny)에서 (gx,gy)로 이동가능한지, 가능하다면 그 최소 이동횟수를 출력하라.
//체스판의 길이는 N이며, 매 테스트케이스마다 다르게 입력받는다.

int chessboard[301][301] = {}; //나이트가 그 위치까지 도착하기 위해 움직인 횟수를 저장해두는 배열. 
int checked[301][301] = {}; //나이트가 도착했었던 위치. 최솟값만을 저장하기 위해 최초로 저장된 값만을 넣어둔다.
queue<int> xpoint;
queue<int> ypoint; 
//BFS를 사용하기 위해 queue를 사용하였다.
//매 주어지는 좌표값을 각각의 queue에 저장하면
int temp_x, temp_y;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,2,1,-1,-2 }; //dx와 dy는 나이트의 8가지 이동방향을 저장해둔 배열이다.
int complete = 0; //목표지점까지 도달했으면 1, 아니면 0의 값을 가지게 된다.

void checker(int x, int y, int goal_x, int goal_y, int length)
{
	xpoint.push(x);
	ypoint.push(y);
	chessboard[x][y] = 0;
	checked[x][y] = 1;
	while (!xpoint.empty() && !ypoint.empty())
	{
		temp_x = xpoint.front();
		xpoint.pop();
		temp_y = ypoint.front();
		ypoint.pop();
		if (temp_x == goal_x && temp_y == goal_y) //목표 위치에 도착하게 되면 while문 종료
		{
			cout << chessboard[temp_x][temp_y] << endl;
			complete = 1;
			break;
		}
		//이제 목표 위치가 아니라서 for문을 돌리는 경우
		for (int i = 0;i < 8;i++)
		{
			int xx = temp_x + dx[i];
			int yy = temp_y + dy[i]; //각각의 x축좌표와 y축좌표를 나이트의 이동규칙에 따라 이동시킨 임시값을 xx와 yy에 저장시켜둔다.
			if (checked[xx][yy] == 0 && xx >= 0 && xx < length&&yy >= 0 && yy < length) //방문하지 않았던 곳이며 체스판을 벗어나지 않는 범위의 좌표라면
			{
				checked[xx][yy] = 1;
				xpoint.push(xx);
				ypoint.push(yy);
				chessboard[xx][yy] = chessboard[temp_x][temp_y] + 1; //지금 위치까지의 이동했던 횟수 + 1의 값을 이동된 위치의 chessboard 배열에 저장해둔다.
			}
		}
	}

}

int main()
{
	int T, N;
	int nx, ny, gx, gy;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> N;
		cin >> nx >> ny;
		cin >> gx >> gy;

		if (nx == gx && ny == gy)
		{
			cout << 0 << endl;
		}
		else
		{
			checker(nx, ny, gx, gy, N);
			if (complete == 0)
			{
				cout << 0 << endl;
			}
			memset(chessboard, 0, sizeof(chessboard));
			memset(checked, 0, sizeof(checked));
			//백준에서 memset을 사용하려면 cstring헤더를 추가시켜둬야한다. 그렇지않으면 컴파일에러 발생.
			while (!xpoint.empty())
			{
				xpoint.pop();
			}
			while (!ypoint.empty())
			{
				ypoint.pop();
			}
		}
	}
	return 0;
}
