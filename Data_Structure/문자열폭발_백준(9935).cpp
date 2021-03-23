#include<iostream>
#include<string>
#include<vector>
using namespace std;

//문자열 S가 주어진다고 가정하자
//폭탄 문자열인 B와 일치하는 문자열이 있다면, 만들어지는 대로 S 문자열에서 제거시키고
//남은 문자열들끼리 서로 합쳐주는 작업을 진행한다.
//이때 합쳐지면서 만들어진 문자열 내에서 B가 또 보이게 된다면 해당 문자열을 지워주도록 한다
//최종적으로 남아있는 문자열이 없다면 "FRULA"를 출력하고, 남아있는 문자열이 있다면 그걸 출력한다.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string S, B;
	vector<char> ans;
	cin >> S;
	cin >> B;
	for (int i = 0;i < S.length();i++) {
		ans.push_back(S[i]);

		//현재까지 ans 벡터에 입력된 문자열의 갯수가 폭탄 문자열보다 길 때에만 체크 시작
		if (ans.size() >= B.length()) {
			//입력된 문자가 폭탄문자열의 마지막 부분과 같을때 탐색시작
			//해당 부분에서부터 앞으로 나아가면서 폭탄문자열만큼 길이가 같은 부분이 있다면
			//해당 부분을 지워버린다. 여기서 vector의 erase 함수 사용
			if (ans[ans.size() - 1] == B[B.length() - 1]) {
				bool checker = true;
				for (int j = 2;j <= B.length();j++) {
					if (ans[ans.size() - j] != B[B.length() - j]) {
						checker = false;
					}
				}
				if (checker == true) {
					ans.erase(ans.end() - B.length(), ans.end());
				}
			}
		}
	}

	if (ans.size() == 0) {
		cout << "FRULA" << '\n';
	}
	else {
		for (int i = 0;i < ans.size();i++) {
			cout << ans[i];
		}
		cout << '\n';
	}
	
	return 0;
}
