#include <iostream>
using namespace std;

/*��Ŀ� ������ 81���� �ڿ����� �־��� �� 
  �̵� �� �ִ밪�� ã�� ���� ����� ��� 
  �ִ밪�� �������� ��� ���� ���� ���� ������ ���
  �� ��ȣ�� ������ ���� ���� ���� ������ ���*/
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
				ry = i;
				rx = j;
			}
			else if (arr[i][j] == big) {  
				if (i < ry)
					ry = i;
				else if(i == ry) {
					if (j < rx)
						rx = j;
				}
			}
		}
	}
	cout << big << "\n";
	cout << ry+1 << ' ' << rx+1;

}