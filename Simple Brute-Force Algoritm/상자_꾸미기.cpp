#include <iostream>
using namespace std;

/*���� 6���� ���ڰ� �ִ�. �̸� �������� �����̸� �ٿ� �ٹз����ϴµ�
  ��, ������ ���� ���� ���� ���̸� ���� �� ����.���� �Ѹ鿡�� ������ �����̸� ����
  ������ �����ϸ� yes �������� ������ no 
  �Է�-> �������� ���� N, ���� �������� ������ ��Ÿ���� N���� ���� */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum = 0;
	string s;
	cin >> n;
	int* arr = new int[n];
	int* cnt = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i+1 == arr[j]) cnt[i]++;
			if (cnt[i] > 2)
				cnt[i] = 2;
		}
		sum += cnt[i];
	}
	
		if (sum >= 6) 
			cout << "YES\n";
		else 
			cout << "NO\n";

		delete[] arr, delete[] cnt;
	
}