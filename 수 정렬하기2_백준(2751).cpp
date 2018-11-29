#include<iostream>
#include<stdio.h>
#define qswap(t, u){int v = t;t = u;u = v;} //�ӽ������� �� ���ڸ� ���� �ٲ��ִ� �Լ��� ������ش�.
#define MAX 1000000
int arr[MAX] = {}; //���ڵ��� ����Ǵ� �迭

//����Ʈ�� �̿��� �ִ� 100������ ������ ����
//�ð������� 1�ʿ��� ������ ����Ʈ�� ����ؾ�������, �׷����� �ұ��ϰ� c++�δ� �ð� �ʰ��� ���� c����� ����� ����ؾ��ߴ�.
//Ư�� ������ �������� ������ ���� ������ �۾ƾ��ϰ�, �������� ���� ������ Ŀ���ϴ� ������ ������� ���Ĺ��.
//���� ��Ģ�� ��߳� ���ڰ� �ִٸ� �� ��ġ�� ���ڿ� �ڸ��� �ٲ۴�.
//�׷��� ���ĵ� ����, ���ڰ� �ִ� �迭�� ũ�⸦ ������ �߶� ������ ������ �ݺ��Ѵ�.

void quick_sort(int *array, int start, int end)
{
	int m_start = start;
	int m_end = end;
	int pivot = array[(start + end) / 2]; //pivot�� ���� ũ�� �񱳸� ���� ������. �� ���ڸ� �������� ������ �۾ƾ��ϰ� �������� Ŀ���Ѵ�.

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
		//��Ģ�� ������� �ʴ� ���� �ѱ��, ��Ģ�� ����Ǵ� ������ m_start�� m_end�� �����صд�.


		if (m_start <= m_end)
		{
			//��Ģ�� ����Ǵ� �ΰ��� ���ڴ� ���� �ٲٰ�
			//m_start�� m_end�� ���� ���� 1++, 1--�� ���ش�.
			qswap(array[m_start], array[m_end]);
			m_start++;
			m_end--;
		}


		//�������� ������ �������� ���� ���� ������, �� 1���� ���ڸ��� ���������� quick_sort�Լ��� �����Ѵ�.
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