#include<iostream>
#include<vector>
using namespace std;
int M, N, T;
int answer = 0;

char arr[7][7] = {};
bool checked[7][7] = {};

//약 5 * 6 사이즈의 지도가 있다고 가정하자
//이동할 수 있는 공간은 ., 이동 못 하는 공간은 T로 표기된다
//좌하단에서 출발해서 우하단으로 이동하고자 하는데 총 이동거리는 무조건 T만큼 소모돼야 한다
//또한 한 번 방문했던 곳은 다시 방문할 수 없다
//위의 규칙을 가진 채 이동할 수 있는 경로의 총 가짓수를 구하여라


//브루트포스가 진행되는 함수
//현재 이동한 위치와 이동한 거리의 길이, 방문 여부가 포함된 배열을 매개변수로 가지고 있다
//지도의 크기가 작아서 가능했던 풀이방식
void brute(int x, int y, int cnt, bool c[7][7]) {
	//이동 횟수가 아직 T 이하라면
	if(cnt <= T){
		//목적지 도착 + T만큼 이동한 게 맞다면 answer++
		if (x == 0 && y == N - 1 && cnt == T) {
			answer++;
		}
		else {
			//그 외의 경우
			//현 위치에서 상하좌우 1칸으로 이동했을 때
			//규칙에 위배되지 않는다면 해당 위치로 이동한 이후 브루트포스를 진행한다
			if (x + 1 < M) {
				if (c[x + 1][y] == 0 && arr[x + 1][y] == '.') {
					c[x + 1][y] = 1;
					brute(x + 1, y, cnt + 1, c);
					c[x + 1][y] = 0;
				}
			}

			if (x - 1 >= 0) {
				if (c[x - 1][y] == 0 && arr[x - 1][y] == '.') {
					c[x - 1][y] = 1;
					brute(x - 1, y, cnt + 1, c);
					c[x - 1][y] = 0;
				}
			}

			if (y + 1 < N) {
				if (c[x][y + 1] == 0 && arr[x][y + 1] == '.') {
					c[x][y + 1] = 1;
					brute(x, y + 1, cnt + 1, c);
					c[x][y + 1] = 0;
				}
			}

			if (y - 1 >= 0) {
				if (c[x][y - 1] == 0 && arr[x][y - 1] == '.') {
					c[x][y - 1] = 1;
					brute(x, y - 1, cnt + 1, c);
					c[x][y - 1] = 0;
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> T;

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	checked[M - 1][0] = 1;

	brute(M - 1, 0, 1, checked);

	cout << answer << '\n';
	return 0;
}