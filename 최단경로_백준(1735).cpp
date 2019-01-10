#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//정점이 V개가 있고, 그 사이를 연결하는 방향성이 있는 간선이 E개가 있다.
//이때, 시작점 start에서 본인의 정점을 포함한 다른 정점까지 가는 방법들 중 최단거리를 모두 출력하는 문제.
//V는 2만 이하의 자연수이며 E는 30만 이하의 자연수이다.
int start, V, E;


typedef struct NODE {
	int end;
	int val;
};

vector<NODE> way_length[300001]; //노드와 노드 사이의 간선을 저장하는 벡터
int dist[20001] = { 0 };		 //시작점에서 다른 점으로의 거리들을 저장하는 배열

void daik() //이번 문제에서 사용하는 다익스트라 알고리즘. 우선순위 큐와 함께 사용한다.
{
	priority_queue<pair<int, int>> pq; 
	pq.push({ 0,start });
	

	while (!pq.empty())
	{
		
		
		int now_NODE = pq.top().second;

		int cost = -1 * pq.top().first;
		pq.pop();

		//경로를 탐색하는 현재의 노드에서 다른 노드로 향하는 간선들을 모두 탐색한다.
		for (int i = 0;i < way_length[now_NODE].size();i++)
		{
			int new_val = dist[now_NODE] + way_length[now_NODE][i].val;
			int before_val = dist[way_length[now_NODE][i].end];

			//지금까지 추려서 얻은 제일 최단거리와 방금 얻은 거리를 비교하여 최단거리가 갱신되는경우
			//우선순위 큐를 통해 간선에 연결된 도착지점의 노드에서의 거리 비교를 위해 앞부분에 음수를 저장해둔다.
			if (new_val < before_val) {
				dist[way_length[now_NODE][i].end] = new_val;
				pq.push({ -1 * new_val,way_length[now_NODE][i].end });
			}
		}
	}
}

int main()
{
	cin >> V >> E >> start;
	int S, T, value; //S는 출발하는 노드번호, T는 도착하는 노드번호, value는 출발 -> 도착 그 사이에 놓인 간선의 가중치값이다.
	for (int i = 0;i < E;i++)
	{
		scanf("%d %d %d", &S, &T, &value);
		//각각의 출발노드에서 도착할 수 있는 노드번호 및 그 때의 간선 가중치를 way_length 벡터에 저장해둔다.
		way_length[S].push_back(NODE{ T,value });
	}

	for (int i = 1;i <= V;i++)
	{
		dist[i] = 1000000000;
	}
	//거리를 구하는 기준이 되는 정점을 0으로 초기화하고, 그 외의 부분은 최댓값으로 지정해준다.
	//최댓값으로 지정되어있는 부분은 그곳까지 가는 거리를 구할 수 없을때 "INF"라는 문자열을 출력하게 된다.
	dist[start] = 0;

	daik();

	for (int i = 1;i <= V;i++)
	{
		if (dist[i] != 1000000000)
		{
			printf("%d\n", dist[i]);
		}
		else
		{
			printf("INF\n");
		}
	}

	return 0;
}

//다익스트라 알고리즘의 개념은 얼추 이해는 되었지만 보다 많은 실습이 필요해보인다.