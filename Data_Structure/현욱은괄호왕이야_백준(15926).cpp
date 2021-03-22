#include<iostream>
#include<stack>
#include<string>
using namespace std;

//길이가 1 ~ 200000인 소괄호로만 이루어진 문자열이 있다
//괄호가 ()와같이 규칙이 이루어져야만 완전한 괄호이며, 규칙이 맞은 괄호들끼리 이어져있거나 서로 포함되어있다면 그것을 하나의 완전한 괄호로 볼 수 있다
//이때 문자열 내에서 얻을 수 있는 최장의 완전한 괄호길이를 구하여라

int main()
{
	int N;
	int answer = 0;
	string brace;		//입력받을 소괄호문자열
	stack<int> bracer;	//최장길이를 알아내기위해 쓰는 스택
	cin >> N;
	cin >> brace;
	bracer.push(-1);
	for (int j = 0;j < brace.length();j++)
	{
		if (brace[j] == '(')
		{
			bracer.push(j);	//스택에 현재위치 입력
		}
		else if (brace[j] == ')')
		{
			bracer.pop();
			if (bracer.empty() != true) {
				answer = answer > j - bracer.top() ? answer : j - bracer.top();
				//스택이 비어있지 않다면, 유효한 괄호문자열임을 의미한다
				//현재까지 알아낸 answer와 현재위치에서 스택의 top()값을 뺀 것을 비교하여 더 큰 값을 answer로 수정한다
			}
			else {
				bracer.push(j);	//스택이 비어있다면, 현재 위치를 입력해준다
			}
		}
	}



	cout << answer << endl;

	return 0;
}
