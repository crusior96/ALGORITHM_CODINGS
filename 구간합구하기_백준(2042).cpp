#include <iostream>
#include <cmath>
#include<algorithm>

using namespace std;
long long int arr[1000001];
long long int segtree[4000004];

//�ִ� 100������ ���ڵ��� �ִٰ� ��������
//N���� ���ڸ� �Է¹��� �� M���� 1�� ������ O���� 2�� ������ �����ϰ� �ȴ�
//1�� ���� : (1 a b)�� �������� �Էµ�. a��° ��ġ�� ���ڸ� b�� �ٲٱ�.
//2�� ���� : (2 a b)�� �������� �Էµ�. a��° ��ġ�������� b��° ��ġ������ ���ڸ� ���� ���� ���ϱ�
//�Է¹��� ������ ���� ��±��� ������Ѷ�



//����Ʈ���� �����ϴ� �Լ�. �� ���� ����Ʈ������ �迭���� arr�� ä������
//�ּ� ������ ������ �������鼭 ���� �� ����Ʈ���� ���������
long long int init(int left, int right, int node) {
	if (left == right) {
		return segtree[node] = arr[left];
	}

	int mid = (left + right) / 2;

	return segtree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

//Ư�� ������ �������� ���ϴ� �Լ�
//������ ������ ��带 ������ ����ϸ鼭 ���ϱ� �۾��� ����ȴ�
//�̺�Ž������ ������ ã�Ƴ����� �ȴ�
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


//������ ����Ʈ���� ������Ʈ�ϴ� �Լ�
//Ư�� ��ġ�� ������ ���̳��¸�ŭ �ش� ��ġ�� ������ �ٸ� �������� �������� ���������ش�
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