//2009024249_������
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m, k;
	int i, j;
	int arrA[100001] = {0};
	int arrB[100001] = {0};
	int check;

	//n�� �޴� ����, m�� key����, k�� ������Ʈ ����
	scanf("%d %d %d", &n, &m, &k);
	int *s = (int*)malloc(sizeof(int)*( m + 1 ));

	for ( i = 0; i < k; i++ )
	{
		scanf("%d %d", &arrA[i], &arrB[i]);
	}

	//�ʱ�ȭ
	for ( i = 0; i < m; i++ )
	{
		s[i] = 0;
	}

	//ī����
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d", &check);
		s[check] += 1;
	}
	
	//���ϱ�
	for ( i = 1; i <= m; i++ )
	{
		s[i] += s[i - 1];
	}

	for (  i = 0; i < k; i++)
	{

		printf("%d\n", s[arrB[i]] - s[arrA[i]-1]);
	}

	return 0;
}
*/