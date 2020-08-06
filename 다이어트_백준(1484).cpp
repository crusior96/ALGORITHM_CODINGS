#include<iostream>
#include<cmath>
using namespace std;

//현재 숫자의 제곱에서 과거 숫자의 제곱을 빼서 나오는 숫자를 G라고 가정하자
//이때, 현재 숫자로 가능한 숫자들을 모두 출력하고 출력할 숫자가 없다면 -1을 출력하라
//단, 과거의 숫자값은 현재의 숫자값보다 무조건 작거나 같다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int G;
	cin >> G;
	long long int s = 1;		//임의의 숫자
	long long int e = 1;		//현재 숫자
	long long int dif = 0;		//G와 비교되는 제곱연산의 결과값
	bool done = true;
	int answered = 0;

	//슬라이드 포인터가 사용되는 알고리즘
	//현재의 숫자도 임의의 숫자도 모르는 상황이므로 둘 다 1로 지정한 후 알고리즘을 시작한다
	//연산을 통해 얻은 값이 G보다 작다면 현재의 숫자값을, G보다 크다면 과거의 숫자값을 1씩 올린다.
	//과거와 현재의 숫자 차이가 1정도밖에 안나고  dif값이 G보다 크다면 알고리즘을 종료한다
	while (done) {
		dif = pow(e, 2) - pow(s, 2);

		if ((e - s == 1) && (dif > G)) {
			if (answered == 0) {
				cout << -1 << '\n';
			}
			done = false;
			break;
		}

		if (dif == G) {
			cout << e << '\n';
			answered = 1;
			s++;
		}
		else if (dif < G) {
			e++;
		}
		else if (dif >= G) {
			s++;
		}


	}
	return 0;

}