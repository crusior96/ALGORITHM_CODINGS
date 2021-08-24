#include<iostream>
#include<string>
using namespace std;
int primary[100001] = {};

//255개의 숫자들로 이루어진 문자열이 주어진다고 가정하자
//이 문자열을 일부분으로 나누었을 때, 해당 부분의 값이 소수인지를 판정하라
//판정은 문자열의 값이 0이 나올때까지 진행되고, 0이 나오게 된다면 그대로 종료한다
//단, 소수의 범위는 2 이상 100000 이하인 것으로 설정한다


//문제 풀이를 너무 어렵게 생각했다는 점과
//문제를 제대로 읽지 못했다는 점이 맞물려서 오래 걸렸다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool done = true;

	//에라토스테네스의 체 시전
	primary[1] = 1;
	for (int i = 2;i <= 318;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 100000;j += i) {
			primary[j] = 1;
		}
	}

	while (done) {
		int answer = 0;
		string S;
		cin >> S;

		//문자열 값이 0이면 종료
		if (S == "0") {
			break;
		}
		else {
			int curr_num;
			curr_num = 0;
			//문자열 길이가 1인 경우엔 해당 값을 기준으로 소수를 판정한다
			if (S.length() == 1) {
				int num_i = S[0] - '0';
				if (primary[num_i] == 0) {
					answer = num_i;
				}
			}
			else {
				//문자열의 모든 지점을 기준으로 1 ~ 5자의 문자열들을 부분적으로 추려낸 다음
				//해당 부분의 문자열을 숫자로 바꾸었을 때, 우선적으로 10만 이하인지를 판정한다
				//그 다음 해당값이 소수인지, 소수가 맞다면 현재 알고 있는 소수보다 큰 값인지 판정하고 갱신한다
				for (int i = 0;i < S.length();i++) {
					for (int j = 1;j <= 5;j++) {
						if (i + j == S.length() + 1) {
							break;
						}
						string tmp_s = S.substr(i, j);
						int num_i = stoi(tmp_s);
						if (num_i <= 100000) {
							if (primary[num_i] == 0) {
								if (answer == 0) {
									answer = num_i;
								}
								else if (answer < num_i) {
									answer = num_i;
								}
							}
						}
					}
				}
			}
			cout << answer << '\n';
		}
	}

	return 0;
}