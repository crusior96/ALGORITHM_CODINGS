#include<iostream>
#include<cmath>
using namespace std;

int N;

//N자리수의 숫자가 있다고 가정하자
//순서대로 오른 쪽의 숫자들을 하나씩 없애나가는 방식으로 숫자들을 만든다고 가정하자
//이때 해당 방식대로 만든 숫자들도 모두 소수인 경우, 그 원래의 소수값을 구하여라


//단순히 에라토스테네스의 체를 응용하기엔 문제에서 제시한 메모리가 매우 작다(4 ~ 8MB)
//따라서 모든 소수값을 저장하기보단 특정 해당하는 값만을 소수판정하는 방식으로 문제를 진행한다
//또한 오른쪽 숫자값을 차례로 없애고 마지막 한 자리만 남았을 때도 소수판정을 하기 때문에
//맨 앞자리가 2, 3, 5, 7과 같은 소수를 맨 앞자리로 가지는 N자리수 만을 판정한다


//해당 값이 소수임을 판정하는 함수
//num이 0이거나 1 혹은 소수가 아닌 경우엔 false 출력
//그 외의 경우엔 소수가 맞으니 true 출력
bool prime_detector(int num) {
	if (num == 1 || num == 0) {
		return false;
	}
	else {
		for (int i = 2;i * i <= num;i++) {
			if (num%i == 0) {
				return false;
			}
		}
	}

	return true;
}

//해당 값이 소수인지 아닌지 + 문제 조건에 맞는지를 판정하는 함수
//조건에서 제사힌 N보다 작은 len일 경우, 자릿수를 늘림과 동시에 소수 판정을 진행한다
//이때, 늘어난 자릿수엔 홀수만이 들어올 수 있다. 짝수 들어오면 2로 나뉘어서 소수가 아니게 된다
void isprime(int num, int len) {
	if (len == N) {
		cout << num << '\n';
	}

	for (int i = 1;i <= 9;i += 2) {
		if (prime_detector(num * 10 + i)) {
			isprime(num * 10 + i, len + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	isprime(2, 1);
	isprime(3, 1);
	isprime(5, 1);
	isprime(7, 1);


	return 0;
}