#include<iostream>
#include<string>
using namespace std;

//num개의 반지에는 10개의 대문자 영어로 이루어진 문자열이 존재한다.
//문자열은 반지 특성상 환형으로 이루어져있고, 읽는 방향은 무조건 왼 -> 오른쪽이다.
//이때, 반지에 있는 문자열 중 code를 포함한 반지의 갯수는 총 몇개인가?

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int answer = 0;
	string code;
	string rings[101] = {};
	int num;
	cin >> code;
	int code_len = code.length();
	cin >> num;

	for (int i = 0;i < num;i++) {
		cin >> rings[i];
		rings[i] = rings[i] + rings[i];
	}


	//string 헤더 내에 있는 find 함수와 npos를 알면 쉬운 문제(모르면 맞아야지류 문제)
	//string_A.find(string_B) : A 문자열에 B 문자열이 있으면 B 문자열이 포함된 곳의 A 문자열상의 위치를 출력한다. 없으면 npos가 출력된다
	//모르면 modular 연산을 통해 반지 문자열이 저장되어있는 문자들의 배열을 환형 배열로 바꿔 저장해서 찾는 방법이 있다

	for (int i = 0;i < num;i++) {
		if (rings[i].find(code) != string::npos) {
			answer++;
		}
	}
	cout << answer << endl;

	return 0;
}