#include<iostream>
using namespace std;
int T, C, price;
int coins[21] = {};
//T번의 테스트케이스동안 C개의 동전으로 price의 값을 지불하는 방법의 수를 얻어내고자 한다.
//단, 방법의 수는 2^31-1보다 작은 값이며 price의 값은 1만 이하이다.
int main()
{
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> C;
		for (int j = 0;j < C;j++)
		{
			cin >> coins[j];
		}
		cin >> price;
		int ways[10001] = {};
		ways[0] = 1;
		//동전의 가격이 싼 것부터 오름차순으로 나열되어있다는점을 이용하여
		//동전의 원래 값에서부터 price까지 그 동전으로만 도달할 수 있는지를 확인한다.
		//도달할 수 있다면, 시작 위치까지 도달할 수 있는 방법의 수를 도착 위치에 더해주며 그것을 반복 및 누적한다.
		//그렇게 모든 종류의 동전에 for문을 적용시킨다.
		for (int j = 0;j < C;j++)
		{
			for (int k = coins[j];k <= price;k++)
			{
				ways[k] += ways[k - coins[j]];
			}
		}
		cout << ways[price] << endl;
	}
	return 0;
}