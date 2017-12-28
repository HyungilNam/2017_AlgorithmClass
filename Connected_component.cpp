//2009024249_남현길

#include <stdio.h>
#include <stdlib.h>

int numV = 0;
int *list = NULL;
int *Qlist = NULL;
int *rep = NULL;

typedef struct _vertex
{

	int groupname;
	int Value;
	int Rank;

	struct _vertex *Parent;
} VT;

VT *vertex;

void MSet(VT *x, int Value)
{

	x->Value = Value;
	x->Parent = x;
	x->Rank = 0;
}

VT *Find(VT *x)
{

	if ( x != x->Parent )
	{

		x->Parent = Find(x->Parent);
	}

	return x->Parent;
}

void Link(VT *x, VT *y)
{

	if ( x->Rank > y->Rank )
	{

		y->Parent = x;			//랭크가 높은 놈이 부모가 되도록
	}

	else
	{

		x->Parent = y;

		if ( x->Rank == y->Rank )
		{

			y->Rank = ++( y->Rank );
		}
	}
}

void Union(VT *x, VT *y)
{

	Link(Find(x), Find(y));
}

int Samexy(VT *x, VT *y)
{

	if ( Find(x) == Find(y) )
	{

		return 1;
	}

	else
	{

		return 0;
	}
}

int main()
{

	int *tmp_list = NULL;
	int v1 = 0;
	int v2 = 0;
	int i = 0, j = 0, tmp = 0;
	int order = 0;
	int cnum = 0;

	scanf("%d", &numV);

	vertex = (VT*)malloc(sizeof(VT)*( numV + 1 ));
	list = (int*)malloc(sizeof(int)*( numV + 1 ));
	tmp_list = (int*)malloc(sizeof(int)*( numV + 1 ));

	for ( i = 1; i <= numV; i++ )
	{

		MSet(&vertex[i], i);
	}

	while ( scanf("%d %d", &v1, &v2) != EOF )
	{

		if ( Find(&vertex[v1]) != Find(&vertex[v2]) )
		{

			Union(&vertex[v1], &vertex[v2]);
		}
	}

	for ( i = 1; i <= numV; i++ )
	{

		list[i] = Find(&vertex[i])->Value;
		tmp_list[i] = Find(&vertex[i])->Value;
	}

	for ( i = 1; i <= numV; i++ )
	{

		tmp = list[i];

		if ( tmp != 0 )
		{

			cnum++;

			for ( j = i + 1; j <= numV; j++ )
			{

				if ( tmp == list[j] )
				{

					list[j] = 0;
				}
			}
		}
	}

	Qlist = (int*)malloc(sizeof(int)*( cnum + 1 ));
	order = 1;

	for ( i = 1; i <= numV; i++ )
	{

		if ( list[i] != 0 )
		{

			Qlist[order++] = list[i];
		}
	}

	for ( i = 1; i <= numV; i++ )
	{

		for ( j = 1; j <= numV; j++ )
		{

			if ( tmp_list[i] == Qlist[j] )
			{

				list[i] = j;
			}
		}
	}

	printf("%d\n", cnum);

	for ( i = 1; i <= numV; i++ )
	{

		printf("%d\n", list[i]);
	}

	return 0;
}