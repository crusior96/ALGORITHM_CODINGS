#include<iostream>
#include<cmath>
using namespace std;

int arr[100001] = {};		//arr[i] : i번째 위치에 입력된 숫자값
int nums[1000001] = {};		//nums[i] : i라는 숫자가 현재 얼마나 있는지 저장해두는 배열

//학생들이 순서대로 앉아있다고 가정하자
//1번째 학생부터 N번째 학생까지 각자가 어떠한 숫자를 가진다고 하고
//각각의 학생들은 순차적으로 한바퀴 돌면서 자신이 가진 숫자가 남이 가진 숫자의 배수인지 아닌지 체크한다
//해당 사항에 걸리는 사람들의 수를 각각의 학생별로 출력하는게 문제의 목표

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		nums[arr[i]]++;
	}

	for (int i = 0;i < N;i++) {
		int tmp = 0;

		//해당 문제에서 사용한 배수판별법은 일일이 비교하기 어려운 상황에서 사용하기 매우 좋다
		//배수판별을 비교하고자 하는 j값을 기준으로 점차 제곱수를 늘려가면서 2가지 케이스에 관해 배수의 갯수를 구하게 된다
		//이전에 사용한 자료값을 사용한다는 점에서 DP랑도 일정부분 일맥상통하는 부분
		for (int j = 1;j*j <= arr[i];j++) {
			//만약에 i번째 사용자가 입력한 숫자가 특정값의 제곱수로 나뉘어떨어지는 값이라면
			if (arr[i] % j == 0) {
				//해당특정값의 갯수만큼 tmp에 더해둔다
				tmp += nums[j];

				//또한 arr[i]가 j의 제곱수인게 아니라면
				if (j != arr[i] / j) {
					//nums[arr[i] / j] 즉 arr[i]의 약수만큼 tmp값에 추가해준다
					tmp += nums[arr[i] / j];
				}
			}
		}

		//1을빼는 이유 : 모든 숫자들은 1의 배수라는 기반값이 있기때문
		cout << tmp - 1 << '\n';
	}


	return 0;
}