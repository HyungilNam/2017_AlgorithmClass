//2009024249_³²Çö±æ
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Node
{
	char* ch;
	int num;

	Node* left;
	Node* right;
} Node;

Node* CreateNode();

Node* InsertTrieBoth(Node* left, Node* right);
int calcurating(Node* node, int bit_size);

void MinHeapify(Node** heap, int M, int index);
void BuildHeap(Node** heap, int M);
Node* ExtractHeap(Node** heap, int M);
void InsertHeap(Node** heap, int M, Node* node);

int main()
{
	int M;  
	Node** heap;
	int S;  
	int power = 0;

	Node* trie;

	int i;

	scanf("%d", &M);

	heap = (Node**)malloc(sizeof(Node*) * ( M + 1 ));
	for ( i = 1; i <= M; i *= 2 )
		power++;

	for ( i = 1; i <= M; i++ )
	{
		heap[i] = CreateNode();
		scanf("%s %d", heap[i]->ch, &heap[i]->num);
		
	}

	scanf("%d", &S);
	

	BuildHeap(heap, M);

	while ( 1 )
	{
		trie = InsertTrieBoth(ExtractHeap(heap, M--), ExtractHeap(heap, M--));
		if ( M == 0 )
			break;
		InsertHeap(heap, M++, trie);
	}

	printf("%d\n", power*S);
	printf("%d\n", calcurating(trie, 0));


	return 0;
}

Node* CreateNode()
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->ch = (char*)malloc(sizeof(char) * 5);

	node->left = NULL;
	node->right = NULL;

	return node;
}

void MinHeapify(Node** heap, int M, int index)
{
	Node* key = heap[index];
	int child;

	for ( child = index * 2; child <= M; child *= 2 )
	{
		if ( child < M && ( heap[child]->num > heap[child + 1]->num ) )
			child++;

		if ( heap[child]->num > key->num )
			break;
		else
			heap[child / 2] = heap[child];
	}

	heap[child / 2] = key;
}

void BuildHeap(Node** heap, int M)
{
	int i;

	for ( i = M / 2; i > 0; i-- )
		MinHeapify(heap, M, i);
}

Node* ExtractHeap(Node** heap, int M)
{
	Node* Ret = heap[1];

	heap[1] = heap[M];
	MinHeapify(heap, M, 1);

	return Ret;
}

void InsertHeap(Node** heap, int M, Node* node)
{
	int i;

	M++;
	for ( i = M; i > 0; i /= 2 )
	{
		if ( i / 2 > 0 && heap[i / 2]->num > node->num )
			heap[i] = heap[i / 2];
		else
			break;
	}
	heap[i] = node;
}

Node* InsertTrieBoth(Node* left, Node* right)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->left = left;
	node->right = right;

	node->num = left->num + right->num;

	return node;
}

int calcurating(Node* node, int bit_size)
{
	int Ret = 0;

	if ( node->left == NULL && node->right == NULL )
		return bit_size * node->num;

	Ret += calcurating(node->left, bit_size + 1);
	Ret += calcurating(node->right, bit_size + 1);

	return Ret;
}*/