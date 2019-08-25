#include<iostream>
#include<string>
using namespace std;

//문자열 S를 입력받았을때, 이 문자열을 팰린드롬으로 만들 수 있다면 팰린드롬으로 만들어내는 문제.
//만약 문자를 임의로 옮겨서 팰린드롬으로 만들 수 있다면 사전순나열로 제일 앞에 오는것을 출력한다.

int main()
{
	int alphabet[26] = {};//'A'부터 'Z'까지의 각각 알파벳들의 갯수를 저장해둔다.
	int checked[26] = {};//'A'부터 'Z'까지의 알파벳들 중 문자열 내부에 있는 알파벳은 checked배열에 1로 저장해둔다.
	char alpha[26] = {}; //'A'부터 'Z'까지의 문자가 저장되는 배열
	string S;
	int odd = 0;//홀수인 알파벳의 갯수가 몇개인지 저장하는 변수
	int isodd, status;
	cin >> S;

	for (int i = 0;i < 26;i++)
	{
		alpha[i] = 'A' + i;
	}

	//문자열 전체 길이에서 알파벳의 갯수 및 종류별 존재여부를 저장해둔다.
	for (int i = 0;i < S.length();i++)
	{
		alphabet[S[i] - 'A']++;
		checked[S[i] - 'A'] = 1;
	}

	isodd = S.length() % 2; //문자열의 길이가 홀수있지의 여부를 따지는 변수
	//모든 알파벳 종류별로 갯수에 따른 상황부여
	for (int i = 0;i < 26;i++)
	{
		//이 알파벳의 갯수가 단 1개라면
		if (alphabet[i] % 2 == 1 && alphabet[i]==1)
		{
			odd++;
			checked[i] = 3;
			status = 2;
		}
		//이 알파벳의 갯수가 홀수개라면
		else if (alphabet[i] % 2 == 1 && alphabet[i] > 1)
		{
			odd++;
			checked[i] = 2;
			status = 3;
		}

		//홀수개인 알파벳의 종류가 2개 이상일경우, 팰린드롬을 만들 수 없으니 그 이후의 시행은 의미없다.
		if (odd >= 2)
		{
			break;
		}
	}

	//팰린드롬구조상 가운데지점을 기준으로 좌우에 동일한 횟수만큼 알파벳이 나오기때문에
	//알파벳 갯수의 절반만큼 양쪽에서 나뉘어져 나오면 된다.
	for (int i = 0;i < 26;i++)
	{
		if (alphabet[i] > 1)
		{
			alphabet[i] = alphabet[i] / 2;
		}
	}

	if (odd >= 2)
	{
		cout << "I'm Sorry Hansoo";
	}
	else if (odd == 1 && isodd == 1) //문자 내에 홀수 개인 알파벳이 한종류만 있고, 문자 길이가 홀수인경우
	{
		//그 한 종류의 알파벳이 1개만 입력되어있을경우
		if (status == 2)
		{
			for (int j = 0;j < 26;j++)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1)
					{
						cout << alpha[j];
					}
				}
			}

			for (int j = 0;j < 26;j++)
			{
				if (checked[j] == 3)
				{
					cout << alpha[j];
					break;
				}
			}

			for (int j = 25;j >= 0;j--)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1)
					{
						cout << alpha[j];
					}
				}
			}
		}
		//그 한종류의 알파벳이 3개 이상의 홀수개로 이루어져 있는 경우
		else if (status == 3)
		{
			for (int j = 0;j < 26;j++)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1 || checked[j] == 2)
					{
						cout << alpha[j];
					}
				}
			}

			for (int j = 0;j < 26;j++)
			{
				if (checked[j] == 2)
				{
					cout << alpha[j];
					break;
				}
			}

			for (int j = 25;j >= 0;j--)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1 || checked[j] == 2)
					{
						cout << alpha[j];
					}
				}
			}
		}
	}
	//문자내의 알파벳들이 모두들 짝수개만큼 있고 문자의 길이 또한 짝수개인경우
	else if (odd == 0 && isodd == 0)
	{
		for (int j = 0;j < 26;j++)
		{
			for (int k = 0;k < alphabet[j];k++)
			{
				if (checked[j] == 1)
				{
					cout << alpha[j];
				}
			}
		}
		
		for (int j = 25;j >=0; j--)
		{
			for (int k = 0;k < alphabet[j];k++)
			{
				if (checked[j] == 1)
				{
					cout << alpha[j];
				}
			}
		}
	}
	else //그 외의 모든경우에는 팰린드롬의 성립이 안된다.
	{
		cout << "I'm Sorry Hansoo";
	}

	return 0;
}