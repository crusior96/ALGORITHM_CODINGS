#include<iostream>
using namespace std;

//흔한 피보나치 수열 문제이지만 조건이 까다롭다.
//N번째 피보나치 수를 구해야하는데 N의 값은 10^18 이하의 값이며
//그 피보나치 수는 10^6으로 나눈 나머지값이 나오면 된다


//피보나치의 재귀함수
int fibo(int x, int y)
{
	return (x + y) % 1000000;
}

//이번에 사용하게 될 기능은 피사노 주기
//주기의 길이가 P이면 N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M으로 나눈것과같다
//이때, M=10^k일때 k>2라면 주기는 항상 15*10^(k-1)이 나오게된다.
//M=1000000이기 때문에 주기값은 1500000가 나오면 된다
int main()
{
	int A = 0;
	int B = 1;
	int num = 2;
	int temp;
	unsigned long long N;
	cin >> N;

	if (N == 0)
	{
		cout << 0 << endl;
	}
	else if (N == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		N = N % 1500000;
		for (int i = 2;i < N + 1;i++)
		{
			temp = A % 1000000;
			A = B % 1000000;
			B = fibo(temp, B);
		}
		cout << B << endl;
	}
	return 0;
}