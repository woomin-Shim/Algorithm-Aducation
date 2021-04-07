#include <stdio.h>
#include <stdlib.h>   // �������� ����ϱ� ���� ������� 
#define MAX 100

int parent[MAX];  //vertex�� �ִ� ������ 100������ ����, input_graph�� ��� vertex=9

void init_set(int n) {  //parent �迭�� -1(root node)�� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int find(int vertex) {   //parent node�� ã�� �Լ� 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	else {
		return parent[vertex] = find(parent[vertex]);
	}
}
                               
void do_union(int v1, int v2) {  // 0  3  
	if (v1 > v2) {
		int temp = v1;
		v1 = v2;
		v2 = temp;
	}

	if (parent[v1] <= parent[v2]) {  //���� v1�� �� ���� ���Ҹ� ���� ��(�����ϱ� �ݴ��)
		//-4   -2
		//int temp = parent[v2];  //parent[v2] �� �ӽ� ����
		parent[v1] += parent[v2];  //parent[v1]�� ���Ұ� �߰� 
		parent[v2] = v1;  //���� v2 node�� ����v1�� �θ�� ���� 
	}
	else {
		//-2   -4
		//int temp = parent[v1];
		parent[v2] += parent[v1];
		parent[v1] = v2;
	}
}