#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int data[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	for (int i = 0; i<n; i++) {
		//i�� ����Ű�� �ִ� ���� �־�� �Ѵ�. ��, i������ ��� ���� 
		
		//j�� ������ i���� ù��° ���ڱ���(0��° ���� x : ���� ���ڿ� ���ϱ� ������)
		for (int j = i; j > 0; j--) {
			if (data[j] < data[j - 1]) {
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
			else break;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
}