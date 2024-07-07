#include<iostream>
#include<algorithm>
#define ElemType int 

using namespace std;

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(ElemType arr[], int n) {
	int i, j;
	for (i = 2;i < n;i++) {
		if (arr[i] < arr[i - 1]) {
			arr[0] = arr[i];
			for (j = i - 1;arr[0] < arr[j];j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void HalfInsertSort(ElemType a[], int n) {
	int low, high, i, j, mid;
	for (i = 2;i < n;i++) {
		a[0] = a[i];
		low = 1, high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (a[mid] > a[0]) high = mid - 1;
			else low = mid + 1;
		}
		for (j = i - 1;j >= high + 1;j--) {
			a[j + 1] = a[j];
		}
		a[high + 1] = a[j];
	}
}
//œ£∂˚≈≈–Ú
void ShellSort(ElemType a[], int n) {
	int dk, i, j;
	for (dk = n / 2;dk >= 1;dk /= 2) {
		for (i = dk + 1;i < n;i++) {
			if (a[i] < a[i - dk]) {
				a[0] = a[i];
				for (j = i - dk;a[0] < a[j] && j>0;j -= dk) a[j + dk] = a[j];
				a[j + dk] = a[0];
			}
		}
	}
}
//√∞≈›≈≈–Ú
void BubbleSort(ElemType a[], int n) {
	for (int i = 0;i < n - 1;i++) {
		bool flag = false;
		for (int j = 1;j < n - i;j++) {
			if (a[j] > a[j - 1]) {
				ElemType temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				flag = true;
			}
		}
		if (!flag)break;
		else flag = false;
	}
}
//øÏÀŸ≈≈–Ú
int Partition(ElemType a[], int left, int right) {
	ElemType pviot = a[left];
	while (left < right) {
		while (left < right && a[right] >= pviot) right--;
		a[left] = a[right];
		while (left < right && a[left] <= pviot) left++;
		a[right] = a[left];
	}
	a[left] = pviot;
	return left;
}
void QuickSort(ElemType a[], int left, int right) {
	if (left < right) {
		int pos = Partition(a, left, right);
		QuickSort(a, left, pos - 1);
		QuickSort(a, pos + 1, right);
	}
}
//ºÚµ•—°‘Ò≈≈–Ú
void SelectSort(ElemType arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			ElemType temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
//∂—≈≈–Ú

void BulidMaxHeap(int a[], int len) {
	for (int i = len / 2;i > 0;i--) {
		HeadAdjust(a, i, len);
	}
}
void HeadAdjust(int a[], int k, int len) {
	a[0] = a[k];
	for (int i = 2 * k;i < len;i *= 2) {
		if (i < len && a[i] < a[i + 1])i++;
		if (a[0] >= a[i])break;
		else {
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];
}
//∂˛¬∑πÈ≤¢≈≈–Ú

//ª˘ ˝≈≈–Ú


int main()
{
	int a[6] = { 0,5,4,3,2,1 };

	SelectSort(a, 6);
	//QuickSort(a, 0, 5);

	for (int i = 1;i <= 5;i++) {
		cout << a[i] << ",";
	}
	cout << endl;

	return 0;
}