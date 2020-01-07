//#include<iostream>
//using namespace std;
//int num[100002] = {};
//int sums[100002] = {};
//int main()
//{
//	unsigned long int M, N, num1, num2;
//	cin >> M >> N;
//	for (int i = 1;i <= M;i++)
//	{
//		cin >> num[i];
//		sums[i] = sums[i - 1] + num[i];
//	}
//
//	for (int i = 0;i < N;i++)
//	{
//		cin >> num1 >> num2;
//		cout << sums[num2] - sums[num1 - 1] << endl;
//	}
//
//	return 0;
//}

//위엣 코딩은 c++로 해서 시간초과가 나버렸다. 시간초과를 고려해서라도 c로 코딩하는 습관을 가지도록 하자.
//M개의 숫자들이 나열된 곳에 N번의 테스트케이스가 있다.
//특정 위치 사이(A ~ B)에 있는 숫자들의 총 합을 구하는 것이 문제의 목표.
//시간초과를 대비하기 위해 시간복잡도를 최대한 줄여줘야하며, O(N)의 시간복잡도를 가진 방법으로 문제를 풀어본다.
#include<cstdio>
using namespace std;

int main()
{
	int M, N, sums[100001] = {};
	scanf("%d %d", &M, &N);
	for (int i = 0;i < M;i++)
	{
		int temp;
		scanf("%d", &temp);
		sums[i + 1] = sums[i] + temp;
	}

	for (int j = 0;j < N;j++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		printf("%d\n", sums[B] - sums[A - 1]);
	}

	return 0;
}