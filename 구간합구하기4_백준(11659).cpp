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

//���� �ڵ��� c++�� �ؼ� �ð��ʰ��� �����ȴ�. �ð��ʰ��� ����ؼ��� c�� �ڵ��ϴ� ������ �������� ����.
//M���� ���ڵ��� ������ ���� N���� �׽�Ʈ���̽��� �ִ�.
//Ư�� ��ġ ����(A ~ B)�� �ִ� ���ڵ��� �� ���� ���ϴ� ���� ������ ��ǥ.
//�ð��ʰ��� ����ϱ� ���� �ð����⵵�� �ִ��� �ٿ�����ϸ�, O(N)�� �ð����⵵�� ���� ������� ������ Ǯ���.
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