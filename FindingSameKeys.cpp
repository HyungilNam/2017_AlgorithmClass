//2009024249_������
/*
//���� �� ���� ��/�ƴϿ��θ�!
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m;
	int i;
	int result = 0;

	scanf("%d %d", &n, &m);

	int arrA[100001] = {0};

	while ( 0< n )
	{
		scanf("%d", &i);
		arrA[i] = 1;
		n--;
	}

	while ( 0<m)
	{
		scanf("%d", &i);
		if ( arrA[i] == 1)
		{
			++result;
			arrA[i] = 0;
		}
		m--;
	}

	printf("%d", result);

	return 0;
}
*/
