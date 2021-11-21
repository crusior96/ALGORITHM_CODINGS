#include<iostream>
#include<string>
#include<stack>
using namespace std;
int answer = 0;
string S;
int checker[52] = {};

//0 ~ 9의 숫자들과 (, )로 이루어진 문자열 S가 주어진다고 가정하자
//문자열 S는 원래의 다른 문자열이 특정한 규칙에 따라 압축된 상황이다
//문자열 내부에 A와 B가 숫자로만 이루어진 A(B)라는 구조의 문자열은, B라는 숫자 문자열의 총 길이 * A라는 뜻이다
//이때 규칙에 맞게 문자열을 해석한다면 이 문자열의 원래 총 길이를 구하여라
//스택을 사용한 문제풀이가 주가 된다


//규칙에 따라 진행되는 함수
int calc(int stk, int len, int idx) {
	//now_stk : 괄호가 시작된 이후 나오게 된 숫자문자열의 갯수
	int now_stk = 0;

	//만약 괄호가 닫히는 상황이라면
	//현재까지 나온 숫자문자열의 갯수 * 시작하는 괄호 바로 앞의 숫자값을 return하게 된다
	//만약 시작하는 괄호가 나오는 상황이라면 2 가지 방법으로 진행한다
	//1. 괄호 다음 괄호 => stk와 len을 지정하지 않고 바로 진행
	//2. 숫자 이후 괄호 => main함수에 있는 규칙과 같게 now_stk에서 1 빼주고 매개변수들을 전달
	//숫자라면 now_stk에 1 추가하여 현재 괄호에 있는 숫자문자열의 길이를 파악한다
	for (int i = idx + 1;i < S.length();i++) {
		if (checker[i] != 1) {
			checker[i] = 1;
			if (S[i] == ')') {
				return stk * now_stk;
			}
			else if (S[i] == '(') {
				if (S[i - 1] >= '0' && S[i - 1] <= '9') {
					now_stk--;
					int tmp = S[i - 1] - '0';
					now_stk += calc(tmp, 0, i);
				}
				else {
					now_stk += calc(stk, len, i);
				}
			}
			else if (S[i] >= '0' && S[i] <= '9') {
				now_stk++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> S;

	//문자열 길이가 1인 경우 예외처리
	if (S.length() == 1) {
		answer = 1;
	}
	else {
		//규칙적용방식
		//현시점에선 재귀가 없는 상황인만큼 숫자가 나온다면 답안인 answer에 바로 1 추가한다
		//만약 (가 나온다면, 현재 답안에서 1만큼 빼고 (의 바로 앞에 있던 숫자 문자열을 숫자로 전환한다
		//이후 해당 값과 곱해야 할 현재까지 쌓인 숫자 문자열의 갯수, 현재 탐색이 진행된 위치를 매개변수 삼아 calc에 전달한다
		//또한 checker[i]를 기준으로 이미 탐색이 진행된 곳이라면 탐색을 진행하지 않는다
		for (int i = 0;i < S.length();i++) {
			if (checker[i] != 1) {
				checker[i] = 1;
				if (S[i] >= '0' && S[i] <= '9') {
					answer++;
				}
				else if (S[i] == '(') {
					answer--;
					int tmp = S[i - 1] - '0';
					answer += calc(tmp, 0, i);
				}
			}
		}
	}
	cout << answer << '\n';

	return 0;
}