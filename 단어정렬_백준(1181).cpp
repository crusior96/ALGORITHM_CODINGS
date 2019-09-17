#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//N개의 단어들이 있다고 가정하자.
//이 단어들을 갯수가 짧은 순서대로 먼저 정렬하고, 같은 길이의 단어들은 사전순으로 정렬하는 기능을 구현하라.
//단, 같은 단어가 중복되어 입력되어진 경우, 중복된 것들 중 한 단어만 적어둔다.

//sort함수에 사용될 다른 정렬법
bool comp(const string &s1, const string &s2)
{
	if (s1.size() == s2.size()) //사이즈가 같다면, 사전순 앞으로 정렬
	{
		return s1 < s2;
	}
	return s1.size() < s2.size(); //사이즈가 다르다면, 짧은 단어를 앞으로 정렬
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

	vector<string>::iterator iter; //벡터의 시작점을 저장하는 변수
	vector<string>::iterator end_iter; //벡터의 끝점을 저장하는 변수

	sort(v.begin(), v.end(), comp); //comp함수에 적어놓은 규칙대로 정렬한다.

	end_iter = unique(v.begin(), v.end()); //중복되는 단어들을 제외시켜준다.
	for (iter = v.begin();iter != end_iter;iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}