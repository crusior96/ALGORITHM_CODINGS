#include<iostream>
using namespace std;

//파스칼의 삼각형의 규칙에 따라, 최대 30의 길이를 가진 삼각형이 있다고 가정하자.
//여기서 R번째 줄의 C번째 점에서 W만큼의 길이를 가진 정삼각형을 그린다면
//그 삼각형 내에 있는 숫자들의 합은 총 얼마인가?

int main()
{
	long int pascal[32][32] = {};
	//파스칼의 삼각형 값을 저장하기 위한 배열
	int R, C, W;
	long int sum = 0;
	pascal[1][1] = 1;
	//파스칼의 삼각형 값을 저장하기 위한 초기값. 
	for (int i = 2;i <= 30;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			//삼각형의 양 끝변에는 1이 저장되도록 한다.
			if ((j == 1) || (j == i))
			{
				pascal[i][j] = 1;
			}
			//그 외의 부분에는 파스칼의 삼각형의 규칙에 따라
			//양 옆의 숫자를 합한 값이 바로 밑 줄의 값이 되는 것으로 저장해준다.
			else
			{
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			}
		}
	}
	cin >> R >> C >> W;

	//시작점을 (R,C)로 지정하여 파스칼의 삼각형값을 저장해준다.
	for (int i = 0;i < W;i++)
	{
		for (int j = 0;j <= i;j++)
		{
			sum = sum + pascal[R + i][C + j];
		}
	}

	cout << sum << endl;

	return 0;

}