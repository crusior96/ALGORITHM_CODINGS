#include<iostream>
#include<cstring>
using namespace std;
int field[101][101] = {}; //땅의 높이가 저장되어지는 배열.
int wet[101][101] = {}; //땅이 비에 잠겼는지 체크하는 배열. 잠겼다면 1, 아니면 0으로 저장되어진다.
int checked[101][101] = {}; //flood_fill 알고리즘이 진행되어진 부분인지 확인하는 배열. 확인되어졌다면 1, 아니면 0으로 저장되어진다.
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;
int N;

//N*N의 땅에 장마가 온다고 가정하자.
//N*N의 땅에는 최대 100의 높이를 지닌 땅들이 다양하게 존재한다.
//장마가 땅의 최대 높이까지 강수량을 서서히 높인다고 가정할 때
//비에 잠기지 않은 땅들이 영역을 이루는 최대 갯수를 구하시오
//단, 강수량의 높이는 0부터 1씩 늘어나고, 강슈랑과 땅의 높이가 같다면 그 땅은 물에 잠기게 된다.


//플러드 필을 사용한 알고리즘. 영역 구하는 문제에서 애용되어진다.
void flood_fill(int x, int y)
{
	checked[x][y] = 1;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ((0 <= nx && nx < N) && (0 <= ny && ny < N))
		{
			//flood_fill 함수가 진행되어진 곳이 아니며 땅이 젖은 곳이 아니라면 flood_fill함수를 실행시켜준다.
			if (checked[nx][ny] == 0 && wet[nx][ny] == 0)
			{
				flood_fill(nx, ny);
			}
		}
	}
}

int main()
{
	int max = 0;
	//field에 있는 땅의 높이들 중 최댓값을 저장해두는 변수. 
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> field[i][j];
			if (max < field[i][j])
			{
				max = field[i][j];
			}
		}
	}

	//빗물의 높이가 0에서부터 땅의 최대 높이까지 올라가게 되므로 for문도 0 ~ max까지만 반복되어지면 된다.
	for (int i = 0;i <= max;i++)
	{
		memset(checked, 0, sizeof(checked));
		//빗물의 높이에 따른 flood_fill함수를 체크한 이후, 다른 빗물의 높이일 때 새로이 flood_fill 실행여부를 체크하기 위해 checked 배열을 초기화시켜준다.
		int temp = 0;
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (i >= field[j][k])
				{
					//땅의 높이가 현재의 빗물 높이보다 낮거나 같다면, 빗물에 잠겼다는 뜻으로 wet 배열에 1로 저장해둔다.
					//이 배열은 어차피 높이가 갈 수록 높아지므로 굳이 초기화시켜 줄 필요는 없다.
					wet[j][k] = 1;
				}
			}
		}

		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (wet[j][k] == 0 && checked[j][k] == 0)
				{
					temp++;
					flood_fill(j, k);
				}
			}
		}

		if (temp > answer)
		{
			answer = temp;
		}
	}

	cout << answer << endl;
	return 0;
}