#include <stdio.h>
#include <stdlib.h>



static void adjustDown(int * data,int size, int m)//向下调整算法
{
	int cur = m;
	int n;
	while (cur * 2 + 1<size)
	{
		if (cur * 2 + 2 >=size)
		{
			n = cur * 2 + 1;
		}
		else
		{
			if (data[cur * 2 + 1] > data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (data[cur] < data[n])
		{
			int tmp = data[cur];
			data[cur] = data[n];
			data[n] = tmp;

			cur = n;
		}
		else
		{
			break;
		}
	}
}
void swapHeap(int* data, int size)//交换首尾元素
{
	if (size == 0)
	{
		return 0;
	}
	int tmp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = tmp;

	adjustDown(data, size - 1, 0);
}
void HeapSortS(int* src, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		adjustDown(src, n, i);
	}

	for (; n > 1; n--)
	{
		swapHeap(src, n);
	}
}


void printArray(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main()
{
	int data[10] = { 2, 3, 4, 5, 7, 1, 8, 9, 10, 6 };

	HeapSortS(data, 10);
	printArray(data, 10);
	system("pause");
	return 0;
}