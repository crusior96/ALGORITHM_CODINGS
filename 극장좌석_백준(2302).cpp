#include<iostream>
using namespace std;

//어떤 극장에 한줄에 1번부터 N번까지의 N개 좌석이 있다. 
//공연을 보러 온 사람들은 자신이 구매한 티켓의 버호, 혹은 그 왼쪽이나 오른쪽 1칸의 자리에 앉을 수 있다.
//단, VIP티켓을 구매 한 사람들은 본인의 자리에만 앉으며, 다른 사람과 자리를 바꾸려 하지 않는다.
//VIP티켓을 산 사람의 수가 VIP_num이고 N의 값이 40 이하일때, N개의 좌석에 앉을 수 있는 방법의 가짓수는?
//단, 방법의 가짓수는 20억 이하이다.

int main()
{
	int N, VIP, VIP_num;
	unsigned long long int ways = 1;
	int VIP_SEAT[45] = {}; //VIP좌석이 저장되는 배열. VIP가 맞다면 VIP_SEAT[0]부터 VIP좌석번호가 저장된다.
	unsigned long long int VIP_PIBO[45] = {}; 
	//N개의 좌석이 있을때 앉을 수 있는 가짓수가 저장되는 배열.
	
	VIP_PIBO[0] = 1;
	VIP_PIBO[1] = 1;
	VIP_PIBO[2] = 2;
	//DP사용을 위해 설정해주는 초기값. 좌석의 갯수가 0, 1, 2개일때 앉을 수 있는 방법의 가짓수를 지정해둔다.
	cin >> N;
	cin >> VIP_num;

	for (int i = 0;i < VIP_num;i++)
	{
		cin >> VIP;
		VIP_SEAT[i] = VIP;
		//VIP좌석의 번호들 입력.
		//VIP좌석의 번호를 입력할때엔 작은 수부터 순차적으로 입력해주는 규칙이 있다. sort()를 쓸 필요가 없어졌다.
	}

	for (int i = 3;i <= 41;i++)
	{
		VIP_PIBO[i] = VIP_PIBO[i - 1] + VIP_PIBO[i - 2];
		//좌석의 자릿수에 따른 총 가짓수를 구해보니, 일정 숫자부턴 피보나치 규칙을 따른 다는 걸 알 수 있었다.
		//그래서 좌석의 숫자가 3일때에부턴 피보나치 규칙에 따라 앉을 수 있는 방법의 가짓수를 저장해둔다.
	}

	if (VIP_num != 0)
	{
		//VIP좌석이 있다면 그 좌석을 기준으로 옮겨다닐 수 있는 자리가 나뉘어진다.
		//가령, 7개의 좌석이 있는데 4번이 VIP석이면 1,2,3번과 4,5,6번의 좌석끼리만 자리를 옮길 수 있다는 뜻.
		//이때, 나뉘어진 자릿수에서 앉을 수 있는 방법을 각각 구한 후, 현재까지 구한 좌석에 앉는 방법의 수에 곱해주면 된다.
		for (int i = 0;i < VIP_num;i++)
		{
			if (i == 0 && i==VIP_num-1) //VIP좌석의 갯수가 1개인 경우
			{
				unsigned long long int temp = VIP_PIBO[VIP_SEAT[i] - 1];
				unsigned long long int temp2 = VIP_PIBO[N - VIP_SEAT[i]];
				ways = ways * temp2 * temp;
			}
			else if (i == 0) //첫 번째 VIP좌석이 나오는 경우
			{
				unsigned long long int temp = VIP_PIBO[VIP_SEAT[i] - 1]; 
				ways = ways * temp;
			}
			else if (i == VIP_num - 1) //마지막 VIP좌석이 나오는 경우
			{
				unsigned long long int temp = VIP_PIBO[N - VIP_SEAT[i]];
				unsigned long long int temp2 = VIP_PIBO[VIP_SEAT[i] - 1 - VIP_SEAT[i - 1]];
				ways = ways * temp*temp2;
			}
			else //그외 중간중간에 나오는 VIP좌석인 경우
			{
				unsigned long long int temp = VIP_PIBO[VIP_SEAT[i] - 1 - VIP_SEAT[i - 1]];
				ways = ways * temp;
			}
		}
	}
	else if (VIP_num == 0)
	{
		ways = VIP_PIBO[N];
	}

	cout << ways << endl;

	return 0;
}