#include<iostream>
#include<vector>
using namespace std;
int parents[52] = {};	//parents[i] : i번째 노드의 parent가 저장되는 부분
int N;

//N개의 노드들이 주어진다 가정하자. 각각의 노드들은 0에서부터 (N - 1)의 순차적인 번호를 부여받는다
//그 다음 각각의 노드들이 parent로 사용 할 노드 번호가 입력이 된다
//parent가 없는 노드 및 root 노드라면 -1을 입력한다
//이때, 어떤 한 노드를 없앤다고 가정하면 그 밑에 있는 노드들도 모두 사라지게 되는데
//그 작업을 한 이후의 리프 노드들을 모두 구하여라

//노드를 제거하는 DFS 함수
//부여받은 now_node값을 parent로 가지는 노드가 있다면 erase_dfs에 해당 노드 번호를 now_node로 부여한다
//그 다음 재귀를 이루어내면서 노드가 제거됐다는 의미로 parent를 -100으로 지정한다
void erase_dfs(int now_node) {
	for (int i = 0;i < N;i++) {
		if (parents[i] == now_node) {
			erase_dfs(i);
			parents[i] = -100;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		int tmp;
		cin >> tmp;
		parents[i] = tmp;
	}
	int eraser;
	cin >> eraser;

	//초기값으로 parents[eraser]를 -100으로 지정한다
	erase_dfs(eraser);
	parents[eraser] = -100;

	int answer = 0;

	//N개의 노드들 중 리프 노드인 것들을 판단하는 반복문
	//부모 노드가 아무튼간에 있거나 본인이 애초에 root 노드인 경우
	//자기 자신을 parent로 지정한 다른 노드가 있다면 해당 노드는 리프 노드가 아니게 된다
	//그 반대의 경우에는 리프 노드임을 확정지을 수 있게된다
	for (int i = 0;i < N;i++) {
		bool isit = true;
		if (parents[i] >= -1)
		{
			for (int j = 0;j < N;j++) {
				if (parents[j] == i) {
					isit = false;
					break;
				}
			}
		}
		else if (parents[i] < 0) {
			isit = false;
		}

		if (isit == true) {
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}