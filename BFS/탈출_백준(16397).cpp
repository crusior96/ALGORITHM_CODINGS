#include<iostream>
#include<queue>
using namespace std;
int checked[100001] = {}; //i까지 도달하는 최소버튼수가 저장되어진다면, checked[i] = 1로 저장해둔다.
int ways[100001] = {}; //i까지 도달하는 최소버튼수를 구했다면, 그 값을 ways[i]에 저장해둔다.
queue<int> q;

//N이라는 숫자를 A와 B라는 버튼을 T번까지만 눌러서 G라는 숫자까지 도달 할 수 있다면, 버튼을 누르는 최소횟수를 구하라.
//A버튼을 누르면 N에 1을 더하게 된다.
//B버튼을 누르면 N을 2배로 하고, 그 숫자의 최대자릿수를 1 없애준다. (ex : 123 -> B -> 146 / 4 -> 7 / 5 -> 0)
//각 버튼을 눌렀을 때, N의 값이 99999를 넘게되면 자동으로 탈출 실패이다.

int main()
{
	int N, T, G;
	cin >> N >> T >> G;
	q.push(N);
	checked[N] = 1;

	//BFS 알고리즘을 사용하기 위해 큐에 넣어두는 최초값은 N이다. 여기서부터 버튼을 누르고 숫자값이 변하기때문.
	while (q.empty() != true)
	{
		int temp = q.front();
		q.pop();

		//목표값에 한번이라도 도달했을경우 while문 종료.
		if (temp == G)
		{
			break;
		}
		else
		{
			//A버튼
			int now = temp + 1;

			//now의 값이 99999 이하이고, now가 되기전까지 누른 버튼의 수가 T보다 작으며, 현재까지 도달한 적 없는 위치일경우
			//현재 위치까지 도달하는 최소 버튼수가 저장되어지며, 현재 위치가 queue에 저장되어진다.
			if (now <= 99999 && ways[temp] < T && checked[now] == 0)
			{
				checked[now] = 1;
				ways[now] = ways[temp] + 1;
				q.push(now);
			}

			//B버튼을 눌렀을 때, 2배가 된 값이 99999를 넘자마자 실패가 되므로, 그 이하일때의 값만을 따져야 한다.
			if (temp * 2 <= 99999)
			{
				int now = temp * 2;

				//now가 한자릿수이지만 0은 아닐경우, 단순히 1을 빼주면 조건이 적용된다.
				if (now < 10 && now !=0)
				{
					now = now - 1;
				}
				else
				{
					//now가 한자릿수가 아닐경우, for문을 사용하여 몇자리수인지 찾아낸 후
					//그 자리의 값에서 1을 뺀 값을 now에 저장해준다.
					for (int i = 10000;i >= 10;i = i / 10)
					{
						if (now / i > 0)
						{
							now = now - i;
							break;
						}
					}
				}

				//now의 값이 99999 이하이고, now가 되기전까지 누른 버튼의 수가 T보다 작으며, 현재까지 도달한 적 없는 위치일경우
				//현재 위치까지 도달하는 최소 버튼수가 저장되어지며, 현재 위치가 queue에 저장되어진다.
				if (now <= 99999 && ways[temp] < T && checked[now] == 0)
				{
					checked[now] = 1;
					ways[now] = ways[temp] + 1;
					q.push(now);
				}
			}
		}
	}
	
	//목표인 G에 도달했었을경우, 도달하는데 걸린 최소버튼수를 출력한다.
	//그렇지 않으면..
	if (checked[G] == 1)
	{
		cout << ways[G] << endl;
	}
	else
	{
		cout << "ANG" << endl;
	}
	return 0;
}
