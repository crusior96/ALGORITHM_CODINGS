#include<iostream>
#include<deque>
using namespace std;

int num[5000001] = {};				//�Է¹��� ���ڵ��� ����Ǵ� �κ�
deque<pair<int, int>> finding_min;	//���� num �迭���� �ִ� ���ڰ��� ����� ������ġ�� �ǹ��Ѵ�

//N���� ���ڵ��� ���������� ��, i - L + 1��° ���ڿ������� i��° ���ڵ� �� �ּڰ��� ���Ͽ���
//�̶�, ������° ���ڴ� ����� �ʿ䰡 ���ٰ� ���� �ȴ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		cin >> num[i];
	}

	for (int i = 0;i < N;i++) {
		//������ �Է¹޴� finding_min deque ���������� ������ �ذ��Ѵ�

		//������Ģ�� i - L + 1��° ���ڿ��� i��° ���ڱ����� �ִ� ������ �ּڰ��� ���ϱ� ������
		//i - L���� �տ� �ִ� ���ڵ��� �̸� finding_min deque���� �����Ѵ�
		if (!finding_min.empty() && finding_min.front().second <= i - L) {
			finding_min.pop_front();
		}

		//�Է¹��� finding_min deque������ num[i]�� ������ ū ������ ��� finding_min���� �����Ѵ�
		//�׷����ؼ� ���� num[i]���� ���� �����ʹ� finding_min�� ���ܵд�
		while (!finding_min.empty() && finding_min.back().first > num[i]) {
			finding_min.pop_back();
		}

		//finding_min�� ���� �� �� �ּڰ��� �����Ѵ�
		//�̶�, �� ���� �ִ� ������ ������������ ���ĵǹǷ� �ش� finding_min deque�� first���� �ش� ������ �ּڰ��̴�
		finding_min.push_back(make_pair(num[i], i));
		cout << finding_min.front().first << " ";
	}
	cout << '\n';
	return 0;
}