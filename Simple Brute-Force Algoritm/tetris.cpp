#include <iostream>
using namespace std;

/*�� ������ 1*4�� ���ڰ� �� �� �ִ��� ���� �˻� �� 
  ���� ���ϸ� 0�� ����ϰ� ���� �Ǹ� �� ���� 1�� ä��� 
  ��� ����� �˻��Ͽ� �����ϴ� ������ ������ ���� �ȴ�. 
  �߿��� ���� 1�� ä��� ���� ������ ������ ���� �ٽ� 1�� ä�� �κ��� 0���� �ʱ�ȭ�ؾ��� */
int map[20][20];
int arr[20];
int num[20];
int main() {
	int c, r;
	cin >> c >> r;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	int X = 0, Y = 0;
	for (int i = 1; i <= c; i++) {//row   c:6 r:7
		int cnt = 0;
		for (int j = 1; j <= r; j++) { //column
			if (map[j][i] == 1) {
				break;
			}
			else {
				cnt++;
			}
			arr[i] = cnt;   // 2 2 2 7 4 2
		}
	}

	for (int i = 1; i <= c; i++) {
		if (arr[i] < 4) {
			X = 0; Y = 0;
		}
		else {
			for (int j = 1; j <= arr[i]; j++)
				map[j][i] = 1;
			for (int k = 1; k <= r; k++) {  //1�� ä��� ������ ������ num[]�� ��´�. 
				int sum = 0;
				for (int p = 1; p <= c; p++) {
					sum += map[k][p];
				}
				if (sum == c) num[i]++;
			}
			for (int j = 1; j <= arr[i]; j++)  //1�� ä���� �κ��� 0���� �ٽ� �ʱ�ȭ 
				map[j][i] = 0;
		}
	}
	int big = num[0];
	for (int i = 1; i <= c; i++) {
		if (big < num[i])
			big = num[i], X = i;
	}
	
	cout << X << ' ' << big << "\n";
}