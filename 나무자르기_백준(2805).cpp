#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long int trees[1000001] = {};

//나무토막의 길이가 M 만큼 필요할 때, N개의 나무들 중 최소한의 나무를 베어서 나무토막을 얻어내고싶다면 어느 높이를 기준으로 잘라야 하는가?
//나무절단기는 절단기의 높이를 H로 지정하면 나무들의 H높이 윗부분을 베어낸다.

int main()
{

	//tall_tree & next_tree : 
	//답을 구하기 위해 지정한 변수들. 최소한의 높이로 자르기 위해 나무들의 높이를 정렬시킨 후, 
	//두 개의 나무 사이값만큼 자르게 된다면 목표값에 해당되는지 안되는지 체크하는 방식으로 탐색한다.
	//tree_num : 현재까지 절단기에 의해 잘려지는데 영향받는 나무의 갯수
	//want_tree : 임시적으로 잘려진 나무들의 길이가 저장되어지는 곳.
	//answer : 출력할 값
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
	//랜덤하게 받은 나무의 높이들을 내림차순으로 정렬한다.
	tall_tree = trees[0];
	next_tree = trees[1];
	//tall_tree와 next_tree에 지정해주는 초기값. 
	unsigned long long int temp = 1;
	//tall_tree와 next_tree의 값에 trees배열값을 순서대로 지정하기 위한 변수.
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