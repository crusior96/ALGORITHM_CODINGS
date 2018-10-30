#include<iostream>
using namespace std;

//� ���忡 ���ٿ� 1������ N�������� N�� �¼��� �ִ�. 
//������ ���� �� ������� �ڽ��� ������ Ƽ���� ��ȣ, Ȥ�� �� �����̳� ������ 1ĭ�� �ڸ��� ���� �� �ִ�.
//��, VIPƼ���� ���� �� ������� ������ �ڸ����� ������, �ٸ� ����� �ڸ��� �ٲٷ� ���� �ʴ´�.
//VIPƼ���� �� ����� ���� VIP_num�̰� N�� ���� 40 �����϶�, N���� �¼��� ���� �� �ִ� ����� ��������?
//��, ����� �������� 20�� �����̴�.

int main()
{
	int N, VIP, VIP_num;
	unsigned long long int ways = 1;
	int VIP_SEAT[45] = {}; //VIP�¼��� ����Ǵ� �迭. VIP�� �´ٸ� VIP_SEAT[0]���� VIP�¼���ȣ�� ����ȴ�.
	unsigned long long int VIP_PIBO[45] = {}; 
	//N���� �¼��� ������ ���� �� �ִ� �������� ����Ǵ� �迭.
	
	VIP_PIBO[0] = 1;
	VIP_PIBO[1] = 1;
	VIP_PIBO[2] = 2;
	//DP����� ���� �������ִ� �ʱⰪ. �¼��� ������ 0, 1, 2���϶� ���� �� �ִ� ����� �������� �����صд�.
	cin >> N;
	cin >> VIP_num;

	for (int i = 0;i < VIP_num;i++)
	{
		cin >> VIP;
		VIP_SEAT[i] = VIP;
		//VIP�¼��� ��ȣ�� �Է�.
		//VIP�¼��� ��ȣ�� �Է��Ҷ��� ���� ������ ���������� �Է����ִ� ��Ģ�� �ִ�. sort()�� �� �ʿ䰡 ��������.
	}

	for (int i = 3;i <= 41;i++)
	{
		VIP_PIBO[i] = VIP_PIBO[i - 1] + VIP_PIBO[i - 2];
		//�¼��� �ڸ����� ���� �� �������� ���غ���, ���� ���ں��� �Ǻ���ġ ��Ģ�� ���� �ٴ� �� �� �� �־���.
		//�׷��� �¼��� ���ڰ� 3�϶������� �Ǻ���ġ ��Ģ�� ���� ���� �� �ִ� ����� �������� �����صд�.
	}

	if (VIP_num != 0)
	{
		//VIP�¼��� �ִٸ� �� �¼��� �������� �Űܴٴ� �� �ִ� �ڸ��� ����������.
		//����, 7���� �¼��� �ִµ� 4���� VIP���̸� 1,2,3���� 4,5,6���� �¼������� �ڸ��� �ű� �� �ִٴ� ��.
		//�̶�, �������� �ڸ������� ���� �� �ִ� ����� ���� ���� ��, ������� ���� �¼��� �ɴ� ����� ���� �����ָ� �ȴ�.
		for (int i = 0;i < VIP_num;i++)
		{
			if (i == 0 && i==VIP_num-1) //VIP�¼��� ������ 1���� ���
			{
				unsigned long long int temp = VIP_PIBO[VIP_SEAT[i] - 1];
				unsigned long long int temp2 = VIP_PIBO[N - VIP_SEAT[i]];
				ways = ways * temp2 * temp;
			}
			else if (i == 0) //ù ��° VIP�¼��� ������ ���
			{
				unsigned long long int temp = VIP_PIBO[VIP_SEAT[i] - 1]; 
				ways = ways * temp;
			}
			else if (i == VIP_num - 1) //������ VIP�¼��� ������ ���
			{
				unsigned long long int temp = VIP_PIBO[N - VIP_SEAT[i]];
				unsigned long long int temp2 = VIP_PIBO[VIP_SEAT[i] - 1 - VIP_SEAT[i - 1]];
				ways = ways * temp*temp2;
			}
			else //�׿� �߰��߰��� ������ VIP�¼��� ���
			{
				unsigned long long int temp = VIP_PIBO[VIP_SEAT[i] - 1 - VIP_SEAT[i - 1]];
				ways = ways * temp;
			}
		}
	}
	else if (VIP_num == 0)
	{
		ways = VIP_PIBO[N];
	}

	cout << ways << endl;

	return 0;
}