#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long int arr[1000001];
long long int segtree[4000004];
long long int moder = 1000000007;

//M개의 숫자가 있고 N번의 1번쿼리와 O번의 2번쿼리가 있다고 가정하자
//쿼리에 대한 입력정보는 각각 a, b, c 순서대로 들어온다
//1번 쿼리 : a가 1인경우, b번째 숫자를 c로 바꾼다
//2번 쿼리 : a가 2인경우, b에서부터 c까지의 숫자를 곱한 값을 출력한다
//모든 쿼리 결과물에 대한 값을 출력하라
//단, 모든 출력 결과물은 1000000007로 나눈 나머지 값을 출력하는 걸로 한다


//구간 곱 새그트리에서 해당 구간의 구간 곱 결과물을 알아내는 함수
long long int search_time(int idx, int left, int right, int start, int end) {
	if (left > end || right < start) {
		return 1;
	}
	else if (left <= start && end <= right) {
		return segtree[idx];
	}

	int mid = (start + end) / 2;

	return (search_time(idx * 2, left, right, start, mid)*search_time(idx * 2 + 1, left, right, mid + 1, end)) % moder;
}


//구간 곱 새그트리를 구현 및 갱신하는 함수. 1번 쿼리에 대한 작업도 여기에서 이루어진다
//특정 위치의 값을 갱신하고자 하는 값으로 갱신함과 동시에
//갱신되는 위치로 인해 변화하는 구간 곱들의 값을 갱신해준다
long long int update(int idx, int target, int val, int start, int end) {
	if (start > target || end < target) {
		return segtree[idx];
	}

	if (start == end) {
		return segtree[idx] = val;
	}

	int mid = (start + end) / 2;

	return segtree[idx] = (((update(idx * 2, target, val, start, mid)*update(idx * 2 + 1, target, val, mid + 1, end)))%moder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N, O;
	cin >> M >> N >> O;
	int query_num = N + O;
	for (int i = 1;i <= M;i++) {
		long long int tmp;
		cin >> tmp;
		update(1, i, tmp, 1, M);
	}
	for (int i = 0;i < query_num;i++) {
		int order;
		cin >> order;
		if (order == 1) {
			int tar, val;
			cin >> tar >> val;
			update(1, tar, val, 1, M);
		}
		else if (order == 2) {
			int s, e;
			cin >> s >> e;
			cout << search_time(1, s, e, 1, M) << '\n';
		}
	}
	return 0;
}