#include<iostream>
#include<queue>
using namespace std;

//N*N개의 숫자가 이차원 배열에 있다. 이때, 각각의 숫자들은 행을 기준으로 아래에 있는 행이 바로위의 행보다 숫자가 크다
//위의 규칙을 가진채로 숫자들이 있는 배열속에 N번째 큰 수를 구하여라. (N <= 1500)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue <int> PQ;
	//PQ에서 최대 힙을 사용하고자 입력되는 변수들에 -1을 곱해준다.
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		PQ.push(-temp);
	}
	//첫 번째 행의 값은 일단 PQ에 저장

	for (int i = 1;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			int temp;
			cin >> temp;
			PQ.push(-temp);
		}
		for (int j = 0;j < N;j++)
		{
			PQ.pop();
		}
		//이어지는 행들의 값을 PQ에 저장시켜준다.
		//이후 N개의 숫자만을 남겨둔 채 나머지 값들은 우선순위에 따라 POP해준다.
		//현재 최소 힙으로 지정되어있기 때문에 절대값이 작은 음수들부터 POP되어진다.
		//후에 남은 N개의 수들 중 TOP에 있는 음수에 -1을 곱하여 출력시켜주면 N번째 큰수가 된다.
	}
	cout << PQ.top() * -1 << "\n";

	return 0;
}