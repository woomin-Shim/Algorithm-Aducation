#include <iostream>
using namespace std;

//���� ���� �� ã��, �װ��� 1���� ä���. �׷��� ������ ������ �� �� �ִ�. 
int map[20][20];
int main() {
	int c, r;
	cin >> c >> r;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	int big = 0, X = 0;
	for (int i = 1; i <= c; i++) {//row   c:6 r:7
		int cnt = 0;
		for (int j = 1; j <= r; j++) { //column
			if (map[j][i] == 0) {
				cnt++;
			}
			else if (map[j][i] == 1) {
				break;
			}
		}
		if (big < cnt)
			big = cnt, X = i; //���� �������� ���ε���
	}

	int idx = 0, idx2 = 0;
	for (int i = 1; i <= r; i++) {
		if (map[i][X] == 1) {
			idx2 = i;
			break;
		}
		else {
			map[i][X] = 1;
			idx++;
		}
	}

	int y = 0;
	for (int i = 1; i <= r; i++) {
		int sum = 0;
		for (int j = 1; j <= c; j++) {
			sum += map[i][j];
		}
		if (sum == c) {
			y++;
		}
	}
	if ((r - idx2 + 1) + 4 > r) {
		X = 0, y = 0;
		cout << X << ' ' << y;
	}
	else
		cout << X << ' ' << y;
}