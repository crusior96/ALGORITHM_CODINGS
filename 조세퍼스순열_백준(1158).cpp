#include<iostream>
#include<queue>
using namespace std;

//1번부터 M번까지의 사람이 M번까지 번호가 적혀있는 원탁에 앉아있다. 1번부터 순서를 세어 N번쨰에 나오는 사람을 원탁에서 빼고 그 자리의 번호를 기억한다.
//모든 사람이 원탁에서 나오게 된다면, 그때 사람들이 나오게 된 번호의 순서를 출력하라.

int main()
{
	queue<int> jo; //사람들이 앉아있는 원탁을 구현하기 위해 회전큐를 응용하기로 한다.
	int results[5001] = {}; //사람들이 자리에서 나오게 된 순서대로 좌석번호가 저장되어진다.
	int M, N;
	cin >> M >> N;
	for (int i = 1;i <= M;i++)
	{
		jo.push(i);
	}

	int temp = 0;
	//사람들이 원탁에서 다 나갈때까지 반복한다.
	while (temp != M)
	{
		//앞에서 N-1명의 사람을 큐의 뒷부분으로 보내고 N번째 위치의 사람을 results배열에 저장 후 큐에서 pop해준다.
		//이를 통해 나름의 순환큐를 구현할 수 있다.
		for (int i = 0;i < N - 1;i++)
		{
			jo.push(jo.front());
			jo.pop();
		}

		results[temp] = jo.front();
		jo.pop();
		temp++;
	}

	cout << '<';
	for (int i = 0;i < M-1;i++)
	{
		cout << results[i] << "," << " ";
	}
	cout << results[M - 1] << '>' << endl;

	return 0;


}