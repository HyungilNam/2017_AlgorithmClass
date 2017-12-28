//2009024249_NHG
/*
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x < y)? x: y)

typedef struct Line
{
	int* assembly_time;
	int* transfer_time;

	int start;
	int end;
} Line;

int main()
{
	int N;  
	Line* line;
	int *time[2], *station[2];

	int a00, a01, a10, a11; 
	int ftime, fstation;

	int *output;    
	int i, j;

	line = (Line*)malloc(sizeof(Line) * 2);

	scanf("%d", &N);
	for ( i = 0; i < 2; i++ )
	{
		line[i].assembly_time = (int*)malloc(sizeof(int) * N);
		line[i].transfer_time = (int*)malloc(sizeof(int) * ( N - 1 ));

		time[i] = (int*)malloc(sizeof(int) * N);
		station[i] = (int*)malloc(sizeof(int) * ( N - 1 ));

		output = (int*)malloc(sizeof(int) * N);
	}

	for ( i = 0; i < 2; i++ )
		scanf("%d", &line[i].start);
	for ( i = 0; i < 2; i++ )
		scanf("%d", &line[i].end);

	//  input assembly_time
	for ( i = 0; i < 2; i++ )
		for ( j = 0; j < N; j++ )
			scanf("%d", &line[i].assembly_time[j]);

	//  input transfer_time
	for ( i = 0; i < 2; i++ )
		for ( j = 0; j < N - 1; j++ )
			scanf("%d", &line[i].transfer_time[j]);

	time[0][0] = line[0].assembly_time[0] + line[0].start;
	time[1][0] = line[1].assembly_time[0] + line[1].start;

	for ( i = 1; i < N; i++ )
	{
		a00 = time[0][( i + 1 ) % 2] + line[0].assembly_time[i];  //  line1 to line1
		a01 = time[0][( i + 1 ) % 2] + line[0].transfer_time[i - 1] + line[1].assembly_time[i];   //  line1 to line2
		a10 = time[1][( i + 1 ) % 2] + line[1].transfer_time[i - 1] + line[0].assembly_time[i];   //  line2 to line1
		a11 = time[1][( i + 1 ) % 2] + line[1].assembly_time[i];  //  line2 to line2

																
		if ( a00 <= a10 )
		{
			time[0][i % 2] = a00;
			station[0][i - 1] = 1;
		}

		//  line(2 to 1) < line(1 to 1)
		else
		{
			time[0][i % 2] = a10;
			station[0][i - 1] = 2;
		}

		//  line(2 to 2) < line(1 to 2)
		if ( a11 <= a01 )
		{
			time[1][i % 2] = a11;
			station[1][i - 1] = 2;
		}

		//  line(1 to 2) < line(2 to 2)
		else
		{
			time[1][i % 2] = a01;
			station[1][i - 1] = 1;
		}
	}

	a00 = time[0][( i + 1 ) % 2] + line[0].end;
	a11 = time[1][( i + 1 ) % 2] + line[1].end;

	if ( a00 < a11 )
	{
		ftime = a00;
		fstation = 1;
	}
	else
	{
		ftime = a11;
		fstation = 2;
	}

	//  saves proper assembly line reversely
	output[N - 1] = fstation;
	for ( i = N - 2; i >= 0; i-- )
	{
		output[i] = station[fstation - 1][i];
		fstation = output[i];
	}

	printf("%d\n", ftime);
	for ( i = 0; i < N; i++ )
		printf("%d %d\n", output[i], i + 1);


	for ( i = 0; i < 2; i++ )
	{
		free(line[i].assembly_time);
		free(line[i].transfer_time);

		free(time[i]);
		free(station[i]);

	}
	free(line);
	free(output);
}

*/
