#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//N*N크기의 맵에 아파트단지가 들어서있다.
//단지별로 다른 색깔을 칠해야 한다면, 총 몇개의 단지가 존재하며 각 단지별 호수는 몇개인가?
//1은 아파트, 0은 아파트 없음



//플로드 필을 처음 마주하게 된 문제. dfs를 아파트 호수 조사방향 지정과 함께 해주었다.


int townmap[26][26] = {};		//아파트의 위치를 표시해두는곳
int checked[26][26] = {};		//아파트 단지별 체크를 해두는곳. 
int r_move[4] = { 0,0,1,-1 };
int c_move[4] = { 1,-1,0,0 };	//좌표가 상하좌우로 움직이기 때문에 각각 x, y좌표의 움직이는 방향을 의미한다.
int n;


int flood_fill(int r, int c)
{
	//아파트가 있음을 알고 체크해둔다.
	checked[r][c] = 1;
	int cnt = 0;
	for (int k = 0;k < 4;k++)
	{
		int nr = r + r_move[k];
		int nc = c + c_move[k];

		//조건 : 지정한 좌표에서 상/하/좌/우로 움직였는데 최대/최소범위를 넘지 않았으며, 그곳에도 아파트 단지가 있고 동일 단지로 체크된 부분이 아니라면
		if (0 <= nr && nr < n && 0 <= nc && nc < n && !checked[nr][nc] && townmap[nr][nc])
		{
			//그 지점의 좌표를 flood_fill함수에 넣어서 재귀시켜준다.
			//1 더해줌으로써 아파트단지가 몇개있는지 체크가능.
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
		//입력을 한 줄의 정수로 받게된다. 
		//한 자릿수대로 2차원배열에 들어가야하므로 문자열로 정수를 받게된다.
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
				//처음 마주하게되는 어느 단지의 아파트라면 flood_fill이 실행될것이다.
				//이미 마주한 적 있거나 체크된 아파트라면 flood_fill이 조건과 어긋나서 실행되지 않는다.
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