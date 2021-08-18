#include<iostream>
#include<list>
#include<cmath>
#include<queue>
using namespace std;

//K개의 소수들이 나열해있다고 가정하자
//해당하는 소수들끼리 곱해서 만들 수 있는 숫자들을 작은 숫자들부터 앞에 오는걸로 정렬한다면
//정렬한 숫자들 중 N번째 숫자는 무엇인지 구하여라
//단, 입력되는 숫자는 541보다 작은 숫자이며, 답으로 나올 수 있는 숫자는 2^31보다 작다
int main() {
	int K, N;
	int primes[101] = {};

	//자동적으로 오름차순 정렬을 진행하기 위해 소수의 곱들을 저장하는 우선순위 큐
	//사이즈 또한 N * (K-1)개만큼 저장하면 돼서 크게 부담은 없다.
	priority_queue<long> PQ;	
	cin >> K >> N;
	for (int i = 0;i < K;i++) {
		int temp;
		cin >> temp;
		primes[i] = temp;
		PQ.push(-temp);
	}

	long answer;
	
	//풀이방식
	//1. 우선 소수들을 PQ에 저장한다
	//2. PQ에서 제일 작은 숫자를 출력하여 소수들이 저장된 배열인 primes의 모든 값과 곱해본다
	//3. answer%primes[j] == 0 즉, 중복되는 곱셈이 진행될 경우,
	//	 해당 부분까지만 PQ값에 저장한 후 primes 배열내의 소수들끼리 곱하는 것을 멈춘다
	//	 이는 중복된 값이 PQ에 저장되는것을 막기 위해서이다
	//4. 그렇게 PQ에서 자료값을 뽑는 과정을 N번 반복한 다음 answer값을 출력하면 된다.
	for (int i = 0;i < N;i++) {
		answer = PQ.top();
		PQ.pop();
		answer = answer * -1;
		for (int j = 0;j < K;j++) {
			long temp = answer * primes[j];
			PQ.push(temp * -1);
			if (answer%primes[j] == 0) {
				break;
			}
		}
	}


	cout << answer << '\n';
	return 0;
}