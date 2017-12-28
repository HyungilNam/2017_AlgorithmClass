//2009024249_³²Çö±æ
/*
#include <stdio.h>
#include <vector>


using namespace std;

int main(int argc, char * argv[])
{
	int n; scanf("%d", &n);
	vector<int> p(n + 1), k(n + 1, 0), s(n + 1, 0);


	for ( int i = 1; i <= n; ++i )
		scanf("%d", &p[i]);


	for ( int i = 1; i <= n; ++i )
	{
		
		int q = -1;

		for ( int j = 1; j <= i; ++j )
			if ( q < p[j] + k[i - j] )
			{
				q = p[j] + k[i - j];
				s[i] = j;
			}
		k[i] = q;
	}


	printf("%d\n", k[n]);

	while ( n > 0 )
	{
		printf("%d ", s[n]);
		n = n - s[n];
	}

	return 0;
}*/