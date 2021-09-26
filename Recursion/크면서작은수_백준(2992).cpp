#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int answer = 1000001;	//변동이 없다면 해당 숫자로는 문제 조건에 맞는 수를 만들 수 없다는 뜻
int idx = 0;
int cmpnum;
int place_num[6] = {};
bool check[6] = {};

//100만보다는 작은 자연수가 있다고 가정하자
//해당 자연수 내에 있는 숫자들을 임의로 재배치해서 현재보단 큰 수 중 최솟값을 만들어내라
//단, 맨 앞자리에 0이 올 수는 없다


//재귀 및 브루트포스가 진행되는 함수
//현재 재배치로 얻게 되는 값을 number, 재배치가 시작된 자릿수를 status로 지정한다
void bruteforc(int number, int status) {
	//status가 0이라면 마지막 1자리수 작업을 진행하고
	//현재 값을 기준으로 문제 조건에 맞게 답안을 비교한다
	if (status == 0) {
		int tot = number;
		for (int i = 0;i < idx;i++) {
			if (check[i] == false) {
				check[i] = true;
				tot += place_num[i];
				check[i] = false;
				break;
			}
		}

		if (answer > tot && cmpnum < tot) {
			answer = tot;
		}
	}
	//status가 0이 아니라면 현재 자릿수를 기준으로 작업을 진행한다
	//재귀함수 적용을 위해 우선적으로 해당 위치의 check를 true로 지정, tmp에 다음 함수로 보낼 값을 계산한 다음 bruteforc에 재귀를 실행하고
	//이후에 진행할 다른 재귀함수를 위해 해당 위치의 chekc를 false로 지정한다
	else {
		for (int i = 0;i < idx;i++) {
			if (check[i] == false) {
				check[i] = true;
				int tmp = pow(10, status) * place_num[i];
				bruteforc(number + tmp, status - 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	cmpnum = N;

	while (N > 0) {
		int tmp = N % 10;
		place_num[idx] = tmp;
		idx++;
		N /= 10;
	}


	//bruteforc함수가 처음 진행되는 부분
	//맨 앞자리를 기준으로 최대 6갈래의 bruteforc가 진행된다
	for (int i = 0;i < idx;i++) {
		if (place_num[i] != 0) {
			check[i] = true;
			int tmp = pow(10, idx - 1) * place_num[i];
			bruteforc(tmp, idx - 2);
			check[i] = false;
		}
	}

	if (answer == 1000001) {
		cout << 0 << '\n';
	}
	else {
		cout << answer << '\n';
	}
	return 0;
}