#include<iostream>
#include<algorithm>
#define MAXLEN 255
#define ElemType int

using namespace std;
//二叉树的顺序存储结构

//二叉树的链式存储结构
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//二叉树的建立
void CreatTree(BiTNode** T) {
	ElemType a;
	cin >> a;
	(*T) = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->data = a;
	CreatTree(&(*T)->lchild);
	CreatTree(&(*T)->rchild);
}

void visit(BiTree) {

}
//二叉树的前序遍历
void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//二叉树的中序遍历
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
//二叉树的后序遍历
void PostOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		InOrder(T->rchild);
		visit(T);
	}
}
//层次遍历
void LevelOrder(BiTree T) {
	//InitQueue(Q);		//初始化辅助队列
	BiTree T;
	//EnQueue(Q,T);		//将根节点入队
	//while (!IsEmpty(Q)) {
	//	DeQueue(Q, p);		//头节点出队
	//	visit(p);
	//	//如果p的孩子不为空则入队
	//	if (p->lchild != NULL) EnQueue(p->lchild);
	//	if (p->rchild != NULL) EnQueue(p->rchild);
	//}
}

int main()
{

	return 0;
}