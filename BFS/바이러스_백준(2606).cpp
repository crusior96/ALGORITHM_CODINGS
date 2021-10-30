#include<iostream>
#include<queue>
using namespace std;

//N개의 컴퓨터가 M가지의 연결루트를 가진 채로 있다.
//첫번째(1번)컴퓨터가 웜바이러스에 감염된 경우, 경로를 통해 감염될 수 있는 컴퓨터는 총 몇대인가?
//경로설정방식 : N1, N2 (N1과 N2는 서로 연결되어있다는 뜻)


int main()
{
	queue<int> VIRUS;
	int CPU[102][102] = {};
	int INFECTED[102] = {};
	int sum = 0;
	int N, M, tmp1, tmp2;
	cin >> N >> M;
	for (int i = 1;i <= M;i++)
	{
		cin >> tmp1 >> tmp2;
		CPU[tmp1][tmp2] = 1;
		//경로를 2차원배열에 저장해둔다. 경로가 존재하면 1, 아니면 0.
	}

	VIRUS.push(1);
	INFECTED[1] = 1;
	//감염된 경험이 1번이라도 있는 컴퓨터는 VIRUS 큐에 저장해둔다.

	while (!VIRUS.empty())
	{
		int current = VIRUS.front();
		VIRUS.pop();

		//감염된 적이 있던 컴퓨터를 하나씩 pop한다.
		//감염된 컴퓨터가 하나라도 경로상에 존재한다면, 나머지 컴퓨터도 감염된 것으로 처리.
		//VIRUS 큐에 저장해둔다.
		//VIRUS 큐에 있는 모든 컴퓨터들을 사용하여 검토했을 때, 더 이상 다른 컴퓨터가 감염 될 수 없을때까지 반복한다.
		for (int i = 1;i <= N;i++)
		{
			if (CPU[current][i] && !INFECTED[i])
			{
				INFECTED[i] = 1;
				VIRUS.push(i);
				sum++;
			}
			else if (CPU[i][current] && !INFECTED[i])
			{
				INFECTED[i] = 1;
				VIRUS.push(i);
				sum++;
			}
		}
	}

	cout << sum << endl;


	return 0;
}
