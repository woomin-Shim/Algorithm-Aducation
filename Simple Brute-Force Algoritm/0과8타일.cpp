#include <iostream>
using namespace std;

/*N:��, M:��
  N��M�� �־����� �� ������� �°� 0�� 8�� �Է��ϸ�
  �¿�� �������� ����� ���*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--)
			cout << arr[i][j] << ' ';
		cout << "\n";
	}
		
}