#include<iostream>
#include<cstdio>
#pragma warning(disable: 4996)

//병신같은 비주얼스튜디오가 scanf를 인식을 못한다.
//이때 위와같이 pragma warning(disable: 4996)을 입력해주면 scanf입력으로 인한 오류를 씹어줄 수 있다.
//물론 이는 비주얼스튜디오내에서 테스트 케이스를 돌려보기 위한 것이므로 답안제출시에는 지워준다.


//최대 천만개의 정수(최대 1만)을 입력하게 된다면, 입력된 정수들을 오름차순으로 출력해주는게 문제.
//시간제한은 3초이므로 scanf & printf를 사용해주자.

int main()
{
	int num[10001] = {}; //최대 1만까지의 정수들의 입력횟수를 수용해주는 배열
	int N;
	int max = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp > max)
		{
			max = temp;
			//조금이라도 밑의 for문을 덜 돌리게하기 위해서 정수 입력된것들이 최대 몇까지 입력되었는지를 체크해준다.
		}
		num[temp]++;
	}

	//최대 max까지의 정수들이 몇 번 입력되었는지 체크하여 입력된 횟수만큼 그 정수를 출력해준다.
	for (int i = 1;i <= max;i++)
	{
		if (num[i] != 0)
		{
			for (int j = 0;j < num[i];j++)
			{
				printf("%d\n", i);
			}
		}
	}

	return 0;
}