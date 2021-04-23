#include <iostream>
using namespace std;
#define MAX_SIZE 10000  

int sorted[MAX_SIZE]; //������������ �պ��� ������ ������ �ӽ������ϱ� ���� �迭 


//�պ��� �����ϴ� �Լ�
void merge(int list[], int low, int mid, int high) {
	int n1 = low;  //left data set
	int n2 = mid + 1;  //right data set
	int s = low;  //sorted �迭�� ���� index

	while (n1 <= mid && n2 <= high) { //����, ������ data set�� ���� ������
		if (list[n1] <= list[n2]) { //���� data�� �����ʺ��� �۰ų� ������ win
			sorted[s++] = list[n1++];
		}
		else {  //������ data�� ������ win
			sorted[s++] = list[n2++];
		}
	}

	if (n1 > mid) {  //���� data�� ��� sorted�� ����� ���
		while (n2 <= high)  //���� ������ data ��� ����
			sorted[s++] = list[n2++];
	}
	else //������ data�� ��� sorted�� ����� ���
		while (n1 <= mid)  //���� ���� data ��� ���� 
			sorted[s++] = list[n1++];

	for (int i = low; i <= high; i++)  //sorted�� �ӽ÷� ���ĵ� ������ list�� 
		list[i] = sorted[i];
}

//�պ�����
void merge_sort_DC(int list[], int low, int high) {
	int middle;//�߰�
	if (low < high) {  //������ ����(�ι����� 2��)
		middle = (low + high) / 2;
		merge_sort_DC(list, low, middle);  //left������ ������� ������ ������ �ϳ��� �ɶ����� ����
		merge_sort_DC(list, middle + 1, high); //right������ ������� ������ ������ �ϳ��� �ɶ����� ����
		merge(list, low, middle, high);  //�պ�
	}
}

int main() {
	int arr[10] = { 3, 7, 1, 2, 2, 55, 6, 1, 3, 9};
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	cout << '\n';
	merge_sort_DC(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	cout << '\n';
	
}