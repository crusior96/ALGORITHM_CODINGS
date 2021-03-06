#include<iostream>
#include<algorithm>
using namespace std;
int jadu[1002] = {};
int num[3][1002][32] = {};
//DP를 사용하여 문제를 풀기 위해 만든 3차원배열.
//각각 자두나무 위치 - 떨어지는 시간 - 최대 움직이는 횟수 를 의미한다.

//2개의 나무(위치는 각각 1, 2)에서 N개의 자두가 순서대로 떨어진다.
//떨어지는 나무를 최대한 받는다면 그 갯수는 몇개인가?
//단, 처음에는 나무 1에서 서있으며, W번 자리를 옮길 수 있다.

int main()
{
	int N, W;
	int answer;
	cin >> N >> W;
	for (int i = 1;i <= N;i++)
	{
		cin >> jadu[i];
	}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= W + 1;j++)
		{
			if (jadu[i] == 1)//떨어진 자두의 위치가 1일때
			{
				num[1][i][j] = max(num[1][i - 1][j] + 1, num[2][i - 1][j - 1] + 1);//위치1에서 자두를 받거나 위치2에서 1초 전에 자리이동하여 받았을 때, 둘 중의 최댓값
				num[2][i][j] = max(num[1][i - 1][j - 1], num[2][i - 1][j]);//위치1에서 자두를 받지 않고 1초 전에 위치2로 옮기거나 위치2에 그대로 있을때, 둘 중의 최댓값
			}
			else//떨어진 자두의 위치가 2일때
			{
				if (i == 1 && j == 1)
					continue;
				num[1][i][j] = max(num[2][i - 1][j - 1], num[1][i - 1][j]);//위치2에서 자두를 받지 않고 1초 전에 위치1로 옮기거나 위치1에 그대로 있을때, 둘 중의 최댓값
				num[2][i][j] = max(num[1][i - 1][j - 1] + 1, num[2][i - 1][j] + 1);//위치1에서 1초 전에 자리이동하여 받거나 위치2에서 자두를 받았을 때, 둘 중의 최댓값
			}
		}
	}

	for (int i = 1;i <= W + 1;i++)
	{
		answer = max(answer, max(num[1][N][i], num[2][N][i]));
	}
	cout << answer << endl;
	return 0;
}
