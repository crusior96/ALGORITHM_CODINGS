#include<iostream>
#include<algorithm>
using namespace std;

//일렬로 N개의 포도주가 놓여있는 상황속에서 2가지 규칙을 지킨채로 최대한의 포도주를 마신다면 최대 얼만큼 마실수 있는가?
//1. 포도주는 연속으로 놓여진 3개의 잔을 마실 수는 없다. 
//2. 포도주 잔을 선택하면, 그 잔에 있는것은 다 먹고 잔을 제자리에 두어야한다.

int main()
{
	int N; //1<=N=10000
	int podoju[10001][3] = {}; 
	/*
	podoju[i][0] : winery[i]의 포도주를 마시지 않은 상태. 연속으로 마신 잔의 수가 초기화된다.
	podoju[i][1] : winery[i]의 포도주를 마신 상태. 연속으로 마신 잔의 수는 1.
	podoju[i][2] : winery[i]와 winery[i-1]의 포도주를 마신 상태. 연속으로 마신 잔의 수는 2.
	*/
	int winery[10001] = {}; //N개의 잔 안에 들어있는 포도주의 양 저장.
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		cin >> winery[i];
	}

	podoju[1][1] = winery[1];
	podoju[2][0] = winery[1];
	podoju[2][1] = winery[2];
	podoju[2][2] = winery[1] + winery[2];
	//기본적으로 지정해주는 초기값. 3잔을 연속으로 마시면 안 되는 규칙으로 인해 초기 2잔까지의 값은 규칙에 맞춰서 초기값을 만들어준다.
	

	for (int i = 3;i <= N;i++)
	{
		podoju[i][0] = max(max(podoju[i - 1][2], podoju[i - 1][1]), podoju[i - 1][0]); 
		//winery[i]의 포도주를 건너뛰겠다는 뜻. 2잔을 마신상태, 1잔을 마신상태, 누적 마신횟수가 초기화된 상태를 비교한다.
		podoju[i][1] = podoju[i - 1][0] + winery[i];
		//winery[i]의 포도주를 마신다는 뜻. winery[i-1]의 포도주는 마시지 않았다.
		podoju[i][2] = podoju[i - 1][1] + winery[i]; 
		//winery[i]의 포도주를 마신다는 뜻. winery[i-1]의 포도주를 마신 상태이다. 
	}


	cout << max(max(podoju[N][0], podoju[N][1]),podoju[N][2]) << endl;
	//최종적으로 N개의 포도주잔까지 도달했을 때, 규칙상 혹은 효율을 따져서 그 잔을 안 마시거나,
	//그 잔을 마신게 연속해서 1번째 잔이 되었거나, 그 잔을 마신게 연속해서 2번째 잔이 되는 경우를 비교하여 최댓값을 출력한다.

	return 0;
}