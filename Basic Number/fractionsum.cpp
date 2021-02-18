#include <iostream>
using namespace std;

/*
���� �и� ��� �ڿ����� �� �м��� �� ���� ���� �и� �ڿ����� �м��� ǥ���� �� �ִ�.
�� �м��� �־����� ��, �� ���� ���м��� ���·� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int gcd(int a, int b) {
	while (1) {
		int rest = a % b;
		if (rest == 0) {
			return b;
			break;
		}
		a = b;
		b = rest;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, a2, b2;
	
	cin >> a >> a2;
	cin >> b >> b2;

	int down = a2 * b2;
	int up = b * a2 + a * b2;

	int num =gcd(up, down);

	cout << up / num << ' ' << down / num;

	return 0;
}