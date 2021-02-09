#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[100001] = {};

//���(2467��) ������ ������ ��Ȳ������ �־����� ��װ��� ������������ �־����� �ʴ´�
//���� �ִ� 10������ ���ڵ��� �����ϱ� ���� ����Ʈ�� ����ߴ�
//����Ʈ�� (NlogN)�� �ð����⵵�� ������ �ִ� �ݸ� �Ϲ����� ��Ʈ�� (N^2)�� �ð����⵵�� �������ִ�


//����Ʈ�� ����ϱ� ���� ���� �����Լ�
//�̸� ���� ������������ ������ �� ������, return 1�� -1�� ���� �ٲ�θ� �������� ������ �����ϴ�
int cmp(const void *a, const void *b){
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 > num2) {
		return 1;
	}
	else if (num1 < num2) {
		return -1;
	}
	else if (num1 == num2) {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, s_liquid, e_liquid;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	//�Է¹��� �迭 arr�� ���� ����Ʈ ����
	qsort(arr, N, sizeof(int), cmp);

	//�ּڰ� ��ü�� 0 �̻��ΰ�쿣 �ּڰ��� �� �������� ���� �� ���
	if (arr[0] >= 0) {
		cout << arr[0] << " " << arr[1] << '\n';
	}
	//�ִ� ��ü�� 0 ������ ��쿣 �ִ񰪰� �� �������� ū �� ���
	else if (arr[N - 1] <= 0) {
		cout << arr[N - 2] << " " << arr[N - 1] << '\n';
	}
	//�� ��쿡 �ش������ ���� ��� �����̵� ��� ���
	else {
		int s = 0;
		int e = N - 1;
		int mini = 2000000001;
		while (s < e) {
			int tmp = arr[e] + arr[s];
			tmp = abs(tmp);
			//�� ��� ������ ���̰��� ��Ȯ�� 0�ΰ�쿣 �۾��� �ߴ��ϸ� �� ����� �ٷ� �����ع�����
			if (tmp == 0) {
				s_liquid = arr[s];
				e_liquid = arr[e];
				break;
			}
			else if (tmp < mini) {
				mini = tmp;
				s_liquid = arr[s];
				e_liquid = arr[e];
			}

			if (arr[s] + arr[e] < 0) {
				s++;
			}
			else if (arr[s] + arr[e] > 0) {
				e--;
			}
		}
		cout << s_liquid << " " << e_liquid << '\n';
	}

	return 0;
}