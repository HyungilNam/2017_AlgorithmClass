// 2009024249_³²Çö±æ
/*
#include<stdio.h>

int main()
{

	int array1[30000];
	int n = 0, key = 0;
	int i = 0, j = 0, k = 0;

	scanf("%d", &n);

	for ( i = 0; i < n; i++ )
	{
		scanf("%d", &array1[i]);
	}

	for ( i = 1; i < n; i++ )
	{
		key = array1[i];
		for ( j = 0; j < i; j++ )
		{
			if ( array1[j] > key )
			{
				for (  k = i; k > j; k-- )
				{
					array1[k] = array1[k - 1];
				}
				array1[j] = key;
				break;
			}
		}
	}

	printf("\n");

	for ( i = n-1; i > -1; i-- )
	{
		printf("%d\n", array1[i]);
	}

return 0;
}
*/

