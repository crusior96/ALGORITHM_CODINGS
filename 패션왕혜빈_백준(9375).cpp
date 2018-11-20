#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//혜빈이는 하루에 한 번 입었던 옷들의 조합을 다른날엔 입지 않는다.
//같은 종류의 옷은 한 벌만 입을 수 있고, 한 벌이라도 입어야만 하는 조건이 있다면
//clothes 수만큼의 옷이 있을때, 옷을 입는 방법의 갯수를 구하라.
//옷의 이름 및 종류는 string으로 입력받는다.

int main()
{
	int N, clothes;
	string cloth_type, cloth_name;
	
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> clothes;
		
		int cloth_type_num[30] = {}; 
		//같은 종류의 옷이 몇 개가 있는지 저장되어지는곳. 각각의 배열 칸은 한 종류의 옷의 몇 벌 있는지를 나타내어준다.
		int ways = 0; //옷을 입을 수 있는 방법의 갯수.
		int temp = 0;
		string cloth_type_depender[30] = {}; //옷의 종류가 저장되어지는 곳.
		if (clothes == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			for (int j = 0;j < clothes;j++)
			{
				cin >> cloth_name >> cloth_type;
				cloth_type_depender[j] = cloth_type;
			}
			sort(cloth_type_depender, cloth_type_depender + clothes);
			//옷의 종류를 입력받은 배열을 정렬시킨다. 같은 단어들은 서로 이웃하게 될 것이다.
			cloth_type_num[0] = 1;
			//초기값. 최소한 한 벌은 주어지기 때문에 지정할 수 있다.
			for (int j = 1;j < clothes;j++)
			{
				//이웃한 값의 옷이 같은 종류의 옷이면 현재 위치의 배열에 1씩 더해주고
				//다른 종류라면 다음 위치의 배열로 이동한 후, 그곳에 1씩 더해준다.
				if (cloth_type_depender[j - 1] == cloth_type_depender[j])
				{
					cloth_type_num[temp]++;
				}
				else
				{
					temp++;
					cloth_type_num[temp]++;
				}
			}
			ways = cloth_type_num[0];
			for (int j = 1;j <= temp;j++)
			{
				ways = (ways + 1)*(cloth_type_num[j] + 1) - 1;
			}
			cout << ways << endl;
		}
	}

	return 0;
}