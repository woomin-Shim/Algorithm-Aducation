#include <iostream>
#include <vector>
using namespace std;

/* BOJ 2485
�ִ������� �̿��� �����̴�.
���μ��� ���� ���� ��� ���� �� ���ݳ����� �ִ� ������� ���Ѵ�.
���� ù ���μ��� ������ ���μ� ������ ���� ���ؼ� �ִ� ������� ������ �־�� �ϴ� ��� ���μ��� ���� ���´�.
�ű⼭ n �� ���ָ� ���� �ɾ�� �ϴ� ���μ��� ���� �� �� �ִ�.
*/

vector<int> v;
vector<int> v2;

int Gcd(int a, int b) {
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
	int n;
	long long int tree;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree;
		v.push_back(tree);
		if (i > 0) {
			v2.push_back(v[i] - v[i - 1]);
		}
	}
		
	int gcd = v2[0];
	for (int i = 1; i < v2.size(); i++) {
		gcd = Gcd(gcd, v2[i]);
	}

	cout << (v[n-1] - v[0]) / gcd - n + 1;
	
	
}