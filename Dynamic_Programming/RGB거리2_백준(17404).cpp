#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
int costs[3][1002] = {};		//costs[i][j] : j번째 단지에 i를 칠했을 때, 지금까지 쓰인 최소 비용
int paints[3][1002] = {};		//paints[i][j] : j번째 단지를 i로 칠했을 때 쓰이는 비용

//3개의 숫자들을 비교해서 최솟값을 구할 때 쓴 함수
//괜히 min함수 자주 쓰기 싫어서 만들었다
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

//1000개의 단지에 색을 칠한다고 가정하자
//이때, n번째 단지에 색을 칠할 때, n+1번째 단지랑 n-1번째 단지랑은 서로 같은 색이면 안된다
//또한, 각각의 단지에 색을 칠할 때 소모되는 비용이 제각각이다
//위 조건들을 모두 만족한 채 색을 칠했을 경우에 쓰이는 최소 비용을 구하여라
//이전에 풀었던 RGB문제와 비슷하지만, 이 경우엔 앞뒤 1칸 거리로도 이웃이기 때문에 제약을 걸어 진행했다
//총 3번의 DP를 돌리는데 각각의 경우, 맨 마지막 단지의 색을 무엇으로 칠할지 정해 둔 다음
//맨 첫번쨰 단지에 칠하게 될 색에 깔끔하게 DP 조건을 걸 수 있게 된다


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	int answer = 1000005;
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> paints[j][i];
		}
	}



	//N이 2 이하인 경우엔 총 6가지 비교 경우를 찾아서 최솟값을 구한다
	if (N <= 2) {
		int temp1 = get_min(paints[0][0] + paints[1][1], paints[0][0] + paints[1][2], paints[0][1] + paints[1][0]);
		int temp2 = get_min(paints[0][1] + paints[1][2], paints[0][2] + paints[1][0], paints[0][2] + paints[1][1]);
		answer = min(temp1, temp2);
	}
	else {
		for (int k = 0;k < 3;k++) {
			int case_1;
			int case_2;
			int cost_test[3][1002] = {};

			//k값에 따라 이번에 맨 마지막 구간에 칠하게 된 색과, 그 다음층에 칠하게 될 색의 최소 비용을 정하게 된다
			if (k == 0) {
				cost_test[0][N - 2] = 1000005;
				cost_test[1][N - 2] = paints[1][N - 2] + paints[0][N - 1];
				cost_test[2][N - 2] = paints[2][N - 2] + paints[0][N - 1];
			}
			else if (k == 1) {
				cost_test[0][N - 2] = paints[0][N - 2] + paints[1][N - 1];
				cost_test[1][N - 2] = 1000005;
				cost_test[2][N - 2] = paints[2][N - 2] + paints[1][N - 1];
			}
			else if (k == 2) {
				cost_test[0][N - 2] = paints[0][N - 2] + paints[2][N - 1];
				cost_test[1][N - 2] = paints[1][N - 2] + paints[2][N - 1];
				cost_test[2][N - 2] = 1000005;
			}

			//만약 N의 값이 위의 과정을 하고도 계층이 남는 3 초과인 경우엔
			//본격적인 DP를 진행하게 된다
			//현 시점(i - 1 계층)의 cost_test값을 j로 칠한다면, 이전 계층(i)에 있는
			//j가 아닌 다른 값의 cost_test값들을 비교해서 paints[j][i-1]과 더한다
			if (N > 3) {
				for (int i = N - 2;i > 1;i--)
				{
					for (int j = 0;j < 3;j++)
					{
						cost_test[j][i - 1] = paints[j][i - 1] + min(cost_test[(j + 1) % 3][i], cost_test[(j + 2) % 3][i]);
					}
				}
			}

			//이제 k의 값에 따라 맨 첫 구간에서 더하게 되는 값이 정해지게 된다
			//k가 0인 경우, 맨 첫 구간에선 paints[1][0], paints[2][0]을 강제로 사용해야만 하기 떄문에
			//위 규칙에 맞게 두 번째 구간에서부터 값을 가져와서 진행한다
			//이후 최솟값을 answer와도 비교하여 answer에 저장한다
			if (k == 0) {
				case_1 = min(paints[1][0] + cost_test[0][1], paints[1][0] + cost_test[2][1]);
				case_2 = min(paints[2][0] + cost_test[0][1], paints[2][0] + cost_test[1][1]);
				answer = get_min(answer, case_1, case_2);
			}
			else if (k == 1) {
				case_1 = min(paints[0][0] + cost_test[1][1], paints[0][0] + cost_test[2][1]);
				case_2 = min(paints[2][0] + cost_test[0][1], paints[2][0] + cost_test[1][1]);
				answer = get_min(answer, case_1, case_2);
			}
			else if (k == 2) {
				case_1 = min(paints[1][0] + cost_test[0][1], paints[1][0] + cost_test[2][1]);
				case_2 = min(paints[0][0] + cost_test[1][1], paints[0][0] + cost_test[2][1]);
				answer = get_min(answer, case_1, case_2);
			}
		}
	}

	cout << answer << '\n';
	return 0;
}