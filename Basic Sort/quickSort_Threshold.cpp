#include <iostream>
#include <time.h>
using namespace std;
#define MAX_SIZE 15000

//execute insertion_sort
void insertion_sort(int list[], int length) {
	for (int i = 1; i < length; i++) {
		for (int j = i; j > 0; j--) {
			//���ҵ��� ���ϸ鼭 ���� ���� ������ swap 
			if (list[j] < list[j - 1]) {
				int tmp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = tmp;
			}
			else break;  //ũ�ٸ� �տ��� �̹� ���ĵ� �����̱� ������ �ݺ� �ʿ� x
		}
	}
}


int partition(int list[], int low, int high) {
	int pivot = low;  //�� ó�� ���� pivot���� setting
	int left = low, right = high;

	while (left < right) {  //�� ���� ��ġ�� while loop ����
		while (list[left] <= list[pivot] && left <= high)  //�Ǻ������� ũ�� stop 
			left++;
		while (list[right] > list[pivot])  //�Ǻ������� �۰ų� ������ stop 
			right--;
		if (left < right) {
			//list[left] �� list[right] swap
			int tmp = list[left];
			list[left] = list[right];
			list[right] = tmp;
		}
	}
	//list[pivot] �� list[right] swap
	int tmp = list[pivot];
	list[pivot] = list[right];
	list[right] = tmp;

	return right;  //return pivot index 
}

//execute basic quicksort
void quickSort_basic(int list[], int start, int end) {
	if (start <= end) {
		int pivot_pos = partition(list, start, end);  //������ partition�� first index
		quickSort_basic(list, start, pivot_pos - 1);
		quickSort_basic(list, pivot_pos + 1, end);
	}
}

//execute quickSort 
void quick_sort(int list[], int low, int high, int Threshold) {
	int cnt = high - low + 1;    //A count of elements  --->  THRESHOLD

	if (low < high) {
		if (cnt <= Threshold) {  //�Ӱ谪���� ���ų� ������ insertion_sort ���� 
			insertion_sort(list, cnt);
		}

		else {
			int pivot = partition(list, low, high);
			//if (low < pivot - 1)  //left partition elements�� �� �� �̻��� ���
				quick_sort(list, low, pivot - 1, Threshold);
			//if (pivot + 1 < high)  //right partition elements�� �� �� �̻��� ���
				quick_sort(list, pivot + 1, high, Threshold);
		}
	}
	
}

int main() {
	int arr[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE], arr4[MAX_SIZE], arr5[MAX_SIZE];
	clock_t start, end;
	double t1, t2, t3, t4, t5;

	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = arr2[i] =arr3[i] = arr4[i] = arr5[i] = rand() % 9999 + 1;
	}
	
	
	start = clock();
	quick_sort(arr, 0, MAX_SIZE - 1, 10);
	end = clock();
	t1 = (double)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < 50; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	start = clock();
	quick_sort(arr2, 0, MAX_SIZE - 1, 100);
	end = clock();
	t2 = (double)(end - start) / CLOCKS_PER_SEC;

   
	start = clock();
	quick_sort(arr3, 0, MAX_SIZE - 1, 1000);
	end = clock();
	t3 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	quick_sort(arr4, 0, MAX_SIZE - 1, 10000);
	end = clock();
	t4 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	quickSort_basic(arr4, 0, MAX_SIZE - 1);
	end = clock();
	t5 = (double)(end - start) / CLOCKS_PER_SEC;

	cout << "THRESHOLD�� 10���� �����Ͽ��� ���� ���� �ð� : " << t1 <<'\n';
	cout << "THRESHOLD�� 100���� �����Ͽ��� ���� ���� �ð� : " << t2 << '\n';   
	cout << "THRESHOLD�� 1000���� �����Ͽ��� ���� ���� �ð� : " << t3 << '\n';
	cout << "THRESHOLD�� 10000���� �����Ͽ��� ���� ���� �ð� : " << t4 << '\n';
	cout << "������ �� ���� ���� �ð� : " << t5 << '\n';
	return 0;
}