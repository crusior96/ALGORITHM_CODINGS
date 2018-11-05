#include<iostream>
#include<cmath>
using namespace std;

//����ڰ� ���������� �������� �̵��ؾ��Ѵ�.
//�߰��߰��� �ִ� �༺�� �ּ������� ����ĥ �� �ִٸ� �ּ� �� �� �����ľ� �ϴ°�?
//��ǥ�� ������ -1000�̻� 1000����, �׽�Ʈ���̽��� �ִ� 100������ �����ȴ�.


int main()
{
	int N, N2;
	int xstart, ystart, xfin, yfin, xpos, ypos, r;
	unsigned long long int comp_xs, comp_ys, comp_xf, comp_yf;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		long long int crossover = 0;
		cin >> xstart >> ystart >> xfin >> yfin;
		cin >> N2;
		for (int j = 0;j < N2;j++)
		{
			cin >> xpos >> ypos >> r;
			//�ִ� 2000^2�� ���� �����ؾ� �ϹǷ� ��� ������ �ڷ����� unsigned long long int�� �������ش�.
			comp_xs = pow(xstart - xpos, 2);
			comp_ys = pow(ystart - ypos, 2);
			comp_xf = pow(xfin - xpos, 2);
			comp_yf = pow(yfin - ypos, 2);
			//� ���ڰ� �༺������ ����ġ�� ���� ������̳� ������ �� �ϳ����� �� ���� �ȿ� �ִ� ���.
			//�� �� �ְų� �� �� �ۿ� �ֵ��� ����ĥ ������ ����.
			//���� �� �� �ϳ����� �ִ� ��츦 �߰����ش�.
			if ((sqrt(comp_xs + comp_ys) >= r) || (sqrt(comp_xf + comp_yf)>=r))
			{
				if (sqrt(comp_xs + comp_ys) < r)
				{
					crossover++;
				}
				else if (sqrt(comp_xf + comp_yf)<r)
				{
					crossover++;
				}
			}
		}
		cout << crossover << endl;
	}

	return 0;
}

//if���� ���Ǳ�� �ۼ������ָ� �Ǵ� �˰���. �𸣸� �� ����ϴ� �� ����.