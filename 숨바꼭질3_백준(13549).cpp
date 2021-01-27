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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N; //M에서 N으로 가야하는문제
	int visited[200001] = {}; //도착했을 때 해당위치까지 가는데 걸린 최소 이동횟수
	bool vis[200001] = {};	  //해당 위치를 방문했는가에 대한 여부 저장
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
			//사실상 이번 알고리즘은 BFS를 사용하기는 하는데 0-1 BFS 알고리즘을 사용한다고 한다
			//BFS탐색과 동시에 탐색이 완료된 곳에 대한 조치를 취한다는 것
			//다만 그것을 사용하지 않고 deque 자료구조 사용 및 deque에 자료값 넣는 순서를 
			//소요시간이 0인 순간이동부터 넣는것으로 정하고 풀면 답이 나오긴 한다
			if ((temp * 2 <= 100000) && (visited[temp * 2] == 0) && (vis[temp * 2] == false))
			{
				visited[temp * 2] = visited[temp];
				vis[temp * 2] = true;
				checker.push_back(temp * 2);
			}

			if ((temp - 1 >= 0) && (visited[temp - 1] == 0) && (vis[temp - 1] == false))
			{
				visited[temp - 1] = visited[temp] + 1;
				vis[temp - 1] = true;
				checker.push_back(temp - 1);
			}

			if (visited[temp + 1] == 0 && (vis[temp + 1] == false))
			{
				visited[temp + 1] = visited[temp] + 1;
				vis[temp + 1] = true;
				checker.push_back(temp + 1);
			}
			checker.pop_front();
		}
	}
	cout << visited[N] << endl;
	return 0;
}