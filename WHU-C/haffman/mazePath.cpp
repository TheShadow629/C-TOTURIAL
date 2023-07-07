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
//以下定义邻接表类型
typedef struct ANode            //边的结点结构类型
{
	int i, j;                    //该边的终点位置(i,j)
	struct ANode* nextarc;      //指向下一条边的指针
} ArcNode;

typedef struct Vnode            //邻接表头结点的类型
{
	ArcNode* firstarc;          //指向第一条边
} VNode;

typedef struct
{
	VNode adjlist[M + 2][N + 2];    //邻接表头节点数组
} ALGraph;                      //图的邻接表类型

typedef struct
{
	int i;                      //当前方块的行号
	int j;                      //当前方块的列号
} Box;

typedef struct
{
	Box data[MaxSize];
	int length;                 //路径长度
} PathType;                     //定义路径类型

int visited[M + 2][N + 2] = { 0 };
int count = 0;
void CreateList(ALGraph*& G, int mg[][N + 2])
//建立迷宫数组对应的邻接表G
{
	int i, j, i1, j1, di;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	for (i = 0; i < M + 2; i++)                   //给邻接表中所有头节点的指针域置初值
		for (j = 0; j < N + 2; j++)
			G->adjlist[i][j].firstarc = NULL;

	for (i = 1; i <= M; i++)                    //检查mg中每个元素
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
					if (mg[i1][j1] == 0)                          //(i1,j1)为可走方块
					{
						p = (ArcNode*)malloc(sizeof(ArcNode));   //创建一个节点*p
						p->i = i1;
						p->j = j1;
						p->nextarc = G->adjlist[i][j].firstarc;   //将*p节点链到链表后
						G->adjlist[i][j].firstarc = p;//头插法
					}
					di++;
				}
			}
}
//输出邻接表G
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
	visited[xi][yi] = 1;                   //置已访问标记
	path.data[path.length].i = xi;
	path.data[path.length].j = yi;
	path.length++;
	if (xi == xe && yi == ye)
	{
		printf("  迷宫路径%d: ", ++count);
		for (int k = 0; k < path.length; k++)
			printf("(%d,%d) ", path.data[k].i, path.data[k].j);
		printf("\n");
	}

	p = G->adjlist[xi][yi].firstarc;  //p指向顶点v的第一条边顶点
	while (p != NULL)
	{
		if (visited[p->i][p->j] == 0) //若(p->i,p->j)方块未访问,递归访问它
			FindPath_DFS(G, p->i, p->j, xe, ye, path);
		p = p->nextarc;               //p指向顶点v的下一条边顶点
	}
	visited[xi][yi] = 0;
}

void FindPath_BFS(ALGraph* G, int xi, int yi, int xe, int ye, PathType path)
{
	//TO DO:广度优先算法寻路
}

//以下是使用广度优先搜索算法和队列实现的迷宫寻路解决方案：
#define MAXSIZE 200
//int visited[MAXSIZE][MAXSIZE];  //二维数组，记录每个方块是否被访问过
//typedef struct {
//	int i, j;  //方块的行列坐标
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
		return 0;  //队列满，无法插入
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

int DeQueue(Queue* Q, Box* x) {
	if (Q->front == Q->rear) {
		return 0;  //队列空，无法删除
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
			printf("  迷宫路径%d: ", ++count);
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
//这个实现方案中，我们使用了结构体“Box”来存储每个方块的坐标，定义了队列数据结构，
//并实现了队列的相关操作（初始化、判断队列是否为空、将元素入队、从队列中删除元素）。
//使用广度优先搜索算法遍历迷宫，将未被访问过的方块依次加入队列中，直到找到终点或队列为空。
//在算法的实现过程中，我们使用visited数组记录每个方块的访问状态，防止多次访问同一方块。



int main()
{
	ALGraph* G;
	int mg[M + 2][N + 2] =                           //迷宫数组
	{
		{1,1,1,1,1,1},
		{1,0,0,0,1,1},
		{1,0,1,0,0,1},
		{1,0,0,0,1,1},
		{1,1,0,0,0,1},
		{1,1,1,1,1,1}
	};
	CreateList(G, mg);
	printf("迷宫对应的邻接表:\n");
	DispAdj(G); //输出邻接表
	PathType path;
	path.length = 0;
	printf("所有的迷宫路径:\n");
	FindPath_DFS(G, 1, 1, M, N, path);
	return 0;
}

