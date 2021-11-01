#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

int R, C;
int answer = -1;
char name_str[1002][1002] = {};			//문자열 배열을 90도 돌리기 위해 만든 임시 배열
string name_list_real[1002] = {};		//문자열을 C * R의 상태로 저장해둔 배열


//각각의 문자열들을 0번째 문자에서 e번째 문자까지 substr을 진행한 이후
//해당 값들을 set 자료구조에 입력해서 set 자료구조의 size를 return 한다
//만약 중복되는 문자열이 있었다면 C보다 작은 값이 return될 것이다
int string_search(int s, int e) {
	set<string> name_sets;

	for (int i = 0;i < C;i++) {
		string tmp = name_list_real[i].substr(0, e);
		name_sets.insert(tmp);
	}

	return name_sets.size();
}

//R * C의 크기에 문자열이 배치돼있다고 가정하자
//문자열들을 위에서 아래로 읽어나간다고 가정하자. 그러게 한다면 총 C개의 문자열이 만들어질 것이다
//이때, 맨 윗줄의 문자열을 지우게 됐을 때 만들어진 C개의 문자열 중 중복되는 것이 없다면 맨 윗줄의 문자열을 지워버린다
//만약 같은 조건에서 중복되는 문자열이 발견된다면, 현재까지 지운 문자열의 총 갯수를 구하여 출력한다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> name_str[R - i - 1][j];
		}
	}

	//R * C 상태인 문자열의 배치를 C * R의 배치로 바꾸는 과정
	for (int i = 0;i < C;i++) {
		string tmp = "";
		for (int j = 0;j < R;j++) {
			tmp += name_str[j][i];
		}
		name_list_real[i] = tmp;
	}


	//C개의 문자열들에 대해 substr(0, R - i - 1)로 나오는 문자열들 중 중복되는 문자열이 있는지 없는지 체크 진행
	//만약 중복되는 값이 있다면 return값인 tmp가 C보다 작을 것이다
	for (int i = 0;i < R - 1;i++) {
		int tmp = string_search(0, R - i - 1);

		if (tmp < C) {
			answer = i;
			break;
		}
	}

	if (answer < 0) {
		cout << R - 1 << '\n';
	}
	else {
		cout << answer << '\n';
	}

	return 0;
}

