#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N, Q;
long long int arr[100002] = {};
long long int segtree[400008] = {};

long long int init(int left, int right, int node) {
	if (left == right) {
		return segtree[node] = arr[left];
	}

	int mid = (left + right) / 2;

	return segtree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

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
	cin >> N >> Q;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	init(1, N, 1);

	for (int i = 1;i <= Q;i++) {
		int s, e, idx;
		long long int target;
		cin >> s >> e >> idx >> target;
		if (s >= e) {
			cout << search_sum(e, s, 1, 1, N) << '\n';
		}
		else {
			cout << search_sum(s, e, 1, 1, N) << '\n';
		}

		long long int dif = target - arr[idx];
		arr[idx] = target;
		update(1, N, 1, idx, dif);
	}
	return 0;
}