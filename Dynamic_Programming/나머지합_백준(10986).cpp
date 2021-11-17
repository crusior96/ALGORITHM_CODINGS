#include<iostream>
using namespace std;
int arr[1000002] = {};
long long int mods[1001] = {};

//N개의 나열된 숫자들(1 ~ 10^6) 중 일정 구간의 합이 M(2 ~ 10^3)으로 나누어지는 구간의 갯수를 구하는 문제
//구간은 연속되어야만 한다

//나름 메모이제이션을 응용한 문제
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	long long int sum = 0;
	long long int ans_mod = 0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}

	
	mods[0] = 1;
	//index 0에서부터 순차적으로 index값을 1씩 늘려가면서 구간합의 나머지 구하기
	//나올 수 있는 나머지 값의 경우를 mods배열에 저장
	for (int i = 0;i < N;i++)
	{
		sum += arr[i];
		sum %= M;
		mods[sum]++;
	}

	//이후 조합식의 규칙에 따라 구간합을 합쳤을 때 나머지가 0이 되는 조건들을 찾아낸다
	//단, 나머지가 0이되는 구간합은 예외처리를 해준다
	for (int i = 0;i <= M;i++)
	{
		if (i > M / 2) {
			break;
		}

		if (i == 0) {
			ans_mod += mods[i] * (mods[i] - 1) / 2;
		}
		else {
			ans_mod += (long long)mods[i] * (long long)(mods[M - i]) / 2;
		}
	}


	cout << ans_mod << '\n';
	return 0;

}
