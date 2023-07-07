//https://blog.51cto.com/sxhelijian/5113207
//https://www.cnblogs.com/codewriter/p/17067637.html

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define M 4
#define N 4
//���¶����ڽӱ�����
typedef struct ANode            //�ߵĽ��ṹ����
{
	int i, j;                    //�ñߵ��յ�λ��(i,j)
	struct ANode* nextarc;      //ָ����һ���ߵ�ָ��
} ArcNode;

typedef struct Vnode            //�ڽӱ�ͷ��������
{
	ArcNode* firstarc;          //ָ���һ����
} VNode;

typedef struct
{
	VNode adjlist[M + 2][N + 2];    //�ڽӱ�ͷ�ڵ�����
} ALGraph;                      //ͼ���ڽӱ�����

typedef struct
{
	int i;                      //��ǰ������к�
	int j;                      //��ǰ������к�
} Box;

typedef struct
{
	Box data[MaxSize];
	int length;                 //·������
} PathType;                     //����·������

int visited[M + 2][N + 2] = { 0 };
int count = 0;
void CreateList(ALGraph*& G, int mg[][N + 2])
//�����Թ������Ӧ���ڽӱ�G
{
	int i, j, i1, j1, di;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	for (i = 0; i < M + 2; i++)                   //���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		for (j = 0; j < N + 2; j++)
			G->adjlist[i][j].firstarc = NULL;

	for (i = 1; i <= M; i++)                    //���mg��ÿ��Ԫ��
		for (j = 1; j <= N; j++)
			if (mg[i][j] == 0)
			{
				di = 0;
				while (di < 4)
				{
					switch (di)
					{
					case 0:
						i1 = i - 1;
						j1 = j;
						break;
					case 1:
						i1 = i;
						j1 = j + 1;
						break;
					case 2:
						i1 = i + 1;
						j1 = j;
						break;
					case 3:
						i1 = i, j1 = j - 1;
						break;
					}
					if (mg[i1][j1] == 0)                          //(i1,j1)Ϊ���߷���
					{
						p = (ArcNode*)malloc(sizeof(ArcNode));   //����һ���ڵ�*p
						p->i = i1;
						p->j = j1;
						p->nextarc = G->adjlist[i][j].firstarc;   //��*p�ڵ����������
						G->adjlist[i][j].firstarc = p;//ͷ�巨
					}
					di++;
				}
			}
}
//����ڽӱ�G
void DispAdj(ALGraph* G)
{
	int i, j;
	ArcNode* p;
	for (i = 0; i < M + 2; i++)
		for (j = 0; j < N + 2; j++)
		{
			printf("  [%d,%d]: ", i, j);
			p = G->adjlist[i][j].firstarc;
			while (p != NULL)
			{
				printf("(%d,%d)  ", p->i, p->j);
				p = p->nextarc;
			}
			printf("\n");
		}
}

void FindPath_DFS(ALGraph* G, int xi, int yi, int xe, int ye, PathType path)
{
	ArcNode* p;
	visited[xi][yi] = 1;                   //���ѷ��ʱ��
	path.data[path.length].i = xi;
	path.data[path.length].j = yi;
	path.length++;
	if (xi == xe && yi == ye)
	{
		printf("  �Թ�·��%d: ", ++count);
		for (int k = 0; k < path.length; k++)
			printf("(%d,%d) ", path.data[k].i, path.data[k].j);
		printf("\n");
	}

	p = G->adjlist[xi][yi].firstarc;  //pָ�򶥵�v�ĵ�һ���߶���
	while (p != NULL)
	{
		if (visited[p->i][p->j] == 0) //��(p->i,p->j)����δ����,�ݹ������
			FindPath_DFS(G, p->i, p->j, xe, ye, path);
		p = p->nextarc;               //pָ�򶥵�v����һ���߶���
	}
	visited[xi][yi] = 0;
}

void FindPath_BFS(ALGraph* G, int xi, int yi, int xe, int ye, PathType path)
{
	//TO DO:��������㷨Ѱ·
}

//������ʹ�ù�����������㷨�Ͷ���ʵ�ֵ��Թ�Ѱ·���������
#define MAXSIZE 200
//int visited[MAXSIZE][MAXSIZE];  //��ά���飬��¼ÿ�������Ƿ񱻷��ʹ�
//typedef struct {
//	int i, j;  //�������������
//}Box;

typedef struct {
	Box data[MAXSIZE];
	int front, rear;
}Queue;


void InitQueue(Queue* Q) {
	Q->front = Q->rear = 0;
}

int QueueEmpty(Queue Q) {
	if (Q.front == Q.rear) return 1;
	else return 0;
}

int EnQueue(Queue* Q, Box x) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return 0;  //���������޷�����
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

int DeQueue(Queue* Q, Box* x) {
	if (Q->front == Q->rear) {
		return 0;  //���пգ��޷�ɾ��
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

void FindPath_BFS(ALGraph* G, int xi, int yi, int xe, int ye) {
	Queue Q;
	Box start, current, next;
	ArcNode* p;

	start.i = xi;
	start.j = yi;
	visited[xi][yi] = 1;
	InitQueue(&Q);
	EnQueue(&Q, start);

	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &current);

		if (current.i == xe && current.j == ye) {
			printf("  �Թ�·��%d: ", ++count);
			for (int k = 0; k < Q.rear; k++) {
				printf("(%d,%d) ", Q.data[k].i, Q.data[k].j);
			}
			printf("\n");
			return;
		}

		p = G->adjlist[current.i][current.j].firstarc;
		while (p != NULL) 
		{
			if (visited[p->i][p->j] == 0) 
			{
				visited[p->i][p->j] = 1;
				next.i = p->i;
				next.j = p->j;
				EnQueue(&Q, next);
			}
			p = p->nextarc;
		}
	}
}
//���ʵ�ַ����У�����ʹ���˽ṹ�塰Box�����洢ÿ����������꣬�����˶������ݽṹ��
//��ʵ���˶��е���ز�������ʼ�����ж϶����Ƿ�Ϊ�ա���Ԫ����ӡ��Ӷ�����ɾ��Ԫ�أ���
//ʹ�ù�����������㷨�����Թ�����δ�����ʹ��ķ������μ�������У�ֱ���ҵ��յ�����Ϊ�ա�
//���㷨��ʵ�ֹ����У�����ʹ��visited�����¼ÿ������ķ���״̬����ֹ��η���ͬһ���顣



int main()
{
	ALGraph* G;
	int mg[M + 2][N + 2] =                           //�Թ�����
	{
		{1,1,1,1,1,1},
		{1,0,0,0,1,1},
		{1,0,1,0,0,1},
		{1,0,0,0,1,1},
		{1,1,0,0,0,1},
		{1,1,1,1,1,1}
	};
	CreateList(G, mg);
	printf("�Թ���Ӧ���ڽӱ�:\n");
	DispAdj(G); //����ڽӱ�
	PathType path;
	path.length = 0;
	printf("���е��Թ�·��:\n");
	FindPath_DFS(G, 1, 1, M, N, path);
	return 0;
}

