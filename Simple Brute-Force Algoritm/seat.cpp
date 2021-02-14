#include <iostream>
using namespace std;

//BOJ 10157 
int seat[1001][1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c, num= 0, dex;
	cin >> r >> c;  // 7  6
	cin >> dex;

	int x = r, y = c; // x�� y���� �̿��Ͽ� �¼���ȣ ����
	int s = -1; //���� ���⿡ ���� ��ȣ�� �޸� �ؼ� ��� 
	int col = 1;
	int row = c+1;

	while (1) {
		for (int i = 1; i <= y; i++) {
			num += 1;
			row += s;
			seat[row][col] = num;		
		}
		x -= 1;
		y -= 1;
		s *= -1; //��ȣ ����

		for (int i = 1; i <= x; i++) {
			num += 1;
			col += s;
			seat[row][col] = num;
		}	

		if (x < 0 || y < 0)break;
	}

	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			if (seat[i][j] == dex)
				cout << j  << ' ' << r-i;
		}
	}


}