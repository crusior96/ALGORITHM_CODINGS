#include<iostream>
using namespace std;
int arr[1000002] = {};
long long int mods[1001] = {};

//N���� ������ ���ڵ�(1 ~ 10^6) �� ���� ������ ���� M(2 ~ 10^3)���� ���������� ������ ������ ���ϴ� ����
//������ ���ӵǾ�߸� �Ѵ�

//���� �޸������̼��� ������ ����
int main()
{
	int N, M;
	long long int sum = 0;
	long long int ans_mod = 0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}

	
	mods[0] = 1;
	//index 0�������� ���������� index���� 1�� �÷����鼭 �������� ������ ���ϱ�
	//���� �� �ִ� ������ ���� ��츦 mods�迭�� ����
	for (int i = 0;i < N;i++)
	{
		sum += arr[i];
		sum %= M;
		mods[sum]++;
	}

	//���� ���ս��� ��Ģ�� ���� �������� ������ �� �������� 0�� �Ǵ� ���ǵ��� ã�Ƴ���
	//��, �������� 0�̵Ǵ� �������� ����ó���� ���ش�
	for (int i = 0;i <= M;i++)
	{
		if (i > M / 2) {
			break;
		}

		if (i == 0) {
			ans_mod += mods[i] * (mods[i] - 1) / 2;
		}
		else {
			ans_mod += (long long)mods[i] * (long long)(mods[M - i]) / 2;
		}
	}


	cout << ans_mod << endl;
	return 0;

}