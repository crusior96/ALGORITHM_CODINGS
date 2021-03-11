#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> P;

//이번엔 N개의 버스정류장과 G개의 버스노선이 있다고 가정하자
//1번째 버스정류장에서 출발하여 N번째 버스정류장에 도착하고자하는데
//중간지점인 mid1번째 버스정류장과 mid2번째 버스정류장을 경유해야만 한다
//위와같은 방식으로 이동했을 경우, 최단거리의 길이를 구하고 길이를 못구하면 -1을 출력하라
//단, 문제에서 주어진 간선은 양방향으로 이동이 가능하며 이동중에 어느 간선 버스정류장이건 반복방문은 가능하다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, G, start, end, mid1, mid2;
	cin >> N >> G;
	start = 0;
	end = N - 1;
	int chk[4] = {};			//chk[i]번째 버스정류장에서 chk[i+1]번째 버스정류장까지의 이동거리를 구하기 위한 좌표
	int total_len = 0;			//1번째 이동루트로 얻을 수 있는 최단거리
	int total_len2 = 0;			//2번째 이동루트로 얻을 수 있는 최단거리
	vector<P> adj[801];	

	

	for (int i = 0;i < G;i++) {
		int s, e, w;
		cin >> s >> e >> w;
		//양방향으로 이동이 가능한 간선이므로 간선목록에 출발과 도착위치를 바꿔가면서 2번 추가해줘야한다
		adj[s - 1].push_back(P(e - 1, w));
		adj[e - 1].push_back(P(s - 1, w));
	}

	cin >> mid1 >> mid2;
	chk[0] = start;
	chk[1] = mid1 - 1;
	chk[2] = mid2 - 1;
	chk[3] = end;

	//간단하게, 주어진 3개의 핵심 버스장 좌표에서 다익스트라 알고리즘을 3번 돌려주면 끝
	//문제풀이과정중 틀렸습니다가 자주 나온 이유는 문제를 제대로 안 읽어서 '양방향'이라는것을 놓쳤기 때문


	//1번째 -> mid1번째 -> mid2번째 -> end번쨰 버스정류장 이동루트

	for (int i = 0;i < 3;i++) {

		priority_queue<P, vector<P>, greater<P>> PQ;
		bool visited[801];
		int distance[801];
		fill(distance, distance + 801, 2400001);
		fill(visited, visited + 801, 0);
		distance[chk[i]] = 0;
		PQ.push(P(0, chk[i]));
		while (!PQ.empty()) {
			int idx;
			do {
				idx = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[idx]);
			if (visited[idx])
				break;

			visited[idx] = true;
			for (auto &p : adj[idx]) {
				int next = p.first;
				int dist = p.second;

				if (distance[next] > distance[idx] + dist) {
					distance[next] = distance[idx] + dist;
					PQ.push(P(distance[next], next));
				}
			}
		}

		if (distance[chk[i + 1]] == 2400001) {
			total_len = 0;
			break;
		}
		else {
			total_len += distance[chk[i + 1]];
		}
	}

	chk[0] = start;
	chk[1] = mid2 - 1;
	chk[2] = mid1 - 1;
	chk[3] = end;

	//1번째 -> mid2번째 -> mid1번째 -> end번째 버스정류장 이동루트

	for (int i = 0;i < 3;i++) {

		priority_queue<P, vector<P>, greater<P>> PQ;
		bool visited[801];
		int distance[801];
		fill(distance, distance + 801, 2400001);
		fill(visited, visited + 801, 0);
		distance[chk[i]] = 0;
		PQ.push(P(0, chk[i]));
		while (!PQ.empty()) {
			int idx;
			do {
				idx = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[idx]);
			if (visited[idx])
				break;

			visited[idx] = true;
			for (auto &p : adj[idx]) {
				int next = p.first;
				int dist = p.second;

				if (distance[next] > distance[idx] + dist) {
					distance[next] = distance[idx] + dist;
					PQ.push(P(distance[next], next));
				}
			}
		}

		if (distance[chk[i + 1]] == 2400001) {
			total_len2 = 0;
			break;
		}
		else {
			total_len2 += distance[chk[i + 1]];
		}
	}

	
	if (total_len == 0 && total_len2 == 0) {
		cout << -1 << '\n';
	}
	else {
		if (total_len == 0 && total_len2 != 0) {
			cout << total_len2 << '\n';
		}
		else if (total_len != 0 && total_len2 == 0) {
			cout << total_len << '\n';
		}
		else {
			if (total_len >= total_len2) {
				cout << total_len2 << '\n';
			}
			else if (total_len < total_len2) {
				cout << total_len << '\n';
			}
		}
	}
	
	return 0;

}