#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int indegree[502];			//해당 건물을 짓는데 연관된 다른 건물들의 갯수가 저장됨
int build_time[502];		//build_time[i] : i번째 건물을 짓는데 필요한 시간
int total_time[502];		//total_time[i] : i번째 건물을 짓기 위한 선행규칙 등등 모두를 포함한 시간
vector<int> adj[502];		//해당 건물을 짓는데 연관된 다른 건물들에 대한 연관성 정보가 저장됨
queue<int> Q;

//N개의 건물들을 짓고자 한다고 가정하자
//각각의 건물들에는 해당 건물을 짓는데 필요한 시간, 해당 건물을 짓기 위해 지어야 할 선행건물에 대한 정보가 들어간다
//해당 정보입력의 끝은 -1로 표시한다
//이때 모든 건물들을 다 짓는데 필요한 최소 시간을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	//위상정렬을 사용하기 위해 정보 저장
	for (int i = 1;i <= N;i++) {
		bool done = true;
		int time;
		cin >> time;
		build_time[i] = time;
		while (done) {
			int tmp;
			cin >> tmp;
			if (tmp == -1) {
				done = false;
				break;
			}
			indegree[i]++;
			adj[tmp].push_back(i);
		}
	}

	//위상정렬을 사용하기 위해 일단 indegree값이 0인것부터 Q에 push하여 위상정렬을 진행한다
	for (int i = 1;i <= N;i++) {
		if (indegree[i] == 0) {
			total_time[i] = build_time[i];
			Q.push(i);
		}
	}

	//해당 건물번호와 연관된 다른 건물들을 짓는 total_time에 현재 건물을 짓는데 필요한 시간들을 추가한다
	//해당 건물번호와 연관된 다른 건물들의 indegree값이 0이라면 Q에 push하고 위상정렬을 계속한다
	for (int i = 1;i <= N;i++) {
		int now = Q.front();
		Q.pop();
		for (int next : adj[now]) {
			total_time[next] = max(total_time[next], total_time[now] + build_time[next]);
			if (--indegree[next] == 0) {
				Q.push(next);
			}
		}	
	}

	for (int i = 1;i <= N;i++) {
		cout << total_time[i] << '\n';
	}
	return 0;
}