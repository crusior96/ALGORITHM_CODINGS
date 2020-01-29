#include<iostream>
#include<stack>
#include<string>
using namespace std;

//사람이 이해하는 연산식과 컴퓨터가 이해하는 연산식의 방식은 다르다 -> 이를 후위표기법이라 한다
//이때 사람이 이해하는 연산식이 입력되었을때, 컴퓨터가 연산식을 작동하는 순서를 출력하라
//연산자는 (, ), +, -, /, *이며 피연산자는 A ~ Z의 알파벳으로 이루어져있다

int main() {
	stack<char> answer; //후위표기법을 출력하기 위해 만든 임의의 스택

	string S;
	cin >> S;
	for (int i = 0;i < S.length();i++) {
		//스택에 연산자 및 피연산자가 push되는 조건들
		//1. 피연산자는 무조건 push해준다
		//2. 스택이 완전히 비어있으면 무조건 push해준다
		//3. 연산자의 우선순위가 현재 answer의 top에 있는 연산자보다 높을경우 push해준다
		//4. 연산자의 우선순위가 현재 answer의 top에 있는 연산자보다 낮거나 같을경우 현재 스택내의 모든 값을 pop해주고, 입력하려했던 연산자를 push해준다
		//4-1. (연산자는 무조건 push해준다
		//4-2. )연산자의 경우, (연산자가 나올때까지 스택내의 모든 값들을 pop해준다
		//4-3. 위의 4.번째 규칙에서도 모든 값을 pop할때 (가 내부에 있다면 그 앞까지만 pop해준다
		if (S[i] >= 'A'&&S[i] <= 'Z') {
			cout << S[i];
		}
		else if (S[i] == '*' || S[i] == '/') {
			while (!answer.empty() && (answer.top() == '/' || answer.top() == '*')) {
				cout << answer.top();
				answer.pop();
			}
			answer.push(S[i]);
		}
		else if (S[i] == '+' || S[i] == '-') {
			while (!answer.empty() && answer.top() != '(') {
				cout << answer.top();
				answer.pop();
			}
			answer.push(S[i]);
		}
		else if (S[i] == '(') {
			answer.push(S[i]);
		}
		else if (S[i] == ')') {
			while (!answer.empty() && answer.top() != '(') {
				cout << answer.top();
				answer.pop();
			}
			answer.pop();
		}
		
	}

	//만약 스택내에 남아있는 연산자 및 피연산자가 있다면 모조리 pop해준다
	while (answer.empty() != true) {
		cout << answer.top();
		answer.pop();
	}

	return 0;
}