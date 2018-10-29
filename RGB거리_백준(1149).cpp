#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//일렬로 N개의 집이 나열되어있는데, 이 집을 빨강, 파랑, 초록색으로 칠하려고 한다.
//서로 이웃하는 집은 같은 색깔로 색칠할 수 없다는 조건이 있다.
//각각 N개의 집은 빨강, 파랑, 초록색으로 칠하는 비용이 서로 다르다. 이때, 최소한의 비용으로 모든 집을 칠하는 방법은?
//단, 처음집과 마지막 집은 서로 이웃이 아니다.

int get_min(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return a;
		else
			return c;
	}
	else
	{
		if (b <= c)
			return b;
		else
			return c;
	}
}

int main()
{
	//끝부분에 색칠을 빨강, 파랑, 초록으로 했을 경우를 초기값으로 지정하여
	//처음 부분으로 갈 때 까지 색칠하는데 드는 비용을 계산해낸다.
	//costs배열은 색칠한 비용의 값이 누적되는 공간이며, paints배열은 각각의 집에 3가지 색깔로 색칠할 때의 비용을 저장한다.
	int costs[1001][3] = {};
	int paints[1001][3] = {};
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			int temp;
			cin >> temp;
			paints[i][j] = temp;
		} 
	}

	costs[N - 1][0] = paints[N - 1][0];
	costs[N - 1][1] = paints[N - 1][1];
	costs[N - 1][2] = paints[N - 1][2];
	//초기값 지정.

	if (N <= 2)
	{
		int temp1 = get_min(paints[0][0], paints[0][1], paints[0][2]);
		int temp2 = get_min(paints[1][0], paints[1][1], paints[1][2]);
		cout << temp1 + temp2 << endl;
		//N이 2보다 작거나 같은 경우가 예외이다.
		//처음집과 마지막집은 서로 이웃이 아니라는 조건이 있기 때문에
		//처음집과 마지막집에서의 색칠시 최소 비용을 합쳐주면 된다.
	}
	else
	{
		for (int i = N;i > 0;i--)
		{
			{
				for (int j = 0;j < 3;j++)
				{
					costs[i - 1][j] = paints[i - 1][j] + min(costs[i][(j + 1) % 3], costs[i][(j + 2) % 3]);
					//N이 2보다 큰 경우에 적용된다.
					//i-1번째 집에 어떤 색깔로 색칠한다면, i번째 집에서 그것을 제외한 다른 색깔을 색칠할 때(2가지) 최소한의 비용이 든 것을 더해준다.
				}
			}
		}
		cout << get_min(costs[0][0], costs[0][2], costs[0][1]) << endl;
		//최종적으로 1번째 집까지 도착했을 경우 최솟값을 출력해준다.
	}
	return 0;
}