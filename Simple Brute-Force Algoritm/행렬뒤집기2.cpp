#include <iostream>
using namespace std;

/*��� ������ 1�� ��Ģ�� �Ȱ���.
  ��, N(������ Ƚ��)�� ���� ���� ����(10X10)�� �Է��ؾ� �Ѵ�.*/

int map[11][11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cin >> map[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < 11; i++)
			map[i][k] += 1;
		for (int j = 1; j < 11; j++) {
			if (k == j) continue;
			map[k][j] += 1;
		}
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (map[i][j] % 2 == 0) cout << 0 << ' ';
			else if (map[i][j] % 2 != 0) cout << 1 << ' ';
			//else cout << map[i][j] << ' ';
		}
		cout << "\n";
	}

}