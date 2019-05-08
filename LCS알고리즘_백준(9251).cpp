#include<iostream>
#include<string>

//길이가 1000 이하인 두개의 문자열이 주어졌을 떄, 최장공동 부분문자열(LCS)의 길이를 구하라.
//DP를 응용하기도 하였지만 알고리즘의 작동방식을 이해하는것이 더 중요하다.

using namespace std;
string str1, str2;
int LCS[1001][1001] = {};
int main()
{
	string A, B;
	cin >> A >> B;
	str1 = '0' + A;
	str2 = '0' + B;
	//편의를 위해 이 알고리즘을 쓰기 위해선 문자열의 앞부분이 0이면 좋다

	for (int i = 0;i < str1.length();i++)
	{
		for (int j = 0;j < str2.length();j++)
		{
			if (i == 0 || j == 0)
			{
				LCS[i][j] = 0;
				continue;
			}

			//현재 비교하는 값이 서로 같을경우에는, 그 위치의 LCS값을 1 증가시켜준다.
			if (str1[i] == str2[j])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			//비교하는 값이 서로 다를 경우에는, 특정 위치의 LCS값끼리 서로 동일시해준다.
			{
				if (LCS[i - 1][j] > LCS[i][j - 1])
				{
					LCS[i][j] = LCS[i - 1][j];
				}
				else
				{
					LCS[i][j] = LCS[i][j - 1];
				}
			}
		}
	}

	cout << LCS[str1.length() - 1][str2.length() - 1]<<endl;
}