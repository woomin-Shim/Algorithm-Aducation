#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n-1 ; j++) 
			cout << ' ';
		for (int k = 0; k < i + 1; k++)
			cout << "*";
		cout << "\n";
	}
}