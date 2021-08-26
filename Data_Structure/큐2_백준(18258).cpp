#include<iostream>
#include<queue>
#include<string>
using namespace std;

//그냥 기본적인 큐의 기능들에 대해 묻는 게 대부분이지만 입출력과 시간복잡도에 중심이 있는 문제
//N개의 명령어를 입력하게 되는데 N의 범위는 1 이상 2000000 이하이다
//또한 무턱대고 queue sql 내에 있는 함수를 사용하면 시간 초과가 일어나게 되니 효율적으로 기능을 구성하자

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string S;
	cin >> N;	
	queue<int> q;

	//큐에 있는 기능들 중 시간 소요를 O(N)이 아닌 O(1)로 줄이기 위해 큐의 사이즈에 대한 변수를 지정해준다
	//해당 변수를 통해 pop, front, back, empty에선 현재 큐 내부에 뭔가 있는지 체크하는 queue.empty() 함수를 사용 안해도 된다
	//또한 size에선 queue.size() 함수를 사용 안해도 된다
	//약 1년전에 이 문제를 못 푼 이유는 변수를 지정해서 소요 시간 단축, 문자열 입력 시간 단축을 못해서라고 생각한다
	int siz = 0;
	for (int i = 0;i < N;i++)
	{
		cin >> S;
		if (S == "push")
		{
			int temp;
			cin >> temp;
			q.push(temp);
			siz++;
		}
		else if (S == "front")
		{
			if (siz == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (S == "back")
		{
			if (siz == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
		else if (S == "pop")
		{
			if (siz == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop();
				siz--;
			}
		}
		else if (S == "size")
		{
			cout << siz << '\n';
		}
		else if (S == "empty")
		{
			if (siz == 0)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}