#include <iostream>
using namespace std;

/*�ڵ��� 10���� �����ϴ� ������ �� ���
  ù��°�ٿ��� ��¥ ���� �ڸ�, �ι�° �ٿ��� �ڵ���5���� ��ȣ�� �����ڸ� �Է�
  */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int day, car, n = 5, cnt=0;
	cin >> day;
	while (n--) {
		cin >> car;
		if (day == car)
			cnt++;
	}
	cout << cnt;
}