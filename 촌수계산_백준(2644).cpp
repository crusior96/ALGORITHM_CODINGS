#include<iostream>
using namespace std;
int M, N, num1, num2, temp1, temp2;
int answer = 0;


//M명의 사람이 있는 가운데, 각 사람들을 1 ~ M번이라고 지칭한다면
//각 사람들간의 1촌관계가 N개 있다고 가정했을때
//num1과 num2의 촌수관계가 몇 촌인지를 알아보고자 한다.


int chon[101][101] = {};
//촌수 관계가 저장되어지는 배열. 서로 촌수 관계가 맞다면 1, 아니면 0을 넣어둔다.

//각각 num1, num2(촌수 관계를 알아보고자 하는 두 사람의 번호)
//cnt는 지금까지 진행된 촌수의 수, before는 now위치에 있는 사람번호가 다른 사람과 이어져있었을 때, 그 사람의 번호이다.
void chon_search(int end, int now, int before, int cnt)
{
	if (end == now)
	{
		//end와 now가 같다면 답을 출력하고 BFS문 정지.
		answer = cnt;
		return;
	}
	else
	{
		//end와 now가 다르다면 BFS문을 계속 돌린다.
		//자기자신(여기에선 chon_search의 now)과 다른 연결된 촌수관계의 사람들하고만 chon_search문을 돌려준다.
		for (int i = 1;i <= M;i++)
		{
			
			if (chon[now][i] == 0)
			{
				continue;
			}

			if (i == before)
			{
				continue;
			}

			chon_search(end, i, now, cnt + 1);
		}
	}
}

int main()
{
	cin >> M;
	cin >> num1 >> num2;
	cin >> N;

	//temp1과 temp2간의 촌수관계를 저장해둔다.
	//바로 이어지는 촌수관계이므로 chon[temp1][temp2]와 [temp2][temp1]에 1을 저장해둔다.
	for (int i = 0;i < N;i++)
	{
		cin >> temp1 >> temp2;
		chon[temp1][temp2] = chon[temp2][temp1] = 1;
	}


	chon_search(num1, num2, 0, 0);
	
	//답이 0(이어지지 못하는 촌수관계이면)이면 -1을 출력
	//아니면 답을 출력하면 된다.
	if (answer == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << answer << endl;
	}

	return 0;
}