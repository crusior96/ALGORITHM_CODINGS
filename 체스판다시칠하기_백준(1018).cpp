#include<iostream>
#include<string>
using namespace std;
char chessboard[52][52] = {};

//단순 for문을 이용하는것이 시간만 잘 지키면 편할수도 있는 문제.
//시간복잡도를 설계하는 방식에 대해서도 공부 핼 필요가 있었다.

//체스판의 가로 세로가 8보다 크거나 같고 50보다 작거나 같은 정수로 이루어져있고 그 위에 흑백 중 임의의 색으로 칠해져 있을 때
//8*8 크기의 체스판을 따로 뽑아내어 체스판의 규칙(흑백이 번갈아 보이는 것)대로 보이게 하려면 체스판 위에 몇 번 새롭게 덧칠해야하는가?

int main()
{
	int M, N;
	int color = 2500; //최대한 칠해야 하는 값을 저장해두는 변수. 최대 50*50번 칠해야 하는 경우도 생기기에 2500으로 초기값 지정.
	int temp_B = 0;
	int temp_W = 0;
	string S;
	cin >> M >> N;
	for (int i = 1;i <= M;i++)
	{
		cin >> S;
		for (int j = 1;j <= S.length();j++)
		{
			chessboard[i][j] = S[j];
		}
	}

	//i와 j는 체스판을 8*8로 떼어낼 때, 체스판의 시작점인 왼쪽 위 좌표를 뜻한다.
	//k와 l은 좌표 (i,j)를 기준으로 8*8로 체스판이 떼어져있을 때, 그 체스판 위의 좌표들을 (k,l)로 나타낸다.
	//체스판에 어떤 색이 칠해져야하는지에 대한 기준을 정할 때, (k + l - i - j)%2의 값을 기준으로 좌표가 가져야 하는 색을 판단해준다.
	for (int i = 1;i <= M - 7;i++)
	{
		for (int j = 1;j <= N - 7;j++)
		{
			//체스판의 왼쪽 위 시작점이 흰색으로 시작하는 체스판을 만들 경우 temp_B 변수에 덧칠해야 하는 횟수 저장
			for (int k = i;k < i + 8;k++)
			{
				for (int l = j;l < j + 8;l++)
				{
					if ((k + l - i - j) % 2 == 1&&chessboard[k][l]=='B')
					{
						temp_B++;
					}
					else if ((k + l - i - j) % 2 == 0 && chessboard[k][l] == 'W')
					{
						temp_B++;
					}
				}
			}
			//체스판의 왼쪽 위 시작점이 검은색으로 시작하는 체스판을 만들 경우 temp_W 변수에 덧칠해야 하는 횟수 저장
			for (int k = i;k < i + 8;k++)
			{
				for (int l = j;l < j + 8;l++)
				{
					if ((k + l - i - j) % 2 == 1 && chessboard[k][l] == 'W')
					{
						temp_W++;
					}
					else if ((k + l - i - j) % 2 == 0 && chessboard[k][l] == 'B')
					{
						temp_W++;
					}
				}
			}
			//temp_B와 temp_W 중 최솟값을 color변수에 저장해둔다.
			if (temp_B >= temp_W)
			{
				if (color > temp_W)
					color = temp_W;
			}
			else if (temp_B < temp_W)
			{
				if (color > temp_B)
					color = temp_B;
			}
			temp_W = 0;
			temp_B = 0;
		}
	}
	cout << color << endl;
	return 0;
}