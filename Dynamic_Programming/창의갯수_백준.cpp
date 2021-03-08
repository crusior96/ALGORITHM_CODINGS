#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits.h>
using namespace std;


//4가지 기능이 있는 버튼을 N회 눌렀을 경우, 최대한 만들어낼 수 있는 창의 갯수는 몇개인가?
//각각의 기능은 1. 창1개 만들기, 2. CTRL + A, 3. CTRL + C, 4. CTRL + V

int main()
{
	unsigned long long int board[200] = {};
	int cache[200] = {};
	int N;
	board[1] = 1;
	board[2] = 2;
	board[3] = 3;
	//점화식을 위해 지정해두는 초기값. 입력 횟수가 1~3회인 경우에는 단순히 창을 추가해주는 것이 최대한 얻을 수 있는 창의 갯수를 알려주며
	//무엇보다 전체 선택 후 복사를 한 다음 붙여넣기를 하기까지의 입력 횟수가 부족하다.
	unsigned long long int answer = 0;
	cin >> N;
	if (N == 1)
	{
		answer = board[1];
	}
	else if (N == 2)
	{
		answer = board[2];
	}
	else if (N == 3)
	{
		answer = board[3];
	}
	else//N의 값이 4 이상일 때 부터 복사과정을 실행할 지, 단순히 창을 추가만 할지, 복사 도중 새로이 복사할 대상을 지정 후 복사할지를 정한다.
	for (unsigned long long int i = 4;i <= N;i++)
	{
		int l = 2;
		//i번째 입력횟수까지 창을 1개씩 추가만 한 경우와 (i-1)번째까지 입력했을 때의 최댓값에서 창을 1개 추가한 값중 최댓값을 얻어낸다.
		unsigned long long int maxNum = max(i, board[i - 1] + 1);
		for (int k = i - 3;k >= 1;k--)//i-3을 해주는 이유는, 전체 선택(1회), 복사(1회), 붙여넣기(1회) 총 3회의 과정을 통해 복사가 되기 때문.
		{
			maxNum = max(maxNum, board[k] * l);
			l++;
			//최초에 복사한 값을 붙여넣으면 원래 값의 2(여기에 상수 l을 사용한다.)배가 되기 때문에
			//복사 된 것을 계속 붙여넣는 과정을 실행하기 위해 l 값을 늘려준다.
		}
		board[i] = maxNum;
	}

	cout << board[N] << endl;

	return 0;
}
