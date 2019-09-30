#include<iostream>
using namespace std;

//호랑이는 1일차에 A개의 떡을, 2일차에 B개의 떡을 먹는다.
//이때 D일차에 N개의 떡을 먹는다면, 1일차와 2일차에 먹은 떡의 갯수는 몇개인가?
//단, 여러 경우의 수가 나와도 한 가지 수만 나오며 A<=B이다.

int main()
{
	int today, days; //오늘 먹은 떡의갯수, 오늘의 일차수.
	cin >> days >> today;
	int used[31][2] = {}; //A개의 떡을 먹은 횟수와 B개의 떡을 먹은 횟수를 저장해두는 배열.
	//1일차에 먹은 떡의 갯수를 A개라 하고 2일차에 먹은 떡의 갯수를 B개라 하자.
	//used[?][0]에는 A개의 떡을 먹은 횟수를, [1]에는 B개의 떡을 먹은 횟수를 저장해둔다.
	used[1][0] = { 1 };
	used[1][1] = { 0 };
	used[2][1] = { 1 };
	used[2][0] = { 0 };

	for (int i = 3;i <= days;i++)
	{
		used[i][0] = used[i - 1][0] + used[i - 2][0];
		used[i][1] = used[i - 1][1] + used[i - 2][1];
	}

	bool temp = true;
	int num = 0; //잠정적인 A의 값
	while (temp)
	{
		//오늘 먹은 떡의 갯수에서 잠정적인 A의 값을 일정 횟수만큼 먹고 남은 값이 B의 갯수만큼 먹는 횟수로 나뉘어진다면
		//num은 A, (today - used[days][0] * num) % used[days][1]는 B가 된다.
		if ((today - used[days][0] * num) % used[days][1] == 0)
		{
			cout << num << "\n" << (today - used[days][0] * num) / used[days][1] << "\n";
			temp = false;
		}
		else
		{
			num++;
		}

	}

	return 0;
}