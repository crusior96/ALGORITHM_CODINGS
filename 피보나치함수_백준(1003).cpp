#include<iostream>
#include<algorithm>
using namespace std;

//40��° �Ǻ���ġ ���� ���õ� ����.

//int fibonacci(int n) {
//	if (n == 0) {
//		printf("0");
//		return 0;
//	}
//	else if (n == 1) {
//		printf("1");
//		return 1;
//	}
//	else {
//		return fibonacci(n?1) + fibonacci(n?2);
//	}
//}
//���� ���� fibonacci�� �Լ���� 0�� 1�� ����س��� ������� �Ǻ���ġ ���� ����Ѵٰ� ������ ��
//0���� 40������ ������ �Է�������, �� ��ġ�� �Ǻ���ġ ���� ���� ��, 0�� 1�� ����س� Ƚ���� ���϶�.

int main()
{
	int T, N;
	pair<int, int> arr[42];
	//�ּ�ó���� �Լ��� �״�� ����ϸ� �ð� �ʰ��� �ɸ��� �ȴ�.
	//pair�����̳ʸ� ����Ͽ� �ʱⰪ�� �������� �� for���� ���� 0�� 1�� ��µ� Ƚ���� ����Ǵ� arr�迭�� ���� �����Ѵ�.
	arr[0].first = 1;
	arr[0].second = 0;
	arr[1].first = 0;
	arr[1].second = 1;
	//�ʱⰪ�� 0�� 1�϶��� �Ǻ���ġ �Լ� ���� �� ������ ��°�.
	for (int i = 2;i <= 40;i++)
	{
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> N;
		cout << arr[N].first << " " << arr[N].second << endl;
	}

	return 0;
}