#include <iostream>
using namespace std;
#define MAX 1234
#define max(a,b) a>b? a : b  // ū �� return 
int P[] = { 0, 4, 6, 8, 9, 6 };  //price 
int W[] = { 0, 2, 4, 5, 8, 3 };  //weight 
int K[MAX][MAX];
int K2[MAX][MAX];

int ks_01_DP(int n, int m) {  // n:�賶 ����, m:�賶 ũ�� 
	int i, w;
	
	//0��(������ X)�� 0��(���԰� 0) ��0���� �ʱ�ȭ
	//for (w = 0; w <= m; w++) K[0][w] = 0;
	//for (i = 0; i <= n; i++) K[i][0] = 0;

	for (i = 1; i <= n; i++) {
		for (w = 1; w <= m; w++) {
			if (w < W[i]) //������ ���԰� �賶�� ���Ը� �ʰ��ϸ� 
				K[i][w] = K[i - 1][w];
			else  //�ʰ����� ������ ������ ����/�������� �ʾ��� �� �� 
				K[i][w] = max(K[i - 1][w], K[i - 1][w - W[i]] + P[i]);
		}
	}

	return K[n][m];
}

int ks_01_DP2(int n, int m) {  //Dynamic programming 2
	int i, w;

	//0��, 0���� ������ �κ� -1�� �ʱ�ȭ 
	for (i = 1; i <= n; i++)
		for (w = 1; w <= m; w++)
			K2[i][w] = -1;

	//int P[] = { 0, 4, 6, 8, 9, 6 };  
	//int W[] = { 0, 2, 4, 5, 8, 3 };  

	/* K[5][13]�� ���ϱ� ���ؼ��� K[4][13]�� K[4][13-W[5]] (=[4][10]) + P[5] �ʿ� 
	   K[4][13]  ->  [3][13], [3][13-W[4]] (=[3][5]) + P[4]  
	   k[4][10]  ->  [3][10], [3][2] + P[4]  
	*/

	
	return K[n][m];

}



int main() {
	int result = ks_01_DP(5, 13);  //�ִ� ���� 
	int result2 = ks_01_DP2(5, 13);

	//DP 1 ��� 
	for (int i = 0; i <= 5; i++) {
		for (int w = 0; w <= 13; w++) {
			//cout << "  ";
			cout.width(3);  //��� �����ϰ� ��� 
			cout << K[i][w];
		}
		cout << endl;
	}
	cout << "\n";
	//DP 2 print
	for (int i = 0; i <= 5; i++) {
		for (int w = 0; w <= 13; w++) {
			//cout << "  ";
			cout.width(3);  //��� �����ϰ� ��� 
			cout << K2[i][w];
		}
		cout << endl;
	}

	
}