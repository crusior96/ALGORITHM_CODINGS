#include<iostream>
#include<string>
using namespace std;


//R,G,B 3개의 색깔로 이루어진 그림이 N*N짜리 판에 그려져있다.
//1*1의 정사각형을 기준으로 그림이 나뉘어져있을때, 3개의 색깔로 각각 이루어진 영역의 갯수를 구하여라.
//이때, 적록색맹인 사람은 R과 G가 같은것으로 보인다.

char maps[102][102] = {};	//그림이 저장되는 배열
int checked[102][102] = {};	//색맹이 아닌 사람의 DFS탐색여부 저장공간. 탐색이 되었으면 1이 저장된다.
int checked2[102][102] = {};//색맹인 사람의 DFS탐색여부 저장공간. 탐색이 되었으면 1이 저장된다.
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;

//색맹이 아닌 사람의 DFS
void normal(int a, int b, char x)
{
	//DFS탈출조건 : DFS탐색이 이미 진행되었던 곳이면 실행종료
	if (checked[a][b] != 1)
	{
		checked[a][b] = 1;
		for (int i = 0;i < 4;i++)
		{
			int temp_x = a + dx[i];
			int temp_y = b + dy[i];
			//상하좌우로 각각 1칸 이동한 좌표가 N*N의 범위안에 있을때
			if ((temp_x >= 0 && temp_x < N) && (temp_y >= 0 && temp_y < N))
			{
				char temp = maps[temp_x][temp_y];
				//이전에 발견한 색깔과 같은 색일경우
				if (temp == x)
				{
					normal(temp_x, temp_y, temp);
				}
			}
		}
	}
}

//색맹인 사람의 DFS
void abnormal(int a, int b, char x)
{
	if (checked2[a][b] != 1)
	{
		checked2[a][b] = 1;
		for (int i = 0;i < 4;i++)
		{
			int temp_x = a + dx[i];
			int temp_y = b + dy[i];
			if ((temp_x >= 0 && temp_x < N) && (temp_y >= 0 && temp_y < N))
			{
				char temp = maps[temp_x][temp_y];
				//적록색맹의 경우엔 'R'과 'G'를 같은것으로 인식하므로
				//for문에는 이전좌표의 색과 지금좌표의 색이 둘다 'B'이거나
				//이전좌표의 색과 지금좌표의 색이 둘다 'B'가 아닌 경우를 찾는다.
				if (x == 'B' && temp == 'B')
				{
					abnormal(temp_x, temp_y, temp);
				}
				else if (x != 'B'&&temp != 'B')
				{
					abnormal(temp_x, temp_y, temp);
				}
			}
		}
	}
}

int main()
{
	int case1 = 0;
	int case2 = 0;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> maps[i][j];
		}
	}

	//DFS탐색이 안된 곳이라면 그 위치의 좌표 및 색깔을 normal함수에 입력한다.
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (checked[i][j] == 0)
			{
				case1++;
				normal(i, j, maps[i][j]);
			}
		}
	}

	//DFS탐색이 안된 곳이라면 그 위치의 좌표 및 색깔을 abnormal함수에 입력한다.
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (checked2[i][j] == 0)
			{
				case2++;
				abnormal(i, j, maps[i][j]);
			}
		}
	}

	cout << case1 << " " << case2 << endl;
	return 0;
}