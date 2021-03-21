#include<iostream>
#include<string>
#include<stack>
using namespace std;

//A와 B로만 이루어져있는 문자열이 N개 있다.
//A와 B의 갯수가 같고, 같은 단어끼리 서로 쌍을 이루기 위해 그어놓은 선이 교차하지 않아야 좋은 단어라 할 수 있다
//이때 나열된 N개의 단어들 중 좋은 단어의 갯수를 구하라

int main() {
	int N;
	int goods = 0;
	stack<char>words; //좋은 단어를 테스트하기위해 쓰이는 stack
	cin >> N;
	for (int i = 0;i < N;i++) {
		string S;
		cin >> S;
		for (int j = 0;j < S.length();j++) {
			//stack이 비어있거나 stack의 top과 다른 단어이면 stack에 push해준다
			//stack의 top과 같은 단어면 top을 pop해준다
			if (words.empty() == true)
			{
				words.push(S[j]);
			}
			else if (words.top() != S[j]) {
				words.push(S[j]);
			}
			else if (words.top() == S[j]) {
				words.pop();
			}
		}

		//위 규칙대로 stack이 완전히 비어있으면 좋은단어이다
		if (words.empty() == true) {
			goods++;
		}
		else {
			//규칙을 만족하지 못하여 stack내부에 단어가 남아있다면 stack내부를 완전히 비울수 있도록 pop해준다
			while (words.empty() != true) {
				words.pop();
			}
		}
	}

	cout << goods << endl;

	return 0;
}
