#include <stdio.h>

//�������ռ�����
int buf[8] = { 0 };
int buf_len = sizeof(buf) / sizeof(buf[0]);

//Ҫ���������
int input_buf[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
int ipt_len = sizeof(input_buf) / sizeof(input_buf[0]);

//ͷβָ��
int head;
int tail;

//fifo: first in, first out���Ƚ��ȳ���
//�����������ݺ���
void fifo_put(int val)
{
	printf("put val: %d\thead: %d\n", val, head);
	//���������������
	buf[head++] = val;
	if (head == buf_len)
	{
		head = 0;
	}
}

//�жϻ������Ƿ�Ϊ�պ���
int fifo_empty(void)
{
	//��ͷβ�����Ϊ��
	if (head != tail)
	{
		return 0;
	}
	//����Ϊ��
	return 1;
}

//�����������ݺ���
int fifo_get(int* val)
{
	//��������Ϊ����ȡ������
	if (!fifo_empty())
	{
		printf("get val: %d\ttail: %d\n", buf[tail], tail);
		*val = buf[tail++];
		if (tail == buf_len)
		{
			tail = 0;
		}
		//ȡ�����ݳɹ�
		return 1;
	}
	//ȡ������ʧ��
	return 0;
}


int main()
{
	//����ȡ�����ݼ�������
	int get_count = 1;
	for (int i = 0; i < ipt_len; i++)
	{
		fifo_put(input_buf[i]);
		//������ȡһ��
		if (i % 2 == 0)
		{
			int val;
			//��ȡ�����ݳɹ����ӡ����
			if (fifo_get(&val))
			{
				printf("val: %d\t\tget count: %d\n\n", val, get_count);
				get_count++;
				//ѭ������������9�Σ�ȡ��5��
			}
		}
	}

	//����ѭ���������鲻Ϊ��ʱȡ��ʣ������
	while (!fifo_empty())
	{
		int val;
		//��ȡ�����ݳɹ����ӡ����
		if (fifo_get(&val))
		{
			printf("val: %d\t\tget count: %d\n\n", val, get_count);
			get_count++;
			//ѭ������������9�Σ�ȡ��9�Σ�������Ϊ�գ��ٴν���ѭ��
		}
	}
	return 0;

	//ע�����������ݵĸ�������14ʱ����ʹ8λ����λ�Ļ���������
}