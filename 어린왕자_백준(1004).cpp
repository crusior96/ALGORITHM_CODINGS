#include<iostream>
#include<cmath>
using namespace std;

//어린왕자가 시작점에서 끝점까지 이동해야한다.
//중간중간에 있는 행성을 최소한으로 지나칠 수 있다면 최소 몇 번 지나쳐야 하는가?
//좌표의 범위는 -1000이상 1000이하, 테스트케이스는 최대 100가지가 제공된다.


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
			//최대 2000^2의 값을 저장해야 하므로 모든 변수의 자료형을 unsigned long long int로 지정해준다.
			comp_xs = pow(xstart - xpos, 2);
			comp_ys = pow(ystart - ypos, 2);
			comp_xf = pow(xfin - xpos, 2);
			comp_yf = pow(yfin - ypos, 2);
			//어린 완자가 행성궤적을 지나치는 경우는 출발점이나 시작점 중 하나만이 그 궤적 안에 있는 경우.
			//둘 다 있거나 둘 다 밖에 있따면 지나칠 이유가 없다.
			//따라서 둘 중 하나만이 있는 경우를 추가해준다.
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

//if문을 주의깊게 작성만해주면 되는 알고리즘. 모르면 꽤 고생하는 것 같다.