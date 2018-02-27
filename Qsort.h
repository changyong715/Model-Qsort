#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int comp(const void* a, const void* b)
{
	return (*(char*)a) > (*(char*)b) ? 1 : 0;
	//return (*(int*)a) > (*(int*)b) ? 1 : 0;
}
void Swap(void *p1, void * p2, int size)
{
	int i = 0;     
	for (i = 0; i< size; i++) 
	{ 
		char tmp = *((char *)p1 + i);  
		*((char *)p1 + i) = *((char *)p2 + i);        
		*((char *)p2 + i) = tmp; 
	}
}
void MyQsort(void* base,size_t count,size_t size,int(*comp)(void*,void*))
{
	int i = 0, j = 0;
	for (; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (comp((char*)base + i * size, (char*)base + j * size)>0)
			{
				Swap((char*)base + i * size, (char*)base + j * size,size);
			}
		}
	}
}
void TestQsort()
{
	//int arr[10] = { 12,23,14,35,42,31,27,87,36,9 };
	char arr[10] = { 'a','h','d','y','j','o','e','r','q','c' };
	MyQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), comp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%c ", arr[i]);
	}
}