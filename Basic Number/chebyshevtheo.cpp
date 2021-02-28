#include <iostream>
#include <math.h>
using namespace std;

/* ����Ʈ��-ü����� ������ ������ �ڿ��� n�� ���Ͽ� n���� ũ�� 2n���� �۰ų� ���� �Ҽ���
* ��� �ϳ� �����Ѵٴ� ������ ��� �ִ�.
* n�� �־����� �� n���� ũ��, 2n ���� �۰ų� ���� �Ҽ��� ������ ���ϴ� ���α׷� �ۼ� 
*/

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int n;

	while (1) {
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (isPrime(i))
				cnt++;
		}
		cout << cnt << "\n";
	}



}