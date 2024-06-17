#include<iostream>
#include<algorithm>
#define ElemType int 

using namespace std;
//栈
//链式存储方式
typedef struct {
	ElemType data;
	struct Linknode* next;
}LiStack;
//线性存储方式
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int top;
}Sqstack;
//队列
//链式存储方式
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
//顺序存储方式
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
//初始化
void InitStack(Sqstack& s) {
	s.top = -1;
}
//链式队列(带头节点)
void InitQueue(LinkQueue& q) {
	q.front = (LinkNode*)malloc(sizeof(LinkNode));
	q.front->next = NULL;
}
//线性队列
void InitQueue(SqQueue& q) {
	q.rear = q.front = 0;
}
//出栈
void Pop(Sqstack& s, ElemType& e) {
	if (s.top == -1)return;
	e = s.data[s.top--];
}
//入栈
void Push(Sqstack& s, ElemType e) {	
	if (s.top == MaxSize) return;
	s.data[s.top++] = e;
}
//进队
//链式队列(带头节点)
void EnQueue(LinkQueue& q, ElemType e) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}
//线性队列
void EnQueue(SqQueue& q, ElemType e) {
	if ((q.rear + 1) % MaxSize == q.front) return;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
}
//出队
//链式队列(带头节点)
void DeQueue(LinkQueue& q, ElemType& e) {
	if (q.front == q.rear) return;
	LinkNode* p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear == p) q.rear = q.front;//若原队列只有一个节点,删除后变空
	free(p);
}
//线性队列
void DeQueue(SqQueue& q, ElemType& e) {
	if (q.rear == q.front) return;
	e = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
}
int main()
{

	return 0;
}