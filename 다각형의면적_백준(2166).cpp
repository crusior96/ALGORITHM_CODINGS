#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
long double x[10001] = {};
long double y[10001] = {};

//절대값이 100000을 넘지 않는 N개의 좌표가 있다고 가정하다.
//각각의 좌표 위치를 입력받는 순서는 다각형이 이루고 있는 꼭지점의 연속된 순서대로라고 할 때
//이 다각형이 이루는 넓이의 값을 소수점 1자리까지 반올림해서 구하여라.

int main()
{
	int N;
	long double result = 0; //200000*200000의 값을 수용할 수 있는 자료형.
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> x[i] >> y[i];
	}

	//다각형의 넓이를 구하는 방법은 많겠지만 이번 문제에선 신발끈 공식을 사용하였다.
	//(x1,y1), (x2,y2), ... (xn,yn)의 n개의 좌표가 있을때
	//x1*y2 +x2*y3 ... + xn*y1 - x2*y1 -x3*y2 ... -x1*yn의 값을 구한 후
	//그것의 절대값에 0.5를 곱한것이 다각형의 넓이라는 공식이다.
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