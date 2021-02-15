#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//LIS �˰����� ����ϰ� �;����� �־��� ������ �ʹ� �� O(N^2)�� �ð����⵵�ϰ�� �ð��ʰ��� ����
//���� �̹��� lower_bound�� Ȱ���� �̺�Ž���� ��鿩�� �ð����⵵�� �ٿ����ߴ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num;
	int answer = 0;
	vector<int>LIS; //�����ϴ� ���� �κм����� ���ڿ�������� ����
	LIS.push_back(0);	//�ּڰ��� �켱������ �־��ش�
	cin >> num;
	for (int i = 0;i < num;i++) {
		int temp;
		cin >> temp;
		//�Է¹��� ���ڰ� LIS���� �ִ񰪺��� ũ�ٸ� LIS�� �ִ����� �������ְ� ����++
		//�׷��� �ʴٸ� �Է¹��� ���� LIS��ġ���� ��� �ش��ϴ��� Ȯ�� ��, �� ���̶� ��ü���ش�
		//��ü���� ���ؼ� LIS�� �����ϴ� ���ڵ��� ���̸� ���Ӱ� ���ÿ� ��������� LIS�� ���� �� �ְԵȴ�.
		if (temp>LIS.back()) {
			answer++;
			LIS.push_back(temp);
		}
		else {
			vector<int>::iterator low_num = lower_bound(LIS.begin(), LIS.end(), temp);
			*low_num = temp;
		}
	}
	cout << answer << endl;
	return 0;
}