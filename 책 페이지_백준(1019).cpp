#include<iostream>
using namespace std;
long long int checker[10];

//어떤 책이 N페이지만큼 있다고 하자. 문제는 그 페이지가 10억까지 갈 수도 있다
//이때, 1페이지서부터 N페이지에는 각각의 페이지에 맞는 숫자들이 기록돼있는데
//0부터 9까지 숫자들이 총 몇번 나오는지 출력하라

//숫자들이 몇 개 있는지 checker에 저장하는 함수
void num_analyzer(long long n, long long n2) {
	while (n > 0) {
		checker[n % 10] += n2;
		n = n / 10;
	}
}


//시간 단축을 위해 설계한 함수
void counter(long long int A, long long int B, long long int n2) {
	while (A % 10 != 0 && A <= B) {
		num_analyzer(A, n2);
		A++;
	}
	if (A > B) {
		return;
	}

	while (B % 10 != 9 && B >= A) {
		num_analyzer(B, n2);
		B--;
	}

	//counter 함수에 넣을 숫자값을 늘리고 줄일 때 임의적으로 숫자 카운팅을 하기 위한 부분
	//정수론이 약간 섞인 부분으로, 숫자가 이만큼은 중복되서 나왔겠구나를 카운팅해서 해당 값을 checker에 곱해나가는 것
	//솔직히 이해가 아직도 잘 안간다. 단순 구현 파트 + 재귀만 쓰면 되는 부분이긴하지만
	//여기는 구현이 빡세다. 근데 이렇게 안 하면 시간초과가 나는 건 시간문제다
	long long cnt = (B / 10 - A / 10 + 1);
	for (int i = 0;i < 10;i++) {
		checker[i] += cnt * n2;
	}

	counter(A / 10, B / 10, n2 * 10);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int num;
	cin >> num;
	counter(1, num, 1);
	for (int i = 0;i < 10;i++) {
		cout << checker[i] << " ";
	}
	return 0;
}