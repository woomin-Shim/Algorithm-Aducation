#include <iostream>
using namespace std;

//���μ� ����
int main() {
	int n;
	cin >> n;

	for (int i = 2; n > 1;) {
		if (n % i == 0) {
			cout << i << ' ';
			n /= i;
		}
		else i++;

	}

}