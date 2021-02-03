#include <iostream>
#include <math.h>
using namespace std;

/*n������ �Ҽ��� ��� ���ϱ�
  �����ٱ����� ���Ͽ��� �Ҽ��� �Ǻ������ϴ�.
  ���� ��� 25�� 5*5, 1*25�� �ݸ� 16�� 4*4, 2*8�� �����ٺ��� ���������� �������� �� 
  */

bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		if (isPrime(i))
			cout << i << ' ';
	}

}