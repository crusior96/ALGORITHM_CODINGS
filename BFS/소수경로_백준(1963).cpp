#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int primary[10001] = {};		//primary[i] = 0이어야 i가 소수임을 입증할 수 있다
int checker[10001] = {};		//checker[i] = i까지 숫자를 바꾸는 데 소모된 기회의 횟수
								//-1로 초기화 할 필요가 있다

//4자리 자연수의 특정한 암호가 있다고 가정하자
//각각 1개 자리를 한 번 바꾸는 방식으로 다른 암호로 만들고자 하는데, 목표하는 암호값이 있다고 가정하자
//이때, 최소한의 횟수로 변환하여 목표하는 암호값에 도달하는 방법을 구하여라
//앞자리가 0인 경우는 소수 경로로 포함하지 않는다


//현재 위치에서 자릿수를 바꿔가면서 소수 경로인지 체크하고, 목표한 소수까지 도달할 수 있는지,
//변환의 횟수가 최소한인지 확인하는 함수
//queue를 사용해서 최소한의 탐색횟수를 기준으로 탐색 범위를 넓혀나간다
void bfs(int idx, int target, int cost) {
	queue<int> q;
	q.push(idx);
	checker[idx] = 0;
	int answer = 0;
	while (q.empty() == false) {
		int tmp = q.front();
		q.pop();

		//목표 위치에 도달했다면 답안을 저장한다
		if (tmp == target) {
			answer = checker[tmp];
			break;
		}

		//현재 위치의 소수를 기준으로 소수의 각 자리를 0에서 9까지 바꿔가면서 대입한다
		//그 다음, 바뀐값이 소수임과 동시에 checker[바뀐소수]의 값이 -1이라면
		//다음 회차의 bfs탐색 소수로 사용을 한다
		for (int i = 0;i < 4;i++) {
			string tmp_s = to_string(tmp);
			for (int j = 0;j < 10;j++) {
				tmp_s[i] = '0' + j;
				int tmp_i = stoi(tmp_s);
				if (tmp_i >= 1000 && primary[tmp_i] == 0 && checker[tmp_i] == -1) {
					checker[tmp_i] = checker[tmp] + 1;
					q.push(tmp_i);
				}
			}
		}
	}
	cout << answer << '\n';
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	primary[1] = 1;
	for (int i = 2;i <= 100;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 10000;j += i) {
			primary[j] = 1;
		}
	}

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		memset(checker, -1, sizeof(checker));
		int s, e;
		cin >> s >> e;
		bfs(s, e, 0);
	}

	return 0;
}