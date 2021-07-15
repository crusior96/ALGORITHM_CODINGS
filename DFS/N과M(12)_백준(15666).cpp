#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int arr[10] = {};
int tmp[10002] = {};
int num[10002] = {};
vector<int> numbers;

//N���� �ڿ����߿��� M���� �� ������ �ִٰ� ��������
//���� ���� ������ ��� ������ �� ������ �񳻸������̾�� �Ѵ�
//�� �������� ���� �� �ִ� ��� �������� ����϶�


//��Ʈ��ŷ ����� ����ؼ� �������� �����Ѵ�
//back_track(int a, int b) : ������ ����µ� ���� a���� ���ڸ� ��ġ�߰� ������ ���ϴ� ������ ���̴� b��� ��
//a == b�̸� ������ �ϼ������� ����ϰ�, a != b�̸� ������� ���� ���� �ڿ� �ٸ� ���ڵ��� �����鼭 �����Ѵ�
//a == b�� ������ �ϼ��� ���Ŀ��� ������ �������� pop_back()�� ������ ���� �ٸ� ���ڸ� �־ �� �ٸ� ����� ���� �����
void back_track(int a, int b) {
	if (a == b) {
		for (int i = 0;i < numbers.size();i++) {
			cout << numbers[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0;i < N;i++) {
			if (numbers.back() <= num[i]) {
				numbers.push_back(num[i]);
				back_track(a + 1, b);
				numbers.pop_back();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		tmp[arr[i]] = 1;
	}
	
	sort(arr, arr + N);
	int idx = 0;
	//���ĵ� ���ڵ��� ���� � ���ڵ��� �ִ��� �ľ��� ����
	//���� �����ϴ� ���ڵ鸸 num �迭�� ������������ �����صд�
	for (int i = 0;i <= 10001;i++) {
		if (tmp[i] == 1) {
			num[idx] = i;
			idx++;
		}
	}
	//num�迭�� �ִ� ��� ���ڵ��� ���� ���� ������ �Է��� ���� back_track�� �����Ѵ�
	for (int i = 0;i < idx;i++) {
		numbers.push_back(num[i]);
		back_track(1, M);
		numbers.pop_back();
	}
	return 0;
}