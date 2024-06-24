#include<iostream>
#include<algorithm>
#define MAXVerttexNum 100		//顶点数目的最大值

//邻接矩阵
typedef char VertexType;		//顶点对应的数据类型
typedef int EdgType;			//边对应的数据类型
typedef struct {
	VertexType vex[MAXVerttexNum];		//顶点表
	EdgType edge[MAXVerttexNum][MAXVerttexNum];//邻接矩阵，边表
	int vexnum, arcnum;			//图当前的顶点数,边数
}Mgraph;
//邻接表
typedef struct ArcNode {		//边表节点
	int adjvex;					//该弧指向顶点的位置
	struct ArcNode* nextrac;	//指向下一条弧的位置
	//InfoType info;			//网的边权值
}ArcNode;
typedef struct VNode {
	VertexType data;			//顶点信息
	ArcNode* firstarc;			//指向第一条依附该顶点弧的指针
}VNode, AdjList[MAXVerttexNum];
typedef struct {
	AdjList vertices;			//邻接表
	int vexnum, arcm;			//图当前的顶点数,弧数
}ALGraph;
using namespace std;

void visit(int i) {

}

//邻接表实现BFS
void BFS(ALGraph g, int i) {
	visit(i);
	//visited[i] = false;		//标记访问的数组
	//EnQueue(Q, i);			//顶点i入队
	//while (!IsEmpty(q))
	//{
	//	DeQueue(Q, v);			//队首元素出队
	//	for (p = g.vertices[v];p;p = p->nextrac) {
	//		w = p->adjvex;
	//		if (visited[w] == false) {
	//			visit(w);
	//			visited[w] = true;
	//			EnQueue(Q, w);
	//		}
	//	}
	//}
}
//邻接矩阵实现BFS
//void BFS(Mgraph g, int i) {
//	visit(i);
//	visited[i] = true;
//	EnQueue(Q, i);
//	while (!IsEmpty(Q)) {
//		DeQueue(g, v);
//		for (w = 0;w < g.vexnum;w++) {
//			if (visit[w] == false && g.edge[v][w] == 1) {
//				visit[w];
//				visited[w] = true;
//				EnQueue(Q, w);
//			}
//		}
//	}
//}
//DFS的伪代码
//bool visited[MAXVerttexNum];		//标记访问数据,数组里面的参数无意义
//void DFS(Graph G) {
//	for (i = 0;i < G.vexnum;i++) {
//		visited[i] = false;
//	}
//	for (i = 0;i < G.vexnum;i++) {
//		if (!visited[i]) DFS(G, i);
//	}
//}

int main()
{

	return 0;
}