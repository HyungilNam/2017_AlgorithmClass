#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define White 0
#define Gray 1
#define Black 2

#define Tree 1
#define BACK 2 
#define forward 3
#define Cross 4

typedef struct UAL
{

	int color;
	int f;
	int d;
} AGraph;

typedef struct _GInfo
{

	int out_degree;
	int *list;
} GInfo;

AGraph *vertex = NULL;
GInfo *vertexInfo = NULL;

int numV = 0;
int time = 0;
int *topoList = NULL;
int topo_num = 0;
int isDAG = 1;

void ADD(int fV, int tV)
{

	int i = 0;
	int cur = 0;

	for ( i = 0; i < numV; i++ )
	{

		if ( vertexInfo[fV].list[i] == 0 )
		{

			break;
		}

		cur++;
	}

	vertexInfo[fV].list[cur] = tV;
}

void DFS_Visit(int fV)
{

	int i = 0;
	int tV = 0;

	time++;

	vertex[fV].color = Gray;
	vertex[fV].d = time;

	for ( i = 0; i < vertexInfo[fV].out_degree; i++ )
	{

		tV = vertexInfo[fV].list[i];

		switch ( vertex[tV].color )
		{

		case White:

			DFS_Visit(tV);
			break;

		case Gray:

			isDAG = 0;
			break;

		case Black:
		default:

			break;
		}
	}

	vertex[fV].color = Black;

	topoList[numV - ( topo_num++ )] = fV;

	time++;
	vertex[fV].f = time;
}

void Sort(int *list, int num)
{

	int i = 0, j = 0, tmp = 0;

	for ( i = 0; i < num; i++ )
	{

		for ( j = i + 1; j < num; j++ )
		{

			if ( list[i] > list[j] )
			{

				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void DFS()
{

	int i = 0;

	for ( i = 1; i <= numV; i++ )
	{

		vertex[i].d = 0;
		vertex[i].f = 0;
		vertex[i].color = White;

		Sort(vertexInfo[i].list, vertexInfo[i].out_degree);
	}

	time = 0;

	for ( i = 1; i <= numV; i++ )
	{

		if ( vertex[i].color == White )
		{

			DFS_Visit(i);
		}
	}
}

int main()
{

	int i = 0, j = 0;
	int fV, tV;

	scanf("%d", &numV);

	vertexInfo = (GInfo*)malloc(sizeof(GInfo)*( numV + 1 ));

	for ( i = 1; i <= numV; i++ )
	{

		vertexInfo[i].list = (int*)malloc(sizeof(int)*numV);
		vertexInfo[i].out_degree = 0;
	}

	for ( i = 1; i <= numV; i++ )
	{

		for ( j = 0; j < numV; j++ )
		{

			vertexInfo[i].list[j] = 0;
		}
	}

	vertex = (AGraph*)malloc(sizeof(AGraph)*( numV + 1 ));
	topoList = (int*)malloc(sizeof(int)*( numV + 1 ));

	while ( scanf("%d %d", &fV, &tV) != EOF )
	{

		ADD(fV, tV);
		vertexInfo[fV].out_degree++;
	}

	DFS();

	printf("%d\n", isDAG);

	if ( isDAG )
	{

		for ( i = 1; i <= numV; i++ )
		{

			printf("%d ", topoList[i]);
		}
	}

	return 0;
}
