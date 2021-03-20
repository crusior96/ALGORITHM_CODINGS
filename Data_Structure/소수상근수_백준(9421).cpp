#include<iostream>
#include<set>
using namespace std;
int primary[1000002] = {};

//어떠한 숫자의 자릿수들의 합을 모두 분해해서
//각각의 숫자들을 제곱 및 그 값들을 더하기를 반복해서 1이 나오면 상근수라고 한다
//이때, 더하기를 반복하다가 기존에 나온 값이 나오게 되면 상근수가 아니다
//이때 N까지의 숫자가 주어진다면 소수이면서 상근수인 값을 구하여라


//범위가 100만까지이므로 해당 값까지의 소수를 판별해둔다
//소수면 primary[i]에 0, 아니면 1이 저장된다
void sosu_time() {
	primary[1] = 1;
	for (int i = 2;i <= 1000;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 1000000;j += i) {
			primary[j] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sosu_time();

	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		//소수인 경우엔 상근수 판별이 진행되며 이때 set 컨테이너가 사용된다
		//set컨테이너는 특정값의 최초 저장여부를 따질 때 유용한 컨테이너이며 트리 형식으로 저장된다
		if (primary[i] == 0) {
			set<int> sosu;
			bool done = true;
			int tmp = i;
			while (done) {
				int sang_tmp = 0;	//각 자릿수들을 제곱한 값들의 합
				int tmp2;
				while (tmp > 0) {
					tmp2 = tmp % 10;
					sang_tmp += (tmp2*tmp2);
					tmp = tmp / 10;
				}

				//최종적으로 상근수가 판별된다면 해당 i값을 출력한다.
				if (sang_tmp == 1) {
					cout << i << '\n';
					done = false;
					break;
				}

				//sosu set에 입력된 적이 있다면 while문을 break, 없다면 sosu set에 입력한다
				if (sosu.count(sang_tmp) == 0) {
					sosu.insert(sang_tmp);
				}
				else if(sosu.count(sang_tmp) == 1) {
					done = false;
					break;
				}
				tmp = sang_tmp;

			}
		}
	}
	return 0;
}
