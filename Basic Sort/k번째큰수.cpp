#include <iostream>
using namespace std;

/*ù° �ٿ� �ڿ��� N, K�� �־����� (1<=N<=100,000, 1<=K<=10)
  �ι�° �ٿ� N���� �ڿ����� �־�����.
  K��°�� ū ���� ���. ��, k�� 1�̶�� ���� ū���� ���. */

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;

	cin >> n >> k;
	int* data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	
	int cnt = 0, result=0;
	for (int i = 0; i < n; i++) {
		cnt++;
		for (int j = 0; j < n - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
			if (cnt == k)
				result = data[n - i-1];
			
		}
	}
	
		cout << result << ' ';



}