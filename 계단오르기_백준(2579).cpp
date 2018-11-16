#include<iostream>
#include<algorithm>
using namespace std;

//N개의 계단에는 각각 점수들이 있다.
//계단을 오르는 규칙을 따르며 올라갈 경우, 최대한 얻을 수 있는 점수는 얼마인가?
//계단을 오르는 규칙에는 1. 한번에 1개 또는 2개 계단을 오를 수 있다. 
//2. 연속된 3개의 계단을 밟아서는 안 된다. 3. 마지막 계단은 꼭 밟아야 한다.
//계단의 갯수는 300 이하의 자연수이며 계단에 쓰인 점수는 10000 이하의 자연수이다

int main()
{
	int N, stair_pt;
	int stairs[310] = {}; //계단의 점수가 저장되는 배열
	int max_pt[310] = {}; //계단을 오르면서 얻을 수 있는 최댓값이 저장되는 배열.
	int cmp_status[4] = {};
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		cin >> stair_pt;
		stairs[i] = stair_pt;
	}
	

	//계단의 총 갯수가 3개 이하인 상황에서는 다른 종류의 점화식을 돌려야 한다.
	//또한, 계단이 1개에서 3계단을 올랐을 때의 계산법도 다르기때문에 처음 1~3번째 계단까지 도달하는 최댓값을 구하는 점화식은
	//다른 종류의 점화식을 사용하여 구해야 한다.
	for (int i = 1;i <= 3 && i <= N;i++)
	{
		if (i != 3)
		{
			//첫 번째, 두 번째 계단은 각각 첫 번째 계단값, 첫 번째와 두 번째 계단을 밟고 온 값을 저장해준다.
			max_pt[i] = max_pt[i - 1] + stairs[i];
		}
		else
		{
			//세 번째 계단은 각각 세 번째 계단과 첫 번째 계단, 세 번째 계단과 두 번째 계단을 밟고 온 값을 비교하여
			//최댓값을 저장해준다. 여기까지가 초기값을 지정해주는 단계라 볼 수 있다.
			max_pt[i] = max(stairs[i] + max_pt[i - 2], stairs[i] + stairs[i - 1]);
			
		}
	}

	for (int i = 4;i <= N;i++)
	{
		//4번째 계단을 오를 때에서부터 적용하는 일반적인 점화식.
		//i번째 계단을 밟을때의 최댓값은 두 가지 경우를 비교하여 구한다.
		//1. 이전 계단(i-1번째 계단)을 밟지 않고 1칸 건너뛰어서 온 경우.
		//2. 이전 계단(i-1번째 계단)을 밟고 올 수 밖에 없었던 경우. 이때에는 i-2번째 계단을 밟아서 오는 경우밖에 없다.
		//그 외의 방법은 최대한 계단을 밟아서 점수를 얻어야 하는 상황에 위배되므로 배제한다.
		max_pt[i] = max(stairs[i] + max_pt[i - 2], stairs[i] + stairs[i - 1] + max_pt[i - 3]);
	}
	cout << max_pt[N] << endl;
	return 0;
}