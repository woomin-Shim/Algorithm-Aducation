#include <iostream>
using namespace std;
/*�� ���� n, k�� �Է¹޾� k���� 1�� ���� n�ڸ� ���� ������ ����ϴ� ���α׷�(��������)*/

int n, k;
int arr[100];
bool TF[100];


void tobin(int x, int y) {  // x��° for���� 1 or 0 
	if (y == 0) {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		cout << "\n";
	}
	else {
		for (int i = x; i < n; i++) {
			arr[i] = 0;
			tobin(i + 1, y - 1);
			arr[i] = 1;
		}
	}

}
int main() {
	for (int i = 0; i < 100; i++) arr[i] = 1;
	cin >> n >> k;
	tobin(0, k);
}