#include<iostream>
#include<cmath>
using namespace std;
//두 명의 사람이 전기를 사용한 양의 총합을 A, 두 명의 사람들의 전기요금 차이를 B라고 하자
//특정 조건에 따라 전기요금을 부과한다 할 때, 두 사람 중 적은 요금을 낼 수 있는 사람의 요금은 얼마인가?
//A와B는 문제를 풀 수 있는 조건상에서만 나온다

/*조건
  사용량이 1 ~ 100 : 1당 2원
  사용량이 101 ~ 10000 : 1당 3원
  사용량이 10001 ~ 1000000 : 1당 5원
  100만 초과시 : 1당 7원
  사용량 범주내의 전기들만 제시된 조건대로 비용을 계산한다
  ex) 150사용 -> 200 + 150 = 350
*/

//특정 비용이 나오기 위한 사용 전기량을 계산하는 함수
int elec_calc(int temp) {
	if (temp <= 200) {
		return temp / 2;
	}
	else if (temp > 200 && temp <= 29900) {
		return 100 + (temp - 200) / 3;
	}
	else if (temp > 29900 && temp <= 4979900) {
		return 10000 + (temp - 29900) / 5;
	}
	else if (temp > 4979900) {
		return 1000000 + (temp - 4979900) / 7;
	}
}

//전기량에 따른 비용을 계산하는 함수
int money_calc(int temp) {
	if (temp <= 100) {
		return temp * 2;
	}
	else if (temp > 100 && temp <= 10000) {
		return 200 + (temp - 100) * 3;
	}
	else if (temp > 10000 && temp <= 1000000) {
		return 29900 + (temp - 10000) * 5;
	}
	else if (temp > 1000000) {
		return 4979900 + (temp - 1000000) * 7;
	}
}

int main() {
	int A, B;
	int total_elec; //두 사람이 사용한 전기용량의 합
	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}
		else {
			total_elec = elec_calc(A);
			int left = 1;
			int right = total_elec;
			//이분 탐색을 이용하여 시간복잡도를 줄이는 것이 중요
			//단순히 for문을 사용하여 방정식을 풀면 시간초과 발생
			//찾고자 하는것은 특정 전기용량을 누군가가 썼을때, 각자의 배분된 전기요금값이 B인 경우를 찾아야하므로
			//이분 탐색이 이루어지는 범위는 1 ~ 전기용량의 합
			while (left <= right) {
				int mid = (left + right) / 2;
				if (abs(money_calc(total_elec - mid) - money_calc(mid)) > B) {
					right = mid - 1;
				}
				else if (abs(money_calc(total_elec - mid) - money_calc(mid)) < B) {
					left = mid + 1;
				}
				else if(abs(money_calc(total_elec-mid) - money_calc(mid))==B){
					//둘 중 최솟값 출력
					if (money_calc(total_elec - mid) >= money_calc(mid)) {
						cout << money_calc(mid) << endl;
					}
					else if (money_calc(total_elec - mid) < money_calc(mid)) {
						cout << money_calc(total_elec - mid) << endl;
					}
					break;
				}
			}
		}
	}


	return 0;
}