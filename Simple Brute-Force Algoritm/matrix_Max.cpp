#include <iostream>
using namespace std;

/*��Ŀ� ������ 81���� �ڿ����� �־��� �� 
  �̵� �� �ִ밪�� ã�� ���� ����� ��� 
  �ִ밪�� �������� ��� �࿭�� ���� ���� ������ ���*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9][9];
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}

	int big = 0, ry, rx; //ry ��, rx�� 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] > big) {
				big = arr[i][j]; //Max
			}
		}
	}
	int mat_i[9] = { 9 }, mat_j[9] = { 9 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j]==big) {
				mat_i[i] = i;
				mat_j[j] = j;
			}
		}
	}
	int min_i = 100, min_j = 100;
	for (int i = 0; i < 9; i++) {
		if (min_i > mat_i[i])
			min_i = mat_i[i];
		if (min_j > mat_j[i])
			min_j = mat_j[i];
	}
	cout << big << "\n";
	cout << min_i+1 << ' ' << min_j+1;

}