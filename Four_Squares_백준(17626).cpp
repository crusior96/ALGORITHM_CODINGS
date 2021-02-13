#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
int answer = 9999999;

//��� ���ڴ� �ִ� 4���� �������� ������ ǥ���ɼ� ������ ������ �� �ִٰ� ����
//�̶�, �־��� ���ڴ� �� ���� �������� ������ ǥ���Ǵ��� ����ϴ� ����


//�ܼ� ���Ʈ������ ��������� Ư�� ������ ���� ������ �ð� �ʰ��� ���´�.
//squares(������� ������ ���� �������� ����, ������ ���� ���������� ���� ���� ��)
//temp_num�� 0�� �ž� �������� ���� ǥ���� ���� �ȴ�.
void squares(int ans, int temp_num) {
	int tmp = sqrt(temp_num);
	int tmp2;
	for (int i = tmp;i >= 1;i--) {
		tmp2 = temp_num - pow(i, 2);
		if (tmp2 == 0) {
			answer = min(answer,ans);
			break;
		}
		else if(tmp2 != 0){
			//�ð� ������ ���ؼ� ���� ans + 1 ���� 4�� ������ Ž���� �����Ѵ�
			if (ans + 1 > 4) {
				break;
			}
			else {
				squares(ans + 1, tmp2);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	squares(1, N);
	cout << answer << '\n';
	return 0;
}