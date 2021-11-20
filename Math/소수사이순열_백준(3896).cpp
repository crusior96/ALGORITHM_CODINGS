#include<iostream>
#include<cmath>
using namespace std;

bool primary[1301890] = {};

//N개의 숫자들이 주어진다고 가정하자
//소수 사이 순열이란, 연속하는 두 개의 소수 사이에 합성수들로만 이어져 있는 순열을 뜻한다
//이때 입력된 숫자를 포함하여 만들 수 있는 소수 사이 순열의 길이를 구하고 만들 수 없다면 0을 출력하라
//숫자의 범위는 정수 1부터 100000번째 소수인 1299709까지이다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	//소수판정을 위해 에라토스테네스의 체 사용
	//범위가 범위인만큼 int값이 아니라 bool값을 사용하는 배열을 선언하여 메모리를 아낀다
	//primary[i]가 1이라면 i는 소수가 아니라는 뜻이다
	primary[1] = 1;
	for (int i = 2;i <= 1141;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 1301811;j += i) {
			primary[j] = 1;
		}
	}

	//소수 간의 거리를 구하기 위한 단순 while문
	//복잡하게 생각하지 않고 현 위치를 기준으로 소수인지 아닌지 우선 판단한 이후
	//소수가 아니라면 점차적으로 1씩 늘리거나 줄이는 방식을 사용하여 소수가 나올 때를 측정한다
	//이후 소수 간의 거리의 최초값인 mini와 최종값인 maxi 사이의 차이값을 출력해주면 된다
	for (int i = 0;i < N;i++) {
		int num, maxi, mini;
		cin >> num;
		maxi = num;
		mini = num;
		bool done = true;

		if (primary[num] == 0) {
			cout << 0 << '\n';
		}
		else {
			while (done) {
				maxi++;
				if (primary[maxi] == 0) {
					break;
				}
				else if (maxi == 1299709) {
					break;
				}
			}

			while (done) {
				mini--;
				if (primary[mini] == 0) {
					break;
				}
				else if (mini == 0) {
					break;
				}
			}
			cout << maxi - mini << '\n';
		}
		
	}

	return 0;
}