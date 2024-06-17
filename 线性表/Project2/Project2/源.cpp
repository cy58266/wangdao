#include<iostream>
#include<algorithm>
#define ElemType int 

using namespace std;

//单链表
typedef struct LNode {
	ElemType data;      //结点的数据域 
	struct LNode* next;   //结点的指针域 
}LNode, * LinkList;//LNode：结构体类型；*LinkList：指向LNode结构体类型的指针
//双链表
typedef struct DNode {
	ElemType data;
	struct DNode* piror, * next;
}Dnode, * DLinkList;
//初始化
//不带头节点
//void InitList(LinkList &l) {
//	l = NULL;
//}
//带头节点
void InitList(LinkList &l) {
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
}
//插入(用后插法插入到位置pos值为e的元素)
bool ListInsert(LinkList &l,int pos,ElemType e) {
	LNode* p = l;
	for (int i = 0;i < pos - 1, p != NULL;i++) {
		p = p->next;
	}
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	//双链表
	/*
	s->next=p->next;
	p->next->prior=s;
	s->piror=p;
	p->next=s;
	*/
	return s;
}
//删除(删除第i个节点)
bool ListDelet(LinkList& l, int i, ElemType& e) {
	LNode* p = l;
	int j = 0;
	while (p != NULL && j != j - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL) return false;
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	//双链表
	/*
	p->next=q->next;
	q->next->prior=p;
	free(q);
	*/

	free(q);
	return true;
}
//查找
//按照值查找
LNode* LocateElem(LinkList l,ElemType e) {
	LNode* p = l;
	while (p->data!=e&&p!=NULL)
	{
		p = p->next;
	}
	return p;
}
//按照位置查找
LNode* GetElem(LinkList l, int pos) {
	LNode* p = l;
	int i = 0;
	while (p != NULL && i != pos) {
		p = p->next;
		i++;
	}
	return p;
}
//归并(有序链表)
void Merge(LinkList l1, LinkList l2, LinkList& l3) {
	LNode* a = l1->next;
	LNode* b = l2->next;
	LNode* c = l1;
	l3 = c;
	while (a && b) {
		if (a->data <= b->data) {
			c->next = a;
			a = a->next;
		}
		else {
			c->next = b;
			b = b->next;
		}
	}
	if (b) {
		c->next = b;
	}
	if (a) {
		c->next = a;
	}
	free(b);
}
//头插法建立单链表
LinkList List_HeadInsert(LinkList& l) {
	LNode* s;
	int x;
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
	cin >> x;
	while (x!=999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = l->next;
		l->next = s;
		cin >> x;
	}
	return l;
}
//尾插法建立单链表
LinkList Link_TailInsert(LinkList& l) {
	int x;
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
	LNode* s, * r = l;
	cin >> x;
	while (x != 999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return l;
}
int main()
{

	return 0;
}