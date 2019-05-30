#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
long double x[10001] = {};
long double y[10001] = {};

//���밪�� 100000�� ���� �ʴ� N���� ��ǥ�� �ִٰ� �����ϴ�.
//������ ��ǥ ��ġ�� �Է¹޴� ������ �ٰ����� �̷�� �ִ� �������� ���ӵ� ������ζ�� �� ��
//�� �ٰ����� �̷�� ������ ���� �Ҽ��� 1�ڸ����� �ݿø��ؼ� ���Ͽ���.

int main()
{
	int N;
	long double result = 0; //200000*200000�� ���� ������ �� �ִ� �ڷ���.
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> x[i] >> y[i];
	}

	//�ٰ����� ���̸� ���ϴ� ����� �������� �̹� �������� �Ź߲� ������ ����Ͽ���.
	//(x1,y1), (x2,y2), ... (xn,yn)�� n���� ��ǥ�� ������
	//x1*y2 +x2*y3 ... + xn*y1 - x2*y1 -x3*y2 ... -x1*yn�� ���� ���� ��
	//�װ��� ���밪�� 0.5�� ���Ѱ��� �ٰ����� ���̶�� �����̴�.
	for (int i = 0;i < N;i++)
	{
		result += x[i] * y[(N + i + 1) % N];
		result -= x[(N + i + 1) % N] * y[i];
	}
	result = round(fabs(result) * 10 / 2) / 10;
	cout << setprecision(1) << fixed;
	cout << result << endl;
	return 0;
}