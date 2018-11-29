#include<iostream>
#include<stdio.h>
#define qswap(t, u){int v = t;t = u;u = v;} //임시적으로 두 숫자를 서로 바꿔주는 함수를 만들어준다.
#define MAX 1000000
int arr[MAX] = {}; //숫자들이 저장되는 배열

//퀵소트를 이용한 최대 100만개의 수들의 정렬
//시간제한이 1초였기 때문에 퀵소트를 사용해야했으며, 그럼에도 불구하고 c++로는 시간 초과가 나서 c언어의 양식을 사용해야했다.
//특정 구간을 기준으로 왼쪽의 값은 무조건 작아야하고, 오른쪽의 값은 무조건 커야하는 조건을 내세우는 정렬방식.
//만약 규칙에 어긋난 숫자가 있다면 그 위치의 숫자와 자리를 바꾼다.
//그렇게 정렬된 이후, 숫자가 있는 배열의 크기를 반으로 잘라 동일한 행위를 반복한다.

void quick_sort(int *array, int start, int end)
{
	int m_start = start;
	int m_end = end;
	int pivot = array[(start + end) / 2]; //pivot은 숫자 크기 비교를 위한 기준점. 이 숫자를 기준으로 왼쪽은 작아야하고 오른쪽은 커야한다.

	while (m_start <= m_end)
	{
		while (pivot > array[m_start])
		{
			m_start++;
		}
		while (pivot < array[m_end])
		{
			m_end--;
		}
		//규칙에 위배되지 않는 곳은 넘기고, 규칙에 위배되는 공간을 m_start와 m_end에 저장해둔다.


		if (m_start <= m_end)
		{
			//규칙에 위배되는 두개의 숫자는 서로 바꾸고
			//m_start와 m_end의 값에 각각 1++, 1--를 해준다.
			qswap(array[m_start], array[m_end]);
			m_start++;
			m_end--;
		}


		//나뉘어진 구간의 시작점과 끝이 같을 때까지, 즉 1개의 숫자만이 남을때까지 quick_sort함수를 실행한다.
		if (start < m_end)
		{
			quick_sort(arr,start,m_end);
		}
		if (m_start < end)
		{
			quick_sort(arr,m_start,end);
		}
	}
}


int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &arr[i]);
	}

	quick_sort(arr,0,N-1);

	for (int i = 0;i < N;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}