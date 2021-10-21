#include<iostream>
using namespace std;

//어떠한 달력이 있다고 가정하자
//해당 달력은 매 주차마다 1개의 줄을 사용하고, 1달이 끝나는 부분의 줄 이후로 이어서 쓸땐
//무조건 다음 줄로 넘어가서 쓴다고 가정하자
//해당 달력에 적힌 1년에 있는 달의 갯수와, 각각의 달에 있는 일의 수, 달력에 표기되는 1주의 날짜 기준을 입력한다면
//달력이 출력되는 총 줄의 갯수를 구하여라

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long int lcm(long long int a, long long int b, long long int gc) {
	return (a*b) / gc;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		long long int M, D, W;
		cin >> M >> D >> W;
		//정수론과 비슷한 문제라서 수식 설명만 하면 될듯하다
		//1. 기본적으로 전체 일수를 구한 다음, 해당 주차가 총 몇주차로 이루어졌는지 구한다
		//2. 매 달이 끝나면 무조건 다음 줄로 넘어가는 조건이 있지만 경우에 따라 줄의 마지막 칸에 달의 마지막 날이 적힐수도 있다
		//3. 따라서 해당 경우를 찾기 위해 전체 달의 갯수 - 기가막히게 마지막 달의 날짜가 줄의 마지막칸인 경우의 수를 계산한다
		//4. 해당 달력이 이루어진 기본적인 주차의 수 + 어쩔 수 없이 다음줄로 넘어가야하는 3번의 경우를 계산하면 된다

		long long int answer_1 = (M * D) / W;
		long long int gcd_temp = gcd(W, D);
		long long int lcm_temp = lcm(W, D, gcd_temp);
		long long int tmp1 = lcm_temp / D;
		long long int answer_2 = M - (M / tmp1);
		long long int answer = answer_1 + answer_2;
		cout << "Case #" << i + 1 << ": " << answer << '\n';
	}
	return 0;
}