#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//N*N크기의 정사각형 판에 다양한 색의 사탕들이 있다.
//사탕은 한 줄에 나열되어있는 동일한 색상의 사탕(동일행, 동일열)만 연속으로 먹을 수 있다.
//여기서 한 쌍의 이웃한 사탕의 위치를 서로 바꿔서 연속으로 최대한 먹을 수 있는 사탕의 갯수는?

int main()
{
	char candyshop[53][53] = {}; //사탕의 색깔이 저장되는곳.
	int N;
	string candyline;
	int max_candy = 0;
	int temp_max = 0;
	char now_max; //연속으로 사탕을 먹는 과정이 시작될 때, 어떤 사탕을 기준으로 먹는지 알려주는 지표.
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> candyline;
		for (int j = 0;j < N;j++)
		{
			candyshop[i][j] = candyline[j];
		}
		//사탕의 색깔을 문자열로 받아서 char단위로 나눠서 candyshop배열에 저장한다.
	}

	//사탕의 배치를 바꾸기 전, 가로줄 방향으로 사탕을 먹을 때, 연속으로 최대한 먹을 수 있는 갯수를 구한다.
	for (int i = 0;i < N;i++)
	{
		temp_max = 0;
		now_max = candyshop[i][0]; //비교 시작시, 첫번째 칸의 사탕 색깔을 기준으로 비교한다.
		for (int j = 0;j < N;j++)
		{
			if (candyshop[i][j] == now_max) //앞에 나온 색깔의 사탕과 색이 같다면
			{
				temp_max++; //연속으로 먹을 수 있는 갯수 증가.
			}
			else if(candyshop[i][j]!=now_max) //앞에 나온 색깔의 사탕과 색이 다르다면
			{
				if (max_candy < temp_max) //연속으로 먹을 수 있는 갯수가 현재의 최댓값보다 크다면
				{
					max_candy = temp_max; //최댓값을 지금 구한 연속으로 먹을 수 있는 갯수로 바꾼다.
					now_max = candyshop[i][j]; //다른 색깔의 사탕을 기준으로 다시 비교를 시작한다.
					temp_max = 1;
				}
				else
				{
					temp_max = 1;
					now_max = candyshop[i][j];
					//그렇지 않다면, 이번에 나온 사탕의 색깔을 기준으로 다시 비교한다.
				}
			}
		}
		if (max_candy < temp_max)
		{
			max_candy = temp_max;
			temp_max = 1;
		}

	}

	//사탕의 배치를 바꾸기 전, 세로줄 방향으로 사탕을 먹을 때, 연속으로 최대한 먹을 수 있는 갯수를 구한다. 
	//최댓값을 구하는 방법에 대한 주석은 위와 동일하여 생략.
	for (int i = 0;i < N;i++)
	{
		temp_max = 0;
		now_max = candyshop[0][i];
		for (int j = 0;j < N;j++)
		{
			if (candyshop[j][i] == now_max)
			{
				temp_max++;
			}
			else if (candyshop[j][i] != now_max)
			{
				if (max_candy < temp_max)
				{
					now_max = candyshop[j][i];
					max_candy = temp_max;
					temp_max = 1;
				}
				else
				{
					now_max = candyshop[j][i];
					temp_max = 1;
				}
			}
		}
		if (max_candy < temp_max)
		{
			max_candy = temp_max;
			temp_max = 1;
		}
	}

	//가로줄을 기준으로 이웃한 한 쌍의 사탕의 위치를 서로 바꿨을때, 최대한 먹을 수 있는 최댓값을 구한다.
	//이때, 사탕의 위치를 바꾸는 과정만 가로줄을 기준으로 진행되고, 사탕을 먹을 수 있는 최댓값은 가로, 세로방향 둘 다 구해본다.
	for (int i = 0; i < N;i++)
	{
		for (int j = 0;j < N - 1;j++)
		{
			char temp = candyshop[i][j];
			candyshop[i][j] = candyshop[i][j + 1];
			candyshop[i][j + 1] = temp;
			//서로 이웃하는 사탕의 위치를 바꿔준 후, 최댓값을 구하는 과정을 진행한다.
			now_max = candyshop[i][0];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[i][k] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[i][k] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[i][k];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[i][k];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[0][j];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[k][j] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[k][j] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[k][j];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[k][j];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[0][j+1];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[k][j+1] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[k][j+1] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[k][j+1];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[k][j+1];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			temp = candyshop[i][j + 1];
			candyshop[i][j + 1] = candyshop[i][j];
			candyshop[i][j] = temp;
		}
	}

	//이번에는 세로 줄을 기준으로 이웃하는 한 쌍의 사탕의 위치를 바꿔본다.
	//마찬가지로, 사탕의 위치만 세로 줄을 기준으로 바꾸고, 연속으로 먹을 수 있는 최대의 사탕의 갯수는 사로, 세로를 기준으로 구한다.
	for (int i = 0; i < N-1;i++)
	{
		for (int j = 0;j < N;j++)
		{
			char temp = candyshop[i][j];
			candyshop[i][j] = candyshop[i+1][j];
			candyshop[i+1][j] = temp;
			now_max = candyshop[i][0];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[i][k] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[i][k] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[i][k];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[i][k];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[i+1][0];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[i+1][k] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[i+1][k] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[i+1][k];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[i+1][k];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[0][j];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[k][j] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[k][j] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[k][j];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[k][j];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			temp = candyshop[i + 1][j];
			candyshop[i + 1][j] = candyshop[i][j];
			candyshop[i][j] = temp;
		}
	}

	cout << max_candy << endl;
	return 0;
}
