#include<iostream>
#include<algorithm>
#define MAXLEN 255

using namespace std;

//定长顺序表表示
typedef struct {
	char ch[MAXLEN];
	int length;
}SString;
//串的链式表示
typedef struct snode
{
	char data;              //数据域
	struct snode* next;     //指针域
} LiString;
//赋值操作
void StrAssign(SString& s, char chs[]) {
	s.length = 0;
	for (int i = 0;chs[i] != '\0';i++) {
		s.ch[i] = chs[i];
		s.length++;
	}
	//cout << endl << s.length;
}
//复制
void StrCopy(SString& s1, SString& s2) {
	for (int i = 0;i < s2.length;i++) {
		s1.ch[i] = s2.ch[i];
		s1.length = i;
	}
	s1.length++;
}
//判断空
bool StrEmpty(SString s) {
	if (s.length == 0)return true;
	return false;
}
//比较两个串
int StrCompare(SString a, SString b) {
	int i = 0;
	for (;i < a.length, i < b.length;i++) {
		if (a.ch[i] > b.ch[i]) return 1;
		else if (a.ch[i] < b.ch[i]) return -1;
		else return 0;
	}
	if ((i == a.length) && (i != b.length))
		return -1;
	else if ((i != a.length) && (i == b.length))
		return 1;
	else
		return 0;
}
//串连接
void Concat(SString& a, SString b, SString c) {
	a.length = b.length + c.length;
	for (int i = 0;i < b.length;i++) {
		a.ch[i] = b.ch[i];
	}
	for (int i = 0;i < c.length;i++) {
		a.ch[i + b.length] = c.ch[i];
	}
}
//获取next数组
void get_next(SString t,int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < t.length) {
		if (j == 0 || t.ch[i] == t.ch[j]) {
			++i, ++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
//KMP
int Index_KMP(SString s, SString t, int next[]) {
	int i = 1, j = 1;
	while (i < s.length && j < t.length) {
		if (j == 0 || s.ch[i] == t.ch[j]) {
			++i, ++j;
		}
		else j = next[j];
	}
	if (j > t.length) return i - t.length;
	else return 0;
}
//输出串
void ShowString(SString s)
{
	if (s.length == 0)
	{
		cout << "当前串为空！" << endl;
	}
	for (int i = 0; i < s.length; i++)
	{
		cout << s.ch[i];
	}
	cout << endl;
}
int main()
{
	SString S, T, N, M, G, L;
	char ch[] = { "abaabcaba" };
	char ch1[] = { "bc" };
	char ch2[] = { "helloworld" };
	StrAssign(S, ch);
	StrAssign(N, ch1);
	StrAssign(M, ch2);
	StrAssign(S, ch);
	cout << "S:";ShowString(S);
	cout << "将一s复制到另外一个:";StrCopy(T, S);ShowString(T);
	cout << "比较串的大小：0代表相等，1代表第一个串比第二个串大，-1代表第一个串比第二个串小";
	cout << "S an T:" << StrCompare(S, T) << endl;
	cout << "将N串和M串连接成新串G" << endl;Concat(G, N, M);ShowString(G);
	int ans[1001];
	get_next(S, ans);
	cout << "(KMP模式匹配算法)子串L在主串S中的位置为:" << Index_KMP(S, N, ans) << endl;
	return 0;
}