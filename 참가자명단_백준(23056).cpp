#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int M, N;

int hak_stack[11] = {};		//hak_stack[i] : i번째 학습에 있는 사람의 수. 최대 N의 값을 가지겠지?

//인적사항 정보를 구현하기 위해 만든 구조체
struct human_info {
	int hak;
	string name;
};

vector<human_info> blue;	
vector<human_info> white;	//각각 청팀, 백팀에 대한 팀원들의 정보가 들어가있다

//구조체의 조건달린 비교를 위해 만든 함수
//주로 학급번호와 이름의 길이, 최종적으론 이름의 사전순을 비교하게 된다
bool comp(human_info h1, human_info h2){
	if (h1.hak > h2.hak) {
		return false;
	}
	else if (h1.hak == h2.hak) {
		if (h1.name.length() > h2.name.length()) {
			return false;
		}
		else if (h1.name.length() == h2.name.length()) {
			if (h1.name > h2.name) {
				return false;
			}
			else if (h1.name <= h2.name) {
				return true;
			}
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}


//최대 500명까지의 학생들의 정보가 입력된다고 가정하자
//이 정보들은 운동회에 신청하고자 하는 학생들의 정보를 시간순서대로 입력한 것이다
//학생들이 속한 학급의 수는 M개이며, 각각의 번호는 1 ~ M일 때, 홀수 번 학급은 청팀, 짝수 번 학급은 백팀이 된다
//또한 각각의 학급에서 최대 N명이 나갈 수 있으며 이는 선착순으로 인해 잘리게 된다
//운동회 참가자 명단 출력 시 청팀을 백팀보다 먼저 출력하고, 학급을 오름차순 출력해야하며, 학생 이름이 짧은 것부터 출력하고, 길이가 같으면 사전순으로 출력해야 한다
//운동회 참가자 명단을 출력하라
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	bool done = true;

	//이래저래 조건이 많은 문제
	//학급별로 최대 N명이기 때문에 해당 조건을 hak_stack에 관련해서 구성한다
	//이후 조건에 맞게 bool comp 함수를 이용하여 청팀과 백팀내의 정보들을 sort한다
	while (done) {
		int hk;
		string nam;
		cin >> hk >> nam;
		if (hk == 0 && nam == "0") {
			done = false;
			break;
		}
		else {
			if (hak_stack[hk] < N) {
				if (hk % 2 == 1) {
					human_info temp;
					temp.hak = hk;
					temp.name = nam;
					blue.push_back(temp);
					hak_stack[hk]++;
				}
				else if (hk % 2 == 0) {
					human_info temp;
					temp.hak = hk;
					temp.name = nam;
					white.push_back(temp);
					hak_stack[hk]++;
				}
			}
		}
	}

	sort(blue.begin(), blue.end(), comp);
	sort(white.begin(), white.end(), comp);

	for (int i = 0;i < blue.size();i++) {	
		{
			cout << blue[i].hak << " " << blue[i].name << '\n';
		}	
	}
	
	for (int i = 0;i < white.size();i++) {
		{
			cout << white[i].hak << " " << white[i].name << '\n';
		}
	}

	return 0;
}