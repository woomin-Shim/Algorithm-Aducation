#include <iostream>
using namespace std;

/*��Ŀ� ������ 81���� �ڿ����� �־��� �� 
  �̵� �� �ִ밪�� ã�� ���� ����� ��� 
  �ִ밪�� �������� ��� ���� ���� ���� ������ ���
  �� ��ȣ�� ������ ���� ���� ���� ������ ���*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, big=0, ry, rx;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> num;

			if (num > big) {
				big = num;
				ry = i;  //��
 				rx = j;  //��
			}

			//else if ���� ��� ���� ���� X
			else if (big == num) {
				if (i < ry || (ry == i && j < rx)) {
					ry = i;
					rx = j;
				}
			}
		}
	}
	cout << big << "\n";
	cout << ry << ' ' << rx;

}