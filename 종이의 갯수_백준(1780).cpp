#include <iostream>
using namespace std;
#pragma warning(disable:4996)

//3의 거듭제곱수인 N*N칸만큼의 종이가 있다고 가정하자
//각각의 종이 위에는 -1, 0, 1로 숫자가 새겨진다.
//종이의 기준이 변의 길이가 3의 거듭제곱인 것이며 변의 길이가 길 수록 좋다.
//최대한 변의 길이가 긴 종이들부터 얻어낸다고 가정할 때, 각각의 숫자들로 이루어진 종이들의 갯수를 구하여라.


const int MAX = 2187; //3^7

int N;
int arr[2187][2187]; //종이의 값들이 저장되는 배열
int result[3];		 //종이에 적힌 값에 따라 그 갯수들이 저장되어지는 배열



void func(int n, int y, int x)

{
	//기저 사례
	if (n == 1)
	{
		result[arr[y][x] + 1]++;
		return;
	}

	bool minus = true, zero = true, plus = true; //종이에 적힌 번호값의 영어문자만이 true로 저장된다.
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (arr[i][j] == -1)
			{
				zero = false;
				plus = false;
			}
			else if (arr[i][j] == 0)
			{
				minus = false;
				plus = false;
			}
			else
			{
				minus = false;
				zero = false;
			}
		}
	}
	//현재 구역의 종이가 전부 다 0인지 1인지 2인지 정한다.
	//그렇지 않은 곳이라면 현재 종이 면적에서 분할하여 다시 탐색한다.
	//분할의 기준은 현재 종이 면적을 정확하게 9개의 정사각형으로 자른 구역이며 
	if (minus)
		result[0]++;
	else if (zero)
		result[1]++;
	else if (plus)
		result[2]++;
	else
	{
		int div = n / 3;
		func(div, y, x);
		func(div, y, x + div);
		func(div, y, x + 2 * div);

		func(div, y + div, x);
		func(div, y + div, x + div);
		func(div, y + div, x + 2 * div);

		func(div, y + 2 * div, x);
		func(div, y + 2 * div, x + div);
		func(div, y + 2 * div, x + 2 * div);

	}

	return;

}



int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	func(N, 0, 0);
	for (int i = 0; i < 3; i++)
		cout << result[i] << "\n";

	return 0;

}