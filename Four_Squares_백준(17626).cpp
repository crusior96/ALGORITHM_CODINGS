#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
int answer = 9999999;

//어떠한 숫자는 최대 4개의 제곱수의 합으로 표현될수 있음을 증명할 수 있다고 하자
//이때, 주어진 숫자는 몇 개의 제곱수의 합으로 표현되는지 출력하는 문제


//단순 브로트포스로 진행되지만 특정 조건을 걸지 않으면 시간 초과가 나온다.
//squares(현재까지 덧셈에 쓰인 제곱수의 갯수, 덧셈에 쓰인 제곱수들을 빼고 남은 값)
//temp_num이 0이 돼야 제곱수로 합을 표현한 것이 된다.
void squares(int ans, int temp_num) {
	int tmp = sqrt(temp_num);
	int tmp2;
	for (int i = tmp;i >= 1;i--) {
		tmp2 = temp_num - pow(i, 2);
		if (tmp2 == 0) {
			answer = min(answer,ans);
			break;
		}
		else if(tmp2 != 0){
			//시간 절역을 위해서 만약 ans + 1 값이 4를 넘으면 탐색을 종료한다
			if (ans + 1 > 4) {
				break;
			}
			else {
				squares(ans + 1, tmp2);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	squares(1, N);
	cout << answer << '\n';
	return 0;
}