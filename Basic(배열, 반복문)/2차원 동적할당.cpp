#include <iostream>
using namespace std;

int main() {
	int row = 5;             //�� �����Դϴ�.
	int column = 10;       //�� �����Դϴ�.
	int cnt = 0;

	int** ary = new int* [row];          //�̺κ��� �����Ҵ��Դϴ�.
	for (int i = 0; i < row; ++i)         //����� �����Ҵ� ���ְ� �ึ�� �� �����Ҵ� ���ִ°̴ϴ�
		ary[i] = new int[column];

	for (int i = 0; i < row; i++) {                       //Ȯ������ 0���� ���ʷ� ���־��ݴϴ�.
		for (int j = 0; j < column; j++) {
			ary[i][j] = cnt++;
		}
	}

	for (int i = 0; i < row; i++) {                       //Ȯ������ �� ���
		for (int j = 0; j < column; j++) {
			cout << ary[i][j] << ",";
		}
		cout << '\n';
	}

	for (int i = 0; i < row; i++)              //�޸� ���� , �ึ�� �������ְ�
		delete[] ary[i];
	delete[] ary;            //���������� �൵ ����
}
