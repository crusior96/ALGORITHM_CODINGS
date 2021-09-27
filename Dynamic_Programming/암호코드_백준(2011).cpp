#include<iostream>
#include<string>
using namespace std;
string S;
int answer = 0;
int arr[5002] = {};

//최대 5천자의 숫자가 있다고 가정하자
//각각의 숫자들의 일부를 알파벳으로 형상화할 수 있다고 가정하자 1 -> A, 26 -> Z와 같은 규칙이다
//이때 숫자가 주어진다면 해당 숫자를 알파벳으로 만들었을 때 만들 수 있는 알파벳들의 종류를 구하여라
//문제 자체는 DP이지만 0으로 인해 다양한 제약 조건이 주어진다. 복잡한 조건을 잘 풀어나가야 한다.


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	int zero_stack = 0;		//알파벳 변경이 불가능함을 안내하는 변수
	int resolved = 0;		//알파벳 변경이 불가능함을 안내하는 변수 2
							//해당 변수가 각각 2, 1이 될 경우 알파벳 변경이 불가능함을 확정한다


	//주어진 숫자의 맨 앞자리가 0이 있다면 알파벳 변경이 불가능함을 암시
	if (S[0] == '0') {
		resolved = 1;
		zero_stack = 2;
		answer = 0;
	}

	//주어진 숫자에 0이 2번 이상 연속으로 배치돼있다면 알파벳 변경이 불가능함을 암시
	for (int i = 0;i < S.length();i++) {
		if (S[i] == '0') {
			zero_stack++;
		}
		else {
			zero_stack = 0;
		}

		if (zero_stack >= 2) {
			resolved = 1;
			answer = 0;
			break;
		}
	}

	//알파벳 변경이 불가능하면 0을 출력하게 된다
	if (resolved == 1) {
		cout << answer << '\n';
	}
	//알파벳 변경 자체가 일단 가능하다면
	else if(resolved != 1){

		//DP 초기값 지정
		//맨 앞자리가 0이 아닌경우(사실상 0이 아니긴함)
		if (S[0] != '0') {
			arr[0] = 1;

			//2번째 자리까지 비교해서 해당 2자리가 10 이상 26인지 체크한다
			//이후 2번째 자리값이 0이 아닌 경우를 체크한다
			if ((S[0] - '0') * 10 + S[1] - '0' >= 10 && (S[0] - '0') * 10 + S[1] - '0' <= 26) {
				arr[1] = 1;
			}

			if (S[1] != '0') {
				arr[1] += 1;
			}
		}


		//숫자의 길이기 2보다는 클 경우 DP를 진행한다
		if(S.length() > 2){
			for (int i = 2;i < S.length();i++) {
				//매 자릿수마다 0이 아닌경우에 실행되는 점화식
				if (S[i] != '0') {
					arr[i] = (arr[i] + arr[i - 1]) % 1000000;
				}

				//현재 자릿수와 바로 앞의 자릿수 즉 총 2개의 자릿수가 모두 0이 아닌경우 실행되는 점화식
				//주의할 점은 2개 자릿수를 기준으로 테스트한 것이기 때문에 arr[i] + arr[i - 2]가 옳은 표현이다
				if (S[i - 1] != '0') {
					int tmp = (S[i - 1] - '0') * 10 + S[i] - '0';
					if (tmp >= 10 && tmp <= 26) {
						arr[i] = (arr[i] + arr[i - 2]) % 1000000;
					}
				}
			}
		}

		cout << arr[S.length() - 1] << '\n';
	}


	return 0;
}