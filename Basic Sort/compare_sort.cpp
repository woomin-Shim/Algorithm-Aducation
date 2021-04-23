#include <iostream>
#include <stdlib.h>
#include <time.h> //clock �Լ��� ����ϱ� ���� ������� 
using namespace std;
#define MAX_SIZE 100000 //���ĵ� �迭 ������ ���� 
int sorted[MAX_SIZE];  //������������ ������ �� ���Ǵ� �ӽ� �迭 


//execute merge 
void merge(int list[], int low, int mid, int high) {
	int n1 = low;  //left partition
	int n2 = mid + 1;  //right partition
	int idx = low;

	while (n1 <= mid && n2 <= high) {  //�����̳� ������ �߿� �����Ͱ� �����Ǹ� �������� 
		if (list[n1] <= list[n2]) {  //���� data�� ������ data���� �۰ų� Ŭ ��� 
			sorted[idx++] = list[n1++];  //�ӽ� �迭�� left data ����
		}
		else { //������ data�� ���� data���� �������
			sorted[idx++] = list[n2++];  //�ӽ� �迭�� right data ����
		}
	}

	if (n1 > mid) {  //���� data ��� ����
		while (n2 <= high) sorted[idx++] = list[n2++];   //���� ������ data�� ����
	}
	else {  //������ data ��� ����
		while (n1 <= mid) sorted[idx++] = list[n1++];   //���� ���� data ����
	}

	for (int i = low; i <= high; i++)
		list[i] = sorted[i];    //�ӽ� �迭�� ���ĵ� �迭�� ������ �迭�� 

}

void merge_sort(int list[], int low, int high) {  
	int middle;
	if (low < high) {
		middle = (low + high) / 2;  //mid index
		merge_sort(list, low, middle);  //���� merge sort
		merge_sort(list, middle + 1, high);  //������ merge sort
		merge(list, low, middle, high);  //execute merge 
	}
}

//call by reference 
void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int list[], int low, int high) {
	int pivot = low;  //�� ó�� ���� pivot���� setting
	int left = low, right = high;

	while (left < right) {  //�� ���� ��ġ�� while loop ����
		while (list[left] <= list[pivot] && left<=high)  //�Ǻ������� ũ�� stop 
			left++;
		while (list[right] > list[pivot])  //�Ǻ������� �۰ų� ������ stop 
			right--;
		if (left < right) {
			//swap(&list[left], &list[right]);
			int tmp = list[left];
			list[left] = list[right];
			list[right] = tmp;
		}
	}
	//swap(&list[pivot], &list[right]);
	int tmp = list[pivot];
	list[pivot] = list[right];
	list[right] = tmp;
	return right;
}

void quick_sort(int list[], int low, int high) {
	if (low < high) {
		int pivot = partition(list, low, high);
		quick_sort(list, low, pivot - 1);
		quick_sort(list, pivot + 1, high);
	}
}

int main() {
	int arr[MAX_SIZE], arr2[MAX_SIZE];   //merge_sort, quick_sort�� ���� �迭 
	

	srand(time(NULL));  //���� ������ ���� SEED
	clock_t start, end;
	double t1 = 0.0, t2 = 0.0;  //merge_sort, quick_sort ���� �ð� ����

	//��սð� ���ϱ� ���� 10���� �ݺ� 
	for (int k = 0; k < 10; k++) {  
		//���� �ѹ� ���� 
		for (int i = 0; i < MAX_SIZE; i++) {
			arr[i] = arr2[i] = rand() % 99999 + 1; // 1~99999 random 
		}
		for (int i = 0; i < 30; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < 30; i++) {
			cout << arr2[i] << " ";
		}
		cout << "\n";


		//merge_sort ����
		start = clock();
		merge_sort(arr, 0, MAX_SIZE - 1);
		end = clock();
		for (int i = 0; i < 30; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		t1 += (double)(end - start) / CLOCKS_PER_SEC;

		//quick_sort ����
		start = clock();
		quick_sort(arr2, 0, MAX_SIZE - 1);
		end = clock();
		for (int i = 0; i < 30; i++) {
			cout << arr2[i] << " ";
		}
		cout << "\n";
		t2 += (double)(end - start) / CLOCKS_PER_SEC;

	}
	cout << "MergeSort�� ���� �ð� : " << t1/10 << '\n';
	cout << "QuickSort�� ���� �ð� : " << t2/10 << '\n';

	return 0; 
}