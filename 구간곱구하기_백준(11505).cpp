#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long int arr[1000001];
long long int segtree[4000004];
long long int moder = 1000000007;

//M���� ���ڰ� �ְ� N���� 1�������� O���� 2�������� �ִٰ� ��������
//������ ���� �Է������� ���� a, b, c ������� ���´�
//1�� ���� : a�� 1�ΰ��, b��° ���ڸ� c�� �ٲ۴�
//2�� ���� : a�� 2�ΰ��, b�������� c������ ���ڸ� ���� ���� ����Ѵ�
//��� ���� ������� ���� ���� ����϶�
//��, ��� ��� ������� 1000000007�� ���� ������ ���� ����ϴ� �ɷ� �Ѵ�


//���� �� ����Ʈ������ �ش� ������ ���� �� ������� �˾Ƴ��� �Լ�
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


//���� �� ����Ʈ���� ���� �� �����ϴ� �Լ�. 1�� ������ ���� �۾��� ���⿡�� �̷������
//Ư�� ��ġ�� ���� �����ϰ��� �ϴ� ������ �����԰� ���ÿ�
//���ŵǴ� ��ġ�� ���� ��ȭ�ϴ� ���� ������ ���� �������ش�
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