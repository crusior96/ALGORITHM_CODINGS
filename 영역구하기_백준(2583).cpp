#include<iostream>
#include<algorithm>
using namespace std;
int place[101][101] = {}; //직사각형의 공간이 제공되어지는 부분. 직사각형이 그려지지 않은 곳은 0, 그 외의 값은 1 이상의 값이 저장된다.
int check[101][101] = {}; //비어있는 공간의 면적을 구하기 위해 만든 배열. 빈 공간이 맞다면 1의 값을, 아니면 1의 값이 저장된다.
int flood[101] = {}; //각각의 빈 공간의 면적이 저장되어지는 배열.
int cnt;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 }; //dr과 dc는 빈 공간의 면적을 구하기 위해 만든 배열이다. 자세한 설명은 flood_fill 함수에 제공되어진다.
int M, N;

//M*N 크기의 직사각형 공간에 num 갯수만의 직사각형이 그려진다고 가정하자.
//직사각형이 그려진 곳을 제외한 공간들을 각각 구해서 공간들의 갯수와 각각의 면적값을 오름차순으로 나열하라.

void flood_fill(int y, int x)
{
	check[y][x] = 1;
	cnt++;
	for (int k = 0;k < 4;k++)
	{
		int nx = x + dr[k], ny = y + dc[k];
		//현재의 좌표값에서 상/하/좌/우 방향으로 1칸만큼 이동시키는 for문을 돌린다.
		if ((0 <= ny && ny < M) && (0 <= nx && nx < N)) //바뀐 좌표값이 직사각형의 공간 내부이며
			if(!check[ny][nx] && place[ny][nx]==0) //빈 공간으로써 체크된 곳이 아닌 곳이며 비어있는 공간이라면
			{
				flood_fill(ny, nx); //그 부분의 좌표값을 다시 flood_fill 함수에 넣고 실행한다.
			}
	}
}

int main(void)
{

	int num;
	int x_1, y_1, x_2, y_2; 
	//직사각형 모양 공간의 꼭짓점이 제공되어진다.
	//X_1 & y_1는 직사각형의 좌하단, x_2 & y_2는 직사각형의 우상단 꼭짓점이다.
	cin >> M >> N >> num;
	for (int i = 0;i < num;i++)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int j = y_1;j < y_2;j++)
		{
			for (int k = x_1;k < x_2;k++)
			{
				place[j][k]++;
				//직사각형이 그려진 곳에 해당되는 곳은 1씩 더해준다.
				//직사각형이 그려진 곳에 들어가있지 않은 공간의 값은 0일 것이다.
			}
		}
	}

	int temp = 0;

	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (place[i][j] == 0 && !check[i][j]) //현재 위치가 그려진 직사각형의 내부가 아니고, 빈 공간으로서 체크 된 부분이 아니라면
			{
				cnt = 0;
				flood_fill(i, j);
				//현재의 빈 공간 좌표값을 flood_fill함수에 넣어서 실행한다.
				//flood_fill 함수 진행 후 cnt변수에 저장되어지는 값을 flood배열에 저장한다.
				flood[temp] = cnt;
				temp++;
			}
		}
	}

	sort(flood, flood + temp);
	cout << temp << endl;
	for (int i = 0;i < temp;i++)
	{
		cout << flood[i] << " ";
	}
	cout << endl;
	return 0;

}

//DP에서 파생된 flood_fill 알고리즘의 풀이법.