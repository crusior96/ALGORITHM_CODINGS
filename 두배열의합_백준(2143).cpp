#include<iostream>
#include<algorithm>
using namespace std;

int arr1[1001] = {};
int arr2[1001] = {};
int arr1_sum[1000001] = {};
int arr2_sum[1000001] = {};


//�迭 arr1�� arr2�� �ִٰ� ��������
//�� �迭�� ������ �����Ѵٸ� ��� �迭 A���� i���� j������ ���� A[i] + A[i+1] ... + A[j]��� ����
//T�� �־�������, arr1�� arr2������ �� �迭���� �����ؼ� T�� ����� �ִ� ������ ����϶�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, num1, num2;
	int answer = 0;
	cin >> T;
	cin >> num1;
	for (int i = 0;i < num1;i++) {
		cin >> arr1[i];
	}

	//�κ����� �����ϱ� ���� ����
	int idx1 = 0;
	for (int i = 0;i < num1;i++) {
		int tmp = arr1[i];
		arr1_sum[idx1] = tmp;
		idx1++;
		for (int j = i + 1;j < num1;j++) {
			tmp += arr1[j];
			arr1_sum[idx1] = tmp;
			idx1++;
		}
	}

	cin >> num2;
	for (int i = 0;i < num2;i++) {
		cin >> arr2[i];
	}

	int idx2 = 0;
	for (int i = 0;i < num2;i++) {
		int tmp = arr2[i];
		arr2_sum[idx2] = tmp;
		idx2++;
		for (int j = i + 1;j < num2;j++) {
			tmp += arr2[j];
			arr2_sum[idx2] = tmp;
			idx2++;
		}
	}
	
	//�κ��յ��� ������������ �������ش�
	//���� �����̵� ������ ������� T���� �����ϴ� �κ����� �ֵ��� ��� ���س���
	//�̶� arr1�� �κ��� �����ʹ� 0��������, arr2�� �κ��� �����ʹ� arr2.size() - 1�������� �����Ѵ�
	sort(arr1_sum, arr1_sum + idx1);
	sort(arr2_sum, arr2_sum + idx2);
	bool done = true;
	int pt1 = 0;
	int pt2 = idx2 - 1;
	long long int cnt = 0;
	while (done) {
		if (arr1_sum[pt1] + arr2_sum[pt2] == T) {
			long long int cnt1 = 1;
			long long int cnt2 = 1;

			while (pt1 + 1 <= idx1 - 1 && arr1_sum[pt1] == arr1_sum[pt1 + 1]) {
				pt1++;
				cnt1++;
			}

			while (pt2 - 1 >= 0 && arr2_sum[pt2] == arr2_sum[pt2 - 1]) {
				pt2--;
				cnt2++;
			}
			cnt += cnt1 * cnt2;
			pt1++;
		}

		if (pt1 <= idx1 - 1 && pt2 >= 0 && arr1_sum[pt1] + arr2_sum[pt2] < T) {
			pt1++;
		}
		
		if (pt1 <= idx1 - 1 && pt2 >= 0 && arr1_sum[pt1] + arr2_sum[pt2] > T) {
			pt2--;
		}

		if (pt1 > idx1 - 1 || pt2 < 0) {
			done = false;
			break;
		}
	}
	cout << cnt << '\n';
	return 0;
}