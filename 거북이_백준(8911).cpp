#include<iostream>
#include<string>
using namespace std;

//거북이의 이동경로를 모두 포함할 수 있는 최대 직사각형의 넓이를 구하라.
//거북이의 이동경로가 입력되고 F,B,R,L 총 4가지 행동방식이 있다.
//F : 앞으로 전진 / B : 뒤로 후진 / R : 오른쪽으로 90도 회전 / L : 왼쪽으로 90도 회전

int main()
{
	int N;
	
	int ways = 1;
	//처음에는 북쪽 방향을 바라보고 있다.
	//ways의 값이 1~4만큼 바뀔 수 있으며, 오른쪽 회전시 1+, 왼쪽 회전시 1-된다.
	//ways = 1 : 북쪽 / ways = 2 : 동쪽 / ways = 3 : 남쪽 / ways = 4 : 서쪽/
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

				//ways 값의 증감에 따라 최대 or 최소 범위를 벗어나게 되면
				//이전에 지정해두었던 최대 or 최소값으로 지정시켜준다.
			}
		}
		cout << (xmax - xmin)*(ymax - ymin) << endl;
	}

	
	return 0;
}
