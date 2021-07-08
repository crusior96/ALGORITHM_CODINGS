#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
long long int arr[100002];
long long int seg_jjak[400008];
long long int seg_hol[400008];

//��� ���ڵ��� �迭�� �������� �ִٰ� ��������
//���������� 3���� ������ ������ ���� a�� b�� ���ڸ� �Է��ϰ� �ȴ�.
//1�� ������ a��° ���ڸ� b�� �ٲٰ� �ǰ�, 2�� ������ a��° ���ڿ��� b��° ���� ������ ¦�� �������� ����ϰ�
//3�� ������ 2�� ������ ��������� Ȧ�� �������� ����ϰ� �ȴ�
//�ش� ���������� �� ���� �����ϰԲ� ������

//����Ǯ�̿��� ����Ʈ���� ����ϰ� �ƴµ�, ¦���� Ȧ�� ������ ���� �Ǵ��ϱ� ���� 2���� �Լ��� ����� �ƴ�
//������ ���ݸ� �� �� © �� �־��ٸ� �ϳ��� ����Ʈ�� �迭�� ����ؼ� �޸� �� �ڵ� ���̸� ���� �� �־��� �� ����

//¦�� üũ�� ����Ʈ���� ���� ���� �Լ�
//¦����� seg_jjak�� 1��, �ƴ϶�� 0�� �����Ѵ�
long long int init_jjak(int left, int right, int node) {
	if (left == right) {
		return seg_jjak[node] = (arr[left] + 1) % 2;
	}

	int mid = (left + right) / 2;
	
	return seg_jjak[node] = init_jjak(left, mid, node * 2) + init_jjak(mid + 1, right, node * 2 + 1);
}

//Ȧ�� üũ�� ����Ʈ���� ���� ���� �Լ�
//Ȧ����� seg_hol�� 1��, �ƴ϶�� 0�� �����Ѵ�
long long int init_hol(int left, int right, int node) {
	if (left == right) {
		return seg_hol[node] = arr[left] % 2;
	}

	int mid = (left + right) / 2;
	return seg_hol[node] = init_hol(left, mid, node * 2) + init_hol(mid + 1, right, node * 2 + 1);
}

//¦���� ������ �Ǵ��ϴ� �Լ�
//����Ʈ���� Ž���ϸ鼭 ������ ������ ���� �ʴ� �������� seg_jjak ������ ã�Ƴ��� ���ذ���
long long int search_jjak(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return 0;
	}

	if (node_left >= left && right >= node_right) {
		return seg_jjak[node];
	}

	int mid = (node_left + node_right) / 2;

	return search_jjak(left, right, node * 2, node_left, mid) + search_jjak(left, right, node * 2 + 1, mid + 1, node_right);
}

//Ȧ���� ������ �Ǵ��ϴ� �Լ�
//����Ʈ���� Ž���ϸ鼭 ������ ������ ���� �ʴ� �������� seg_hol ������ ã�Ƴ��� ���ذ���
long long int search_hol(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return 0;
	}

	if (node_left >= left && right >= node_right) {
		return seg_hol[node];
	}

	int mid = (node_left + node_right) / 2;

	return search_hol(left, right, node * 2, node_left, mid) + search_hol(left, right, node * 2 + 1, mid + 1, node_right);
}

//���� �������� ���� ¦���� ������ �����ϴ� �Լ�
//�ش� �κп��� ����߾��µ�, ������ �� ���� �ش� �κ��� �ߺ������� ó���ϴ� �ٶ��� ������ �־���
void update_jjak(int left, int right, int node, int idx, long long int dif) {
	if (idx<left || idx>right) {
		return;
	}

	if ((dif + 1) % 2 == 1) {
		seg_jjak[node]++;
	}
	else {
		seg_jjak[node]--;
	}

	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	update_jjak(left, mid, node * 2, idx, dif);
	update_jjak(mid + 1, right, node * 2 + 1, idx, dif);
}

//���� �������� ���� Ȧ���� ������ �����ϴ� �Լ�
void update_hol(int left, int right, int node, int idx, long long int dif) {
	if (idx<left || idx>right) {
		return;
	}
	
	if (dif % 2 == 1) {
		seg_hol[node]++;
	}
	else {
		seg_hol[node]--;
	}

	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	update_hol(left, mid, node * 2, idx, dif);
	update_hol(mid + 1, right, node * 2 + 1, idx, dif);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	init_jjak(1, N, 1);
	init_hol(1, N, 1);


	cin >> M;

	for (int j = 0;j < M;j++) {
		int order;
		cin >> order;
		if (order == 1) {
			int index;
			long long int before, target;
			cin >> index >> target;
			before = arr[index];
			arr[index] = target;
			if (before % 2 == 0 && target % 2 == 0) {
				continue;
			}
			else if (before % 2 == 1 && target % 2 == 1) {
				continue;
				
			}
			else {
				update_jjak(1, N, 1, index, target);
				update_hol(1, N, 1, index, target);
			}
		}
		else if (order == 2) {
			int s, e;
			cin >> s >> e;
			cout << search_jjak(s, e, 1, 1, N) << '\n';
		}
		else if (order == 3) {
			int s, e;
			cin >> s >> e;
			cout << search_hol(s, e, 1, 1, N) << '\n';
		}
	}

	return 0;
}