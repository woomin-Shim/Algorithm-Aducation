#include <iostream>
using namespace std;

/*ü������ ���� �⹰�� �������� ������ ���� ��ġ���� ���� ��,�࿡ �ش��ϴ� ĭ �� �ϳ��� �̵�����
  8X8 ü������ ���¸� �Է��Ѵ�, 0�� �⹰�� ���»���, 1�� ŷ, 2�� ��� ��(�ִ� 2��), 
  3�� �� �� �ٸ� �⹰
  ���� ŷ�� ���� ���ɼ��� ������ 1, ������ 0�� ��� */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9][9], ky=0, kx=0, ry, rx, cnt=1, ry2, rx2, result=0;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) { //King Coordinate
				ky = i;
				kx = j;
			}
			if (arr[i][j] == 2) { //rook Coordinate
				ry = i, rx = j;
				cnt++;
			}
			if (cnt == 2) {
				if (arr[i][j] == 2)
					ry2 = i, rx2 = j;
			}
		}
	}
	for (int i = rx + 1; i < 9; i++) {
		if (arr[ry][i] == 1) result = 1;
		else if (arr[ry][i] == 3) break;
	}
	for (int i = rx - 1; i > 0; i--) {
		if (arr[ry][i] == 1)result = 1;
		else if (arr[ry][i] == 3) break;
	}
	for (int i = ry + 1; i < 9; i++) {
		if (arr[i][rx] == 1) result = 1;
		else if (arr[i][rx] == 3) break;
	}
	for (int i = ry - 1; i > 0; i--) {
		if (arr[i][rx] == 1) result = 1;
		else if (arr[i][rx] == 3) break;
	}

	cout << result;
}