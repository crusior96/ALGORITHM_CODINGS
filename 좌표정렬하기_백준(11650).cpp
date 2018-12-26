#include<iostream>
#include<algorithm>
using namespace std;

//pair 컨테이너와 그것을 오름차순으로 정렬해보았다.
//원래는 sort만 써도 가능하다고 했는데 sort 함수에 compare 함수를 넣음으로써 확실화했다.


bool compare(const pair<int, int> &a, const pair<int, int>&b)
{
	//문제상에서 첫 번째 좌표를 기준으로 정렬한 후
	//그 좌표값이 동일한 좌표들끼리는 두 번째 좌표를 기준으로 정렬하기에
	//1차적으로 첫 번쨰 값, 그 다음 두 번째 값을 기준으로 정렬한다.
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}


int main()
{
	int N;
	pair<int, int> arr[100001];
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + N, compare);

	for (int i = 0;i < N;i++)
	{
		cout << arr[i].first <<" "<< arr[i].second << "\n";
	}
	return 0;
}