#include <iostream>
using namespace std;
/*�ڿ��� n�� �Է� �޾� �̸� n���� ���� �ڿ������� ������ ��Ÿ���� ����� ��� ����ϴ� 
���α׷��� ��� ȣ���� ����Ͽ� �ۼ�*/

//!!!!!! Wrong ---> Time limit exceed

int n;
int arr[100];
int result = 0;

void division(int x, int idx) {  //arr[idx]��°������ ���� x��� print
	if (idx>n)  // *** NOT idx>=n
		return;

	int cnt = 0;
	for (int i = 0; i < idx; i++) {
		cnt += arr[i];
	}

	//if(cnt > n) return;  ??

	if (cnt == n) {
		for (int i = 0; i < idx; i++) {
				if (!(i == idx - 1)) cout << arr[i] << "+";
				else cout << arr[i];
		}
		result++;
		cout << "\n";
	}
	else {
		for (int i = x; i > 0; i--) {   // 0 1 2 3 
			arr[idx] = i;                   // 3 3 3 3 

			
			//if (idx>0 && arr[idx - 1] < arr[idx]) continue;
			division(i, idx + 1);

		}
	}
}
int main() {
	cin >> n;
	division(n-1, 0);
	cout << result;
	return 0;
}