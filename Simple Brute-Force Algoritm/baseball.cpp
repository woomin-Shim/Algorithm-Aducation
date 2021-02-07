#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//BOJ 2503

typedef struct {
	int number;
	int Strike;
	int Ball;
}Baseball;


vector<Baseball> v;
bool true_num[1000];

void init() {
	memset(true_num, true, sizeof(true_num)); //true_num �迭�� ��ü�� true�� 
	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);  //�ε��� ������ ���ϰ� �ϱ����� string���� 
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			true_num[i] = false;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) //0�� �������� �ʾƵ� ��
			true_num[i] = false;
	}
}

void input() {
	int n;
	Baseball B;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		B.number = a;
		B.Strike = b;
		B.Ball = c;

		v.push_back(B);
	}
}

void result() {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		int num = v[i].number;
		int strike = v[i].Strike;
		int ball = v[i].Ball;
		string ori = to_string(num);
		for (int j = 123; j <= 987; j++) {
			int temp_s = 0;
			int temp_b = 0;
			if (true_num[j]) {
				string s = to_string(j);
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (a == b) {
							if (ori[a] == s[b])
								temp_s++;
						}
						else {
							if (ori[a] == s[b])
								temp_b++;
						}
					}
				}
			}
			//123~987 ������ ������ ��Ʈ����ũ�� ���� �ȸ����� �� ���ڴ� False ó�� 
			if (strike != temp_s || ball != temp_b) true_num[j] = false;
		}
	}
	for (int i = 123; i <= 987; i++)
		if (true_num[i]) cnt++;
	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	 
	init();
	input();
	result();

	return 0;
}