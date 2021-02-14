#include<iostream>
#include<algorithm>
using namespace std;
int len[102][102] = {};

//city개의 도시가 있고 bus개의 도시간 이동경로가 있다
//이때, 각 도시에서 출발해서 각각의 도시로 도착하려 할 때, 그 때의 최단 이동비용을 구하여라
//이동경로는 s, e, cost로 표기하며 s에서 출발하여 e로 도착하고 cost만큼의 이동비용이 발생한다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int city, bus;
	cin >> city;
	cin >> bus;
	//초기화작업
	//같은곳으로 도착하는 경우는 0, 도착할 수 없는 경로인 경우엔 특정값이 저장된다
	for (int i = 1;i <= city;i++) {
		for (int j = 1;j <= city;j++) {
			if (i == j) {
				len[i][j] = 0;
			}
			else {
				len[i][j] = 1000000000;
			}
		}
	}

	//이동경로 저장 및 최소 이동비용 최초갱신
	//단, 기준은 해당 이동경로를 1번만 사용했을 경우
	for (int i = 0;i < bus;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		len[s][e] = min(len[s][e], cost);
	}

	//3중 for문을 사용하여 플로이드 와샬 알고리즘을 구현한다
	//해당 도시로 직접 가는 방법과 해당 도시를 향하는 길에 경유할 수 있는
	//다른 도시를 이용한 루트를 비교하여 최소 비용을 저장한다
	for (int k = 1;k <= city;k++) {
		for (int i = 1;i <= city;i++) {
			for (int j = 1;j <= city;j++) {
				len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
			}
		}
	}

	//출력할 때 해당 배열에 특정값이 저장돼있으면 0을, 아니면 배열값을 출력한다
	for (int i = 1;i <= city;i++) {
		for (int j = 1;j <= city;j++) {
			if (len[i][j] == 1000000000) {
				cout << 0 << " ";
			}
			else {
				cout << len[i][j] << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}