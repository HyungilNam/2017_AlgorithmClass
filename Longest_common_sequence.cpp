//2009024249_³²Çö±æ
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x < y)? x: y);

#define MAX_SIZE 501

char* LCS(char* string1, char* string2);

int main()
{
	char string1[MAX_SIZE], string2[MAX_SIZE];

	scanf("%s %s", string1, string2);

	if ( strlen(string1) < strlen(string2) )
		printf("%s", LCS(string2, string1));
	else
		printf("%s", LCS(string1, string2));

	return 0;
}

char* LCS(char* string1, char* string2)
{
	char* aStr;
	int **table, **pass_t;
	int len1 = strlen(string1), len2 = strlen(string2);
	int left, top;
	int i, j, index;

	table = (int**)malloc(sizeof(int*) * ( len2 + 1 ));
	pass_t = (int**)malloc(sizeof(int*) * ( len2 + 1 ));
	for ( i = 0; i <= len2; i++ )
	{
		table[i] = (int*)malloc(sizeof(int) * 2);
		pass_t[i] = (int*)malloc(sizeof(int) * ( len1 + 1 ));
	}

	
	for ( i = 0; i <= len2; i++ )
		table[i][0] = 0;

	
	for ( i = 1; i <= len1; i++ )
	{
		table[0][i % 2] = 0;
		for ( j = 1; j <= len2; j++ )
		{
			
			if ( string2[j - 1] == string1[i - 1] )
			{
				
				table[j][i % 2] = table[j - 1][( i - 1 ) % 2] + 1;
				pass_t[j][i] = 1;
			}

		
			else
			{
				left = table[j][( i - 1 ) % 2];
				top = table[j - 1][i % 2];

		
				if ( left > top )
				{
					table[j][i % 2] = left;
					pass_t[j][i] = 0;
				}

				//  left <= top, arrow = 2
				else
				{
					table[j][i % 2] = top;
					pass_t[j][i] = 2;
				}
			}
		}
	}

	index = table[len2][len1 % 2];
	aStr = (char*)malloc(sizeof(char) * ( index + 1 ));
	aStr[index--] = '\0';

	i = len2;
	j = len1;
	while ( i > 0 && j > 0 )
	{
		if ( pass_t[i][j] == 1 )
		{
			aStr[index--] = string2[i - 1];
			i--; j--;
		}
		else if ( pass_t[i][j] == 0 )
		{
			j--;
		}
		else
		{
			i--;
		}
	}

	return aStr;
}*/