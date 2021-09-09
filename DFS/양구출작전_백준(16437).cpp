#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int N;

//섬과 섬 사이의 연결 상태를 저장한 vector
vector<int> island[123460];

//DFS를 진행하는 함수 부분
//변수값으로 현재 섬의 양 & 늑대들의 분포상태 및 마릿수, 현재 섬의 위치를 가지게 된다
//return 값으론 현 위치에서 도착할 수 있는 양의 마릿수이다
long long int DFS_SW(vector<pair<char, int>> &lands, int curr) {
	//curr의 위치에서 나아갈 수 있는 다른 섬들의 갯수
	int siz = island[curr].size();

	//curr의 위치가 단말 노드인 경우
	//해당 위치에 양이있으면 그 만큼의 숫자를, 늑대라면 0을 return한다
	if (siz == 0) {
		if (lands[curr].first == 'S') {
			return lands[curr].second;
		}
		else {
			return 0;
		}
	}

	//단말노드까지 이어졌을 때, 얻을 수 있는 최대 양의 마릿수
	long long int now = 0;

	//탐색이 이루어질 다음 위치의 값을 next로 지정한 후, 해당 변수와 함께 DFS_SW를 계속 진행한다
	for (int i = 0;i < siz;++i) {
		int next = island[curr][i];
		now += DFS_SW(lands, next);
	}

	//탐색을 진행할 때, 늑대라 해서 음수가 된다면, 0으로 고정시켜버리고
	//양이라 한다면 양수로 바꿔서 값을 전송시킨다
	if (lands[curr].first == 'W') {
		now -= lands[curr].second;
		if (now < 0) {
			now = 0;
		}
	}
	else {
		now += lands[curr].second;
	}
	return now;
	
}

//N개의 섬이 있다고 가정하자. 각각 1 ~ N의 번호를 가지고 있다
//모든 섬들은 어떻게든 1번 섬으로 향하는 길이 있고, 1번 섬까지 도착하는 양의 마릿수를 구하고자한다
//각각의 섬에는 양과 늑대가 있고, 늑대는 양이 오는 순간 즉각적으로 먹게 된다
//하지만, 늑대는 정해진 수치만큼 양을 먹으면 그 이후론 안먹는다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	//현재 위치의 섬이 양인지 늑대인지, 그 개체수가 얼마인지 저장한 vector
	vector<pair<char, int>> islands(N + 1);
	islands[1] = make_pair('S', 0);

	for (int i = 2;i <= N;i++) {
		char species;
		int num;
		int parent;
		cin >> species >> num >> parent;
		islands[i] = make_pair(species, num);
		island[parent].push_back(i);
	}

	
	cout << DFS_SW(islands, 1) << '\n';
	return 0;
}