#include<iostream>
using namespace std;

//N가지 종류의 동전을 사용하여 K원을 만들려고 한다. (0 < N <=100 / 0 < K <= 10000)
//이때, 각각의 동전들을 사용한 값을 최소로 할 때 그 값을 구하여라. 각각의 동전은 10만 이하의 가치를 지닌다.
//만약 K원을 만들수가 없다면 -1을 출력하면 된다.

int main()
{
	int N, K;
	unsigned long long int prices[101] = {};
	unsigned long long int ways[100001] = {};

	cin >> N >> K;

	for (int i = 1;i <= N;i++)
	{
		unsigned long long int temp;
		cin >> temp;
		prices[i] = temp;
	}

	//i원을 만들기 위한 최솟값을 구하기위해 극단적으로 동전들이 1원일때 10만원을 만들 수 있는 최솟값인 10만에 + 1한 값 저장
	for (int i = 1;i <= K;i++)
	{
		ways[i] = 100001;
	}


	for (int i = 1;i <= N;i++)
	{
		//비교 횟수를 최소화하기 위하여 현재 동전의 가치 ~ 목표값까지를 비교범위로 조정한다.
		for (int j = prices[i];j <= K;j++)
		{
			//j - prices[i] + 1의 의미
			//현재 위치는 이번에 사용할 동전을 이전 동전의 가치만큼의 위치에서 그 동전을 1번 더 사용하여
			//그만큼의 동전사용횟수가 누적되었음을 의미한다.
			if (ways[j] <= ways[j - prices[i]] + 1)
			{
				ways[j] = ways[j];
			}
			else if(ways[j]>ways[j-prices[i]] + 1)
			{
				ways[j] = ways[j - prices[i]] + 1;
			}
		}
	}

	if (ways[K] == 100001)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ways[K] << endl;
	}
	return 0;
}