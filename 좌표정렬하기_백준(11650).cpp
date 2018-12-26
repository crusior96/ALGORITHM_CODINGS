#include<iostream>
#include<algorithm>
using namespace std;

//pair �����̳ʿ� �װ��� ������������ �����غ��Ҵ�.
//������ sort�� �ᵵ �����ϴٰ� �ߴµ� sort �Լ��� compare �Լ��� �������ν� Ȯ��ȭ�ߴ�.


bool compare(const pair<int, int> &a, const pair<int, int>&b)
{
	//�����󿡼� ù ��° ��ǥ�� �������� ������ ��
	//�� ��ǥ���� ������ ��ǥ�鳢���� �� ��° ��ǥ�� �������� �����ϱ⿡
	//1�������� ù ���� ��, �� ���� �� ��° ���� �������� �����Ѵ�.
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