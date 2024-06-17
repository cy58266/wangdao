#include<iostream>
#include<algorithm>
#define ElemType int 

using namespace std;
//栈
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int top;
}Sqstack;
//队列

//初始化
void InitStack(Sqstack& s) {
	s.top = -1;
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

//出队
int main()
{

	return 0;
}