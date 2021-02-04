#include <iostream>
using namespace std;

/*ü������ ���� �⹰�� �������� ������ ���� ��ġ���� ���� ��,�࿡ �ش��ϴ� ĭ �� �ϳ��� �̵�����
  8X8 ü������ ���¸� �Է��Ѵ�, 0�� �⹰�� ���»���, 1�� ŷ, 2�� ��� ��(�ִ� 2��), 
  3�� �� �� �ٸ� �⹰
  ���� ŷ�� ���� ���ɼ��� ������ 1, ������ 0�� ��� */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9][9], ry[2] , rx[2], cnt = 0, result = 0;
	for (int i = 0; i < 2; i++) {
		ry[i] = 0;
		rx[i] = 0;
	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) { //Rook Coordinate 
				ry[cnt] = i;
				rx[cnt] = j;
				cnt++;
			}
		}
	}
	
	bool flag = false;
	int ry1, rx1;
	for (int k = 0; k <2; k++) {
		ry1 = ry[k];
		rx1 = rx[k];
		for (int i = rx1 + 1; i < 9; i++) {
			if (arr[ry1][i] == 1) flag = true;
			else if (arr[ry1][i] == 3) break;
		}
		for (int i = rx1 - 1; i > 0; i--) {
			if (arr[ry1][i] == 1)flag = true;
			else if (arr[ry1][i] == 3) break;
		}
		for (int i = ry1 + 1; i < 9; i++) {
			if (arr[i][rx1] == 1) flag = true;
			else if (arr[i][rx1] == 3) break;
		}
		for (int i = ry1 - 1; i > 0; i--) {
			if (arr[i][rx1] == 1) flag = true;
			else if (arr[i][rx1] == 3) break;
		}
	}
	
	if (flag) cout << "1\n";
	else cout << 0;
}