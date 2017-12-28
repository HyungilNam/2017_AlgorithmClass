//2009024249 ³²Çö±æ

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define INF 100000

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > QQ;
vector<pair<int, int> > Node1[5001];
int N, M;
int K;
int u, v, w;

int Dijkstra(int st)
{
	int length[5001];
	for ( int i = 1; i <= N; i++ )
	{
		if ( i != st )
			length[i] = INF;
		else
			QQ.push(make_pair(length[i], i));
	}
	length[st] = 0;
	while ( !QQ.empty() )
	{
		int u = QQ.top().second, val = QQ.top().first;
		QQ.pop();
		for ( int j = 0; j < Node1[u].size(); j++ )
		{
			if ( length[u] + Node1[u][j].second < length[Node1[u][j].first] )
			{
				length[Node1[u][j].first] = length[u] + Node1[u][j].second;
				QQ.push(make_pair(length[Node1[u][j].first], Node1[u][j].first));
			}
		}
	}
	int MAX = 0;
	for ( int i = 1; i <= N; i++ )
	{
		MAX = max(MAX, length[i]);
	}
	return MAX;
}

int main()
{
	cin >> N;
	for ( int i = 1; i <= N; i++ )
	{
		int temp, num;
		cin >> temp >> num;
		for ( int j = 0; j < num; j++ )
		{
			int v, w;
			cin >> v >> w;
			Node1[i].push_back(make_pair(v, w));
		}
	}
	cout << Dijkstra(1);
	return 0;
}