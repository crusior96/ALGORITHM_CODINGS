#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long int trees[1000001] = {};

//�����丷�� ���̰� M ��ŭ �ʿ��� ��, N���� ������ �� �ּ����� ������ ��� �����丷�� ����ʹٸ� ��� ���̸� �������� �߶�� �ϴ°�?
//�������ܱ�� ���ܱ��� ���̸� H�� �����ϸ� �������� H���� ���κ��� �����.

int main()
{

	//tall_tree & next_tree : 
	//���� ���ϱ� ���� ������ ������. �ּ����� ���̷� �ڸ��� ���� �������� ���̸� ���Ľ�Ų ��, 
	//�� ���� ���� ���̰���ŭ �ڸ��� �ȴٸ� ��ǥ���� �ش�Ǵ��� �ȵǴ��� üũ�ϴ� ������� Ž���Ѵ�.
	//tree_num : ������� ���ܱ⿡ ���� �߷����µ� ����޴� ������ ����
	//want_tree : �ӽ������� �߷��� �������� ���̰� ����Ǿ����� ��.
	//answer : ����� ��
	unsigned long long int N, M, tall_tree, next_tree, tree_num, answer;
	unsigned long long int want_tree = 0;
	tree_num = 0;
	answer = 0; 
	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		cin >> trees[i];
	}
	sort(trees, trees + N);
	reverse(trees, trees + N);
	//�����ϰ� ���� ������ ���̵��� ������������ �����Ѵ�.
	tall_tree = trees[0];
	next_tree = trees[1];
	//tall_tree�� next_tree�� �������ִ� �ʱⰪ. 
	unsigned long long int temp = 1;
	//tall_tree�� next_tree�� ���� trees�迭���� ������� �����ϱ� ���� ����.
	while (want_tree < M)
	{
		tree_num++;
		if (want_tree + tree_num * (tall_tree - next_tree) >= M)
		{
			for (int i = 0;i <= tall_tree - next_tree;i++)
			{
				if (want_tree + tree_num*i>=M)
				{
					answer = tall_tree - i;
					want_tree = want_tree + tree_num * i;
					break;
				}
			}
		}
		else
		{
			want_tree = want_tree + tree_num * (tall_tree - next_tree);
			tall_tree = trees[temp];
			next_tree = trees[temp + 1];
			temp++;
		}
	}

	cout << answer << endl;
	return 0;
}