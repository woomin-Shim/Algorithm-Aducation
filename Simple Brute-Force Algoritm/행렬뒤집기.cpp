#include <iostream>
using namespace std;

/*����� �����´�. ������ ���Ұ� 1�̸� 0���� ����� ,0�̸� 1�θ����.
  ù��° ������ ���� 1��1���� 1��, i��° ���������� i�� i���� ������� �Ѵ�.
  N�� �Է��Ͽ��� �� ������ ���� ��� */
int map[11][11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt=1;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= 10; i++)
			map[i][cnt] += 1;
		for (int j = 1; j <= 10; j++) {
			if (j == k) continue;
			map[cnt][j] += 1;
		}
		cnt++;
	}
	
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (map[i][j] == 2) cout << 0 << ' ';
			else cout << map[i][j] << ' ';
		}
		cout << "\n";
	}

}