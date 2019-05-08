#include<iostream>
#include<string>

//���̰� 1000 ������ �ΰ��� ���ڿ��� �־����� ��, ������� �κй��ڿ�(LCS)�� ���̸� ���϶�.
//DP�� �����ϱ⵵ �Ͽ����� �˰����� �۵������ �����ϴ°��� �� �߿��ϴ�.

using namespace std;
string str1, str2;
int LCS[1001][1001] = {};
int main()
{
	string A, B;
	cin >> A >> B;
	str1 = '0' + A;
	str2 = '0' + B;
	//���Ǹ� ���� �� �˰����� ���� ���ؼ� ���ڿ��� �պκ��� 0�̸� ����

	for (int i = 0;i < str1.length();i++)
	{
		for (int j = 0;j < str2.length();j++)
		{
			if (i == 0 || j == 0)
			{
				LCS[i][j] = 0;
				continue;
			}

			//���� ���ϴ� ���� ���� ������쿡��, �� ��ġ�� LCS���� 1 ���������ش�.
			if (str1[i] == str2[j])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			//���ϴ� ���� ���� �ٸ� ��쿡��, Ư�� ��ġ�� LCS������ ���� ���Ͻ����ش�.
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