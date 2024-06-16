#include<iostream>
#include<algorithm>
#define MaxSize 50
#define ElemType int
#define DataType int

using namespace std;
typedef struct {
	ElemType data[MaxSize];
	int length;
	int maxsize = MaxSize;
}Sqlist;


bool Del_min(Sqlist& l, ElemType& value) {

	if (l.length < 0) return false;

	value = l.data[0];
	int pos = 0;
	for (int i = 0;i < l.length;i++) {
		if (l.data[i] < value) {
			value = l.data[i];
			pos = i;
		}
	}
	l.data[pos] = l.data[l.length - 1];
	l.length -= 1;
	return true;

}

void Reverse(Sqlist& l) {
	int right = l.length - 1;
	ElemType temp;
	for (int i = 0;i != right;i++, right--) {
		temp = l.data[i];
		l.data[i] = l.data[right];
		l.data[right] = temp;
	}
}

void Delet_Same(Sqlist& l, ElemType value) {
	int right = l.length - 1;
	int count = 0;
	ElemType temp;
	for (int i = 0;i != right; i++) {
		if (l.data[i] = value) {
			temp = l.data[i];
			l.data[i] = l.data[right];
			l.data[right] = temp;
			count++;
		}
	}
	l.length -= count;
}

bool Del_s_t(Sqlist& l, ElemType s, ElemType t) {
	int k = 0;
	if (l.length < 0 || t > s) return false;
	for (int i = 0;i < l.length;i++) {
		if (l.data[i] >= s && l.data[i] <= t) k++;
		else l.data[i - k] = l.data[i];
	}
	l.length -= k;
	return true;
}

bool Delet_Same(Sqlist& l) {
	int k = 0;
	if (l.length = 0) return false;
	for (int i = 0;i < l.length - 1;i++) {
		if (l.data[i] = l.data[i + 1]) k++;
		else l.data[i - k] = l.data[i];
	}
	l.length -= k;
	return true;
}

bool Merge(Sqlist a, Sqlist b, Sqlist& c) {
	if (a.length + b.length > c.maxsize)return false;
	int i, j, k = 0;
	while (i < a.length && j < b.length)
	{
		if (a.data[i] >= b.data[j]) {
			c.data[k++] = a.data[i++];
		}
		else {
			c.data[k++] = b.data[j++];
		}
	}
	while (i < a.length) {
		c.data[k++] = a.data[i++];
	}
	while (j < b.length) {
		c.data[k++] = b.data[j++];
	}
	c.length = k;
	return k;
}

void Reverse(DataType a[], int left, int right, int arraysize) {

}
void Exchange(DataType a[], int m, int n, int arraysize) {
	Reverse(a, 0, m + n - 1, arraysize);
	Reverse(a, 0, n - 1, arraysize);
	Reverse(a, n, m + n - 1, arraysize);
}

void SearchExchangeInsert(ElemType a[], ElemType x, int n) {
	int left, mid = 0;
	int right = n - 1;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] > x) {
			right = mid - 1;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else break;
	}
	if (mid != n - 1 && a[mid] == x) {
		ElemType temp;
		temp = a[mid];
		a[mid] = a[mid + 1];
		a[mid + 1] = temp;
	}
	if (left > right) {
		int i = n - 1;
		for (;i > right;i--) a[i + 1] = a[i];
		a[i + 1] = x;
	}
}

void SameKey(int a[], int b[], int c[], int n) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < n && k < n) {
		if (a[i] == b[j] && a[i] == c[k]) {
			cout << a[i];
			i++;j++;k++;
		}
		else {
			int maxnum = max(a[i], b[j], c[k]);
			if (a[i] < maxnum)i++;
			if (b[j] < maxnum)j++;
			if (c[k] < maxnum)k++;
		}
	}
}

//10
//Reverse(0,n-1);
//Reverse(p,n-1);
//Reverse(0,p);
//11
int M_Search(int a[], int b[], int n) {
	int count = 0;
	int i = 0, j = 0;
	int temp = 0;
	while (count < n)
	{
		if (a[i] <= b[j]) {
			temp = a[i];
			i++;
			count++;
		}
		else
		{
			temp = b[j];
			j++;
			count++;
		}
	}
	return temp;
}



int main()
{
	
	return 0;
}