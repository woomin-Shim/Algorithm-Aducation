#include <iostream>
#include <math.h>
using namespace std;

/*������ ��Ÿ��� ��Ÿ���� ����� ����
  ù��° �ٿ��� ���潺 ������ ��ũ�� N, ���� NXN����
  ��° �ٿ��� ������ ��ġ�� ��ġ x,y�� ������ ��Ÿ� R�� �Է�
  (x,y�� 1�̻� N������ �ڿ���, R�� N/2������ �ڿ���)
  ������ ��Ÿ��� ��� */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y, r;
	cin >> n;
	cin >> x >> y >> r;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == x && j == y)	cout << "X ";
			else if (abs(x - i) + abs(y - j) <= r) 
					cout << abs(x - i) + abs(y - j) << ' ';
			else
				cout << 0 << ' ';
		}
		cout << "\n";
	}

}