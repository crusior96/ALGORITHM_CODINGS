#include<iostream>
using namespace std;

//N개의 숫자가 나열되어있고, 이 숫자들을 이용하여 등식을 만들려 한다.
//마지막 숫자의 값을 얻어내기 위해 앞에서부터 숫자들을 더하고 빼는식으로 식들을 만든다면
//총 몇가지의 식을 만들 수 있는가?
//단, 계산과정중 0 미만 혹은 20 초과의 숫자를 저장할 수 없다고 가정하자.

int main()
{
	int N;
	int numbers[103] = {}; //N개의 나열되는 정수값들이 저장되는 배열.
	long results[3][22] = {};
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> numbers[i];
	}

	//results[1] : 숫자 T의 값에 도달할 수 있는 등식의 갯수를 저장해둔다. 이때, 그 갯수는 resluts[1][T]에 저장된다.
	//results[2] : 임시적으로 다음 계산값을 저장해둔다. 
	//이때, 다음 계산값이라함은 현재 위치까지 계산해서 얻어낼 수 있는 값들에 그 다음 수를 더하거나 빼서 조건에 부합하는 값을 의미한다.
	//DP를 위해 초기값을 지정해둔다. 나열된 정수의 맨 첫번째 값을 resluts[1][첫번째 값]에 저장해둔다.
	results[1][numbers[0]]++;

	for (int i = 1;i < N-1;i++)
	{
		//N-1번째 값까지 정수들을 더하고 빼는 과정을 진행한다.
		//조건은, results[1][j]의 배열에 0이 아닌 값이 저장되어있어야 한다.
		for (int j = 0;j <= 20;j++)
		{
			if (results[1][j] != 0)
			{
				if (j + numbers[i] <= 20)
				{
					results[2][j + numbers[i]]+=results[1][j];
				}

				if (j - numbers[i] >= 0)
				{
					results[2][j - numbers[i]]+=results[1][j];
				}
				//j의 값에 numbers[i]값을 더하고 뺀 값이 각각 조건에 해당된다면 저장해둔다.
				//이때, 이전의 resluts[1][j]값은 0으로 초기화해준다.

				results[1][j] = 0;
			}
		}
		for (int j = 0;j <= 20;j++)
		{
			//위의 for문을 진행한 후 results[2]의 값에 저장된 것들을
			//resluts[1]의 배열에 그대로 옮겨담은 후 results[2]의 배열을 초기화시킨다.
			results[1][j] += results[2][j];
			results[2][j] = 0;
		}
	}

	//N번째 숫자에 해당하는 results[1][numbers[N-1]]의 값을 출력한다. 
	cout << results[1][numbers[N-1]] << endl;
	return 0;

}

