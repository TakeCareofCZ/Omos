#include <stdio.h>

//缓冲区空间数组
int buf[8] = { 0 };
int buf_len = sizeof(buf) / sizeof(buf[0]);

//要放入的数据
int input_buf[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
int ipt_len = sizeof(input_buf) / sizeof(input_buf[0]);

//头尾指针
int head;
int tail;

//fifo: first in, first out（先进先出）
//缓冲区进数据函数
void fifo_put(int val)
{
	printf("put val: %d\thead: %d\n", val, head);
	//往缓冲区里放数据
	buf[head++] = val;
	if (head == buf_len)
	{
		head = 0;
	}
}

//判断缓冲区是非为空函数
int fifo_empty(void)
{
	//若头尾相等则不为空
	if (head != tail)
	{
		return 0;
	}
	//否则为空
	return 1;
}

//缓冲区出数据函数
int fifo_get(int* val)
{
	//缓冲区不为空则取出数据
	if (!fifo_empty())
	{
		printf("get val: %d\ttail: %d\n", buf[tail], tail);
		*val = buf[tail++];
		if (tail == buf_len)
		{
			tail = 0;
		}
		//取出数据成功
		return 1;
	}
	//取出数据失败
	return 0;
}


int main()
{
	//定义取出数据计数变量
	int get_count = 1;
	for (int i = 0; i < ipt_len; i++)
	{
		fifo_put(input_buf[i]);
		//放两次取一次
		if (i % 2 == 0)
		{
			int val;
			//若取出数据成功则打印出来
			if (fifo_get(&val))
			{
				printf("val: %d\t\tget count: %d\n\n", val, get_count);
				get_count++;
				//循环结束，放了9次，取了5次
			}
		}
	}

	//继续循环，当数组不为空时取出剩余数据
	while (!fifo_empty())
	{
		int val;
		//若取出数据成功则打印出来
		if (fifo_get(&val))
		{
			printf("val: %d\t\tget count: %d\n\n", val, get_count);
			get_count++;
			//循环结束，放了9次，取了9次，缓冲区为空，再次进行循环
		}
	}
	return 0;

	//注：当输入数据的个数大于14时，会使8位数据位的缓冲区爆掉
}