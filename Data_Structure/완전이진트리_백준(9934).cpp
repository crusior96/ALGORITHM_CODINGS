#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

//Ʈ���� Inorder�� �����ϴ� ����
//Ʈ����� �ڷᱸ���� ���������� ����ϴ� ���� �ƴ�����
//�� ������ �˰� �ִٸ� Ǯ��� �� �ִ� ��������

//��� �������� Ž��Ʈ���� Inorder�� Ž������ ��, K���� �ܰ�� �̷���� ���ڵ�� �־����ٰ� ��������
//�̶�, Ʈ���� Root���� �ܸ� ������ ������ ������ �ִ� ���ڵ��� ������� ����ϸ� �Ǵ� ����
//K�� ���� �ִ� 10�̴�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> arr[12];
	int num[1500] = {};
	int K;
	cin >> K;

	//K�ܰ��� �������� Ž��Ʈ���� pow(2,K) - 1���� ������ �־�����
	for (int i = 0;i < pow(2, K) - 1;i++) {
		cin >> num[i];
	}



	if (K == 1) {
		cout << num[0] << '\n';
	}
	else {
		//K���� 2 �̻��ΰ��, �� ���ڵ��� �ε����� �����ϴ� �۾��� �����Ѵ�
		//���� �ܰ� Ʈ���� Ž�� �ε����� �� �ܰ� Ʈ���� Ž�� �ε��� �յڷ� �����½����� �ε����� Ȯ���Ѵ�
		//���� �ش� �ε����� string�������� �����Ѵ�
		//����, K�� 10�ΰ�쿣 Ư���ϰ� �����ؼ� z�� �ε����� �����Ѵ�
		string S = "1";
		string ans;
		for (int i = 2;i <= K;i++) {
			if (i == 10) {
				string tmp = "z";
				ans = S + tmp + S;
				S = ans;
			}
			else {
				string tmp = to_string(i);
				ans = S + tmp + S;
				S = ans;
			}
		}

		//�ε��� ���¿� ���� �ش� �ε����� ���� ���� arr[�ε���]�� �־�д�
		//���ڿ��� ����ó���� ������Ѵ�
		for (int i = 0;i < ans.length();i++) {
			if (ans[i] == 'z') {
				arr[10].push_back(num[i]);
			}
			else {
				arr[ans[i] - '0'].push_back(num[i]);
			}

		}


		for (int i = K;i >= 1;i--) {
			for (int j = 0;j < arr[i].size();j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
	}

	return 0;
}