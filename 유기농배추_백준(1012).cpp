#include<iostream>
#include<algorithm>
using namespace std;
int radish[55][55] = {}; //배추의 유무를 확인하는 배열
int check[55][55] = {}; //이미 플로드필 함수를 적용시켰는지 확인해두는 배열
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int cnt = 0;
int h, w;

//플로드 필을 이용하여 영토의 '갯수'를 구하는 문제.
//h*w 크기의 밭이 있을 때, 배추가 심겨져 있는곳을 1, 아닌곳으로 0으로 입력한다고 가정하자.
//유기농 벌레가 이우한 배추 사이는 이동할 수 있다면, 벌레를 최소한 몇 개 사용하면 될까?

void flood_fill(int x, int y)
{
	check[x][y] = 1;
	for (int k = 0;k < 4;k++)
	{
		int nx = x + dr[k], ny = y + dc[k];
		if ((0 <= ny && ny < h) && (0 <= nx && nx < w))
			if (check[nx][ny] == 0 && radish[nx][ny] == 1)
			{
				flood_fill(nx, ny);
			}
	}
}

int main()
{
	int N, num, x, y;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		//N회 반복해야 하는 문제이므로, for문이 시작할때마다 초기화해준다.
		memset(radish, 0, sizeof(radish));
		memset(check, 0, sizeof(check));
		cnt = 0;
		cin >> w >> h >> num;
		for (int j = 0;j < num;j++)
		{
			cin >> x >> y;
			radish[x][y] = 1;
		}


		for (int k = 0;k < w;k++)
		{
			for (int j = 0;j < h;j++)
			{
				//배추가 심겨져있고 플로드 필 체크가 되어지지 않은 위치라면
				if (radish[k][j] == 1 && check[k][j] == 0)
				{
					//벌레를 놓아야 할 새로운 공간++
					//플로드 필 함수를 실행시켜준다.
					cnt++;
					flood_fill(k, j);

				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}