#include<iostream>
#include<queue>
using namespace std;

//N���� ���ڸ� �Է��ϴ� �����߿��� Ȧ�� �� ° ���ڸ� �Է�������
//������� �Է��� ���ڵ��� �������� �߾Ӱ��� ���ؼ� �����ϴ� ���� �̹� ������ ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		//�켱���� ť�� ����Ͽ� ���� �ּ� �� �׸��� �ִ� ��
		//�ִ� ���� ��쿣 vector�� ��� �̿��ߴ��� �˾Ƶ� �ʿ䰡 �ִ�
		//���� �̷��� 2�� ����� �� ���� : �ϳ��� ��������, �ϳ��� ������������ �ּ� �߾ӿ� �ִ� ���� ã�� ���ؼ�
		priority_queue<int>min_num;
		priority_queue<int, vector<int>, greater<int>>max_num;
		int cout_stk = 0;
		int N;
		cin >> N;
		cout << (N / 2) + 1 << '\n';
		for (int i = 1;i <= N;i++) {

			int tmp;
			cin >> tmp;
			//���ڵ��� �����Ƽ� ����ִ´�. ������ �ִ� ��, �״��� �ּ� ���� �ִ� ������� �����Ѵ�.
			if (max_num.size() == min_num.size()) {
				min_num.push(tmp);
			}
			else {
				max_num.push(tmp);
			}

			//max_num���� �ִ񰪰� min_num���� �ּڰ��� �� max_num���� �۴ٸ� ���� �ٲ��ش� 
			if (!max_num.empty() && !min_num.empty() && max_num.top() < min_num.top()) {
				int tmp1 = max_num.top();
				int tmp2 = min_num.top();
				max_num.pop();
				min_num.pop();
				max_num.push(tmp2);
				min_num.push(tmp1);
			}

			//�� Ȧ����° ���� min_num���� �ּڰ� �� top()���� ����Ѵ�. ��Ȯ�� ���޵� ���ڵ� �� ����� �ִ�.
			if (i % 2 == 1) {
				cout << min_num.top() << ' ';
				cout_stk++;
				if (cout_stk % 10 == 0 && N >= 10) {
					cout << '\n';
				}
			}
		}
		cout << '\n';
	}

	return 0;
}