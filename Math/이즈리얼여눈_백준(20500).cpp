#include<iostream>
#include<string>
using namespace std;
long long int arr[1517] = {};

//사실상 배수판정법에 관해 알아볼 수 있었던 문제
//우리가 알고 있던 한 자릿수 배수 뿐만 아니라 다양한 2자리 수 배수들의 조건에 관해서도 알 수 있다
//문제가 물은 건 1과 5로만 이루어진 N자릿수 중 15의 배수인 수들의 갯수를 구하라는 뜻이다
//답은 1000000007로 나눈 나머지의 값을 출력하게 된다
//https://ko.wikipedia.org/wiki/%EB%B0%B0%EC%88%98_%ED%8C%90%EC%A0%95%EB%B2%95

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	//초기값만 찾아본다면 간단한 DP로 풀 수 있었다
	for (int i = 4;i <= N;i++) {
		arr[i] = ((arr[i - 2] * 2) % 1000000007 + (arr[i - 1]) % 1000000007) % 1000000007;
	}
	cout << arr[N] << '\n';
	return 0;
}