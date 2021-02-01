#include<iostream>
#include<string>
#include<vector>
using namespace std;

//���ڿ� S�� �־����ٰ� ��������
//��ź ���ڿ��� B�� ��ġ�ϴ� ���ڿ��� �ִٸ�, ��������� ��� S ���ڿ����� ���Ž�Ű��
//���� ���ڿ��鳢�� ���� �����ִ� �۾��� �����Ѵ�.
//�̶� �������鼭 ������� ���ڿ� ������ B�� �� ���̰� �ȴٸ� �ش� ���ڿ��� �����ֵ��� �Ѵ�
//���������� �����ִ� ���ڿ��� ���ٸ� "FRULA"�� ����ϰ�, �����ִ� ���ڿ��� �ִٸ� �װ� ����Ѵ�.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string S, B;
	vector<char> ans;
	cin >> S;
	cin >> B;
	for (int i = 0;i < S.length();i++) {
		ans.push_back(S[i]);

		//������� ans ���Ϳ� �Էµ� ���ڿ��� ������ ��ź ���ڿ����� �� ������ üũ ����
		if (ans.size() >= B.length()) {
			//�Էµ� ���ڰ� ��ź���ڿ��� ������ �κа� ������ Ž������
			//�ش� �κп������� ������ ���ư��鼭 ��ź���ڿ���ŭ ���̰� ���� �κ��� �ִٸ�
			//�ش� �κ��� ����������. ���⼭ vector�� erase �Լ� ���
			if (ans[ans.size() - 1] == B[B.length() - 1]) {
				bool checker = true;
				for (int j = 2;j <= B.length();j++) {
					if (ans[ans.size() - j] != B[B.length() - j]) {
						checker = false;
					}
				}
				if (checker == true) {
					ans.erase(ans.end() - B.length(), ans.end());
				}
			}
		}
	}

	if (ans.size() == 0) {
		cout << "FRULA" << '\n';
	}
	else {
		for (int i = 0;i < ans.size();i++) {
			cout << ans[i];
		}
		cout << '\n';
	}
	
	return 0;
}