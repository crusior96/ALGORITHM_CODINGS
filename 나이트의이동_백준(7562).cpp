#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//T���� �׽�Ʈ���̽����� ����Ʈ�� (nx,ny)���� (gx,gy)�� �̵���������, �����ϴٸ� �� �ּ� �̵�Ƚ���� ����϶�.
//ü������ ���̴� N�̸�, �� �׽�Ʈ���̽����� �ٸ��� �Է¹޴´�.

int chessboard[301][301] = {}; //����Ʈ�� �� ��ġ���� �����ϱ� ���� ������ Ƚ���� �����صδ� �迭. 
int checked[301][301] = {}; //����Ʈ�� �����߾��� ��ġ. �ּڰ����� �����ϱ� ���� ���ʷ� ����� ������ �־�д�.
queue<int> xpoint;
queue<int> ypoint; 
//BFS�� ����ϱ� ���� queue�� ����Ͽ���.
//�� �־����� ��ǥ���� ������ queue�� �����ϸ�
int temp_x, temp_y;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,2,1,-1,-2 }; //dx�� dy�� ����Ʈ�� 8���� �̵������� �����ص� �迭�̴�.
int complete = 0; //��ǥ�������� ���������� 1, �ƴϸ� 0�� ���� ������ �ȴ�.

void checker(int x, int y, int goal_x, int goal_y, int length)
{
	xpoint.push(x);
	ypoint.push(y);
	chessboard[x][y] = 0;
	checked[x][y] = 1;
	while (!xpoint.empty() && !ypoint.empty())
	{
		temp_x = xpoint.front();
		xpoint.pop();
		temp_y = ypoint.front();
		ypoint.pop();
		if (temp_x == goal_x && temp_y == goal_y) //��ǥ ��ġ�� �����ϰ� �Ǹ� while�� ����
		{
			cout << chessboard[temp_x][temp_y] << endl;
			complete = 1;
			break;
		}
		//���� ��ǥ ��ġ�� �ƴ϶� for���� ������ ���
		for (int i = 0;i < 8;i++)
		{
			int xx = temp_x + dx[i];
			int yy = temp_y + dy[i]; //������ x����ǥ�� y����ǥ�� ����Ʈ�� �̵���Ģ�� ���� �̵���Ų �ӽð��� xx�� yy�� ������ѵд�.
			if (checked[xx][yy] == 0 && xx >= 0 && xx < length&&yy >= 0 && yy < length) //�湮���� �ʾҴ� ���̸� ü������ ����� �ʴ� ������ ��ǥ���
			{
				checked[xx][yy] = 1;
				xpoint.push(xx);
				ypoint.push(yy);
				chessboard[xx][yy] = chessboard[temp_x][temp_y] + 1; //���� ��ġ������ �̵��ߴ� Ƚ�� + 1�� ���� �̵��� ��ġ�� chessboard �迭�� �����صд�.
			}
		}
	}

}

int main()
{
	int T, N;
	int nx, ny, gx, gy;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		cin >> N;
		cin >> nx >> ny;
		cin >> gx >> gy;

		if (nx == gx && ny == gy)
		{
			cout << 0 << endl;
		}
		else
		{
			checker(nx, ny, gx, gy, N);
			if (complete == 0)
			{
				cout << 0 << endl;
			}
			memset(chessboard, 0, sizeof(chessboard));
			memset(checked, 0, sizeof(checked));
			//���ؿ��� memset�� ����Ϸ��� cstring����� �߰����ѵ־��Ѵ�. �׷��������� �����Ͽ��� �߻�.
			while (!xpoint.empty())
			{
				xpoint.pop();
			}
			while (!ypoint.empty())
			{
				ypoint.pop();
			}
		}
	}
	return 0;
}