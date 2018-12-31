#include<iostream>
#include<algorithm>
using namespace std;

//일렬로 나열되어있는 N개의 상자를 선택하여 넣으려한다.
//왼쪽에서 오른쪽 순서대로 작은 크기의 상자를 큰 상자에 넣을 수 있는 규칙이 있다.
//이 규칙을 지키는채로 박스를 넣는다면 최대 몇 개의 박스를 넣을 수 있는가?

int main()
{
	int N;
	int box[1001] = {}; //상자들의 크기를 저장해두는 배열.
	int boxes[1001] = {}; //상자에 넣을 수 있는 다른 상자의 갯수를 저장해두는 배열.
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> box[i];
	}
	for (int i = 0;i < N;i++)
	{
		if (boxes[i] == 0) //이 상자를 처음으로 상자넣기를 시작할 때, 1의 초기값을 저장해준다.
		{
			boxes[i] = 1;
		}
		for (int j = 0;j < i;j++) //현재 위치보다 왼쪽에 있는 상자들을 기준으로 크기를 비교하여
		{
			if (box[i] > box[j]) //왼쪽 위치에 있던 상자가 오른쪽에 있는 상자보다 크기가 작으면
			{
				if (boxes[i] < boxes[j]+1) //그 왼쪽에 있던 상자에 넣을 수 있는 상자의 최대갯수 + 1이 오른쪽에 있는 상자보다 갯수가 많다면
				{
					boxes[i] = boxes[j]+1; //오른쪽에 있는 상자에 넣을 수 있는 상자의 최대갯수는 그 왼쪽 상자에 넣을 수 있는 갯수 + 1이 된다.
				}
			}
		}
	}
	sort(boxes, boxes + N);
	cout << boxes[N - 1] << endl;
	return 0;
}