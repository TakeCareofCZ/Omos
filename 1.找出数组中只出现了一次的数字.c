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
	printf("请录入一个数组（要求除了某一个元素只出现一次以外，其余每个元素均出现两次）：\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n数组中只出现一次的数字是%d\n", find_num(arr,len));
	return 0;
}