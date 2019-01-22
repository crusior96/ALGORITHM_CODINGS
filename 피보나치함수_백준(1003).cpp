#include<iostream>
#include<algorithm>
using namespace std;

//40번째 피보나치 수와 관련된 문제.

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
//위와 같은 fibonacci의 함수대로 0과 1을 출력해내는 방식으로 피보나치 수를 계산한다고 가정할 때
//0에서 40까지의 정수를 입력했을때, 그 위치의 피보나치 값을 구할 때, 0과 1을 출력해낸 횟수를 구하라.

int main()
{
	int T, N;
	pair<int, int> arr[42];
	//주석처리된 함수를 그대로 사용하면 시간 초과가 걸리게 된다.
	//pair컨테이너를 사용하여 초기값을 지정해준 후 for문을 통해 0과 1이 출력된 횟수가 저장되는 arr배열에 값을 저장한다.
	arr[0].first = 1;
	arr[0].second = 0;
	arr[1].first = 0;
	arr[1].second = 1;
	//초기값은 0과 1일때의 피보나치 함수 실행 시 나오는 출력값.
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