#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//N���� ���̵��� ���� 1���� N������ ��ȣ�� ������ �ִ�
//�� ���̵��� ���� ���� ���ֱ� �ѵ� ���� ������ ���� ä ���ִٸ�
//�� ���̵��� A�� B�� ��ġ�� �ٲٴ� ������ �������� ������ �� ��
//��ġ�� �ٲٴ� Ƚ���� �ּҷ� �� ���� �� Ƚ���� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num;
	int answer = 0;

	//���⿡�� ������ ����ߴ� LIS �˰����� ����Ͽ���
	//�ش� �˰����� �ߺ��Ǵ� ���ڰ� ���ٸ� �� ȿ���� 100% ����ȴ�
	//LIS�˰����� ����� ������, �����ϴ� �������� ���¸� �ִ��� �����ϰ� �ش����� �ʴ� ���ڸ� �ű�� ���ؼ��̴�
	//�ᱹ �� ������ ���� LIS �˰������� ���� ���� ���� �κм����� ���̸� N���� ���� ���̴�
	vector<int>LIS;
	LIS.push_back(-1000000001);
	cin >> num;
	for (int i = 0;i < num;i++) {
		int temp;
		cin >> temp;
		if (temp > LIS.back()) {
			answer++;
			LIS.push_back(temp);
		}
		else {
			vector<int>::iterator low_num = lower_bound(LIS.begin(), LIS.end(), temp);
			*low_num = temp;
		}
	}
	cout << num - answer << endl;
	return 0;
}