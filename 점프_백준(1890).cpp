#include<iostream>
using namespace std;


//N*N칸의 모눈종이칸이 있다. 왼쪽 위에서 오른쪽 아래로 가는 경로의 모든 수를 구하여라.
//점프를 할땐 오른쪽이나 아래로만 가능하며, 점프도중 방향을 바꿀 수는 없다.
//점프 해야 하는 칸의 수는 본인이 서 있는 모눈종이칸의 수이다.
int main()
{
	int N, map_point;
	int maps[101][101] = {};//모눈종이칸의 숫자모음
	unsigned long long int ways[101][101] = {};//각 모눈종이칸까지 도달할 수 있는 가짓수 모음
	cin >> N;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> map_point;
			maps[i][j] = map_point;
		}
	}
	
	ways[0][0] = 1;//초기값설정. 이 위치에서 이 위치값만큼 오른쪽 or 아랫쪽에 있는 위치까지 도달할 수 있는 방법은 왼쪽 위에서 출발하는 방법밖에 없다.

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (ways[i][j] != 0 && maps[i][j]!=0)//각 모눈종이까지 도달하는 방법의 수가 하나라도 있거나 이동할 수 있는 칸이 정해져있을경우
			{
				int temp = maps[i][j];//임시변수에 이동해야하는 칸을 입력.
				if (i + temp <= N - 1)//
				{
					ways[i + temp][j] += ways[i][j];
				}


				if (j + temp <= N - 1)
				{
					ways[i][j + temp] += ways[i][j];
				}

				//모눈종이 밖으로 벗어나지 않을 만큼만 이동하게 된다면
				//오른쪽 또는 아랫쪽에 그 거리(temp)만큼 떨어진 칸의 ways 배열값에 ways[i][j]값을 더해준다.
			}
			else if (ways[i][j] == 0)
			{
				continue;
			}
		}
	}

	cout << ways[N - 1][N - 1] << endl;
	return 0;
}