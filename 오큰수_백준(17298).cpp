#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

int num[1000001] = {};			//��ū�� ���� ���������� ����Ǵ� �迭
stack<pair<int, int>> obigsu;	//��ū�� ������ ã������ �Ϻ� �������� ����Ǵ� ����.
								//<�Է��� ����, ������ ��ġ>�� ����ȴ�

//N���� ��ȣ���� �ִٰ� ��������
//��ū����� ���ڰ� �ִµ� �� ���ڴ� �ڽ��� �������� �ؼ� �����ʿ� �ִ� ���ڵ� ��
//ū ���ڵ� �߿� ���� ���ʿ� �ִ� ���ڵ��� �ǹ��Ѵ�
//�̶�, ������ N���� ��ȣ�鿡 ���ؼ� ������ ��ū������ ���Ͽ���
//��, ��ū���� ã�� �� ���� ��쿡�� -1�� ����Ѵ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		num[i] = -1;
	}

	//����� �˰��� �� �ڷᱸ���� ����� ����(Monotone Stack)�̴�
	//�׻� ������ ���¸� ������������ ���������ִ� �˰����̴�
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		//��ū�� ������ ������� �ʴ°��
		while (obigsu.empty() == false) {
			//���� �Է��� ���� ���� ��ū�� top()�� ��ġ�� ���ڰ����� ū ���
			//���� ��ū���� top()�� ��ġ�� ��ġ ������ ���� num[��ġ]�� temp�� �����Ѵ�
			if (temp > obigsu.top().first) {
				num[obigsu.top().second] = temp;
				obigsu.pop();
			}
			else {
				break;
			}
		}
		obigsu.push(pair<int, int>(temp, i));
	}

	for (int i = 0;i < N;i++) {
		cout << num[i] << " ";
	}

	return 0;
}