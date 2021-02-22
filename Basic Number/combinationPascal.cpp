#include <iostream>
using namespace std;

//2���� �迭�� ũ�Ⱑ ũ�� Runtime Error!! , Ʋ��Ǯ�� 
//BOJ 2004

int arr[31][31];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            }
            else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= i; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << "\n";
   }
    int rest=0, cnt=0;
    while (1) {
        rest = arr[n][m] % 10;
        if (rest != 0) break;
       
        cnt++;
        arr[n][m] /= 10;  
    }

    cout << cnt;
    return 0;
}


/*

nCr + nCr+1 = n+1Cr+1 �̴�.
���� ���, 10�� �� 2���� ���� ����� ���� 45���̴�. -> 10 x 9 / 2 x 1;
9C1 + 9C2 = 45�̴�.

�ٸ� ���� ����, 9�� �� 3���� ���� ����� ���� 9C3 �ε�,
8C2 + 8C3 ���� ǥ���ȴ�.

<�ڵ�>

#include<stdio.h>

int n,m;
int combi[32][32];

int getCombi(int arr[][32], int l, int k)
{
  if(k==1){
    // nC1�� �׻� n

    arr[l][k] = l;

    return l;
  }
  if(k==0){

    // nC0 �� �׻� 1

    arr[l][k] = 1;

    return 1;
  }
  if(l==k){
    // nCn �� �׻� 1
    arr[l][k] = 1;
    return 1;
  }

  if(arr[l][k]!=0){
    return arr[l][k];
  }


  arr[l][k] = getCombi(arr,l-1,k)+getCombi(arr,l-1,k-1);
  return arr[l][k];
}

int main(){

  scanf("%d %d",&n,&m);

  printf("%d",getCombi(combi,n,m));

  return 0;

}*/