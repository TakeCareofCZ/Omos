#include <stdio.h>

int find_num(int arr[], int len)
{
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		res ^= arr[i];
	}
	return res;
}

int main()
{
	int arr[5] = {0};
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("��¼��һ�����飨Ҫ�����ĳһ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Σ���\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n������ֻ����һ�ε�������%d\n", find_num(arr,len));
	return 0;
}