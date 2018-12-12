#include<iostream>
using namespace std;
int music[1001] = {}; //각각의 음악을 연주할 때 변화시켜야하는 볼륨값을 저장해두는 배열
long volume[3][1001] = {}; 
//volume[1]에는 현재까지 연주할 수 있는 노래의 볼륨에 1을 저장해둔다.
//volume[2]에는 volume[1] 볼륨에서 조건을 준수하며 music[i]의 값을 더하거나 뺀 값의 위치에 1을 임시적으로 저장해둔다.

//start개의 음악을 연주하려한다. 이때, 이번 음악을 연주하고 다음 음악을 연주하기 위해선, 현재 볼륨 + music[i] 또는 music[i]의 크기로 볼륨을 조정해야한다.
//첫 노래의 볼륨이 N이고 최대한 올릴 수 있는 볼륨은 M, 최소한 줄일 수 있는 볼륨이 0이라면
//마지막 곡을 연주할 때 만들 수 있는 최대의 볼륨을 구하라.
//볼륨을 조절할 수 없는 순간이 온다면 -1을 출력한다.


int main()
{
	int start, N, M;
	int checker = 0; //볼륨을 조정할 수 있을때엔 1, 조정할 수 없는 순간이 되면 0으로 값을 저장한다.
	cin >> start >> N >> M;

	for (int i = 0;i < start;i++)
	{
		cin >> music[i];
	}

	volume[1][N]++; //초기 노래연주값이 N이므로 volume[1][N]에 1을 저장한 후 for문을 시작한다.

	for (int i = 0;i <= start;i++)
	{

		checker = 0;
		for (int j = 0;j <= M;j++)
		{
			if (volume[1][j] != 0)
			{
				if (j + music[i] <= M)
				{
					volume[2][j + music[i]] = 1;
				}
				if (j - music[i] >= 0)
				{
					volume[2][j - music[i]] = 1;
				}
				checker = 1;
			}
			volume[1][j] = 0;
			//조건에 맞춰서 volume[2]로 값을 전달하면
			//volume[1]의 기존값은 0으로 돌려둔다.
		}

		if (checker == 0)
		{
			cout << -1 << endl;
			break;
		}

		for (int j = 0;j <= M;j++)
		{
			volume[1][j] = volume[2][j];
			volume[2][j] = 0;
			//임시적으로 저장해두는 곳인 volume[2]는 volume[1]로 값을 전달한 후 0으로 초기화한다.
		}
		
	}

		for (int i = M;i >= 0;i--)
		{
			//volume[1]에 저장된 값을 중 맨 뒷주소부터 1이 저장되어있는지를 확인한 후
			//1이 저장되어있는 곳을 노래연주의 최댓값으로 간주, 그 위치를 출력한다.
			if (volume[1][i] == 1)
			{
				cout << i << endl;
				break;
			}
		}

	return 0;
}