#include<iostream>
#include<string>
using namespace std;

//N번의 테스트케이스동안 brace 변수에 괄호의 모양이 (와 )을 사용하여 입력된다.
//괄호의 모양이 () 모양처럼 되어있는것을 x라 하자. 이를 완전한 괄호라 칭한다.
//이런 모양의 괄호가 다른 종류가 또 있을때, 둘이 붙여놨을 경우에도 완전한 괄호가 될 수 있다.
//입력받은 brace변수가 완전한 괄호인지 아닌지 판단하자.

int main()
{
	int N;
	int balancer = 0;
	string brace;
	cin >> N;
	//brace문자열에 있는 괄호들의 모양에 따라 balancer변수의 값을 변화시킨다.
	//'('의 경우에는 balancer++ , ')'의 경우에는 balancer--가 된다.
	//중간에 balancer 값이 음수가 되어버리거나 문자열 끝가지 갔을때 0이 아닌경우엔 'NO'
	//문자열 끝까지 가서 계산해보았을때 0이 나오면 'YES'를 출력한다.
	for (int i = 0;i < N;i++)
	{
		cin >> brace;
		for (int j = 0;j < brace.length();j++)
		{
			if (balancer < 0)
				break;


			if (brace[j] == '(')
				balancer++;
			else if (brace[j] == ')')
				balancer--;
		}

		if (balancer == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		balancer = 0;		
	}

	return 0;
}