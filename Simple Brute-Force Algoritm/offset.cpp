#include <iostream>
using namespace std;

/*5x5 2���� �迭�� �־��� �� � ���Ұ�
  �����¿쿡 �ִ� ���Һ��� ���� �� �ش� ��ġ�� *�� ǥ��*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == 0 || i == 6 || j == 6 || j == 0)
				arr[i][j] = 9;
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j + 1] &&
				arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j - 1])
				cout << "*" << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}


	/*
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i >= 1 && i <= 5 && j >= 1 && j <= 5) {
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j + 1] &&
					arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j - 1])
					cout << "*" << ' ', j++;
				if (j < 6)
					cout << arr[i][j] << ' ';
			}
		}
		if(i>0) cout << "\n";
	}
	*/

}