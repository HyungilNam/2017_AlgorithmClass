//2009024249_남현길
/*
#include<stdio.h>

void selectionSort(int arr[], int n, int m);

int main()
{
	int i;
	int n, m;     //n:사이즈, m: 정렬 회수

	int arr[30000];

	scanf("%d %d", &n, &m);
	

	for (  i = 0; i < n; i++ )
	{
		scanf("%d", &arr[i]);
	}

	selectionSort(arr, n, m);

	for ( i = 0; i < n; i++ )
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}

void selectionSort(int arr[], int n, int m)
{
	int i, j;
	int min;
	int tmp;

	for (  i = 0; i < m; i++ )
	{
		min = i;
		for (  j = i+1; j < n; j++ )
		{
			if ( arr[j]<arr[min])
			{
				min = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}*/