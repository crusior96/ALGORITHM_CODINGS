#include<iostream>
#include<cmath>
using namespace std;
//�� ���� ����� ���⸦ ����� ���� ������ A, �� ���� ������� ������ ���̸� B��� ����
//Ư�� ���ǿ� ���� �������� �ΰ��Ѵ� �� ��, �� ��� �� ���� ����� �� �� �ִ� ����� ����� ���ΰ�?
//A��B�� ������ Ǯ �� �ִ� ���ǻ󿡼��� ���´�

/*����
  ��뷮�� 1 ~ 100 : 1�� 2��
  ��뷮�� 101 ~ 10000 : 1�� 3��
  ��뷮�� 10001 ~ 1000000 : 1�� 5��
  100�� �ʰ��� : 1�� 7��
  ��뷮 ���ֳ��� ����鸸 ���õ� ���Ǵ�� ����� ����Ѵ�
  ex) 150��� -> 200 + 150 = 350
*/

//Ư�� ����� ������ ���� ��� ���ⷮ�� ����ϴ� �Լ�
int elec_calc(int temp) {
	if (temp <= 200) {
		return temp / 2;
	}
	else if (temp > 200 && temp <= 29900) {
		return 100 + (temp - 200) / 3;
	}
	else if (temp > 29900 && temp <= 4979900) {
		return 10000 + (temp - 29900) / 5;
	}
	else if (temp > 4979900) {
		return 1000000 + (temp - 4979900) / 7;
	}
}

//���ⷮ�� ���� ����� ����ϴ� �Լ�
int money_calc(int temp) {
	if (temp <= 100) {
		return temp * 2;
	}
	else if (temp > 100 && temp <= 10000) {
		return 200 + (temp - 100) * 3;
	}
	else if (temp > 10000 && temp <= 1000000) {
		return 29900 + (temp - 10000) * 5;
	}
	else if (temp > 1000000) {
		return 4979900 + (temp - 1000000) * 7;
	}
}

int main() {
	int A, B;
	int total_elec; //�� ����� ����� ����뷮�� ��
	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}
		else {
			total_elec = elec_calc(A);
			int left = 1;
			int right = total_elec;
			//�̺� Ž���� �̿��Ͽ� �ð����⵵�� ���̴� ���� �߿�
			//�ܼ��� for���� ����Ͽ� �������� Ǯ�� �ð��ʰ� �߻�
			//ã���� �ϴ°��� Ư�� ����뷮�� �������� ������, ������ ��е� �����ݰ��� B�� ��츦 ã�ƾ��ϹǷ�
			//�̺� Ž���� �̷������ ������ 1 ~ ����뷮�� ��
			while (left <= right) {
				int mid = (left + right) / 2;
				if (abs(money_calc(total_elec - mid) - money_calc(mid)) > B) {
					right = mid - 1;
				}
				else if (abs(money_calc(total_elec - mid) - money_calc(mid)) < B) {
					left = mid + 1;
				}
				else if(abs(money_calc(total_elec-mid) - money_calc(mid))==B){
					//�� �� �ּڰ� ���
					if (money_calc(total_elec - mid) >= money_calc(mid)) {
						cout << money_calc(mid) << endl;
					}
					else if (money_calc(total_elec - mid) < money_calc(mid)) {
						cout << money_calc(total_elec - mid) << endl;
					}
					break;
				}
			}
		}
	}


	return 0;
}