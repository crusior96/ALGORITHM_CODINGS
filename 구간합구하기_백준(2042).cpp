#include <iostream>
#include <cmath>
#include<algorithm>

using namespace std;
long long int arr[1000001];
long long int segtree[4000004];

//최대 100만개의 숫자들이 있다고 가정하자
//N개의 숫자를 입력받은 후 M개의 1번 쿼리와 O개의 2번 쿼리를 진행하게 된다
//1번 쿼리 : (1 a b)의 형식으로 입력됨. a번째 위치의 숫자를 b로 바꾸기.
//2번 쿼리 : (2 a b)의 형식으로 입력됨. a번째 위치에서부터 b번째 위치까지의 숫자를 더한 값을 구하기
//입력받은 쿼리에 따른 출력까지 진행시켜라



//새그트리를 구현하는 함수. 맨 밑의 새그트리값은 배열값인 arr로 채워지며
//최소 범위의 값들이 합쳐지면서 구간 합 새그트리가 만들어진다
long long int init(int left, int right, int node) {
	if (left == right) {
		return segtree[node] = arr[left];
	}

	int mid = (left + right) / 2;

	return segtree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

//특정 구간의 구간합을 구하는 함수
//범위로 지정한 노드를 범위를 고려하면서 더하기 작업이 진행된다
//이분탐색으로 범위를 찾아나가게 된다
long long int search_sum(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return 0;
	}

	if (node_left >= left && right >= node_right) {
		return segtree[node];
	}

	int mid = (node_left + node_right) / 2;

	return search_sum(left, right, node * 2, node_left, mid) + search_sum(left, right, node * 2 + 1, mid + 1, node_right);
}


//구간합 새그트리를 업데이트하는 함수
//특정 위치의 값에서 차이나는만큼 해당 위치를 포함한 다른 구간들의 구간합을 변동시켜준다
void update(int left, int right, int node, long long int idx, long long int dif) {
	if (idx<left || idx>right) {
		return;
	}
	segtree[node] += dif;
	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, node * 2, idx, dif);
	update(mid + 1, right, node * 2 + 1, idx, dif);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, O;
	cin >> N >> M >> O;

	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	init(1, N, 1);

	for (int j = 0;j < M + O;j++) {
		int order;
		cin >> order;
		if (order == 1) {
			long long int index, target;
			cin >> index >> target;
			long long int difference = target - arr[index];
			arr[index] = target;
			update(1, N, 1, index, difference);
		}
		else if (order == 2) {
			int s, e;
			cin >> s >> e;
			cout << search_sum(s, e, 1, 1, N) << '\n';
		}
	}

	return 0;
}