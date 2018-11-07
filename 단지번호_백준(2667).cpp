#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//N*Nũ���� �ʿ� ����Ʈ������ ���ִ�.
//�������� �ٸ� ������ ĥ�ؾ� �Ѵٸ�, �� ��� ������ �����ϸ� �� ������ ȣ���� ��ΰ�?
//1�� ����Ʈ, 0�� ����Ʈ ����



//�÷ε� ���� ó�� �����ϰ� �� ����. dfs�� ����Ʈ ȣ�� ������� ������ �Բ� ���־���.


int townmap[26][26] = {};		//����Ʈ�� ��ġ�� ǥ���صδ°�
int checked[26][26] = {};		//����Ʈ ������ üũ�� �صδ°�. 
int r_move[4] = { 0,0,1,-1 };
int c_move[4] = { 1,-1,0,0 };	//��ǥ�� �����¿�� �����̱� ������ ���� x, y��ǥ�� �����̴� ������ �ǹ��Ѵ�.
int n;


int flood_fill(int r, int c)
{
	//����Ʈ�� ������ �˰� üũ�صд�.
	checked[r][c] = 1;
	int cnt = 0;
	for (int k = 0;k < 4;k++)
	{
		int nr = r + r_move[k];
		int nc = c + c_move[k];

		//���� : ������ ��ǥ���� ��/��/��/��� �������µ� �ִ�/�ּҹ����� ���� �ʾ�����, �װ����� ����Ʈ ������ �ְ� ���� ������ üũ�� �κ��� �ƴ϶��
		if (0 <= nr && nr < n && 0 <= nc && nc < n && !checked[nr][nc] && townmap[nr][nc])
		{
			//�� ������ ��ǥ�� flood_fill�Լ��� �־ ��ͽ����ش�.
			//1 ���������ν� ����Ʈ������ ��ִ��� üũ����.
			cnt += flood_fill(nr, nc) + 1;
		}
	}

	return cnt;
}


int main()
{
	vector<int> answers;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		//�Է��� �� ���� ������ �ްԵȴ�. 
		//�� �ڸ������ 2�����迭�� �����ϹǷ� ���ڿ��� ������ �ްԵȴ�.
		string temp;
		cin >> temp;
		for (int j = 0;j < n;j++)
		{
			townmap[i][j] = temp[n-1-j] - '0';
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (townmap[i][j] && checked[i][j] == 0)
			{
				//ó�� �����ϰԵǴ� ��� ������ ����Ʈ��� flood_fill�� ����ɰ��̴�.
				//�̹� ������ �� �ְų� üũ�� ����Ʈ��� flood_fill�� ���ǰ� ��߳��� ������� �ʴ´�.
				answers.push_back(flood_fill(i, j) + 1);
			}
		}
	}

	sort(answers.begin(),answers.end());
	cout << answers.size() << endl;
	for (int i = 0;i < answers.size();i++)
	{
		cout << answers[i] << endl;
	}

	return 0;
}