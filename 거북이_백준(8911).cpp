#include<iostream>
#include<string>
using namespace std;

//�ź����� �̵���θ� ��� ������ �� �ִ� �ִ� ���簢���� ���̸� ���϶�.
//�ź����� �̵���ΰ� �Էµǰ� F,B,R,L �� 4���� �ൿ����� �ִ�.
//F : ������ ���� / B : �ڷ� ���� / R : ���������� 90�� ȸ�� / L : �������� 90�� ȸ��

int main()
{
	int N;
	
	int ways = 1;
	//ó������ ���� ������ �ٶ󺸰� �ִ�.
	//ways�� ���� 1~4��ŭ �ٲ� �� ������, ������ ȸ���� 1+, ���� ȸ���� 1-�ȴ�.
	//ways = 1 : ���� / ways = 2 : ���� / ways = 3 : ���� / ways = 4 : ����/
	string S;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
	int xmax = 0;
	int ymax = 0;
	int xmin = 0;
	int ymin = 0;
	int xpos = 0;
	int ypos = 0;
		cin >> S;
		for (int j = 0;j < S.length();j++)
		{
			int temp = 0;
			switch (S[j])
			{
			case 'F':
				if (ways == 1) {
					ypos++;
					if (ypos > ymax) ymax = ypos;
				}
				else if (ways == 2) {
					xpos++;
					if (xpos > xmax) xmax = xpos;
				}
				else if (ways == 3) {
					ypos--;
					if (ypos < ymin) ymin = ypos;
				}
				else if (ways == 4) {
					xpos--;
					if (xpos < xmin) xmin = xpos;
				}

				break;
			case 'B':
				if (ways == 1) {
					ypos--;
					if (ypos < ymin) ymin = ypos;
				}
				else if (ways == 2) {
					xpos--;
					if (xpos < xmin) xmin = xpos;
				}
				else if (ways == 3) {
					ypos++;
					if (ypos > ymax) ymax = ypos;
				}
				else if (ways == 4) {
					xpos++;
					if (xpos > xmax) xmax = xpos;
				}
				break;

			case 'L':
				ways--;
				if (ways == 0) ways = 4;
				break;

			case 'R':
				ways++;
				if (ways == 5) ways = 1;
				break;

				//ways ���� ������ ���� �ִ� or �ּ� ������ ����� �Ǹ�
				//������ �����صξ��� �ִ� or �ּҰ����� ���������ش�.
			}
		}
		cout << (xmax - xmin)*(ymax - ymin) << endl;
	}

	
	return 0;
}
