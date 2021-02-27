#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

//회사의 N개의 출입기록이 있다고 가정하자
//N개의 출입기록 내에는 회사에 출입한 사람의 이름 및 출입상태가 저장될때
//현시점에 회사에 남아있는 사람의 이름들을 사전순으로 출력하라

//map 자료구조의 성질을 이용한 문제풀이
//map의 구조 : <key값, value값>
//map의 특징 : key값을 기준으로 자동 정렬되며 key값은 중복되지 않는다
//map 자료구조는 pair로 저장되며 사용처는 보통 삽입과 동시에 정렬하거나 데이터의 삽입과 삭제가 적을때 사용한다


map<string, bool>company;		//회사에 들어간 사람들의 현재 상태를 저장한다
vector<string> names;			//현재 회사에 있는 사람들의 이름을 저장한다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		string s1, s2;
		cin >> s1 >> s2;
		//만약 company내에 입출력의 기록이 남아있다면
		//s2값의 여부에따라 회사내에 남았는지 아닌지를 저장한다
		if (company.count(s1)) {
			if (s2 == "enter") {
				company[s1] = true;
			}
			else if (s2 == "leave") {
				company[s1] = false;
			}
			continue;
		}
		names.push_back(s1);
		company[s1] = true;
	}

	//회사에 있었던 사람들의 이름을 오름차순으로 정렬한다
	sort(names.begin(), names.end(), greater<string>());

	//회사내에 남아있는 사람들에 한해서 이름 출력
	for (int i = 0;i < company.size();i++) {
		if (company[names[i]]==true) {
			cout << names[i] << "\n";
		}
	}

	return 0;
}