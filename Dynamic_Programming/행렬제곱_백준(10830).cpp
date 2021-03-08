#include<iostream>
#include<vector>

using namespace std;
int N;
long long B;
int arr[6][6]; //거듭제곱을 하게 될 행렬의 원본.

//N*N의 행렬을 B번 거듭제곱하게 될 경우 각각의 행렬칸이 가지는 값을 구한다
//값이 매우 커져서 저장이 어려워지기때문에 각각의 배열값은 1000으로 나눈 나머지를 저장해둔다.

vector<vector<int>> timer(long long num)
{
	vector<vector<int>> time(N, vector<int>(N));
	vector<vector<int>> temp(N, vector<int>(N));

	//제곱을 해야 하는 횟수 및 짝-홀수 상태에 따라 해야하는 계산이 달라진다.
	//이는 X^8 = ((X^2)^2)^2와 같이 단순히 8번의 제곱이 아닌, X^2를 3번 거듭제곱하는 방식으로
	//연산의 횟수를 줄여서 시간복잡도를 줄이려는 목적이다.

	//1. 제곱을 하지 않을경우
	if (num == 1)
	{
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				temp[i][j] = arr[i][j] % 1000;
			}
		}
		//그냥 1000으로 나눈 나머지값이 들어있는 행렬을 temp행렬에 저장하여 반환한다.
		return temp;
	}
	//2. 제곱하는 횟수가 짝수일경우
	else if (num % 2 == 0)
	{
		//제곱하는 횟수를 2로 나는 값을 timer함수에 넣어서 연산하여 temp에 넣어준다.
		temp = timer(num / 2);


		//밑의 연산방식은 기존에 이미 제곱이 되어있던 temp배열끼리 제곱해주는 것.
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				for (int k = 0;k < N;k++)
				{
					time[i][j] += temp[i][k] * temp[k][j];
				}
				time[i][j] %= 1000;
			}
		}

		return time;
	}
	//3. 제곱하는 횟수가 홀수일경우
	else
	{
		//제곱하는 횟수에서 1 뺀 값을 timer함수에 넣어서 연산하여 temp에 넣어준다.
		temp = timer(num - 1);


		//밑의 연산방식은 기존에 이미 제곱이 되어있던 temp배열에 원본인 arr배열을 1번 추가하여 곱해주는 것.
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				for (int k = 0;k < N;k++)
				{
					time[i][j] += temp[i][k] * arr[k][j];
				}
				time[i][j] %= 1000;
			}
		}

		return time;
	}
}

int main()
{

	cin >> N >> B;
	vector<vector<int>> time(N, vector<int>(N));
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> arr[i][j];
		}
	}

	time = timer(B);

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cout << time[i][j]<< " ";
		}
		cout << "\n";
	}
	return 0;
}
