#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//M에 위치한 사람이 N에 있는 사람을 보기위해 3 가지 방법으로 이동하여 도착하려한다.
//각각의 방법은 M에서 M+1 혹은 M-1로 걸어가거나, M*2의 위치로 순간이동하는 것이다.
//걸어가는 과정에선 1초가 소모되고 순간이동을 하는과정에선 시간소모가 없을때
//M에서 N으로 도착하는 최단소모시간을 구하여라


int main()
{
	int M, N; //M에서 N으로 가야하는문제
	int visited[100001] = {}; //위치 i에 몇초만에 최단시간으로 도달했는지 저장해주는배열
	deque <int> checker; 
	//BFS방법을 이용하여 문제를 풀고자한다. 주어진위치값을 pop_front()해주고,
	//그 위치에서 +1 / -1 / *2한 위치로 이동한것을 checker에 push_back해준다.
	cin >> M >> N;
	checker.push_back(M);
	while (checker.empty() != 1)
	{
		int temp = checker.front();
		//현재위치가 목표값과 같다면
		if (temp == N)
		{
			while (checker.empty() != 1)
			{
				//checker 덱 안의값을 모두 비워준다.
				checker.pop_front();
			}
			break;
		}
		else
		{
			//현재 위치가 목표값보다 뒤에 있다면
			if (temp > N)
			{
				//목표값으로 가기위해선 현재위치에서 -1하는 행동밖에 못한다.
				if (visited[temp - 1] == 0)//방문한 적이 없는 위치라면
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
					//최초 도착시간을 visited배열에 저장해주고, 그 위치를 checker에 push_back
				}
				else if (visited[temp - 1] > visited[temp] + 1)//방문한 적이 있는 위치이지만 이동하는데 걸린 시간이 최단으로 단축된다면
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
					//최단 도착시간을 visited배열에 저장해주고, 그 위치를 checker에 push_back
				}
			}
			//현재 위치가 목표값보다 앞에 있다면
			else if (temp < N)
			{
				//if문을 돌려주는 순서는 *2일때가 먼저, 그 다음 +1과 -1은 뒤에 알아서 오면 된다.
				//*2일때 0초가 걸린다는점에서 BFS가 가지고있는 가중치와 연관되어있는것으로 추정된다.
				//각각의 2개의 if문으로 이루어진 3쌍의 if ~ else if문은 위와같은 규칙과 같은 원리로 작동한다.
				if ((temp * 2 <= 100000) && (visited[temp * 2] == 0))
				{
					visited[temp * 2] = visited[temp];
					checker.push_back(temp * 2);
				}
				else if ((temp * 2 <= 100000) && (visited[temp * 2] > visited[temp] + 1))
				{
					visited[temp * 2] = visited[temp];
					checker.push_back(temp * 2);
				}

				if (visited[temp + 1] == 0)
				{
					visited[temp + 1] = visited[temp] + 1;
					checker.push_back(temp + 1);
				}
				else if (visited[temp + 1] > visited[temp] + 1)
				{
					visited[temp + 1] = visited[temp] + 1;
					checker.push_back(temp + 1);
				}

				if ((temp - 1 != -1) && (visited[temp - 1] == 0))
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
				}
				else if ((temp - 1 != -1) && (visited[temp - 1] > visited[temp] + 1))
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
				}
			}
		}
		checker.pop_front();
		//위치탐색에 사용했었던 checker.front()의 값 제거.
	}
	cout << visited[N] << endl;
	return 0;
}