#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int> mapdot[5005];			//mapdot[i] : i번 색깔을 가진 점들의 좌표 위치가 저장되는 곳
vector<pair<int, int>> dot_idx;		//점들의 정보가 저장되는 곳

//N개의 점에 대한 좌표들이 들어온다고 가정하자
//각각 해당 점의 위치와 점의 색깔을 지정해주게 되고 수직선상에 있게된다
//점들은 자신 인근에 제일 가까운 점과 화살표를 이루게 된다 가정할 때
//그렇게 만들어지는 화살표들의 길이의 합을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int answer = 0;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int idx, color;
		cin >> idx >> color;
		dot_idx.push_back({ idx,color });
	}

	//점의 정보들을 점의 위치를 기준으로 정렬한다
	sort(dot_idx.begin(), dot_idx.end());

	//점의 색깔들을 기준으로 해당 색깔을 가진 점들의 위치를 저장한다
	//이때 사전에 점의 위치가 정렬됐기 때문에 mapdot[점색깔번호]에 저장되는 좌표들은 오름차순이 된다
	for (int i = 0;i < N;i++) {
		mapdot[dot_idx[i].second].push_back(dot_idx[i].first);
	}

	//화살표의 길이를 구하기 위한 부분
	//특정 색깔을 가진 점들의 모임이 2개 이상이어야만 화살표가 구성될 수 있다는 점과
	//점의 위치가 해당 점 그룹의 맨 앞인지 맨 뒤인지에 따라서도 다른 로직을 사용한다
	for (int i = 1;i <= N;i++) {
		if (mapdot[i].size() > 1) {
			for (int j = 0;j < mapdot[i].size();j++) {
				if (j == mapdot[i].size() - 1) {
					answer += mapdot[i][j] - mapdot[i][j - 1];
				}
				else if (j == 0) {
					answer += mapdot[i][j + 1] - mapdot[i][j];
				}
				else {
					answer += min(mapdot[i][j + 1] - mapdot[i][j], mapdot[i][j] - mapdot[i][j - 1]);
				}
			}
		}
	}

	cout << answer << '\n';
	
	return 0;
}