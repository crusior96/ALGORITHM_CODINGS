#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//N���� �ܾ���� �ִٰ� ��������.
//�� �ܾ���� ������ ª�� ������� ���� �����ϰ�, ���� ������ �ܾ���� ���������� �����ϴ� ����� �����϶�.
//��, ���� �ܾ �ߺ��Ǿ� �ԷµǾ��� ���, �ߺ��� �͵� �� �� �ܾ ����д�.

//sort�Լ��� ���� �ٸ� ���Ĺ�
bool comp(const string &s1, const string &s2)
{
	if (s1.size() == s2.size()) //����� ���ٸ�, ������ ������ ����
	{
		return s1 < s2;
	}
	return s1.size() < s2.size(); //����� �ٸ��ٸ�, ª�� �ܾ ������ ����
}

int main()
{
	vector<string> v;
	string S;
	int N;
	cin >> N;

	for (int i = 0;i < N;i++)
	{
		cin >> S;
		v.push_back(S);
	}

	vector<string>::iterator iter; //������ �������� �����ϴ� ����
	vector<string>::iterator end_iter; //������ ������ �����ϴ� ����

	sort(v.begin(), v.end(), comp); //comp�Լ��� ������� ��Ģ��� �����Ѵ�.

	end_iter = unique(v.begin(), v.end()); //�ߺ��Ǵ� �ܾ���� ���ܽ����ش�.
	for (iter = v.begin();iter != end_iter;iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}