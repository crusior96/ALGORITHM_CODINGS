#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

//N개의 회의를 한 사무실 안에서 모두 끝낼수 없는 상황속에서 최대한 많은 갯수의 회의를 진행하고자 한다
//N개의 회의들이 이루어질 때 시작시간과 끝나는 시간이 주어진다면 최대한 몇 개의 회의를 할 수 있는가?
//이때 시작시간 및 끝나는 시간의 범위는 2^31-1 미만이다

using namespace std;
int work_start[100000] = {};
int work_end[100000] = {};

int main() {
	vector<pair<int, int>> order;	//회의의 시작 및 끝나는 시간이 저장되어지는 벡터
									//pair 콘테이너를 사용한다
	int N;
	int fastest = 0;				//회의가 시작해야하는 시간들 중 제일 이른 시간
	int work_num = 0;				//현재까지 이루어진 회의의 갯수
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> work_start[i] >> work_end[i];
	}

	//주어진 회의들을 회의 시작시간을 기준으로 나열한다
	for (int i = 0;i < N;i++) {
		order.push_back(make_pair(work_end[i], work_start[i]));
	}
	sort(order.begin(), order.end());

	//그리디 알고리즘을 사용하여 단순히 시작시간이 제일 이르고 시작시간이 같다면 끝나는 시간이 제일 이른 회의부터 회의실에 배정한다
	//다른 알고리즘에 비하여 O(log N)의 시간복잡도를 가지고 있다
	for (int i = 0;i < order.size();i++) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;

		if (fastest <= meetingBegin) {
			fastest = meetingEnd;
			work_num++;
		}
	}

	cout << work_num << endl;
	return 0;
}