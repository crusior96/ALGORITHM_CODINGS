#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

//N���� ȸ�Ǹ� �� �繫�� �ȿ��� ��� ������ ���� ��Ȳ�ӿ��� �ִ��� ���� ������ ȸ�Ǹ� �����ϰ��� �Ѵ�
//N���� ȸ�ǵ��� �̷���� �� ���۽ð��� ������ �ð��� �־����ٸ� �ִ��� �� ���� ȸ�Ǹ� �� �� �ִ°�?
//�̶� ���۽ð� �� ������ �ð��� ������ 2^31-1 �̸��̴�

using namespace std;
int work_start[100000] = {};
int work_end[100000] = {};

int main() {
	vector<pair<int, int>> order;	//ȸ���� ���� �� ������ �ð��� ����Ǿ����� ����
									//pair �����̳ʸ� ����Ѵ�
	int N;
	int fastest = 0;				//ȸ�ǰ� �����ؾ��ϴ� �ð��� �� ���� �̸� �ð�
	int work_num = 0;				//������� �̷���� ȸ���� ����
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> work_start[i] >> work_end[i];
	}

	//�־��� ȸ�ǵ��� ȸ�� ���۽ð��� �������� �����Ѵ�
	for (int i = 0;i < N;i++) {
		order.push_back(make_pair(work_end[i], work_start[i]));
	}
	sort(order.begin(), order.end());

	//�׸��� �˰����� ����Ͽ� �ܼ��� ���۽ð��� ���� �̸��� ���۽ð��� ���ٸ� ������ �ð��� ���� �̸� ȸ�Ǻ��� ȸ�ǽǿ� �����Ѵ�
	//�ٸ� �˰��� ���Ͽ� O(log N)�� �ð����⵵�� ������ �ִ�
	for (int i = 0;i < order.size();i++) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;

		if (fastest <= meetingBegin) {
			fastest = meetingEnd;
			work_num++;
		}
	}

	cout << work_num << endl;
	return 0;
}