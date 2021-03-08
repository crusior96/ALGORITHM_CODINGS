#include<iostream>
#include<queue>
using namespace std;
int checked[1000001] = {}; //i층까지 도달하는 최소한의 버튼입력수가 존재한다면, checked[i]에 1이 저장되어진다.
int ways[1000001] = {}; //i층까지 도달하는 최소한의 버튼입력수를 ways[i]에 저장한다.
unsigned long int F, S, G, U, D;
queue <unsigned long int> q; //BFS 알고리즘의 사용을 위해 만든 큐.

//총 F층으로 이루어진 건물에 S층에 위치해있는 한 사람이 G층까지 도달하고 싶어한다.
//엘리베이터엔 U층만큼 위로 올라가거나 D층만큼 아래로 내려가는 버튼이 있다.
//이때, G층으로 도착할 수 있다면 그때까지 버튼을 누르는 최소한의 갯수는 몇개인지 출력하라.
//도착하지 못한다면 "use the stairs"라는 문장을 출력한다.


int main()
{
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	checked[S] = 1;
	//큐가 비워질때까지 엘리베이터의 움직임을 계속 테스트한다.
	while (q.empty() != true)
	{
		//U와 D만큼 올라가고 내려갔을 때, 그 때 그 위치에 도달하는 최소버튼수를 구한다.
		int temp = q.front();
		q.pop();

		//now는 각각 temp에서 U만큼 올라가거나 D만큼 내려간 층수가 저장되는 변수이다.
		int now = temp + U;

		//최소버튼수가 없고, temp + U의 값이 건물 최대층수를 넘지 않으면
		if (now <= F && checked[now] == 0)
		{
			//현재 위치의 최소버튼수 체크여부를 저장해주고, 최소버튼수 또한 저장해준다.
			checked[now] = 1;
			ways[now] = ways[temp] + 1;
			q.push(now);
		}

		now = temp - D;

		//최소버튼수가 없고, temp - D의 값이 건물 최저층수보다 낮아지지 않으면
		if (now >= 1 && checked[now] == 0)
		{
			//현재 위치의 최소버튼수 체크여부를 저장해주고, 최소버튼수 또한 저장해준다.
			checked[now] = 1;
			ways[now] = ways[temp] + 1;
			q.push(now);
		}

		//BFS알고리즘을 사용하고 있기에, ways배열에 저장해주는 값은 ways[temp] + 1이면 충분하다.
		//그 위치까지 도달하는 최소한의 값을 구하는 알고리즘이기 때문.
	}

	//G까지 도착하는 최소버튼수가 저장되어진다면 ways[G]를 출력한다.
	if (checked[G] == 1)
	{
		cout << ways[G] << endl;
	}
	else
	{
		cout << "use the stairs" << endl;
	}

	return 0;
}
