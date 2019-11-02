#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

//N개의 숫자를 입력받아서 절대값이 작은 숫자부터 출력한다.
//이때, 절대값이 같은 숫자가 두개 이상 있다면, 그 숫자들 중 작은값을 우선적으로 출력한다.
//만약 출력할 숫자가 남아있지 않다면 0을 출력한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//출력의 시간을 줄이기 위한 코드
	priority_queue <int> PQ_plus;
	priority_queue <int> PQ_minus;
	//각각 입력받은 수가 양수, 음수일 때 저장되어지는 우선순위 큐
	//조건에 맞게 저장하기 위해 plus 큐에 값을 저장할 땐 -1을 곱해준다.
	//그래야 절대값이 오름차순으로 숫자가 정렬된다.
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			//출력 할 숫자가 전혀 없으면 0 출력
			if (PQ_plus.empty() == 1 && PQ_minus.empty() == 1)
			{
				cout << "0\n";
			}
			else
			{
				if (PQ_plus.empty() == 0 && PQ_minus.empty() == 1)
				{
					cout << PQ_plus.top() * -1 << "\n";
					PQ_plus.pop();
				}
				else if (PQ_plus.empty() == 1 && PQ_minus.empty() == 0)
				{
					cout << PQ_minus.top() << "\n";
					PQ_minus.pop();
				}
				//출력 할 숫자가 한쪽 큐에만 있으면 그 쪽의 top()을 출력
				else if (PQ_plus.empty() == 0 && PQ_minus.empty() == 0)
				{
					if (abs(PQ_plus.top()) >= abs(PQ_minus.top()))
					{
						cout << PQ_minus.top() << "\n";
						PQ_minus.pop();
					}
					else if (abs(PQ_plus.top()) < abs(PQ_minus.top()))
					{
						cout << PQ_plus.top() * -1 << "\n";
						PQ_plus.pop();
					}
					//양 쪽 다 숫자가 남아있다면 각각가의 큐의 top()을 비교하여 절대값이 작은 숫자부터 출력한다.
					//이 때, 서로의 숫자가 같다면, 작은 숫자를 출력한다.
				}
			}
		}
		else if(temp!=0)
		{
			if (temp > 0)
			{
				PQ_plus.push(-temp);
			}
			else if (temp < 0)
			{
				PQ_minus.push(temp);
			}
		}
	}
	return 0;
}