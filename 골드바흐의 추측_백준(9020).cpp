#include<iostream>
#pragma warning(disable:4996)

int primary[1000001] = {};

//100만 이하의 짝수는 각기 다른 두 소수로 출력됨을 보여주면 된다.
//이때, 여러 가지 방법이 있다면 두 소수간의 차이가 제일 큰 쌍을 우선적으로 출력한다.
//만약 두 소수값을 구할 수 없다면 실행실패문을 출력해준다.
//입력을 0으로 받게 되면 종료시킬 것.

int main()
{
	bool doit = true;
	primary[1] = 1;
	for (int i = 2;i <= 1000;i++)
	{
		if (primary[i] == 1)
		{
			continue;
		}
		for (int j = i + i;j <= 1000000;j += i)
		{
			primary[j] = 1;
		}
	}

	while (doit)
	{
		int temp;
		int possible = 0;
		scanf("%d", &temp);
		if (temp == 0)
		{
			doit = false;
			break;
			//while문 종료
		}
		else
		{
			for (int i = 2;i <= temp / 2;i++)
			{
				//짝수값에서 현재 소수값을 뺐을 때, 그 값 또한 소수라면 성립
				//두 소수간의 차이가 큰 값을 출력해야하기 때문에
				//작은 소수부터 비교해준다
				if (primary[temp - i] == 0 && primary[i]==0)
				{
					printf("%d = %d + %d\n", temp, i, temp - i);
					possible = 1;
					break;
				}
			}

			if (possible == 0)
			{
				printf("Goldbach's conjecture is wrong.\n");
			}
		}
	}

	return 0;
}